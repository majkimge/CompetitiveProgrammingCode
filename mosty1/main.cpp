#include <bits/stdc++.h>
#define lld long long
#define MAX 100009
using namespace std;

lld tab[MAX];
lld n;
lld wyn,wyn1;

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&tab[i]);
    }
    sort(tab+1,tab+n+1);

    if(n<2){
        cout<<tab[1];
    }else if(n<3){
        cout<<tab[2];
        }else{
            if(n%2){
                wyn+=tab[3]+tab[1];
                for(int i=5;i<=n;i+=2){
                    wyn+=min(tab[i]+tab[2]*2+tab[1],tab[i]+tab[i-1]+2*tab[1]);
                }
            }else{
                for(int i=4;i<=n;i+=2){
                    wyn+=min(tab[i]+tab[2]*2+tab[1],tab[i]+tab[i-1]+2*tab[1]);
                }
            }
            if(tab[n]+tab[n-1]+2*tab[1]<tab[n]+tab[2]*2){
                //wyn-=tab[1];
            }else{
                //wyn-=tab[2];
            }
            cout<<wyn+tab[2];
        }



    return 0;
}
