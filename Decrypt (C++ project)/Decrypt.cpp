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
 TA NOTE:

 YOU ARE NOT EXPECTED TO DO WELL ON THE 2ND TEST CASE.
 FOCUS ON THE FIRST TEST CASE THEN TRY TO ATTEMPT THE 2ND PART
 REPLICATE THE ENCRYPTION SCHEME FIRST THEN ATTEMPT DECRYPTON
 BEGIN WITH PROB OF RANDOM CHARACTER = 0 THEN INCREASE THE PROBABILITY

*/

string encrypt(string input, string key);
void define_letter_frequency(char frequency_map[]);
char frequency_map[26];



//randomly choose a character c from{ <space>,a,..,z }
char random_letter_generator()
{
	return 'a' + rand() % 26;
}


int coin_generation_algorithm(int ciphertext_pointer, int L)
{
	// coin_value is a real number in [0,1]
	int coin_value = 0;
	/*
	PLACEHOLDER CODE FOR COIN GENERATION
	*/
	return coin_value;
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

int main() {

	string input;
	string output;
	string key;

	if (ENCRYPT)
	{
		//Uses a mono-alphabetic substitution cipher and attempts to decrypt it

		cout << "Enter plaintext " << endl;
		cin >> input;

		cout << "Enter the key:  " << endl;
		cin >> key;

		key = "secret";
		output = encrypt(input, key);

		//output = cipheredIt(input, key);

		cout << "Ciphertext:  " << output << endl;

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
}

//Attempting to recreate the pr ofessor's encryption scheme from his pseudocode
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
	int message_pointer = 1;
	int num_rand_characters = 0;
	int prob_of_random_ciphertext = 0;
	string CT("", input.length());

	int coin_value = coin_generation_algorithm(ciphertext_pointer, input.length());  // coin_value is a real number in [0,1]

/*
TA NOTE:

	abc  = plain text
	abc = KEY
	pt pointer is at a
	flip a coin. if 0<=value<=prob of random ciphertext
	insert random char
	else
	encrypt pt a with char a from the key

*/
	do {
		if (prob_of_random_ciphertext < coin_value && coin_value <= 1)
		{
			//set j = m[message_pointer] // j is a value between 0 and 26
			int j = input[message_pointer];

			//set c[ciphertext_pointer] = k[j]
			CT[ciphertext_pointer] = key[j];
			message_pointer++;

			ciphertext_pointer++;
		}

		if (0 <= coin_value && coin_value <= prob_of_random_ciphertext)
		{
			//randomly choose a character c from {<space>,a,..,z}
			char c = random_letter_generator();

			//set c[ciphertext_pointer] = c
			CT[ciphertext_pointer] = c;
			ciphertext_pointer++;
		}
		//Until ciphertext_pointer > L + num_rand_characters
	} while (ciphertext_pointer > (input.length() + num_rand_characters));
	//Return c[1]...c[L + num_rand_characters]
	return CT;

}