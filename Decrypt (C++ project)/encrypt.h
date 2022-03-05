#ifndef encrypt_h
#define encrypt_h

#include<iostream>
#include<string>
#include<random>
#include<math.h>

using namespace std;

char random_letter_generator();
string key_gen();
double coin_generation_algorithm(int ciphertext_pointer, int L);
string encrypt(string input, string key);


#endif
