#ifndef analyze_H
#define analyze_H

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <vector>
#include <cmath>

using namespace std;

struct letter {
	char letter;
	int freq = 0;
};

int decipher_key_length();
bool freq_compare(const letter a, const letter b);
float chi_square(int freq, letter * frequency_map, letter * frequency_PT);
void percentile(letter frequency_map[]);
void return_count(string line, letter frequency_map[]);
void CT_FREQUENCY(string input, letter frequency_map[]);
void define_letter_frequency(letter frequency_PT1[], letter frequency_PT2[], letter frequency_PT3[], letter frequency_PT4[], letter frequency_PT5[]);

/*
int get_pos(int pos, string text);
string spaces(int indice);
float dict_percentage(string d);
string get_count(int count, string text);
int lfl(int count);
string sort_v(int val);
int compare(string plain, string cipher);
*/

#endif