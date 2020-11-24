#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 300009

using namespace std;

int n,m,rep[MAX],a,b,c;

int wlk[MAX];

vector<pair<int,int> >kraw[MAX];

pair<int, pair<int,int> >krawy[MAX*3];

int maxi,mini;

int Find(int x){
    if(rep[x]!=x)rep[x]=Find(rep[x]);
    return rep[x];
}

int Union(int x, int y){
    int rx=Find(x);
    int ry=Find(y);
    if(wlk[ry]<wlk[rx])swap(ry,rx);
    if(rx!=ry){
        rep[rx]=ry;
        wlk[ry]+=wlk[rx];
        return 1;
    }
    return 0;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&a,&b,&c);
        kraw[a].pb(mp(b,c));
        kraw[b].pb(mp(a,c));
        krawy[i]=mp(c,mp(a,b));
    }
    sort(krawy,krawy+m);

    for(int i=1;i<=n;++i){
        rep[i]=i;
        wlk[i]=1;
    }
    for(int i=0;i<m;++i){
        mini+=(Union(krawy[i].s.f,krawy[i].s.s))*krawy[i].f;
    }

    for(int i=1;i<=n;++i){
        rep[i]=i;
        wlk[i]=1;
    }
    for(int i=m-1;i>=0;--i){
        maxi+=(Union(krawy[i].s.f,krawy[i].s.s))*krawy[i].f;
    }

    printf("%d",maxi-mini+1);
    return 0;
}
