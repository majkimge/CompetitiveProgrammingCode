#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define MOD 1000000007
#define INF 1000696969

using namespace std;

lld odl[2009][2009],wynik;
lld wag[2009],a,b,c;
int rep[2009];
int odw[2009];
vector<pair<lld,lld> >kraw[2009];
int n;
vector<pair<lld,pair<lld,lld> > > v;

int Find(int x){
    if(rep[x]!=x)rep[x]=Find(rep[x]);
    return rep[x];
}

int Union(int x, int y, int xd){
    int rx=Find(x);
    int ry=Find(y);

    if(rx!=ry){
            //cout<<x<<" "<<y<<" "<<xd<<endl;
        wynik+=xd;
        rep[rx]=ry;
    }
}

int dfs(int from, int od, int ter){
    odl[od][from]=ter;
    odw[from]=od;
    for(int i=0;i<kraw[from].size();++i){
        if(odw[kraw[from][i].f]!=od){
            dfs(kraw[from][i].f,od,ter+kraw[from][i].s);
        }
    }
}


int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&wag[i]);
    }
    for(int i=0;i<n-1;++i){
        scanf("%lld%lld%lld",&a,&b,&c);
        kraw[a].pb(mp(b,c));
        kraw[b].pb(mp(a,c));
    }

    for(int i=1;i<=n;++i){
        dfs(i,i,0);
    }
    for(int i=1;i<=n;++i){
        rep[i]=i;
        for(int j=1;j<=n;++j){
            //cout<<i<<" "<<j<<" "<<odl[i][j]<<endl;
            if(i!=j){
                v.pb(mp(wag[i]+wag[j]+odl[i][j],mp(i,j)));
            }
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i){

        Union(v[i].s.f,v[i].s.s,v[i].f);
    }
    printf("%lld",wynik);
    return 0;
}
