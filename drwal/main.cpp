#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 10009
#define MOD 1000000007
#define INF 1000696969

using namespace std;

int n,p,t;
int dp[10009][2];
int tab[1009];

int main()
{
    scanf("%d",&n);

    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    for(int i=1;i<MAX;++i){
        dp[i][0]=dp[i][1]=MOD;
    }
    dp[0][1]=MOD;
    for(int i=0;i<n;++i){
        for(int j=MAX-1;j>=tab[i];--j){
            dp[j][0]=min(dp[j][0],dp[j][1]);
            dp[j][1]=min(dp[j-tab[i]][0]+1,dp[j-tab[i]][1]);
        }
        for(int j=1;j<tab[i];++j){
            dp[j][0]=min(dp[j][0],dp[j][1]);
            dp[j][1]=INF;
        }
    }
    scanf("%d",&p);
    for(int i=0;i<p;++i){
        scanf("%d",&t);
        if(min(dp[t][0],dp[t][1])<MOD){
            printf("%d\n",min(dp[t][0],dp[t][1]));
        }else{
            printf("-1\n");
        }

    }
    return 0;
}
