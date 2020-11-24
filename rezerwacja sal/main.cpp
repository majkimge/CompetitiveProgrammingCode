#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 10004205361450474
#define MOD 1000000007
#define INF 1000696969

using namespace std;

int n,dp[30009],a,b;
vector<int> tab[30009];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&a,&b);
        tab[b].pb(a);
    }
    dp[0]=0;
    for(int i=1;i<=30000;++i){
        for(int j=0;j<tab[i].size();++j){
            dp[i]=max(dp[i],dp[tab[i][j]]+(i-tab[i][j]));
        }
        dp[i]=max(dp[i],dp[i-1]);
    }
    printf("%d",dp[30000]);
    return 0;
}
