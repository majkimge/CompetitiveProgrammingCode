#include <bits/stdc++.h>
#define lld long long
#define MAX 100009

using namespace std;

lld n;
lld tab[MAX];
lld wyn,sum;

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
        sum+=tab[i];
    }
    wyn=abs(tab[n-1]-tab[n-2]);
    for(int i=n-3;i>=0;--i){
        wyn=abs(wyn-tab[i]);
    }
    printf("%lld",(wyn+sum)/2);
    return 0;
}
