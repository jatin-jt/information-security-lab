#include <bits/stdc++.h>
using namespace std;
int power(int b,int e,int p)
{
	if(e==0) return 1;
	int ans = power(b,e/2,p);
	if(e%2) return (((ans*ans)%p)*b)%p;
	return (ans*ans)%p;
}

int main(int argc, char const *argv[])
{
	srand(time(0));
	int g, p, x, y, shared_key,abdata,badata;
	cout<<"Enter the prime number:";
	cin>>p;
	cout<<"Enter a primary root(/generator) of Z"<<p<<":";
	cin>>g;
	cout<<"Generating random number for Alice.."<<endl;
	x = rand()%p;
	cout<<"Generating random number for Bob.."<<endl;
	y = rand()%p;
	//alice to bob
	abdata = power(g,x,p);
	//bob to alice
	badata = power(g,y,p);
	cout<<"Data sent by Alice to Bob:"<<abdata<<endl;
	cout<<"Data sent by Bob to Alice:"<<badata<<endl;
	cout<<endl;
	shared_key = power(badata,x,p);
	cout<<"Shared key calculated by Alice:"<<power(badata,x,p)<<endl;
	cout<<"Shared key calculated by Bob:"<<power(abdata,y,p)<<endl;
	return 0;
}