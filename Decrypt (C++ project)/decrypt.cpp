#include<string>
#include <fstream>

using namespace std;


/* The frequency mappings for plaintext #1 - #5 */
int frequency_PT1[27] = {0};
int frequency_PT2[27] = {0};
int frequency_PT3[27] = {0};
int frequency_PT4[27] = {0};
int frequency_PT5[27] = {0};


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


//Read the plaintext dictionary and calculate the letter frequency of all 5 candidates
void define_letter_frequency(int frequency_map[])
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


//Same as the function above, but calculates the letter frequency of the ciphertext
void CT_FREQUENCY(string input, int frequency_map[])
{
	int j = 0;
	return_count(input, frequency_map);

	//Counts the frequencies
	/*
	cout << "Frequency of our Ciphertext:  " << endl;
	for (int i = 0; i < 26; i++)
		cout << char(i + 'a') << " : " << frequency_map[i] << endl;
	cout << "_" << " : " << frequency_map[26] << endl;
	*/
}


//Must begin by figuring out how long the key length might be
int decipher_key_length()
{
	int key_length = 0;
	return key_length;
}


string decryption_scheme(string input, string k) {
	/* The different parameters */
	int L = 500;		//Length of message
	int u = 5;			
	int v = 50;
	int t = 5;		//Between 1 and 24



	int frequency_map[26] = { 0 };	//We will be using this to map out the letter frequency of the ciphertext
	string output;
	int j = 0;

	/* First, we will begin by acquiring the letter frequency of the ciphertext and the 5 plaintext candidates */
	define_letter_frequency(frequency_map);


	return output;

}
