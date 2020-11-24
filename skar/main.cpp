#include <bits/stdc++.h>

#define lld long long

using namespace std;

lld n;
lld tab[500000];
lld temp;
lld wynik;
int main()
{
    scanf("%lld",&n);
    for(lld i=0;i<n;++i){
        scanf("%lld",&temp);
        tab[temp]++;
    }
    for(int i=0;i<500000;++i){
        tab[i+1]+=tab[i]/2;
    }
    for(int i=0;i<500000;++i){
        if(tab[i]>0){
            wynik=i;
        }
    }
    printf("%lld",wynik);
    return 0;
}
