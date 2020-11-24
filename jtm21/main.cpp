#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 20009
#define INF 1000000
#define MOD 255

using namespace std;


lld dp[100];
lld poty[100];

lld f(lld n){
    if(n==0)return 1;
    if(n%2==0)return 4*f(n/2)-n-3;
    return f(n-1) + 2*n;

}

int main()
{
    dp[0]=3;
    poty[0]=1;
    for(int i=1;i<90;++i){
        poty[i]=(4*poty[i-1])%MOD;
    }
    for(int i=1;i<=85;++i){
        dp[i]=(dp[i-1]+poty[i]*2)%MOD;
    }
    cout<<f(1213);
    return 0;
}
