#ifndef analyze_H
#define analyze_H

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <vector>
#include <cmath>
#include<iomanip>

using namespace std;

struct letter {
	char letter;
	int freq = 0;
};

struct mapping {
	char PT[27];
	char CT[27];
};

int decipher_key_length();
bool freq_compare(const letter a, const letter b);
float chi_square(mapping frequency[], letter* frequency_map, letter* frequency_PT);
void percentile(letter frequency_map[], mapping frequency[]);
void return_count(string line, letter frequency_map[]);
void CT_FREQUENCY(string input, letter frequency_map[]);
void define_letter_frequency(letter frequency_PT1[], letter frequency_PT2[], letter frequency_PT3[], letter frequency_PT4[], letter frequency_PT5[]);

#endif