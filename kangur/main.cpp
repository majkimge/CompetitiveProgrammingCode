#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1000009
#define pii pair<int,int>

using namespace std;

int n,x,y,czypo,czykon;
lld dp[2004][2004];
lld MOD=1000000007;


int main()
{
    scanf("%d%d%d",&n,&x,&y);
    dp[1][1]=1;
    if(x==1){
        czypo=1;
    }else if(y==1){
        czykon=1;
    }
    for(int i=2;i<=n;++i){
        for(int j=1;j<n;++j){
            dp[i][j]+=dp[i-1][j-1];
            if(i!=x&&i!=y){
                dp[i][j]+=dp[i-1][j+1]*(j+1-czypo-czykon)*(j);
            }else if(i==x){
                dp[i][j]+=dp[i-1][j]*(j-czykon);
                czypo=1;
            }else{
                dp[i][j]+=dp[i-1][j]*(j-czypo);
                czykon=1;
            }
            dp[i][j]%=MOD;
        }
    }
    //cout<<dp[2][2];
    if(n==1){
        printf("1");
        return 1;
    }
    if(x!=n&&y!=n){
        printf("%lld",dp[n-1][2]);
    }else{
        printf("%lld",dp[n-1][1]);
    }
    return 0;
}
