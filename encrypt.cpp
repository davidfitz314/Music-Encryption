#include "encrypt.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

MyEncrypt::MyEncrypt()
{
	this->alphabet = "abcdefghijklmnopqrstuvwxyz., ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	this->file_name_enc = "nofileselected.txt";
	this->file_name_dec = "nofilselected2.txt";
}

MyEncrypt::~MyEncrypt()
{
	//deconstructor
}

void MyEncrypt::SetInputFileNameE(std::string input_file_name_in)
{
	this->file_name_enc = input_file_name_in;
}

void MyEncrypt::SetInputFileNameD(std::string input_file_name_in)
{
	this->file_name_dec = input_file_name_in;
}

string MyEncrypt::GetInputFileName()
{
	return this->file_name_enc;
}

int MyEncrypt::AlphabetValue(char letter_in)
{
	if (letter_in == 'A'){
		return 440%this->alphabet.size();
	} else if (letter_in == 'B'){
		return 493%this->alphabet.size();
	} else if (letter_in == 'C'){
		return 523%this->alphabet.size();
	} else if (letter_in == 'D'){
		return 587%this->alphabet.size();
	} else if (letter_in == 'E'){
		return 329%this->alphabet.size();
	} else if (letter_in == 'F'){
		return 349%this->alphabet.size();
	} else if (letter_in == 'G'){
		return 392%this->alphabet.size();
	} else {
		cout << "Error in value" << endl;
		exit(0);
	}
	return 0;
}

char MyEncrypt::rotateForCaesar(char letter_in, int spaces)
{
	//find index of letter_in
	//std::size_t found = this->alphabet.find(letter_in);
	int found = -1;
	for (int i = 0; i<alphabet.size();i++){
		if (alphabet[i] == letter_in){
			found = i;
		} 
	}

	if (found == -1){
		return '$';
	}

	//test if index + spaces > end of alphabet
	//if greater take index+spaces - alphabet length
	if ((found+spaces)>=this->alphabet.size())
	{

		return this->alphabet[found+spaces-alphabet.size()];
	} else {
		//else rotate letter from index + spaces

		return this->alphabet[found+spaces];
	}
}

char MyEncrypt::rotateBackCaesar(char letter_in, int spaces){
		//find index of letter_in
	int found = -1;
	for (int i = 0; i<alphabet.size();i++){
		if (alphabet[i] == letter_in){
			found = i;
		} 
	}

	if (found == -1){

		return '\n';
	}
	int moveLeft = found - spaces;
	//test if index - spaces > 0
	//if greater take index-spaces + alphabet length
	
	if (moveLeft<0)
	{
		return this->alphabet[alphabet.size()+(found-spaces)];
	} else {
		//else rotate letter from index - spaces
		return this->alphabet[found-spaces];
	}
	
}

void MyEncrypt::caesar(string key_in)
{
	string fileStore = "";
	string line;
	ifstream myfile (this->file_name_enc);
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			fileStore += line + "\n";
		}
		myfile.close();
	} else cout << "Unable to open file"; 
	
	ofstream caesarEncrypted;
	caesarEncrypted.open(this->file_name_dec);
	//keysize is how many characters should go in a block based on the initial file size
	int key_size = fileStore.size()/key_in.size();
	int encryptionLocation = 0;
	for (int i = 0; i<fileStore.size(); i++)
	{
		if (fileStore[i]=='eof'){
			break;
		}
		if (i != 0){
			if (i%key_size == 0){
				if (encryptionLocation < key_in.size()-1){
					encryptionLocation ++;
				}
			}
		}
		//perform encryption based on the index encrpytion location
		//encrypt based on encryption location and move value number spaces over.
		int tempValue = 0;
		tempValue = AlphabetValue(key_in[encryptionLocation]);
		
		char tempEncrypted;
		tempEncrypted = this->rotateForCaesar(fileStore[i],tempValue); 
		if (tempEncrypted == '$' && fileStore.size()-i<7){

		} else {
		
			caesarEncrypted << tempEncrypted;
		}
	}
	caesarEncrypted.close();
}

void MyEncrypt::caesarDecrypt(string key_in)
{
	string fileStore = "";
	string line;
	ifstream myfile (this->file_name_dec);
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			fileStore += line + "\n";
		}
		myfile.close();
	} else cout << "Unable to open file"; 
	
	ofstream caesarEncrypted;
	caesarEncrypted.open("output.txt");
	//keysize is how many characters should go in a block based on the initial file size
	int key_size = fileStore.size()/key_in.size();
	int encryptionLocation = 0;
	for (int i = 0; i<fileStore.size(); i++)
	{
		if (fileStore[i]=='eof'){
			break;
		}
		if (i != 0){
			if (i%key_size == 0){
				if (encryptionLocation < key_in.size()-1){
					encryptionLocation ++;
				}
			}
		}
		//perform encryption based on the index encrpytion location
		//encrypt based on encryption location and move value number spaces over.
		int tempValue = 0;
		tempValue = AlphabetValue(key_in[encryptionLocation]);
		char tempEncrypted;
		tempEncrypted = this->rotateBackCaesar(fileStore[i],tempValue); 
		if (tempEncrypted == '\n' && fileStore.size()-i<7){

		} else {
			caesarEncrypted << tempEncrypted;
		}
	}
	caesarEncrypted.close();
}