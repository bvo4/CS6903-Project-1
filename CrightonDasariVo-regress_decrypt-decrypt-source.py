import pickle
import pathlib
import math
import string
import numpy as np
from decimal import Decimal, ROUND_UP
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import PolynomialFeatures
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import cross_val_score
from tqdm import tqdm

import utils
from utils import plaintexts


def argwhere(records, feature, value):
  return np.array([i for i, row in enumerate(records) if row[feature] == value])

"""
Give the amount of probability of random characters used during encryption and the position of a particular
Train a regression model based on the following features:
    1: amount of randomness in the ciphertext
    2: position of a character in the plaintext

Use these features to predict the approximate position of a character in the
ciphertext
"""
def train_regression_model(data_file):
    # skip training if model already exists
    model_path = pathlib.Path('./model.pkl')
    if model_path.is_file():
        # load existing model
        with open(model_path, 'rb') as f:
            pipeline = pickle.load(f)
        return pipeline
    else: # train and save the model if it hasn't been saved already
        data = np.load('data.npy')
        polynomial_features = PolynomialFeatures(degree=3, include_bias=False)
        linear_regression = LinearRegression()
        pipeline = Pipeline(
                [
                    ("polynomial_features", polynomial_features),
                    ("linear_regression", linear_regression),
                ]
            )
        pipeline.fit(data[:, 0:2], data[:, -1])
        preds = pipeline.predict(data[:, 0:2])


        # save the model
        with open(model_path, 'wb+') as f:
            pickle.dump(pipeline, f)
        return pipeline

"""
Store a word, a specefic letter in that word, the index of that letter, how
many times the letter occurs in the word, and the plaintext the word was
sampled from
"""
class WordLetter:
  def __init__(self, word, letter, idx, n_occur, plaintext):
    self.word = word
    self.letter = letter
    self.idx = idx
    self.n_occur = n_occur
    self.plaintext = plaintext

  def __repr__(self):
    return f'word: {self.word}, letter: {self.letter}, idx: {self.idx}, plaintext: {self.plaintext}'
  
  
def get_interesting_words(plaintext_dict):
    """
    For every text in the plaintext dictionary, return words that contain a letter that repeats at least 3 times

    """
    words_to_check = []
    for idx, text in plaintext_dict.items():
        letter_reps = []

        start_idx = []
        # for each word, compute the starting characters index
        for char_idx, char in enumerate(text):
          # slice till the next space character
          if char_idx == 0 or text[char_idx-1] == ' ':
            start_idx.append(char_idx)

        for s_idx, word in zip(start_idx, text.split(' ')):
            letter_counts = {letter: 0 for letter in utils.get_letters()}
            for letter in word:
                letter_counts[letter] += 1
            for letter, count in letter_counts.items():
                if count > 2:
                    letter_reps.append(WordLetter(word, letter, s_idx, count, idx))

        words_to_check.extend(letter_reps)
    return words_to_check


def decrypt(ciphertext):
    plaintext_scores = {i: 0 for i in range(1, 6)}
    interesting_words = get_interesting_words(plaintexts)
    model = train_regression_model('data.npy')
    for word in interesting_words:
        plaintext_pos = utils.get_relative_positions(word.word, word.letter)
        plaintext_start, plaintext_end = word.idx, word.idx + len(word.word)
        plaintext_std = np.std(plaintext_pos)

        # compute the amount of skew in the cipher text
        cipher_freq = utils.compute_letter_frequencies(ciphertext)
        skew_value = utils.compute_skew(cipher_freq)

        # use regression model to predict start and end point
        cipher_slice_idx = model.predict([[skew_value, plaintext_start], [skew_value, plaintext_end]])
        padding = 2
        cipher_start, cipher_end = math.floor(cipher_slice_idx[0]-padding), math.floor(cipher_slice_idx[1]+padding) # round and pad the slice to make sure we dont miss anything
        # slice the ciphertext
        cipher_slice = ciphertext[cipher_start:cipher_end]

        # find letters that appear more than 3 times
        letter_counts = {l: 0 for l in string.ascii_lowercase}
        letter_counts[' '] = 0
        for char in cipher_slice:
            letter_counts[char] += 1

        # for each letter that appears more than 3 times, compute the standard deviation of the relative positions
        min_std = 1
        for letter, count in letter_counts.items():
            if count > 2:
                cipher_pos = utils.get_relative_positions(cipher_slice, letter)
                min_std = min(np.std(cipher_pos), min_std)
        plaintext_scores[word.plaintext] += min_std

    prediction = None
    min_score = 999
    for p, score in plaintext_scores.items():
      if score < min_score:
        min_score = score
        prediction = p
    return prediction


if __name__ == '__main__':
    
    cipher_text = input("Enter the Ciphertext: \n")
    print("Deciphering Ciphertext...")
    guess = decrypt(cipher_text)
    print("My plaintext guess is Plain Text #{}".format(guess))

