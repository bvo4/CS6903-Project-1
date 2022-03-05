#ifndef encrypt_h
#define encrypt_h

#include<iostream>
#include<string>
#include<random>
#include<math.h>

using namespace std;

char random_letter_generator();
int coin_generation_algorithm(int ciphertext_pointer, int L);
string encrypt(string input, string key);
string generate_key(char alphabet[]);
int random_number_generator();

#endif