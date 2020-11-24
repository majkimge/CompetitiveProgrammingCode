#include <bits/stdc++.h>
#define lld long long
#define MAX 100009
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000
#define MOD 1000696969

using namespace std;

lld n;
lld tab[MAX];
lld dp[1009][1009];
lld ile[MAX];
lld ile1[MAX];

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
    }
    int czy=0;
    for(int i=0;i<n;++i){

        for(int j=0;j<i;++j){
            if(__gcd(tab[i],tab[j])==1&&ile[tab[j]]==0){
                ile[tab[j]]=1;
                czy++;
                break;
            }
        }
    }
    for(int i=n-1;i>=0;--i){

        for(int j=i;j<n;++j){
            if(__gcd(tab[i],tab[j])==1&&ile1[tab[j]]==0){
                ile1[tab[j]]=1;
                czy++;
                break;
            }
        }
    }
    if(czy>=2*n-2){
        printf("TAK");
    }else{
        printf("NIE");
    }
    return 0;
}
