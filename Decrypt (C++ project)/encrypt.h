#ifndef encrypt_h
#define encrypt_h

#include<map>
#include<iostream>
#include<string>
#include<random>
#include<math.h>

using namespace std;

char random_letter_generator();
std::map<char, char> key_gen();
void print_key(map<char, char> key);
double coin_generation_algorithm(int ciphertext_pointer, int L);
string encrypt(string input, std::map<char, char> key);


#endif
