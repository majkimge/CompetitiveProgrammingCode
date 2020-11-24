#include <bits/stdc++.h>
#define MAX 1000009
#define lld long long
using namespace std;

lld n,m,a,b,mini=1000000000,maxi,minim,maxim,ile,wynik;
lld tab[MAX];
lld tab1[MAX];

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&m);
    for(int i=0;i<n;++i){
        scanf("%lld",&a);
        scanf("%lld",&b);
        tab[a]++;
        tab[a+b]--;
        tab1[a]+=b;
    }
    for(int i=1;i<=m;++i){
        wynik-=ile;
        ile+=tab[i];
        wynik+=tab1[i];
        if(wynik>maxi){
            maxi=wynik;
            maxim=i;
        }
        if(wynik<mini){
            mini=wynik;
            minim=i;
        }
    }
    printf("%lld %lld",maxim,minim);
    return 0;
}
