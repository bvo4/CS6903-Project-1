import time
import string
import argparse
import random
from tqdm import tqdm
import numpy as np
import matplotlib.pyplot as plt


plaintexts = {
    1: "underwaists wayfarings fluty analgia refuels transcribing nibbled okra buttonholer venalness hamlet praus apprisers presifted cubital walloper dissembler bunting wizardries squirrel preselect befitted licensee encumbrances proliferations tinkerer egrets recourse churl kolinskies ionospheric docents unnatural scuffler muches petulant acorns subconscious xyster tunelessly boners slag amazement intercapillary manse unsay embezzle stuccoer dissembles batwing valediction iceboxes ketchups phonily con",
    2: "rhomb subrents brasiers render avg tote lesbian dibbers jeopardy struggling urogram furrowed hydrargyrum advertizing cheroots goons congratulation assaulters ictuses indurates wingovers relishes briskly livelihoods inflatable serialized lockboxes cowers holster conciliating parentage yowing restores conformities marted barrettes graphically overdevelop sublimely chokey chinches abstracts rights hockshops bourgeoisie coalition translucent fiascoes panzer mucus capacitated stereotyper omahas produ",
    3: "yorkers peccaries agenda beshrews outboxing biding herons liturgies nonconciliatory elliptical confidants concealable teacups chairmanning proems ecclesiastically shafting nonpossessively doughboy inclusion linden zebroid parabolic misadventures fanciers grovelers requiters catmints hyped necklace rootstock rigorously indissolubility universally burrowers underproduced disillusionment wrestling yellowbellied sherpa unburnt jewelry grange dicker overheats daphnia arteriosclerotic landsat jongleur",
    4: "cygnets chatterers pauline passive expounders cordwains caravel antidisestablishmentarianism syllabubs purled hangdogs clonic murmurers admirable subdialects lockjaws unpatentable jagging negotiated impersonates mammons chumminess semi pinner comprised managership conus turned netherlands temporariness languishers aerate sadists chemistry migraine froggiest sounding rapidly shelving maligning shriek faeries misogynist clarities oversight doylies remodeler tauruses prostrated frugging comestible ",
    5: "ovulatory geriatric hijack nonintoxicants prophylactic nonprotective skyhook warehouser paganized brigading european sassier antipasti tallyho warmer portables selling scheming amirate flanker photosensitizer multistage utile paralyzes indexer backrests tarmac doles siphoned casavas mudslinging nonverbal weevil arbitral painted vespertine plexiglass tanker seaworthiness uninterested anathematizing conduces terbiums wheelbarrow kabalas stagnation briskets counterclockwise hearthsides spuriously s"
    }


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

