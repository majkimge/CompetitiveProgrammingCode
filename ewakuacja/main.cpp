#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 4002
#define MOD 1000000009


using namespace std;

lld lud[MAX];
lld schron[MAX];
lld wynik,n,m,INF=100000000000000000;

pair<lld,lld> wss[MAX];

lld dp[MAX][MAX];
lld pozy[MAX],ilezos;

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&lud[i]);

    }

    scanf("%lld",&m);
    for(int i=1;i<=m;++i){
        scanf("%lld",&schron[i]);

    }
    sort(lud+1,lud+n+1);
    sort(schron+1,schron+m+1);

    for(int j=1;j<=n;++j){
        dp[1][j]=dp[1][j-1]+abs(schron[1]-lud[j]);
    }

    for(int i=2;i<=m;++i){
        dp[i][i]=dp[i-1][i-1]+abs(schron[i]-lud[i]);
        for(int j=i+1;j<=n;++j){
            dp[i][j]=min(dp[i-1][j-1]+abs(schron[i]-lud[j]),dp[i][j-1]+abs(schron[i]-lud[j]));
        }
    }
    printf("%lld",dp[m][n]);
    return 0;
}
