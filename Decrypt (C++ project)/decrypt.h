#pragma once

#include<string>


extern int frequency_PT1[27];
extern int frequency_PT2[27];
extern int frequency_PT3[27];
extern int frequency_PT4[27];
extern int frequency_PT5[27];


void return_count(std::string line, int frequency_map[]);
void define_letter_frequency(int frequency_map[]);
void CT_FREQUENCY(std::string input, int frequency_map[]);
int decipher_key_length();
std::string decryption_scheme(std::string input, std::string k);
