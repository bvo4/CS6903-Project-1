#include "encrypt.h"

using namespace std;

//randomly choose a character c from{ <space>,a,..,z }
char random_letter_generator()
{
	// Initialize Mersenne Twister pseudo-random number generator
	random_device rd;
	mt19937 gen(rd());

	//Choose a random letter a-z
	uniform_int_distribution<> dis(0, 26);
	int random_number = dis(gen);
	if (random_number >= 26)
		return ' ';

	return char('a' + random_number);
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


		if (prob_of_random_ciphertext < coin_value && coin_value <= 1)
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

	//Forcibly turncating to length 500 for now
	//NEED TO REMOVE THIS LATER WHEN ACTUAL PRACTICE IS USED
	return string(CT).substr(0, 499);
}

string generate_key(char alphabet[])
{
	char key[500];
	int numbers[27] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 , 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };
	bool erased[27] = { false };
	for (int i = 0; i < 27; i++)
	{
		int index = random_number_generator();
		while (index >= numbers[i] && erased[i] == false)
		{
			index = random_number_generator();
			erased[i] = true;
		}
		key[alphabet[i]] = alphabet[index];
		erased[i] = true;
	}
	return string(key);
}

int random_number_generator()
{
	// Initialize Mersenne Twister pseudo-random number generator
	random_device rd;
	mt19937 gen(rd());

	//Choose a random letter a-z
	uniform_int_distribution<> dis(0, 26);
	int random_number = dis(gen);

	return random_number;
}