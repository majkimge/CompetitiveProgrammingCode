#include<bits/stdc++.h>
#include<string.h>
#define lld long long
using namespace std;

lld a,x,c,n,wyn;
bool tab[1000000];
int main(){
	scanf("%lld",&a);
	scanf("%lld",&c);
	scanf("%lld",&n);
	scanf("%lld",&x);
	tab[x]++;
	wyn=1;
	lld y=(a*x+c)%n;

	while(tab[y]==0){
        //cout<<y;
		wyn++;
		tab[y]=1;
		y=(y*a+c)%n;
		//cout<<y;
	}
	cout<<wyn;
	/*for(int i=0;i<strlen(liczba);++i){
		suma+=liczba[i]-48;
		turbo+=(liczba[i]-48)*(i+1);
	}*/

	//cout<<suma;
}
