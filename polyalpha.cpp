#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
char getCharacter(int a,int b)
{
	return (a+b+26)%26 + 'a';
}
 
string generate_key(string input_key, int option, string plaintext)
{
	string key = "";
	int req_length = plaintext.length();
	int n = input_key.length();
	// vigenere cipher
	if(option == 1)
	{
		for (int i = 0; i < req_length; ++i)
		{
			key += input_key[i%n];
		}
	}
	// autokey cipher
	else
	{
		key += input_key;
		int idx = 0;
		while(key.length() < req_length)
		{
			key += plaintext[idx];
			idx = (idx+1)%req_length;
		}
	}
	return key;
}
 
string encrypt(string plaintext, string key)
{
	string ciphertext = "";
	for (int i = 0; i < plaintext.length(); ++i)
	{
		ciphertext += getCharacter(plaintext[i]-'a',key[i]-'a');
	}
	return ciphertext;
}
 
string decrypt(string ciphertext, string key)
{
	string plaintext = "";
	for (int i = 0; i < ciphertext.length(); ++i)
	{
		plaintext+=getCharacter(ciphertext[i],-key[i]);
	}
	return plaintext;
}
 
int main()
{
	string plaintext, ciphertext, key;
	int option;
 
	cout<<"Enter string to be encrypted(consisting of a-z): ";
	cin>>plaintext;
	cout<<"Enter 1 for VIGENERE CIPHER and 2 for AUTOKEY CIPHER:";
	cin>>option;
	cout<<"Enter the key: ";
	cin>>key;
 
	key = generate_key(key, option, plaintext);
	cout<<"The generated key for the plaintext: "<<key<<endl;
	ciphertext = encrypt(plaintext, key);
    cout<<"Polyalphabetic Ciphertext: "<<ciphertext<<endl;
   	cout<<"Polyalphabetic Plaintext after decryption: ";
   	cout<<decrypt(ciphertext, key)<<endl;
 
	return 0;
}