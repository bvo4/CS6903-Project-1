#ifndef analyze_H
#define analyze_H

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <vector>

using namespace std;

int decipher_key_length();
float chi_square(int freq, int frequency_map[], int frequency_PT[]);
void return_count(string line, int frequency_map[]);
void CT_FREQUENCY(string input, int frequency_map[]);
void define_letter_frequency(int frequency_PT1[], int frequency_PT2[], int frequency_PT3[], int frequency_PT4[], int frequency_PT5[]);

int get_pos(int pos, string text);
string spaces(int indice);
string decryption(string e);

#endif