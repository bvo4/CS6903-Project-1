#ifndef encrypt_h
#define encrypt_h

#include<iostream>
#include<string>
#include<random>

using namespace std;

//randomly choose a character c from{ <space>,a,..,z }
char random_letter_generator();
string encrypt(string input, string key);
// coin_value is a real number in [0,1]
int coin_generation_algorithm(int ciphertext_pointer, int L);

#endif