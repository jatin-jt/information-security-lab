#include <iostream>
#include <string>
using namespace std;

void extended_euclidean(int a, int b, int &x, int &y)
{
    if(a%b==0)
    {
        x = 0;
        y = 1;
        return;
    }

    extended_euclidean(b, a%b, x, y);
    int temp = x;
    x = y;
    y = temp - y*(a/b);
}

int mod_inverse(int a, int p)
{
    int x, y;
    extended_euclidean(a, p, x, y);
    if(x<0)
        x += p;
    return x;
}

string add(string message, int key)
{
	string ans = "";
	for (int i = 0; i < message.length(); ++i)
	{
		ans+=char(97 + (int (message[i]-97) + key)%26);
	}
	return ans;
}

string mul(string message, int key)
{
	string ans = "";
	for (int i = 0; i < message.length(); ++i)
	{
		ans+=char(97 + (int (message[i]-97) * key)%26);
	}
	return ans;
}

string encrypt(string message, int add_key, int mul_key)
{
	return mul(add(message,add_key),mul_key);
}

string decrypt(string message, int add_key, int mul_key)
{
	int add_dec_key = (26 - add_key)%26;
	int mul_dec_key = mod_inverse(mul_key,26);
	return add(mul(message,mul_dec_key),add_dec_key);
}


int main(int argc, char const *argv[])
{
	int add_key,mul_key;
	string message;
	cout<<"Enter string to be encrypted(consisting of a-z):";
	cin>>message;
	cout<<"Enter additive key(0-25):";
	cin>>add_key;
	cout<<"Enter multiplicative key(odd numbers between 0-25 other than 13):";
	cin>>mul_key;

	string enc_message = encrypt(message,add_key,mul_key);
	cout<<"Encrypted message is:"<<enc_message<<endl;
	cout<<"Decrypted message is:"<<decrypt(enc_message,add_key,mul_key)<<endl;

	return 0;
}