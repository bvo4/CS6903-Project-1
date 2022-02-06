#include<iostream>
#include<string>
#include<random>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

using namespace std;

char random_letter_generator()
{
	return 'a' + rand() % 26;
}

int coin_generation_algorithm(int ciphertext_pointer, L)
{
	int coin_value = 0;
	return coin_value;
}

/*

Pseudocode

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
string decryption_scheme(string input) {
	string output;
	int j = 0;


	int ciphertext_pointer = 1;
	int message_pointer = 1;
	int num_rand_characters = 0;
	int prob_of_random_ciphertext = 0.95;
	//Repeat
	int coin_value = coin_generation_algorithm(ciphertext_pointer, L);  // coin_value is a real number in [0,1]
	if (prob_of_random_ciphertext < coin_value && prob_of_random_ciphertext <= 1)
	{
		j = m[message_pointer]; // j is a value between 0 and 26
		c[ciphertext_pointer] = k[j];
		message_pointer++;
	}

	if (0 <= coin_value && coin_value <= prob_of_random_ciphertext)
	{

		//randomly choose a character c from{ <space>,a,..,z }
		char rand_letter = random_letter_generator();


		set c[ciphertext_pointer] = c
		num_rand_characters = num_rand_characters + 1
		ciphertext_pointer = ciphertext_pointer + 1
		Until ciphertext_pointer > L + num_rand_characters
	}
		Return c[1]...c[L + num_rand_characters]

	return output;
}

int main() {

//1. print on screen something like "Enter the ciphertext:",
//2. obtain the ciphertext from stdin,
	string input;
	string output;
	cout << "Enter the ciphertext: " << endl;
	cin >> input;

	output = decryption_scheme(input);
	cout << "My plaintext guess is:  " << output << endl;
}