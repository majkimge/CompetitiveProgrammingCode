#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1100000
#define pii pair<int,int>

using namespace std;

int n,a,b,m;
vector<int> kraw[MAX];
int odw[MAX];
int gl[MAX];
int low[MAX];
int oczy[MAX];
int rep[MAX];


int Find(int x){
    if(x!=rep[x])rep[x]=Find(rep[x]);
    return rep[x];
}

int Union(int x,int y){
    int rx=Find(x);
    int ry=Find(y);
    if(rx!=ry){
        rep[rx]=ry;
    }
}

void dfs(int gdz,int ojc,int gleb){
    odw[gdz]=1;
    gl[gdz]=gleb;
    oczy[gdz]=ojc;
    low[gdz]=gleb;
    for(int i=0;i<kraw[gdz].size();++i){
        if(!odw[kraw[gdz][i]]){
            dfs(kraw[gdz][i],gdz,gleb+1);
        }
    }
    for(int i=0;i<kraw[gdz].size();++i){
        if(ojc!=kraw[gdz][i]){
            low[gdz]=min(low[gdz],low[kraw[gdz][i]]);
        }
    }
}

void dfsdwu(int gdz,int ojc,int gleb){
    odw[gdz]=1;
    for(int i=0;i<kraw[gdz].size();++i){
        if(!odw[kraw[gdz][i]]){
            dfsdwu(kraw[gdz][i],gdz,gleb+1);
        }
    }
    if(low[gdz]<gl[ojc])Union(gdz,ojc);
}






int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        rep[i]=i;
    }
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        kraw[a].pb(b);
        kraw[b].pb(a);
    }
    dfs(1,1,0);
    for(int i=1;i<=n;++i){
        odw[i]=0;
    }
    dfsdwu(1,1,0);
    for(int i=1;i<=n;++i){
        printf("%d ",Find(i));
    }
    return 0;
}
