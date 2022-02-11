#include<iostream>
#include<string>
#include<random>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define ENCRYPT true

using namespace std;

string encrypt(string input, string key);
string cipheredIt(string msg, string encoded);

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

//Do decryption here
string decryption_scheme(string input, string k) {
	/* The different parameters */
	int L = 500;		//Length of message
	int u = 5;			
	int v = 50;
	int t = 5;		//Between 1 and 24

	string output;
	int j = 0;

	
	int ciphertext_pointer = 1;
	int message_pointer = 1;
	int num_rand_characters = 0;
	int prob_of_random_ciphertext = 0.95;
	//Repeat
	
	int coin_value = coin_generation_algorithm(ciphertext_pointer, L);  // coin_value is a real number in [0,1]
	/*
	if (prob_of_random_ciphertext < coin_value && prob_of_random_ciphertext <= 1)
	{
		j = m[message_pointer]; // j is a value between 0 and 26
		c[ciphertext_pointer] = k[j];
		message_pointer++;
	}

	if (0 <= coin_value && coin_value <= prob_of_random_ciphertext)
	{
		char rand_letter = random_letter_generator();


		set c[ciphertext_pointer] = c
		num_rand_characters = num_rand_characters + 1
		ciphertext_pointer = ciphertext_pointer + 1
		Until ciphertext_pointer > L + num_rand_characters
	}
	//Return c[1]...c[L + num_rand_characters]
	*/
	return output;

}

int main() {

	string input;
	string output;
	string key

	if (ENCRYPT)
	{
		//Uses a mono-alphabetic substitution cipher and attempts to decrypt it

		cout << "Enter plaintext " << endl;
		cin >> input;

		cout << "Enter the key:  " << endl;
		cin >> key;

		key = "secret";
		key = encrypt(input, key);

		output = cipheredIt(input, key);

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

//Taken from:  https://www.geeksforgeeks.org/keyword-cipher/#:~:text=A%20keyword%20cipher%20is%20a,%2C%20B%2C%20C%2C%20etc.
//Will remove once we get the plaintext dictionary
string encrypt(string input, string key)
{
	/*
	Professor mentioned that given a key,
	we would be able to encrypt a plaintesxt message into the matching ciphertext,
	so leaving this here in case it's needed
	*/
	string encoded = "";
	// This array represents the
	// 26 letters of alphabets
	bool arr[26] = { 0 };

	// This loop inserts the keyword
	// at the start of the encoded string
	for (int i = 0; i < key.size(); i++)
	{
		if (key[i] >= 'A' && key[i] <= 'Z')
		{
			// To check whether the character is inserted
			// earlier in the encoded string or not
			if (arr[key[i] - 65] == 0)
			{
				encoded += key[i];
				arr[key[i] - 65] = 1;
			}
		}
		else if (key[i] >= 'a' && key[i] <= 'z')
		{
			if (arr[key[i] - 97] == 0)
			{
				encoded += key[i] - 32;
				arr[key[i] - 97] = 1;
			}
		}
	}

	// This loop inserts the remaining
	// characters in the encoded string.
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] == 0)
		{
			arr[i] = 1;
			encoded += char(i + 65);
		}
	}
	return encoded;
}

// Function that generates encodes(cipher) the message
string cipheredIt(string msg, string encoded)
{
	string cipher = "";

	// This loop ciphered the message.
	// Spaces, special characters and numbers remain same.
	for (int i = 0; i < msg.size(); i++)
	{
		if (msg[i] >= 'a' && msg[i] <= 'z')
		{
			int pos = msg[i] - 97;
			cipher += encoded[pos];
		}
		else if (msg[i] >= 'A' && msg[i] <= 'Z')
		{
			int pos = msg[i] - 65;
			cipher += encoded[pos];
		}
		else
		{
			cipher += msg[i];
		}
	}
	return cipher;
}