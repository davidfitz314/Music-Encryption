#ifndef _ENCRYPT_H_
#define _ENCRYPT_H_
//using includes in the header causes issues
#include <string>
#pragma once

class MyEncrypt
{
public:
	MyEncrypt();
	~MyEncrypt();
	void SetInputFileNameE(std::string input_file_name_in);
	void SetInputFileNameD(std::string input_file_name_in);
	std::string GetInputFileName();
	int AlphabetValue(char letter_in);
	char rotateForCaesar(char letter_in, int spaces);
	char rotateBackCaesar(char letter_in, int spaces);
	void caesar(std::string key_in);
	void caesarDecrypt(std::string key_in);
private:
	std::string alphabet;
	std::string file_name_enc;
	std::string file_name_dec;

};

#endif