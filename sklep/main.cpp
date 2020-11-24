#include <bits/stdc++.h>

#define lld long long
#define mp make_pair
#define f first
#define s second
#define MAX 1000009
#define INF 100000000000

using namespace std;

lld n;
lld tab[MAX];
lld mini=INF;
lld wynik;
lld maxwyn;
bool na;
int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
        if(tab[i]<mini){
            mini=tab[i];
        }
    }
    for(int i=0;i<n;++i){
        if(tab[i]==mini&&na==0){
            na=1;
            wynik++;
            if(wynik>maxwyn){
                maxwyn=wynik;
            }
        }else if(tab[i]==mini&&na==1){
            wynik++;
            if(wynik>maxwyn){
                maxwyn=wynik;
            }
        }else if(tab[i]!=mini&&na==1){
            na=0;
            wynik=0;

        }
    }
    printf("%lld",maxwyn);
    return 0;
}
