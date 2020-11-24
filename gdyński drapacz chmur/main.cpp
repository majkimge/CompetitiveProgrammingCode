#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 109

using namespace std;

int n,l,tab[MAX],tab1[MAX];
lld wynik;

int main()
{
    scanf("%d",&n);
    scanf("%d",&l);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
        tab1[i]=tab[i];
    }
    lld sum=0;
        for(int i=1;i<n;++i){
            sum+=abs(tab[i]-tab[i-1]);
        }
        if(sum<=l) wynik++;
    while(next_permutation(tab,tab+n)){
        sum=0;
        for(int i=1;i<n;++i){
            sum+=abs(tab[i]-tab[i-1]);
        }
        if(sum<=l) wynik++;
    }
    while(prev_permutation(tab1,tab1+n)){
        sum=0;
        for(int i=1;i<n;++i){
            sum+=abs(tab1[i]-tab1[i-1]);
        }
        if(sum<=l) wynik++;
    }

    printf("%lld",wynik);
    return 0;
}
