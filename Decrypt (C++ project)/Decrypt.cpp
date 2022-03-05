#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#include "analyze.h"
#include "encrypt.h"

#define ENCRYPT true

using namespace std;

/*
Personal notes:
For test #1, we have 5 candidate plaintexts.
Key length is always shorter than the plaintext message.
Since this is using the monoalphabetic substitution cipher, look at the frequency of the plaintext vs the letter frequency of the ciphertext
*/

/*
 TA NOTE:
 YOU ARE NOT EXPECTED TO DO WELL ON THE 2ND TEST CASE.
 FOCUS ON THE FIRST TEST CASE THEN TRY TO ATTEMPT THE 2ND PART
 REPLICATE THE ENCRYPTION SCHEME FIRST THEN ATTEMPT DECRYPTON
 BEGIN WITH PROB OF RANDOM CHARACTER = 0 THEN INCREASE THE PROBABILITY
*/

/* The frequency mappings for plaintext #1 - #5 */
int frequency_PT1[27] = { 0 };
int frequency_PT2[27] = { 0 };
int frequency_PT3[27] = { 0 };
int frequency_PT4[27] = { 0 };
int frequency_PT5[27] = { 0 };

void Compare_Frequency(int frequency_map[]);


/*
* Key Length is at most 24
* Message length is at most 24
*/
/* Part 1 will involve a known-plaintext attack since we're using a plaintext dictionary to decrypt ciphertext */

string decryption_scheme(string input, string k) {
	/* The different parameters */

	int frequency_map[27] = { 0 };	//We will be using this to map out the letter frequency of the ciphertext
	string output;
	int j = 0;

	/* First, we will begin by acquiring the letter frequency of the ciphertext and the 5 plaintext candidates */
	define_letter_frequency(frequency_PT1, frequency_PT2, frequency_PT3, frequency_PT4, frequency_PT5);

	//Define the CT letter frequency
	CT_FREQUENCY(input, frequency_map);

	//Compare letter frequencies
	Compare_Frequency(frequency_map);

	return "PLACEHOLDER";
}

int main() {

	string input;
	string output;
	string key;

	if (ENCRYPT)
	{
		//Uses a mono-alphabetic substitution cipher and attempts to decrypt it

		/* Use our encryption pseudocode to encode plaintext into ciphertext */
		input = "underwaists wayfarings fluty analgia refuels transcribing nibbled okra buttonholer venalness hamlet praus apprisers presifted cubital walloper dissembler bunting wizardries squirrel preselect befitted licensee encumbrances proliferations tinkerer egrets recourse churl kolinskies ionospheric docents unnatural scuffler muches petulant acorns subconscious xyster tunelessly boners slag amazement intercapillary manse unsay embezzle stuccoer dissembles batwing valediction iceboxes ketchups phonily con";
		cout << "Our input is:  " << input << endl << endl;
		input = encrypt(input, "secret");
		cout << "Encrypted output:  " << input << endl;

		/* Use our Ciphertext to decrypt the plaintexxt and figure out the plaintext */
		cout << "Now inputting the ciphertext into the decryption algorithm" << endl;
		output = decryption_scheme(input, key);
	}
	else
	{

		//Input would be key k=k[0],...,k[26] and message m=m[1],...,m[L]
		cout << "Enter the ciphertext: " << endl;
		cin >> input;

		output = decryption_scheme(input, key);
		cout << "My plaintext guess is:  " << output << endl;
	}

	return 0;
}


void Alvin_test(string e) {
	string key = e.generate_key(e.alphabet);
	for (int i = 0; i < p; i++)
	{
		p_count.append(e.dict_percentage(e.get_count(count, i)))
			p_position.append(get_pos(possible_keys, i))

			cipher_text = e.encrypt(i, key)
			c.append(cipher_text)
			c_count.append(e.dict_percentage(e.get_count(count, cipher_text)))
			c_position.append(get_pos(possible_keys, cipher_text))
			known_key.append({ i[-1] : cipher_text[-1] })
	}
	cout << (known_key) << endl;

	for (int i, val = 0; i < p_position; i++, val++)
	{
		cout << "Plain text {}" << i + 1 << endl;
		char letter = known_key[i][(known_key[i].keys())[0]];
		cout << c_position[i][letter], letter);
	}
}

/* Compare the letter frequencies of all plaintext messages with the ciphertext to see which plaintext password has the closest match
https://www.tapatalk.com/groups/crypto/the-index-of-coincidence-the-chi-test-the-kappa-t238.html
*/
void Compare_Frequency(int frequency_map[])
{
	//Will count votes for each of the 5 plaintext messages
	int weight[5] = { 0 };

	//For each letter, find the top 5 corresponding letters for each plaintext candidates to find the closest match.
	int i, coincidence, max = 0;

	//We will use the chi test to determine which plaintext candidate is the best match.
	cout << "Chi Square of : " << chi_square(0, frequency_map, frequency_PT1) << endl;
}

//Attempting to recreate the professor's encryption scheme from his pseudocode
	/*
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
	*/