#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<vector>

#include "analyze.h"
#include "encrypt.h"

#define ENCRYPT true

using namespace std;

/*
Personal notes:
For test #1, we have 5 candidate plaintexts.
Key length is always shorter than the plaintext message.
Since this is using the monoalphabetic substitution cipher, look at the frequency of the plaintext vs the letter frequency of the ciphertext
*/

/*
 TA NOTE:
 YOU ARE NOT EXPECTED TO DO WELL ON THE 2ND TEST CASE.
 FOCUS ON THE FIRST TEST CASE THEN TRY TO ATTEMPT THE 2ND PART
 REPLICATE THE ENCRYPTION SCHEME FIRST THEN ATTEMPT DECRYPTON
 BEGIN WITH PROB OF RANDOM CHARACTER = 0 THEN INCREASE THE PROBABILITY
*/

/* The frequency mappings for plaintext #1 - #5 */
letter frequency_PT1[27];
letter frequency_PT2[27];
letter frequency_PT3[27];
letter frequency_PT4[27];
letter frequency_PT5[27];

void Compare_Frequency(letter frequency_map[], string ciphertext);
void key_map(letter frequency_map[], letter frequency_PT[], string ciphertext);


/*
* Key Length is at most 24
* Message length is at most 24
*/
/* Part 1 will involve a known-plaintext attack since we're using a plaintext dictionary to decrypt ciphertext */

string decryption_scheme(string input, map<char, char> key) {
//	/* The different parameters */
//
	letter frequency_map[27] = { 0 };	//We will be using this to map out the letter frequency of the ciphertext
	string output;
//
//	/* First, we will begin by acquiring the letter frequency of the ciphertext and the 5 plaintext candidates */
	define_letter_frequency(frequency_PT1, frequency_PT2, frequency_PT3, frequency_PT4, frequency_PT5);
	//
//	//Define the CT letter frequency
	CT_FREQUENCY(input, frequency_map);
//
//	//Compare letter frequencies
	Compare_Frequency(frequency_map, input);
//
	return "PLACEHOLDER";
}


int main() {

	string input;
	string output;
	map<char, char> key = key_gen();

	if (ENCRYPT)
	{
		//Uses a mono-alphabetic substitution cipher and attempts to decrypt it

		/* Use our encryption pseudocode to encode plaintext into ciphertext */
		input = "underwaists wayfarings fluty analgia refuels transcribing nibbled okra buttonholer venalness hamlet praus apprisers presifted cubital walloper dissembler bunting wizardries squirrel preselect befitted licensee encumbrances proliferations tinkerer egrets recourse churl kolinskies ionospheric docents unnatural scuffler muches petulant acorns subconscious xyster tunelessly boners slag amazement intercapillary manse unsay embezzle stuccoer dissembles batwing valediction iceboxes ketchups phonily con";
		cout << "Our input is:  " << input << endl << endl;
//        cout << "Key: " << endl;
//        print_key(key);
        input = encrypt(input, key);
		cout << "Encrypted output:  " << input << endl;

		///* Use our Ciphertext to decrypt the plaintexxt and figure out the plaintext */
		cout << "Now inputting the ciphertext into the decryption algorithm" << endl;
		output = decryption_scheme(input, key);
	}
	else
	{

		//Input would be key k=k[0],...,k[26] and message m=m[1],...,m[L]
		cout << "Enter the ciphertext: " << endl;
		cin >> input;

		output = decryption_scheme(input, key);
		cout << "My plaintext guess is:  " << output << endl;
	}

	return 0;
}

/* Compare the letter frequencies of all plaintext messages with the ciphertext to see which plaintext password has the closest match
https://www.tapatalk.com/groups/crypto/the-index-of-coincidence-the-chi-test-the-kappa-t238.html
*/
void Compare_Frequency(letter frequency_map[], string ciphertext)
{
	//Will count votes for each of the 5 plaintext messages
	int weight[5] = { 0 };

	//For each letter, find the top 5 corresponding letters for each plaintext candidates to find the closest match.
	int max = 0;

	//We will use the chi test to determine which plaintext candidate is the best match.

	//Used for sorting and temporary analysis
	vector<letter> temp_PT;
	vector<letter> temp_CT;
	letter temp_PT2[27];
	letter temp_CT2[27];

	for (int i = 0; i < 27; i++)
	{
		letter temp;
		temp.freq = frequency_map[i].freq;
		temp.letter = char(i + 'a');
		temp_CT.push_back(temp);

		temp.freq = frequency_PT1[i].freq;
		temp_PT.push_back(temp);
	}

	sort(temp_PT.begin(), temp_PT.end(), freq_compare);
	sort(temp_CT.begin(), temp_CT.end(), freq_compare);

	copy(temp_PT.begin(), temp_PT.end(), temp_PT2);
	copy(temp_CT.begin(), temp_CT.end(), temp_CT2);

	percentile(frequency_PT1);
	cout << "Chi Square of : " << chi_square(0, temp_CT2, temp_PT2) << endl;
	key_map(temp_CT2, temp_PT2, ciphertext);

}

void key_map(letter frequency_map[], letter frequency_PT[], string ciphertext)
{
	cout << "Initiating brute force mapping:  " << endl;
	cout << " Input:  " << ciphertext << endl;
	string temp = ciphertext;

	for (int i = 0; i < 26; i++)
	{
		cout << "Using: " << frequency_map[i].letter << " with " << char('a' + i) << endl;
		temp.replace(temp.begin(), temp.end(), char('a' + i), frequency_map[i].letter);
	}
	cout << "End result:  " << temp << endl;
}