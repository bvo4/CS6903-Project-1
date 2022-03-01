#include "analyze.h"
using namespace std;

int decipher_key_length()
{
	int key_length = 0;
	return key_length;
}

//Use the Chi Square probability to determine the probability of having a match
//  chi = SUM[i = 1 to k] ( f[i] * f'[i] ) / ( n * n' )
float chi_square(int freq)
{
	float chi = 0;
	int sum = 0;

	/*
	for (int i = 0; i < k; i++)
	{
		sum += f[i] * f'[i]'
	}
	*/

	return 0;
}

//Quick function to quickly take the entire string and map the letter frequencies to the array
void return_count(string line, int frequency_map[])
{
	int j = 0;
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] >= 'a' && line[i] <= 'z')
		{
			j = line[i] - 'a';
			frequency_map[j]++;
		}
		else if (line[i] == ' ')
			frequency_map[26]++;
	}
}

//Same as the function above, but calculates the letter frequency of the ciphertext
void CT_FREQUENCY(string input, int frequency_map[])
{
	return_count(input, frequency_map);

	/*
	cout << "Frequency of our Ciphertext:  " << endl;
	for (int i = 0; i < 26; i++)
		cout << char(i + 'a') << " : " << frequency_map[i] << endl;
	cout << "_" << " : " << frequency_map[26] << endl;
	*/
}

void define_letter_frequency(int frequency_PT1[], int frequency_PT2[], int frequency_PT3[], int frequency_PT4[], int frequency_PT5[])
{
	ifstream dictionary;
	string line;
	dictionary.open("../../dictionary_1.txt");

	while (getline(dictionary, line))
	{
		if (line == "Candidate Plaintext #1")
		{
			//Skip the blank line to reach the candidate plaintext
			getline(dictionary, line); getline(dictionary, line);
			return_count(line, frequency_PT1);
		}

		else if (line == "Candidate Plaintext #2")
		{
			//Skip the blank line to reach the candidate plaintext
			getline(dictionary, line); getline(dictionary, line);
			return_count(line, frequency_PT2);
		}

		else if (line == "Candidate Plaintext #3")
		{
			//Skip the blank line to reach the candidate plaintext
			getline(dictionary, line); getline(dictionary, line);
			return_count(line, frequency_PT3);
		}

		else if (line == "Candidate Plaintext #4")
		{
			//Skip the blank line to reach the candidate plaintext
			getline(dictionary, line); getline(dictionary, line);
			return_count(line, frequency_PT4);
		}

		else if (line == "Candidate Plaintext #5")
		{
			//Skip the blank line to reach the candidate plaintext
			getline(dictionary, line); getline(dictionary, line);
			return_count(line, frequency_PT5);
		}

	}

	/*
	cout << "Frequency of all alphabets in the string is:" << endl;
	for (int i = 0; i < 27; i++)
		cout << char(i + 'a') << " : " << frequency_PT5[i] << endl;
	cout << "_" << " : " << frequency_PT5[26] << endl;
	*/

	dictionary.close();
}