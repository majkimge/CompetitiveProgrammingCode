#include <bits/stdc++.h>

#define lld long long
#define MAX 200002
#define MLD 100000000000000
using namespace std;
int n,m;
lld ilo=MLD;
lld krup[MAX];
lld gracz[MAX];
lld wynik=0;
lld nwd(lld n, lld m){
    while(n!=m){
        if(n>m) n=n-m;
        if(n<m) m=m-n;

    }
    return m;
}
int main()
{
    scanf("%i",&n);
    scanf("%i",&m);
    for(int i=0;i<n;++i){
        scanf("%lld",&gracz[i]);
    }
    for(int i=0;i<m;++i){
        scanf("%lld",&krup[i]);
    }
    for(int i=0;i<n;++i){
        ilo=MLD;
        for(int j=0;j<m;++j){
            if(krup[j]*gracz[i]/(nwd(krup[j],gracz[i])*nwd(krup[j],gracz[i]))<ilo){
                ilo=krup[j]*gracz[i]/(nwd(krup[j],gracz[i])*nwd(krup[j],gracz[i]));
            }
        }
        if(ilo>wynik) wynik=ilo;
    }
    printf("%lld\n",wynik);
    return 0;
}
