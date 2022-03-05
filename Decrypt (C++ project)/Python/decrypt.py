import encrypt as e

p1 = "underwaists wayfarings fluty analgia refuels transcribing nibbled okra buttonholer venalness hamlet praus apprisers presifted cubital walloper dissembler bunting wizardries squirrel preselect befitted licensee encumbrances proliferations tinkerer egrets recourse churl kolinskies ionospheric docents unnatural scuffler muches petulant acorns subconscious xyster tunelessly boners slag amazement intercapillary manse unsay embezzle stuccoer dissembles batwing valediction iceboxes ketchups phonily con"
p2 = "rhomb subrents brasiers render avg tote lesbian dibbers jeopardy struggling urogram furrowed hydrargyrum advertizing cheroots goons congratulation assaulters ictuses indurates wingovers relishes briskly livelihoods inflatable serialized lockboxes cowers holster conciliating parentage yowing restores conformities marted barrettes graphically overdevelop sublimely chokey chinches abstracts rights hockshops bourgeoisie coalition translucent fiascoes panzer mucus capacitated stereotyper omahas produ"
p3 = "yorkers peccaries agenda beshrews outboxing biding herons liturgies nonconciliatory elliptical confidants concealable teacups chairmanning proems ecclesiastically shafting nonpossessively doughboy inclusion linden zebroid parabolic misadventures fanciers grovelers requiters catmints hyped necklace rootstock rigorously indissolubility universally burrowers underproduced disillusionment wrestling yellowbellied sherpa unburnt jewelry grange dicker overheats daphnia arteriosclerotic landsat jongleur"
p4 = "cygnets chatterers pauline passive expounders cordwains caravel antidisestablishmentarianism syllabubs purled hangdogs clonic murmurers admirable subdialects lockjaws unpatentable jagging negotiated impersonates mammons chumminess semi pinner comprised managership conus turned netherlands temporariness languishers aerate sadists chemistry migraine froggiest sounding rapidly shelving maligning shriek faeries misogynist clarities oversight doylies remodeler tauruses prostrated frugging comestible "
p5 = "ovulatory geriatric hijack nonintoxicants prophylactic nonprotective skyhook warehouser paganized brigading european sassier antipasti tallyho warmer portables selling scheming amirate flanker photosensitizer multistage utile paralyzes indexer backrests tarmac doles siphoned casavas mudslinging nonverbal weevil arbitral painted vespertine plexiglass tanker seaworthiness uninterested anathematizing conduces terbiums wheelbarrow kabalas stagnation briskets counterclockwise hearthsides spuriously s"

p = [p1, p2, p3, p4, p5]
c = []

p_count = []
c_count = []
p_position = []
c_position = []
known_key = []

possible_keys = {"a":[], "b":[], "c":[], "d":[], "e":[], "f":[], "g":[], "h":[], "i":[], "j":[], "k":[],
             "l":[], "m":[], "n":[], "o":[], "p":[], "q":[], "r":[], "s":[], "t":[], "u":[], "v":[], "w":[], "x":[], "y":[], "z":[], " ":[]}

guess_key = {}

count = {"a":0, "b":0, "c":0, "d":0, "e":0, "f":0, "g":0, "h":0, "i":0, "j":0, "k":0,
             "l":0, "m":0, "n":0, "o":0, "p":0, "q":0, "r":0, "s":0, "t":0, "u":0, "v":0, "w":0, "x":0, "y":0, "z":0, " ":0}

def get_pos(pos, text):
    clone = {}
    for i in pos.keys():
        clone[i] = []
    for i, val in enumerate(text):
        clone[val].append(i)
    return clone

def spaces(indice):
    lst = []
    bck = 0
    fnt = 1
    while fnt != len(indice) - 1:
        lst.append(indice[fnt]-indice[bck])
        fnt += 1
        bck += 1
    return lst

key = e.generate_key(e.alphabet)
for i in p:
    p_count.append(e.dict_percentage(e.get_count(count, i)))
    p_position.append(get_pos(possible_keys, i))

    cipher_text = e.encrypt(i, key)
    c.append(cipher_text)
    c_count.append(e.dict_percentage(e.get_count(count, cipher_text)))
    c_position.append(get_pos(possible_keys, cipher_text))
    known_key.append({i[-1] : cipher_text[-1]})

print(known_key)

for i, val in enumerate(p_position):
    print("Plain text {}".format(i+1), "length: {}".format(len(c[i])))
    letter = known_key[i][list(known_key[i].keys())[0]]
    print(c_position[i][letter], letter)
    print()


"""
print(plain_count)
print()
print(cipher_count)
print()
print(guess_key)
print()
print(e.lfl(plain_count), e.lfl(cipher_count))
print()
"""
"""
print(key)
print(plain_count["n"], cipher_count[guess_key["n"]])
print()

print(p_position["n"], len(p_position["n"]))
print()
print(c_position[guess_key["n"]], len(c_position[guess_key["n"]]))
print()
print(len(p_position["n"])/len(c_position[guess_key["n"]]))
print()
print(spaces(p_position["n"]))
print()
print(spaces(c_position[guess_key["n"]]))
"""
"""
plain_pointer = 0
for i in cipher1:
    if i not in guess_key:
        guess_key[p1[plain_pointer]] = i
    else:
        possible_keys[i].append
"""