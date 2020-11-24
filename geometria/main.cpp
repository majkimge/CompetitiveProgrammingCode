#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1000009
#define MOD 1000000007

using namespace std;

lld n,k;
lld dp[130][130];

int main()
{
    scanf("%lld%lld",&n,&k);
    dp[3][1]=1;
    for(int i=4;i<=n;++i){
        dp[i][1]=1;
        for(int j=2;j<=min(k,(lld)i-2);++j){
            dp[i][j]+=dp[i-1][j]+dp[i-1][j-1]+dp[i-1][j-1];
            for(int p=4;p<=i-1;++p){
                for(int d=max(1,j-(i-p));d<=min(p-2,j-1);++d){
                    dp[i][j]+=(dp[p-1][d]+dp[p-1][d-1])*dp[i-p+2][j-d];
                    dp[i][j]%=MOD;
                }
            }
        }
    }
    printf("%lld",dp[n][k]);
    return 0;
}
