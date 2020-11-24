#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1009
#define INF 1000000000.0
#define MOD 1000000009

using namespace std;

int t,n;
double x[MAX];
double y[MAX];
double px[MAX];
double py[MAX];
double p;
double dp[MAX];
double dp2[MAX];
double wynik;

int main()
{
    scanf("%d",&t);
    for(int xx=0;xx<t;++xx){
        scanf("%d",&n);
        scanf("%lf",&p);
        wynik=INF;
        for(int i=1;i<=n;++i){
            scanf("%lf",&x[i]);
            scanf("%lf",&y[i]);
            px[i]=px[i-1]+x[i];
            py[i]=py[i-1]+y[i];
        }
        dp[1]=x[1];
        dp2[1]=y[1];
        for(int i=2;i<=n;++i){
            dp[i]=px[i];
            dp2[i]=py[i];
            for(int j=0;j<i;++j){
                dp[i]=min(dp[i],dp[j]+px[i-j]+p);
                dp2[i]=min(dp2[i],dp2[j]+py[i-j]+p);
            }
        }
        for(int i=1;i<n;++i){
            //cout<<dp[i]<<endl;
            wynik=min(wynik,dp[i]+dp2[n-i]+p);
        }
        printf("%.3lf\n",wynik);
    }
    return 0;
}
