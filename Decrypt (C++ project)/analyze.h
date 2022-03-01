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

#endif