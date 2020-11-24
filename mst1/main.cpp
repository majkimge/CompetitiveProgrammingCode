#include <bits/stdc++.h>
#define lld long long
#define MAX 100009
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000
using namespace std;

int n,k,m,a,b,w;
vector<pair<int,int> >kraw[MAX];

int fw[9];
int dp[MAX][65];

int main()
{
    scanf("%d",&n);
    scanf("%d",&k);
    scanf("%d",&m);
    for(int i=0;i<k;++i){
        scanf("%d",&fw[i]);
    }
    for(int i=0;i<m;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&w);
        kraw[a].pb(mp(w,b));
        kraw[b].pb(mp(a,b));
    }
    for(int i=1;i<=n;++i){

    }
    for(int i=0;i<32;++i){
        for(int j=1;j<=n;++j){
            for(int z=0;z<)
        }
    }
    return 0;
}
