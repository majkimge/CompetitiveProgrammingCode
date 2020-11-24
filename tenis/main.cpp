#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define MAX 1009

lld n,k,wynik;
lld tab[MAX];
using namespace std;

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&k);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
    }
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if((tab[i]*tab[j])%k==0) wynik++;
        }
    }
    printf("%lld",wynik);
    return 0;
}
