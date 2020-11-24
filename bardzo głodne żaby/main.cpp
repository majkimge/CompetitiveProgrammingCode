#include <bits/stdc++.h>
#define pbpush_back
#define mp make_pair
#define lld long long
#define f first
#define s second
#define MAX 500009
#define INF 2000000009

using namespace std;

lld n,mini=INF,suma,czyr,czydod,czyuj,ost;
lld tab[MAX];

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
        if(tab[i]<0){
            czyuj=1;
        }else{
            czydod=1;
        }
        suma+=abs(tab[i]);
    }
    if(n==1){
        printf("%lld",tab[0]);
    }else{
        if(!czydod||!czyuj){
            for(int i=1;i<n;++i){
                mini=min(mini,abs(tab[i])+abs(tab[i-1])-abs((abs(tab[i])-abs(tab[i-1]))));
            }
            printf("%lld",suma-mini);
        }else{
            printf("%lld",suma);
        }

    }

    return 0;
}
