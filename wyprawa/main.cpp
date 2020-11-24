#include <bits/stdc++.h>
#define lld long long
#define MAX 200009

using namespace std;

lld n,ros,wyn,wyn2;
lld tab[MAX];

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
    }

    if(tab[1]>tab[0]){
        ros=1;

    }
    wyn=2;
    for(int i=2;i<n;++i){
        if(tab[i]>tab[i-1]){
            if(!ros){
                wyn=1;
                ros=1;
            }
            wyn++;
            wyn2=max(wyn2,wyn);
        }else if(tab[i]<tab[i-1]){
            wyn++;
            ros=0;
            wyn2=max(wyn2,wyn);
        }else{
            ros=0;
            wyn=1;
        }
    }
    printf("%lld",wyn2);
    return 0;
}
