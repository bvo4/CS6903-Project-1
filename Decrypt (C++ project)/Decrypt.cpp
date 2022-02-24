#include<iostream>
#include<string>
#include<vector>
#include<random>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

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

string encrypt(string input, string key);
void define_letter_frequency(int frequency_map[]);
int frequency_map[26];

/* The frequency mappings for plaintext #1 - #5 */
int frequency_PT1[26] = {0};
int frequency_PT2[26] = {0};
int frequency_PT3[26] = {0};
int frequency_PT4[26] = {0};
int frequency_PT5[26] = {0};

int decipher_key_length();
void CT_FREQUENCY(string input, int frequency_map[]);

//randomly choose a character c from{ <space>,a,..,z }
char random_letter_generator()
{
	// Initialize Mersenne Twister pseudo-random number generator
	random_device rd;
	mt19937 gen(rd());

	//Choose a random letter a-z
	uniform_int_distribution<> dis(0, 26);
	int random_number = dis(gen);
	if (random_number == 26)
		return ' ';

	return 'a' + dis(gen);
}


// coin_value is a real number in [0,1]
int coin_generation_algorithm(int ciphertext_pointer, int L)
{
	// Initialize Mersenne Twister pseudo-random number generator
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> dis(0, 1);
	return dis(gen);
}

/* Part 1 will involve a known-plaintext attack since we're using a plaintext dictionary to decrypt ciphertext */
string decryption_scheme(string input, string k) {
	/* The different parameters */
	int L = 500;		//Length of message
	int u = 5;			
	int v = 50;
	int t = 5;		//Between 1 and 24

	string output;
	int j = 0;
	/*
	* Key Length is at most 24
	* Message length is at most 24
	*/

	return output;

}

//Must begin by figuring out how long the key length might be
int decipher_key_length()
{
	int key_length = 0;
	return key_length;
}

int main() {

	string input;
	string output;
	string key;
	int frequency_map[26] = {0};


	if (ENCRYPT)
	{
		//Uses a mono-alphabetic substitution cipher and attempts to decrypt it
		//CT_FREQUENCY("abcdefghijklmnopqrstuvwxyz", frequency_map);
		//define_letter_frequency(frequency_map);

		
		//cout << "Enter plaintext " << endl;
		//cin >> noskipws >> input;
		string output = encrypt("underwaists wayfarings fluty analgia refuels transcribing nibbled okra buttonholer venalness hamlet praus apprisers presifted cubital walloper dissembler bunting wizardries squirrel preselect befitted licensee encumbrances proliferations tinkerer egrets recourse churl kolinskies ionospheric docents unnatural scuffler muches petulant acorns subconscious xyster tunelessly boners slag amazement intercapillary manse unsay embezzle stuccoer dissembles batwing valediction iceboxes ketchups phonily con", "secret");
		cout << "Encrypted output:  " << output << endl;
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

	cout << "Frequency of all alphabets in the string is:" << endl;
	for (int i = 0; i < 26; i++)
		cout << char(i + 'a') << " : " << frequency_PT5[i] << endl;

	dictionary.close();
}

//Same as the function above, but calculates the letter frequency of the ciphertext
void CT_FREQUENCY(string input, int frequency_map[])
{
	int j = 0;
	return_count(input, frequency_map);

	cout << "Frequency of our Ciphertext:  " << endl;
	for (int i = 0; i < 26; i++)
		cout << char(i + 'a') << " : " << frequency_map[i] << endl;

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
string encrypt(string input, string key)
{
	int ciphertext_pointer = 0;
	int message_pointer = 0;
	int num_rand_characters = 0;
	int prob_of_random_ciphertext = 0;
	char CT[500];

	int coin_value = coin_generation_algorithm(ciphertext_pointer, input.length());  // coin_value is a real number in [0,1]

/*
TA NOTE:

	abc  = plain text
	abc = KEY
	pt pointer is at a
	flip a coin. if 0<=value<=prob of random ciphertextncy
	insert random char
	else
	encrypt pt a with char a from the key

*/
	do {
		//cout << "input #" << message_pointer << " : " << input[message_pointer] << endl;
		if (isspace(input[message_pointer]))
		{
			message_pointer++;
			CT[ciphertext_pointer] = ' ';
			ciphertext_pointer++;
		}

		else if (prob_of_random_ciphertext < coin_value && coin_value <= 1)
		{
			//set j = m[message_pointer] // j is a value between 0 and 26
			int j = input[message_pointer];

			//set c[ciphertext_pointer] = k[j]
			CT[ciphertext_pointer] = key[j % key.length()];

			message_pointer++;
			ciphertext_pointer++;
		}

		else if (0 <= coin_value && coin_value <= prob_of_random_ciphertext)
		{
			//randomly choose a character c from {<space>,a,..,z}
			char c = random_letter_generator();
			//set c[ciphertext_pointer] = c
			CT[ciphertext_pointer] = c;
			ciphertext_pointer++;
		}
		//Until ciphertext_pointer > L + num_rand_characters
	} while (ciphertext_pointer < (input.length() - 1 + num_rand_characters) && message_pointer < 500);
	//Return c[1]...c[L + num_rand_characters]
	cout << "CIPHERTEXT: " << CT << endl;
	return CT;

}