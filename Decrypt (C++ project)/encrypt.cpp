#include<random>
#include<math.h>

using namespace std;

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
