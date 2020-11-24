#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200009
#define MOD 1000000007


using namespace std;


int dfs(int from,lld mini1,lld mini2, lld mini3, lld mini4){

}

int main()
{
    canf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&wag[i]);
    }
    while(kk<n)kk<<=1;
    for(int i=0;i<n-1;++i){
        scanf("%lld%lld%lld",&a,&b,&c);
        kraw[a].pb(mp(b,c));
        kraw[b].pb(mp(a,c));
    }
    for(int i=0;i<n;++i){
        tree[kk+i].s.s=i;
    }
    for(int i=kk+n;i<2*kk;++i){
        add(1,i,i,0,kk-1,INF);
    }
    dfs(1,1,0);

    return 0;
}
