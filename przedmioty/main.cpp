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

lld n,m,x,y,z,akt=1,wynik;

lld dp[59];
lld tab[59][3];

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        scanf("%d",&y);
        scanf("%d",&z);
        tab[i][0]=x;
        tab[i][1]=y;
        tab[i][2]=z;
    }
    for(int i=0;i<n;++i){
        while(tab[i][2]>0){
            for(int j=m-tab[i][0];j>=0;--j){
                dp[j+tab[i][0]]=max(dp[j+tab[i][0]],dp[j]+tab[i][1]);
            }

            tab[i][2]--;
        }
    }

    for(int i=0;i<=m;++i){
        wynik=max(wynik,dp[i]);
    }
    printf("%d",wynik);
    return 0;
}
