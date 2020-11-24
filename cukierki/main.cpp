#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 500009


using namespace std;

lld n,tab[25];
lld wynik,INF=30000000000;
lld heu[4];

lld brut(lld kt,lld a, lld d, lld b){
    if(kt==n){
        if(a>=d&&d>=b)return a-b;
        return INF;
    }else{
        return min(min(brut(kt+1,a+tab[kt],d,b),brut(kt+1,a,d+tab[kt],b)),brut(kt+1,a,d,b+tab[kt]));
    }
}

lld heura(lld xd){

    heu[0]=heu[1]=heu[2]=0;
    for(int i=0;i<n;++i){
        heu[(rand()&1)+(rand()&1)]+=tab[i];
    }
    if(heu[0]>=heu[1]&&heu[1]>=heu[2]){
        wynik=min(wynik,heu[0]-heu[2]);
    }
}


int main()
{
    scanf("%lld",&n);

    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
    }
    srand(n*n+123*123+time(NULL));
    if(n<=18){
        printf("%lld",brut(0,0,0,0));
    }else{
        wynik=INF;
        for(int j=0;j<1000000;++j){
            heura(j);
        }
        printf("%lld",wynik);
    }

    return 0;
}
