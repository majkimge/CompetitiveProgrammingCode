#include<bits/stdc++.h>
#define MAX 1000009
#define lld long long
using namespace std;

lld n,k,akt,last,wynik;
lld tab[MAX];
lld mody[1009];

int main(){
scanf("%lld",&n);
scanf("%lld",&k);
mody[0]=1;
for(int i=0;i<n;++i){
	scanf("%lld",&tab[i]);
	akt+=tab[i]%k;
	akt%=k;
	wynik+=mody[akt];
	mody[(akt)%k]++;
	last=akt;
	last%=k;
}
cout<<wynik;
}
