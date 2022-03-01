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

void define_letter_frequency(int frequency_map[]);

/* The frequency mappings for plaintext #1 - #5 */
int frequency_PT1[27] = { 0 };
int frequency_PT2[27] = { 0 };
int frequency_PT3[27] = { 0 };
int frequency_PT4[27] = { 0 };
int frequency_PT5[27] = { 0 };

int decipher_key_length();
void CT_FREQUENCY(string input, int frequency_map[]);
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
	define_letter_frequency(frequency_map);

	//Define the CT letter frequency
	CT_FREQUENCY(input, frequency_map);

	//Compare letter frequencies
	

	return "PLACEHOLDER";

}

int main() {

	string input;
	string output;
	string key;

	if (ENCRYPT)
	{
		//Uses a mono-alphabetic substitution cipher and attempts to decrypt it
		//CT_FREQUENCY("abcdefghijklmnopqrstuvwxyz", frequency_map);
		//define_letter_frequency(frequency_map);


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

//Quick function to quickly take the entire string and map the letter frequencies to the array
void return_count(string line, int frequency_map[])
{
	int j = 0;
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] >= 'a' && line[i] <= 'z')
		{
			j = line[i] - 'a';
			frequency_map[j]++;
		}
		else if (line[i] == ' ')
			frequency_map[26]++;
	}
}


//Read the plaintext dictionary and calculate the letter frequency of all 5 candidates
#include <fstream>
void define_letter_frequency(int frequency_map[])
{
	ifstream dictionary;
	string line;
	dictionary.open("../../dictionary_1.txt");

	while (getline(dictionary, line))
	{
		if (line == "Candidate Plaintext #1")
		{
			//Skip the blank line to reach the candidate plaintext
			getline(dictionary, line); getline(dictionary, line);
			return_count(line, frequency_PT1);
		}

		else if (line == "Candidate Plaintext #2")
		{
			//Skip the blank line to reach the candidate plaintext
			getline(dictionary, line); getline(dictionary, line);
			return_count(line, frequency_PT2);
		}

		else if (line == "Candidate Plaintext #3")
		{
			//Skip the blank line to reach the candidate plaintext
			getline(dictionary, line); getline(dictionary, line);
			return_count(line, frequency_PT3);
		}

		else if (line == "Candidate Plaintext #4")
		{
			//Skip the blank line to reach the candidate plaintext
			getline(dictionary, line); getline(dictionary, line);
			return_count(line, frequency_PT4);
		}

		else if (line == "Candidate Plaintext #5")
		{
			//Skip the blank line to reach the candidate plaintext
			getline(dictionary, line); getline(dictionary, line);
			return_count(line, frequency_PT5);
		}

	}

	/*
	cout << "Frequency of all alphabets in the string is:" << endl;
	for (int i = 0; i < 27; i++)
		cout << char(i + 'a') << " : " << frequency_PT5[i] << endl;
	cout << "_" << " : " << frequency_PT5[26] << endl;
	*/

	dictionary.close();
}

//Same as the function above, but calculates the letter frequency of the ciphertext
void CT_FREQUENCY(string input, int frequency_map[])
{
	return_count(input, frequency_map);

	/*
	cout << "Frequency of our Ciphertext:  " << endl;
	for (int i = 0; i < 26; i++)
		cout << char(i + 'a') << " : " << frequency_map[i] << endl;
	cout << "_" << " : " << frequency_map[26] << endl;
	*/
}

//Use the Chi Square probability to determine the probability of having a match
//  chi = SUM[i = 1 to k] ( f[i] * f'[i] ) / ( n * n' )
float chi_square(int freq)
{
	float chi = 0;
	int sum = 0;

	/*
	for (int i = 0; i < k; i++)
	{
		sum += f[i] * f'[i]'
	}
	*/

	return 0;
}

/* Compare the letter frequencies of all plaintext messages with the ciphertext to see which plaintext password has the closest match */
void Compare_Frequency(int frequency_map[])
{
	//Will count votes for each of the 5 plaintext messages
	int weight[5] = { 0 };

	//For each letter, find the top 5 corresponding letters for each plaintext candidates to find the closest match.
	int i, coincidence, max = 0;

	//We will use the chi test to determine which plaintext candidate is the best match.
	//while (true)
	{
	//	if(frequency_map[i])
	}
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