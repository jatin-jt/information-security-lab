#include <bits/stdc++.h>
using namespace std;
map<char,char> key,inv_key; 
void init()
{
	vector<int> v;
	for(int i = 0;i<26;++i)	v.push_back(i);
	random_shuffle(v.begin(), v.end());
	for (int i = 0; i < 26; ++i)
	{
		key[i+'a'] = 'a'+v[i];
		inv_key['a'+v[i]] = i+'a';
	}
}
string encrypt(string message)
{
	string ans="";
	for (int i = 0; i < message.length(); ++i)
	{
		ans+=key[message[i]];
	}
	return ans;
}

string decrypt(string message)
{
	string ans="";
	for (int i = 0; i < message.length(); ++i)
	{
		ans+=inv_key[message[i]];
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	init();
	string message;
	cout<<"Enter string to be encrypted(consisting of a-z):";
	cin>>message;

	string enc_message = encrypt(message);
	cout<<"Encrypted message is:"<<enc_message<<endl;
	cout<<"Decrypted message is:"<<decrypt(enc_message)<<endl;
	return 0;
}