#include <bits/stdc++.h>
#define lld long long

using namespace std;

int pier[20000];
int z,n,m,ilep;
int czyp[20009];
int dp[20009][2];

int main()
{
    for(int i=2;i<=20000;++i){
        if(!czyp[i]){
            pier[ilep]=i;
            ++ilep;
            for(int j=i*i;j<=20000;j+=i){
                czyp[j]=1;
            }
        }
    }

    scanf("%d",&z);
    scanf("%d",&m);
    dp[0][1]=1;
    for(int i=0;i<ilep;++i){
        for(int j=pier[i];j<=20000;++j){
            dp[j][0]+=dp[j-pier[i]][1];
            dp[j][1]+=dp[j-pier[i]][0];
            dp[j][0]%=m;
            dp[j][1]%=m;
        }
    }
    for(int xx=0;xx<z;++xx){
        scanf("%d",&n);
        printf("%d\n",dp[n][1]);
    }
    return 0;
}
