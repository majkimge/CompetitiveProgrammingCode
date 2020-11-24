#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 50009
#define MOD 1000000009

using namespace std;

int n,m,p,t,a,b,c,d,e,f;
vector<pair<int,pair<pair<int,int>,pair<int,int> > > >kraw[MAX];
vector<pair<pair<pair<int,int>,pair<int,int> >,int > >odwkraw[MAX];

int dfs(int od,int wart){

}

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        scanf("%d",&d);
        scanf("%d",&e);
        scanf("%d",&f);
        kraw[a].pb(mp(b,mp(mp(c,d),mp(e,f))));
        odwkraw[b].pb(mp(mp(mp(e,f),mp(c,d)),a));
    }
    for(int i=1;i<=n;++i){
        sort(kraw[i].begin(),kraw[i].end());
    }
    return 0;
}
