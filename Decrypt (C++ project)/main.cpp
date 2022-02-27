#include<iostream>
#include "encrypt.h"
#include "decrypt.h"

using namespace std;

#define ENCRYPT true

int main()
{

	string input;
	string output;
	string key;


	if (ENCRYPT)
	{
		//Uses a mono-alphabetic substitution cipher and attempts to decrypt it
		//CT_FREQUENCY("abcdefghijklmnopqrstuvwxyz", frequency_map);
		//define_letter_frequency(frequency_map);

		
		/* Use our encryption pseudocode to encode plaintext into ciphertext */
		input = "underwaists wayfarings fluty analgia refuels transcribing nibbled okra buttonholer venalness hamlet praus apprisers presifted cubital walloper dissembler bunting wizardries squirrel preselect befitted licensee encumbrances proliferations tinkerer egrets recourse churl kolinskies ionospheric docents unnatural scuffler muches petulant acorns subconscious xyster tunelessly boners slag amazement intercapillary manse unsay embezzle stuccoer dissembles batwing valediction iceboxes ketchups phonily con";
		cout << "Our input is:  " << input << endl << endl;
		input = encrypt(input, "secret");
		cout << "Encrypted output:  " << input << endl;

		/* Use our Ciphertext to decrypt the plaintexxt and figure out the plaintext */
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

