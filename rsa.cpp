#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector<ll> primes;
bool sieve[1000000];
ll gcd(ll a,ll b)
{
	return (b==0)?a:gcd(b,a%b);
}
ll pow(ll a,ll p,ll m)
{
	ll res=1;
	while(p>0)
	{
		if(p&1)res=(res*a)%m;
		a=(a*a)%m;
		p>>=1;
	}
	return res;
}
void extended_euclidean(ll a, ll b, ll &x, ll &y)
{
    if(a%b==0)
    {
        x = 0;
        y = 1;
        return;
    }
    extended_euclidean(b, a%b, x, y);
    ll temp = x;
    x = y;
    y = temp - y*(a/b);
}
ll mod_inverse(ll a, ll p)
{
    ll x, y;
    extended_euclidean(a, p, x, y);
    if(x<0)
        x += p;
    return x;
}
void make_sieve()
{
	for(ll i = 2;i<1000000;i++)
	{
		if(sieve[i]==0)
		{
			primes.pb(i);
			for(ll j = i;j<1000000;j+=i)
				sieve[j] = 1;
		}
	}
}
ll get_public_key(ll n, ll phi)
{
	return 7ll;
}

int main(int argc, char const *argv[])
{
	srand(time(0));
	make_sieve();
	ll p,q,n,phi,e,d;
	ll plaintext,ciphertext;
	cout<<"Generating 2 random primes..."<<endl;
	p = primes[rand()%primes.size()];
	q = primes[rand()%primes.size()];
	n = p*q;
	phi = (p-1)*(q-1);
	cout<<"Generating public key..."<<endl;
	e = get_public_key(n,phi);
	cout<<"Generating private key..."<<endl;
	d = mod_inverse(e,phi);
	cout<<"Public key (e,n): "<<e<<" "<<n<<endl;
	cout<<"Enter some number:";
	cin>>plaintext;
	ciphertext = pow(plaintext,e,n);
	cout<<"Encrypted number:"<<ciphertext<<endl;
	cout<<"Decrypted number:"<<pow(ciphertext,d,n)<<endl;
	return 0;
}