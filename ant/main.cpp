#include <bits/stdc++.h>
#define lld long long
#define MAX 100009
#define MOD 1000000009
#define mp make_pair
#define f first
#define s second
using namespace std;

lld t,n,wyn,maxi;
lld dyn[MAX];
lld tab[MAX];

int main()
{
    scanf("%lld",&t);
    for(int z=1;z<=t;++z){
        scanf("%lld",&n);
        for(int i=0;i<n;++i){
            dyn[i]=0;
        }
        for(int i=0;i<n;++i){
            scanf("%lld",&tab[n-1-i]);
        }
        wyn=1;
        maxi=0;
        dyn[0]=1;
        for(int i=1;i<n;++i){
                maxi=0;
            for(int j=0;j<i;++j){
                if(float(tab[j])>(float)tab[i]/8){
                    maxi=max(maxi,dyn[j]);
                }
            }
            dyn[i]=maxi+1;
            wyn=max(wyn,dyn[i]);
        }
        printf("Case #%d: %lld\n",z,wyn);
    }
    return 0;
}
