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