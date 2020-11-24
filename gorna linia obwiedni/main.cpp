#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1009
#define INF 1000000000000000

using namespace std;

int n,a,b;
pair<int,int> tab[MAX];
pair<int,int> dp[MAX];

int main()
{
    scanf("%d",&n);
    scanf("%d",&a);
    scanf("%d",&b);
    if(a<b) swap(a,b);
    tab[0]=mp(a,b);
    dp[0]=mp(b,a);
    for(int i=1;i<n;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        if(a<b) swap(a,b);
        tab[i]=mp(a,b);
        dp[i]=mp(max(b+abs(a-tab[i-1].f)+dp[i-1].f,b+abs(a-tab[i-1].s)+dp[i-1].s),max(a+abs(b-tab[i-1].f)+dp[i-1].f,a+abs(b-tab[i-1].s)+dp[i-1].s));
    }
    printf("%d",max(dp[n-1].f,dp[n-1].s));
    return 0;
}
