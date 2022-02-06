/*

Instructions:
ciphertext_pointer = 1
message_pointer = 1
num_rand_characters = 0
prob_of_random_ciphertext = 0.05
Repeat
let coin_value = coin_generation_algorithm(ciphertext_pointer,L)  // coin_value is a real number in [0,1]
if prob_of_random_ciphertext < coin_value <= 1 then
set j = m[message_pointer] // j is a value between 0 and 26
set c[ciphertext_pointer] = k[j]
message_pointer = message_pointer + 1
if 0 <= coin_value <= prob_of_random_ciphertext then
randomly choose a character c from {<space>,a,..,z}
set c[ciphertext_pointer] = c
num_rand_characters = num_rand_characters + 1
ciphertext_pointer = ciphertext_pointer +1
Until ciphertext_pointer > L + num_rand_characters
Return c[1]...c[L + num_rand_characters]

*/