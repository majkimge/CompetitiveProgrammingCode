#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 2000009
#define lld long long


using namespace std;

lld z,n,m;

lld tab[MAX/2];

int main()
{
    scanf("%lld",&z);
    for(int xx=0;xx<z;++xx){
        scanf("%lld",&n);
        scanf("%lld",&m);
        for(int i=0;i<n;++i){
            scanf("%lld",&tab[i]);
        }
        if((m/n)%2==0){
            printf("%lld\n",tab[m%n]);
        }else{
            printf("%lld\n",tab[n-m%n-1]);
        }

    }
    return 0;
}
