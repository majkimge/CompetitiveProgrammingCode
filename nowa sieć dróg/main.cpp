#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200009
#define MOD 1000000007

using namespace std;

int n;
lld wag[MAX],a,b,c;
lld kol[MAX];
pair<lld,lld> scdol[MAX][4];
int odw[MAX];

int dfs(int from){
    odw[from]=1;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            dfs(kraw[from][i]);
        }
    }

}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&wag[i]);
    }
    while(kk<n)kk<<=1;
    for(int i=0;i<n-1;++i){
        scanf("%lld%lld%lld",&a,&b,&c);
        kraw[a].pb(mp(b,c));
        kraw[b].pb(mp(a,c));
    }
    return 0;
}
