#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 30009
#define MOD 1000000009
#define INF 1000000000000000

using namespace std;

lld n,it;
lld dp[2][MAX];
char s[MAX];

int main()
{
    scanf("%lld",&n);
    scanf("%s",s);
    dp[0][1]=1;
    for(int i=1;i<n;++i){
        //s[i]='(';
        for(int j=0;j<n;++j){
            dp[it^1][j]=0;
        }
        if(s[i]=='('){
            for(int j=1;j<n;++j){
                dp[it^1][j]=dp[it][j-1];
                //dp[it^1][j]%=MOD;
            }
            dp[it^1][0]=0;
            for(int j=0;j<n;++j){
                dp[it^1][j]+=dp[it][j+1];
                dp[it^1][j]%=MOD;
            }
        }else{
            dp[it^1][0]=0;
            for(int j=0;j<n;++j){
                dp[it^1][j]=dp[it][j+1];
                dp[it^1][j]%=MOD;
            }
        }
        it=(it^1);
    }
    printf("%lld",dp[it][0]);
    return 0;
}
