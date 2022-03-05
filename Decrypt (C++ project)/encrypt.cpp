#include<map>
#include<algorithm>
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
double coin_generation_algorithm(int ciphertext_pointer, int L)
{
	// Initialize Mersenne Twister pseudo-random number generator
	random_device rd;
	mt19937 gen(rd());

	uniform_real_distribution<> dis(0.0, 1.0);
	return dis(gen);
}

/*
  Generate key for encryption

  The key is a sequence of 27 distinct numbers between 0 and 26

  :returns key: random permutation of distinct numbers from 0 to 26
 */
map<char, char> key_gen()
{
    int key_length = 26;
    string key = " "; // include space as first character
    for (int i = 0; i < key_length; ++i)
    {
        key += 'a' + i; //append all other alphabetic characters (lower-case only)
    }
    
    // shuffle key randomly
    std::random_device rd;
    mt19937 gen = mt19937{rd()};
    std::shuffle(key.begin(), key.end(), gen);
    map<char, char> key_map = { {' ', key[0]} };
    for (int i = 0; i < key_length; i++)
    {
        key_map['a'+i] = key[i+1];
    }
    return key_map;
}

void print_key(map<char, char> key)
{
    for (const auto& n : key) {
      std::cout << n.first << " = " << n.second << "; " << endl;
    }
    cout << endl;
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
string encrypt(string input, map<char, char> key)
{
	int ciphertext_pointer = 0;
	int message_pointer = 0;
	int num_rand_characters = 0;
	int prob_of_random_ciphertext = 0;
    vector<char> CT;


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
        double coin_value = coin_generation_algorithm(ciphertext_pointer, input.length());  // coin_value is a real number in [0,1]


		if (prob_of_random_ciphertext == 0 || prob_of_random_ciphertext < coin_value)
		{
			//set j = m[message_pointer] // j is a value between 0 and 26
			int j = input[message_pointer];

			//set c[ciphertext_pointer] = k[j]
            char c = key[j];
            CT.push_back(c);

			message_pointer++;
		}

		else
		{
			//randomly choose a character c from {<space>,a,..,z}
			char c = random_letter_generator();
			//set c[ciphertext_pointer] = c
            CT.push_back(c);
            num_rand_characters += 1;
		}

	} while (message_pointer < 500);
    
	  //Return c[1]...c[L + num_rand_characters]
    string ciphertext = "";
    for (int c = 0; c < CT.size(); ++c)
    {
        ciphertext += CT[c];
    }
	return ciphertext;
}
