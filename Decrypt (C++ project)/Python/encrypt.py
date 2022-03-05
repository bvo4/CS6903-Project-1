import random 
import numpy as np
import matplotlib.pyplot as plt

alphabet = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k",
             "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", " " ]

count = {"a":0, "b":0, "c":0, "d":0, "e":0, "f":0, "g":0, "h":0, "i":0, "j":0, "k":0,
             "l":0, "m":0, "n":0, "o":0, "p":0, "q":0, "r":0, "s":0, "t":0, "u":0, "v":0, "w":0, "x":0, "y":0, "z":0, " ":0}

def generate_key(alphabet):
    key = {}
    numbers = [i for i in range(27)]
    for i in range(27):
        index = random.randint(0,len(alphabet))
        while index not in numbers:
            index = random.randint(0,len(alphabet))
        key[alphabet[i]] = alphabet[index]
        numbers.remove(index)
    return key

def encrypt(m, key):
    prob_of_random_ciphertext = 0.70
    cipher = ''
    index = 0
    num_rand = 0
    while index != len(m):
        coin = random.uniform(0, 1)
        if (prob_of_random_ciphertext < coin <= 1):
            cipher += key[m[index]]
            index += 1
        if (0 <= coin <= prob_of_random_ciphertext):
            random_num = random.randint(0,26)
            cipher += alphabet[random_num]
            num_rand += 1
    return cipher

def get_count(count, text):
    clone = {}
    for i in count.keys():
        clone[i] = 0
    for i in text:
        clone[i] += 1
    return clone

def mfl(count):
    most_freq = (" ", 0)
    for i in count.keys():
        if count[i] > most_freq[1]:
            most_freq = (i, count[i])
    return most_freq

def lfl(count):
    most_freq = ("NAN", 1000)
    for i in count.keys():
        if count[i] < most_freq[1]:
            most_freq = (i, count[i])
    return most_freq

def sort_v(val):
    return {k: v for k, v in sorted(val.items(), key=lambda item: item[1])}

def compare(plain, cipher):
    similarity = 0
    for i, val in enumerate(plain):
        if abs(val - cipher[i]) <= 0.001:
            similarity += 1
    return similarity

def compare_all(cipher_target, plains):
    text = 1
    all_sim = []
    print(cipher_target, "target", sum(cipher_target))
    for val in plains:
        all_sim.append(compare(cipher_target, val))
        print(val)
    for i in all_sim:
        print("This cipher target has {0} similarities with Plain text {1}".format(i, text))
        text += 1
    closest = all_sim.index(max(all_sim)) - 1
    print("This is most similar to Plain text {0}".format(all_sim.index(max(all_sim))+1))

def dict_percentage(d):
    total = sum(d.values())
    for i in d.keys():
        d[i] = d[i] / total
    return d


"""
p1 = "underwaists wayfarings fluty analgia refuels transcribing nibbled okra buttonholer venalness hamlet praus apprisers presifted cubital walloper dissembler bunting wizardries squirrel preselect befitted licensee encumbrances proliferations tinkerer egrets recourse churl kolinskies ionospheric docents unnatural scuffler muches petulant acorns subconscious xyster tunelessly boners slag amazement intercapillary manse unsay embezzle stuccoer dissembles batwing valediction iceboxes ketchups phonily con"
p2 = "rhomb subrents brasiers render avg tote lesbian dibbers jeopardy struggling urogram furrowed hydrargyrum advertizing cheroots goons congratulation assaulters ictuses indurates wingovers relishes briskly livelihoods inflatable serialized lockboxes cowers holster conciliating parentage yowing restores conformities marted barrettes graphically overdevelop sublimely chokey chinches abstracts rights hockshops bourgeoisie coalition translucent fiascoes panzer mucus capacitated stereotyper omahas produ"
p3 = "yorkers peccaries agenda beshrews outboxing biding herons liturgies nonconciliatory elliptical confidants concealable teacups chairmanning proems ecclesiastically shafting nonpossessively doughboy inclusion linden zebroid parabolic misadventures fanciers grovelers requiters catmints hyped necklace rootstock rigorously indissolubility universally burrowers underproduced disillusionment wrestling yellowbellied sherpa unburnt jewelry grange dicker overheats daphnia arteriosclerotic landsat jongleur"
p4 = "cygnets chatterers pauline passive expounders cordwains caravel antidisestablishmentarianism syllabubs purled hangdogs clonic murmurers admirable subdialects lockjaws unpatentable jagging negotiated impersonates mammons chumminess semi pinner comprised managership conus turned netherlands temporariness languishers aerate sadists chemistry migraine froggiest sounding rapidly shelving maligning shriek faeries misogynist clarities oversight doylies remodeler tauruses prostrated frugging comestible "
p5 = "ovulatory geriatric hijack nonintoxicants prophylactic nonprotective skyhook warehouser paganized brigading european sassier antipasti tallyho warmer portables selling scheming amirate flanker photosensitizer multistage utile paralyzes indexer backrests tarmac doles siphoned casavas mudslinging nonverbal weevil arbitral painted vespertine plexiglass tanker seaworthiness uninterested anathematizing conduces terbiums wheelbarrow kabalas stagnation briskets counterclockwise hearthsides spuriously s"

key = generate_key(alphabet)

cipher_text = encrypt(p1, key)
message_count = get_count(count, p1)
cipher_count = get_count(count, cipher_text)

cipher_text2 = encrypt(p2, key)
message_count2 = get_count(count, p2)
cipher_count2 = get_count(count, cipher_text2)

cipher_text3 = encrypt(p3, key)
message_count3 = get_count(count, p3)
cipher_count3 = get_count(count, cipher_text3)

cipher_text4 = encrypt(p4, key)
message_count4 = get_count(count, p4)
cipher_count4 = get_count(count, cipher_text4)

cipher_text5 = encrypt(p5, key)
message_count5 = get_count(count, p5)
cipher_count5 = get_count(count, cipher_text5)

sorted_plain_count = [list(sort_v(message_count).values()), list(sort_v(message_count2).values()), list(sort_v(message_count3).values()), list(sort_v(message_count4).values()), list(sort_v(message_count5).values())]
sorted_cipher_count = [list(sort_v(cipher_count).values()), list(sort_v(cipher_count2).values()), list(sort_v(cipher_count3).values()), list(sort_v(cipher_count4).values()), list(sort_v(cipher_count5).values())]


print("Calculating similarities with Ciphertext 1")
compare_all(sorted_cipher_count[0], sorted_plain_count)
print()
print("Calculating similarities with Ciphertext 2")
compare_all(sorted_cipher_count[1], sorted_plain_count)
print()
print("Calculating similarities with Ciphertext 3")
compare_all(sorted_cipher_count[2], sorted_plain_count)
print()
print("Calculating similarities with Ciphertext 4")
compare_all(sorted_cipher_count[3], sorted_plain_count)
print()
print("Calculating similarities with Ciphertext 5")
compare_all(sorted_cipher_count[4], sorted_plain_count)
print()

print("mfl", mfl(message_count), mfl(cipher_count), "lfl", lfl(message_count), lfl(cipher_count))
print()
print("mfl2", mfl(message_count2), mfl(cipher_count2), "lfl", lfl(message_count2), lfl(cipher_count2))
print()
print("mfl3", mfl(message_count3), mfl(cipher_count3), "lfl", lfl(message_count3), lfl(cipher_count3))
print()
print("mfl4", mfl(message_count4), mfl(cipher_count4), "lfl", lfl(message_count4), lfl(cipher_count4))
print()
print("mfl5", mfl(message_count5), mfl(cipher_count5), "lfl", lfl(message_count5), lfl(cipher_count5))
print()

print((sum(cipher_count.values())-500)/ 500)
print((sum(cipher_count2.values())-500)/ 500)
print((sum(cipher_count3.values())-500)/ 500)
print((sum(cipher_count4.values())-500)/ 500)
print((sum(cipher_count5.values())-500)/ 500)

dict_percentage(message_count)
dict_percentage(message_count2)
dict_percentage(message_count3)
dict_percentage(message_count4)
dict_percentage(message_count5)

dict_percentage(cipher_count)
dict_percentage(cipher_count2)
dict_percentage(cipher_count3)
dict_percentage(cipher_count4)
dict_percentage(cipher_count5)

print(key)
#print(cipher_text)

plt.subplot(5,2,1)
plt.title("Plaintext 1")
plt.bar(message_count.keys(), message_count.values(), 0.5, color='g')
plt.subplot(5,2,2)
plt.title("Ciphertext 1")
plt.bar(cipher_count.keys(), cipher_count.values(), 0.5, color='g')

plt.subplot(5,2,3)
plt.title("Plaintext 2")
plt.bar(message_count2.keys(), message_count2.values(), 0.5, color='g')
plt.subplot(5,2,4)
plt.title("Ciphertext 2")
plt.bar(cipher_count2.keys(), cipher_count2.values(), 0.5, color='g')

plt.subplot(5,2,5)
plt.title("Plaintext 3")
plt.bar(message_count3.keys(), message_count3.values(), 0.5, color='g')
plt.subplot(5,2,6)
plt.title("Ciphertext 3")
plt.bar(cipher_count3.keys(), cipher_count3.values(), 0.5, color='g')

plt.subplot(5,2,7)
plt.title("Plaintext 4")
plt.bar(message_count4.keys(), message_count4.values(), 0.5, color='g')
plt.subplot(5,2,8)
plt.title("Ciphertext 4")
plt.bar(cipher_count4.keys(), cipher_count4.values(), 0.5, color='g')

plt.subplot(5,2,9)
plt.title("Plaintext 5")
plt.bar(message_count5.keys(), message_count5.values(), 0.5, color='g')
plt.subplot(5,2,10)
plt.title("Ciphertext 5")
plt.bar(cipher_count5.keys(), cipher_count5.values(), 0.5, color='g')

plt.show()
"""