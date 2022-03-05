#include "analyze.h"
using namespace std;

int decipher_key_length()
{
	int key_length = 0;
	return key_length;
}

//Use the Chi Square probability to determine the probability of having a match
//  chi = SUM[i = 1 to k] ( f[i] * f'[i] ) / ( n * n' )

/*
Where k is the number of distinct letters in the alphabet, 
f is the number of times the i'th letter appears in the first string and f' is the number of times the i'th letter appears in the second string. 
And n and n' are the total number of characters in the first and second strings.
*/
float chi_square(int freq, int frequency_map[], int frequency_PT[])
{
	float chi = 0;
	int sum = 0;
	int k = 27;
	int n = 500;		//Length of first string
	int n2 = 500;		//Length of second string

	for (int i = 0; i < k; i++)
	{
			sum += (frequency_map[i] * frequency_PT[i]) / (n/n2);
	}
	

	return sum;
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

int get_pos(int pos, string text) {
	int clone[27];

	for (int i, val = 0; i < text.length() && val < text.length(); i++, val++)
		clone[val] += i;
	return clone;
}

string spaces(int indice) {
	string lst;
	int bck = 0;
	int	fnt = 1;
	string plaintext;
	while (fnt != len(indice) - 1)
		lst.append(indice[fnt] - indice[bck]);
	fnt++;
	bck++;
	return lst;
}


string get_count(int count, string text)
{
	string clone;
	for (int i = 0; i < text.length(); i++)
		clone[i] ++;
	return clone;
}

int mfl(int count)
{
	char most_freq;
	for (int i = 0; i < count.keys(); i++)
	{
		if (count[i] > most_freq[1])
			most_freq = (i, count[i]);
	}
	return most_freq;
}

int lfl(int count)
{
	char most_freq = ("NAN", 1000);
		for (int i = 0; i < count.keys(); i++)
		{
			if count[i] < most_freq[1] :
			most_freq = (i, count[i])
		}
	return most_freq;
}

string sort_v(int val)
{
	return { k: v for k, v in sorted(val.items(), key = lambda item : item[1]) }
}

int compare(string plain, string cipher)
{
	int similarity = 0
		for i, val in enumerate(plain)
		{
			if (abs(val - cipher[i]) <= 0.001)
				similarity++;
		}
				return similarity
}

float dict_percentage(int d[])
{
	float total = sum(d.values());
	for (int i = 0, i < d.keys(); i++)
	{
		d[i] = d[i] / total;
	}
	return d;
}