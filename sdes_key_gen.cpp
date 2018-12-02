#include <bits/stdc++.h>
using namespace std;
string ls(string a,int i)
{
	return a.substr(i)+a.substr(0,i);
}
string apply8(string a)
{
	int P8[8] = { 6, 3, 7, 4, 8, 5, 10, 9};
	string key = "00000000";
	for (int i = 0; i < 8; ++i)
	{
		key[i] = a[P8[i]-1];
	}
	return key;
}
void generatesubkeys(string key)
{
	//apply p10
	int P10[10] = { 3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
	string key1="",key2="";
	string temp="0000000000";

	for (int i = 0; i < 10; ++i)
		temp[i] = key[P10[i]-1];
	key = temp;
	key = ls(key.substr(0,5),1) + ls(key.substr(5),1);
	key1 = apply8(key);
	//cout<<key<<endl;
	key = ls(key.substr(0,5),2) + ls(key.substr(5),2);
	//cout<<key<<endl;
	key2 = apply8(key);
	cout<<"Key1:"<<key1<<endl<<"Key2:"<<key2<<endl;
}
int main()
{
	string key;
	cout<<"Enter 10-bit key:";
	cin>>key;
	generatesubkeys(key);
	return 0;
}