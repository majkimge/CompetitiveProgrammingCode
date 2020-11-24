#include <bits/stdc++.h>
#define lld long long
#define MAX 100009
using namespace std;

lld n,b,wynyl,wynyp,wynik;

lld tab[MAX];
map<lld,lld> wynylew;
map<lld,lld> wynypraw;

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&b);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);

    }
    lld co=-1;
    lld ite=0;
    while(co!=b){
        co=tab[ite];
        ite++;
    }
    ite--;
    //cout<<ite;
    for(int i=ite-1;i>=0;--i){
        if(tab[i]>b){
            wynyl+=1;
        }else{
            wynyl-=1;
        }
        if(wynyl==0){
            wynik++;
        }
        wynylew[wynyl]++;
    }
    for(int i=ite+1;i<n;++i){
        if(tab[i]>b){
            wynyp+=1;
        }else{
            wynyp-=1;
        }
        if(wynyp==0){
            wynik++;
        }
        wynypraw[wynyp]++;
    }
    lld boi=0;
    wynyl=0;
    wynyp=0;

    for(int i=-n;i<=n;++i){

        wynik+=wynylew[i]*wynypraw[-i];

    }
    printf("%lld",wynik+1);
    return 0;
}
