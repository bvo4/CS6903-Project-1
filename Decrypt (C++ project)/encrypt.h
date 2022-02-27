#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <iostream>
#include <string.h>
#include<random>

class encryption
{
private:

public:

	int coin_generation_algorithm(int ciphertext_pointer, int L);
	std::string encrypt(std::string input, std::string key);
	char random_letter_generator();

};

#endif