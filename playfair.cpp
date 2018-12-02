#include <bits/stdc++.h>

using namespace std;
char key[5][5];
map <char,pair<int,int> > pos;
void init()
{
	vector<int> v;
	for(int i = 0;i<26;++i)	if(i!=16) v.push_back(i);
	random_shuffle(v.begin(), v.end());
	for (int i = 0; i < 25; ++i)
	{
		key[i/5][i%5] = 'a'+v[i];
		pos['a'+v[i]]=make_pair(i/5,i%5);
	}
}

string encrypt(string message)
{
	string ans="";
	for (int i = 0; i < message.length(); i+=2)
	{
		int  x1,x2,y1,y2;
		x1=pos[message[i]].first;
		y1=pos[message[i]].second;
		x2=pos[message[i+1]].first;
		y2=pos[message[i+1]].second;
		if(x1!=x2&&y1!=y2)
		{	
			ans.push_back(key[x1][y2]);
			ans.push_back(key[x2][y1]);
		}
		else if(x1==x2){
			ans.push_back(key[x1][(y1+1)%5]);
			ans.push_back(key[x1][(y2+1)%5]);
		}
		else if(y1==y2){
			ans.push_back(key[(x1+1)%5][y1]);
			ans.push_back(key[(x2+1)%5][y1]);
		}
	}
	return ans;
}

string decrypt(string message)
{
string ans="";
	for (int i = 0; i < message.length(); i+=2)
	{
		int  x1,x2,y1,y2;
		x1=pos[message[i]].first;
		y1=pos[message[i]].second;
		x2=pos[message[i+1]].first;
		y2=pos[message[i+1]].second;
		if(x1!=x2&&y1!=y2)
		{	
			ans.push_back(key[x1][y2]);
			ans.push_back(key[x2][y1]);
		}
		else if(x1==x2){
			ans.push_back(key[x1][(y1+4)%5]);
			ans.push_back(key[x1][(y2+4)%5]);
		}
		else if(y1==y2){
			ans.push_back(key[(x1+4)%5][y1]);
			ans.push_back(key[(x2+4)%5][y1]);
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	init();
	string message;
	cout<<"Enter string to be encrypted(consisting of a-z):";
	cin>>message;
	if(message.length()%2!=0)message.push_back('z');
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++)
		{
			cout<<key[i][j];
		}
		cout<<'\n';
	}
	string enc_message = encrypt(message);
	cout<<"Encrypted message is:"<<enc_message<<endl;
	cout<<"Decrypted message is:"<<decrypt(enc_message)<<endl;
	return 0;
}