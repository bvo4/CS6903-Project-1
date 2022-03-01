#ifndef analyze_H
#define analyze_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int decipher_key_length();
float chi_square(int freq);
void return_count(string line, int frequency_map[]);
void CT_FREQUENCY(string input, int frequency_map[]);
void define_letter_frequency(int frequency_PT1[], int frequency_PT2[], int frequency_PT3[], int frequency_PT4[], int frequency_PT5[]);


#endif