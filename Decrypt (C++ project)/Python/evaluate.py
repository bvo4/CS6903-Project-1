import time
import string
import argparse
import random
from tqdm import tqdm
import numpy as np
import matplotlib.pyplot as plt



def get_letters():
  letters = [letter for letter in string.ascii_lowercase]
  letters.append(' ')
  return letters


def keygen():
  letters = get_letters()
  original_letters = letters[:] # make a shallow copy
  random.shuffle(letters)
  return {key: letter for key, letter in zip(original_letters, letters)}


"""
Apply monoalphabetic substitution cipher with random noise added
"""
def encrypt(message, key=None, rand_prob=0, return_cipher_positions=False):
  if key is None: # if a key is not supplied, randomly make a new one
    key = keygen()

  ciphertext = ''
  cipher_pos = []
  message_ptr = 0
  letters = get_letters()
  while message_ptr < len(message):
    coin_value = random.uniform(0, 1)
    if rand_prob == 0 or rand_prob < coin_value:
      message_letter = message[message_ptr]
      ciphertext += key[message_letter]
      message_ptr += 1
      cipher_pos.append(len(ciphertext)-1)
    else:
      ciphertext += random.choice(letters)

  if return_cipher_positions:
      return ciphertext, cipher_pos
  return ciphertext

"""
Evaluate a decryption function
report decryption accuracy with respect to randomness
report runtime with respect to randomness
"""
def evaluate(n_trials, decryption_alg):
    random_values = [i/20 for i in range(16)]
    accuracy = []
    runtime = []
    for r in tqdm(random_values):
        n_correct = 0
        runs = []
        for _ in range(n_trials):
            # choose a plaintext
            plaintext_choice = random.choice([1,2,3,4,5])
            plaintext = plaintexts[plaintext_choice]
            # encrypt the message
            ciphertext = encrypt(plaintext)
            start = time.time()
            prediction = decryption_alg(ciphertext)
            elapsed = time.time() - start
            runs.append(elapsed)
            n_correct += int(prediction == plaintext_choice)
        acc = n_correct/n_trials
        accuracy.append([r, acc])
        runtime.append([r, np.mean(runs)])
    return np.array(accuracy), np.array(runtime)

def plot(data):
    fig, ax = plt.subplots()
    ax.scatter(data[:, 0], data[:, 1])
    return fig, ax
    pass

"""
randomly guess the plaintext
This is the baseline that all other algorithms should be measured against

Basic structure of a decryption algorithm should take a single ciphertext as
input and return a single prediction between [1, 5] for the plaintext that the
ciphertext was sampled from

"""
def dummy_decryption(ciphertext):
    return random.choice([1,2,3,4,5])


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-n', '--n_trials', default=100, type=int)
    args = parser.parse_args()

    # get accuracy and runtime at different random probabilities used during encryption
    accuracy, runtime = evaluate(args.n_trials, dummy_decryption)

    # plot evaluation statistics
    fig, ax = plt.subplots(2)
    ax[0].plot(accuracy[:, 0], accuracy[:, 1])
    ax[0].set_xlabel('probability of random character')
    ax[0].set_ylabel('prediction accuracy')
    ax[0].axhline(0.2, color='red', label='baseline')
    ax[0].legend()
    ax[1].plot(runtime[:, 0], runtime[:, 1])
    ax[1].set_xlabel('probability of random character')
    ax[1].set_ylabel('runtime (s)')
    fig.tight_layout()
    plt.show()

