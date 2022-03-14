#include "analyze.h"
using namespace std;

int decipher_key_length()
{
	int key_length = 0;
	return key_length;
}
bool freq_compare(const letter a, const letter b)
{
	return a.freq > b.freq;
}

//Use the Chi Square probability to determine the probability of having a match
//  chi = SUM[i = 1 to k] ( f[i] * f'[i] ) / ( n * n' )

/*
Where k is the number of distinct letters in the alphabet, 
f is the number of times the i'th letter appears in the first string and f' is the number of times the i'th letter appears in the second string. 
And n and n' are the total number of characters in the first and second strings.
*/
float chi_square(int freq, letter * frequency_map, letter * frequency_PT)
{
	float chi = 0;
	double sum = 0;
	int k = 27;			//Number of letters in the alphabet
	int n = 500;		//Length of first string
	int n2 = 500;		//Length of second string

	for (int i = 0; i < k; i++)
	{
		cout << frequency_map[i].letter << " : " << frequency_map[i].freq << " vs. " << frequency_PT[i].letter << " : " << frequency_PT[i].freq << endl;
		sum += pow (frequency_map[i].freq - frequency_PT[i].freq, 2);
		sum = sum / (frequency_map[i].freq);
	}
	cout <<"SUM: " << sum << endl;
	return sum;
}

void percentile(letter frequency_map[])
{
	for (int i = 0; i < 27; i++)
	{
		double percent = (frequency_map[i].freq * 100) / (500 - 1);
		cout << "Percentile:  " << frequency_map[i].letter << "=" << percent << endl;
	}
}

//Quick function to quickly take the entire string and map the letter frequencies to the array
void return_count(string line, letter frequency_map[])
{
	//Define all letters here because why not
	for (int i = 0; i < 26; i++)
		frequency_map[i].letter = 'a' + i;

	int j;
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] >= 'a' && line[i] <= 'z')
		{
			j = line[i] - 'a';
			frequency_map[j].freq++;
		}
		else if (line[i] == ' ')
		{
			frequency_map[26].letter = ' ';	//Lazy
			frequency_map[26].freq++;
		}
	}
}

//Same as the function above, but calculates the letter frequency of the ciphertext
void CT_FREQUENCY(string input, letter frequency_map[])
{
	return_count(input, frequency_map);

	/*
	cout << "Frequency of our Ciphertext:  " << endl;
	for (int i = 0; i < 26; i++)
		cout << char(i + 'a') << " : " << frequency_map[i] << endl;
	cout << "_" << " : " << frequency_map[26] << endl;
	*/
}

void define_letter_frequency(letter frequency_PT1[], letter frequency_PT2[], letter frequency_PT3[], letter frequency_PT4[], letter frequency_PT5[])
{
	ifstream dictionary;
	string line;
	dictionary.open("../../../dictionary_1.txt");

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