import string
import numpy as np
from scipy.stats import skew

# Based on Brandon and Rohin's analysis
# by Alvin Crighton 

plaintexts = {
    1: "underwaists wayfarings fluty analgia refuels transcribing nibbled okra buttonholer venalness hamlet praus apprisers presifted cubital walloper dissembler bunting wizardries squirrel preselect befitted licensee encumbrances proliferations tinkerer egrets recourse churl kolinskies ionospheric docents unnatural scuffler muches petulant acorns subconscious xyster tunelessly boners slag amazement intercapillary manse unsay embezzle stuccoer dissembles batwing valediction iceboxes ketchups phonily con",
    2: "rhomb subrents brasiers render avg tote lesbian dibbers jeopardy struggling urogram furrowed hydrargyrum advertizing cheroots goons congratulation assaulters ictuses indurates wingovers relishes briskly livelihoods inflatable serialized lockboxes cowers holster conciliating parentage yowing restores conformities marted barrettes graphically overdevelop sublimely chokey chinches abstracts rights hockshops bourgeoisie coalition translucent fiascoes panzer mucus capacitated stereotyper omahas produ",
    3: "yorkers peccaries agenda beshrews outboxing biding herons liturgies nonconciliatory elliptical confidants concealable teacups chairmanning proems ecclesiastically shafting nonpossessively doughboy inclusion linden zebroid parabolic misadventures fanciers grovelers requiters catmints hyped necklace rootstock rigorously indissolubility universally burrowers underproduced disillusionment wrestling yellowbellied sherpa unburnt jewelry grange dicker overheats daphnia arteriosclerotic landsat jongleur",
    4: "cygnets chatterers pauline passive expounders cordwains caravel antidisestablishmentarianism syllabubs purled hangdogs clonic murmurers admirable subdialects lockjaws unpatentable jagging negotiated impersonates mammons chumminess semi pinner comprised managership conus turned netherlands temporariness languishers aerate sadists chemistry migraine froggiest sounding rapidly shelving maligning shriek faeries misogynist clarities oversight doylies remodeler tauruses prostrated frugging comestible ",
    5: "ovulatory geriatric hijack nonintoxicants prophylactic nonprotective skyhook warehouser paganized brigading european sassier antipasti tallyho warmer portables selling scheming amirate flanker photosensitizer multistage utile paralyzes indexer backrests tarmac doles siphoned casavas mudslinging nonverbal weevil arbitral painted vespertine plexiglass tanker seaworthiness uninterested anathematizing conduces terbiums wheelbarrow kabalas stagnation briskets counterclockwise hearthsides spuriously s"
    }

alphabet = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k",
             "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", " " ]

p1 = "underwaists wayfarings fluty analgia refuels transcribing nibbled okra buttonholer venalness hamlet praus apprisers presifted cubital walloper dissembler bunting wizardries squirrel preselect befitted licensee encumbrances proliferations tinkerer egrets recourse churl kolinskies ionospheric docents unnatural scuffler muches petulant acorns subconscious xyster tunelessly boners slag amazement intercapillary manse unsay embezzle stuccoer dissembles batwing valediction iceboxes ketchups phonily con"
p2 = "rhomb subrents brasiers render avg tote lesbian dibbers jeopardy struggling urogram furrowed hydrargyrum advertizing cheroots goons congratulation assaulters ictuses indurates wingovers relishes briskly livelihoods inflatable serialized lockboxes cowers holster conciliating parentage yowing restores conformities marted barrettes graphically overdevelop sublimely chokey chinches abstracts rights hockshops bourgeoisie coalition translucent fiascoes panzer mucus capacitated stereotyper omahas produ"
p3 = "yorkers peccaries agenda beshrews outboxing biding herons liturgies nonconciliatory elliptical confidants concealable teacups chairmanning proems ecclesiastically shafting nonpossessively doughboy inclusion linden zebroid parabolic misadventures fanciers grovelers requiters catmints hyped necklace rootstock rigorously indissolubility universally burrowers underproduced disillusionment wrestling yellowbellied sherpa unburnt jewelry grange dicker overheats daphnia arteriosclerotic landsat jongleur"
p4 = "cygnets chatterers pauline passive expounders cordwains caravel antidisestablishmentarianism syllabubs purled hangdogs clonic murmurers admirable subdialects lockjaws unpatentable jagging negotiated impersonates mammons chumminess semi pinner comprised managership conus turned netherlands temporariness languishers aerate sadists chemistry migraine froggiest sounding rapidly shelving maligning shriek faeries misogynist clarities oversight doylies remodeler tauruses prostrated frugging comestible "
p5 = "ovulatory geriatric hijack nonintoxicants prophylactic nonprotective skyhook warehouser paganized brigading european sassier antipasti tallyho warmer portables selling scheming amirate flanker photosensitizer multistage utile paralyzes indexer backrests tarmac doles siphoned casavas mudslinging nonverbal weevil arbitral painted vespertine plexiglass tanker seaworthiness uninterested anathematizing conduces terbiums wheelbarrow kabalas stagnation briskets counterclockwise hearthsides spuriously s"

p = [p1, p2, p3, p4, p5]
c = []

possible_keys = {"a":[], "b":[], "c":[], "d":[], "e":[], "f":[], "g":[], "h":[], "i":[], "j":[], "k":[],
             "l":[], "m":[], "n":[], "o":[], "p":[], "q":[], "r":[], "s":[], "t":[], "u":[], "v":[], "w":[], "x":[], "y":[], "z":[], " ":[]}

def get_pos(pos, text):
    # Gets relative position of all the letters
    clone = {}
    for i in pos.keys():
        clone[i] = []
    for i, val in enumerate(text):
        clone[val].append(i/len(text))
    return clone

def concat_dict_values(d):
    return ''.join(d.values())

def compute_letter_frequencies(text):
    # build dictionary to store letter frequencies
    freq = {}
    for letter in string.ascii_lowercase:
        freq[letter] = 0
        freq[' '] = 0
    # count letter frequencies
    for letter in text:
        freq[letter] += 1

    # store letters and frequencies as numpy arrays
    letters = np.array(list(freq.keys()))
    freq = np.array(list(freq.values()))

    # normalize counts of letters
    freq = freq / np.sum(freq)

    # sort for visualization
    sorted_idx = np.argsort(freq)
    letters_sorted = letters[sorted_idx]
    freq_sorted = freq[sorted_idx]

    # reconstruct the dictionary in sorted order
    return {l: f for l, f in zip(letters_sorted, freq_sorted)}

def get_plain_freq():
    # retrieves the letter frequencies of all the plain text and stores them in a list
    letter_freq = []
    for i in p:
        letter_freq.append(compute_letter_frequencies(i))
    return letter_freq

def compute_chi_squared(ciphertext, expected_freq, cipher_letter, plain_letter, random_prob_estimate):
    # look up how many times the cipher letter occurs in the ciphertext
    cipher_occur = len([i for i in ciphertext if i == cipher_letter])

    plain_occur = len(ciphertext)*(1-random_prob_estimate)*expected_freq[plain_letter]

    # compute chi squared metric
    chi = ((cipher_occur - plain_occur)**2)/plain_occur
    return chi

def compute_skew(frequencies):
  samples = []
  for i, (letter, freq) in enumerate(frequencies.items()):
    for _ in range(int(freq*10000)):
      samples.append(i)
  return skew(samples)

def get_closest_cipher_letter(ciphertext, encrypted_frequency, expected_frequency, mapped_letters, plain_letter):
    random_prob = compute_skew(encrypted_frequency) + 1 # rough estimate of random probability based on regression model
    min_chi = 99999
    min_ciph_letter = None
    for cipher_letter in encrypted_frequency:
        if cipher_letter in mapped_letters:
            # we've already found a good match for this letter, so let's move on
            continue
        chi = compute_chi_squared(ciphertext, expected_frequency, cipher_letter, plain_letter, random_prob)
        if chi is not None and chi < min_chi:
            min_chi = chi
            min_ciph_letter = cipher_letter
    return min_ciph_letter

def get_approx_key(ciphertext):
    # retrieves approximate key from english letter frequency 
    expected_frequency = compute_letter_frequencies(concat_dict_values(plaintexts))
    encrypted_frequency = compute_letter_frequencies(ciphertext)
    approx_key = {}
    mapped_cipher_letters = []
    for plain_letter, plain_freq in expected_frequency.items():
        closest_match = get_closest_cipher_letter(ciphertext, encrypted_frequency, expected_frequency, mapped_cipher_letters, plain_letter)
        approx_key[plain_letter] = closest_match
        mapped_cipher_letters.append(closest_match)
    return approx_key

def recovery_func(cipher_text):
    # uses the approx key to get a rough deciphered text
    key_guess = get_approx_key(cipher_text)
    recovery = ""
    for i in cipher_text:
        recovery = recovery + key_guess[i]
    return recovery

def get_position():
    # gets relative position of all the plain text
    p_position = []
    for i in p:
        p_position.append(get_pos(possible_keys, i))
    return p_position

def check_relative(decrypt):
    # Deciphering function to guess which plaintext this ciphertext is. 
    decrypt = recovery_func(decrypt)
    d_rel = get_pos(possible_keys, decrypt)
    chi_error = []
    letter_freq = get_position()
    for positions in letter_freq:
        chi_calc = 0
        total_chi = 0
        for letters in list(positions.keys()):
            for expected in positions[letters]:
                minimum = 999999
                if expected != 0:
                    for guess in d_rel[letters]:   
                        calc = (guess - expected)**2/expected
                        if calc < minimum:
                            minimum = calc
           
            total_chi += minimum
        chi_error.append(total_chi)
    guess = chi_error.index(min(chi_error))
    return guess

def main():
    cipher_text = input("Enter the Ciphertext: \n")
    print("Deciphering Ciphertext...")
    guess = check_relative(cipher_text)+1
    print("My plaintext guess is Plain Text #{}".format(guess))

main()