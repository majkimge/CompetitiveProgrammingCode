#include <bits/stdc++.h>
#define lld long long
#define MAX 100009
#define MOD 1000696969
#define mp make_pair
#define f first
#define s second
using namespace std;

lld n,wyn;
lld tab[MAX];

lld nwd(lld a,lld b){
    while(b!=0){
        lld c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
    }
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
             if(nwd(tab[i],tab[j])==1){
                wyn++;
             }
        }
    }
    printf("%lld",wyn);
    return 0;
}
