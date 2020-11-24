#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1000009
#define pii pair<int,int>

using namespace std;

int n,x,y;
lld dp[2000][2000][2];
lld prefy[2000][2000][2];
lld MOD=1000000007;


int main()
{
    scanf("%d%d%d",&n,&x,&y);
    if()
    dp[1][1][0]=1;
    dp[1][1][1]=1;
    prefy[1][1][0]=1;
    prefy[1][1][1]=1;
    for(int i=2;i<=n;++i){
        for(int j=1;j<=i;++j){
            dp[i][j][0]=prefy[i-1][j-1][1];
            dp[i][j][1]=prefy[i-1][j][0];
        }
        for(int j=1;j<=i;++j){
            prefy[i][j][1]=dp[i][j][1]+prefy[i][j-1][1];
            prefy[i][j][1]%=MOD;
        }
        for(int j=i;j>0;--j){
            prefy[i][j][0]=dp[i][j][0]+prefy[i][j+1][0];
            prefy[i][j][0]%=MOD;
        }
    }
    printf("%lld", (dp[n][y][0]+dp[n][y][1]));
    return 0;
}
