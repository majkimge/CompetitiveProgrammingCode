#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 10000
#define INF 100000000

using namespace std;

struct edge
{
    lld a,b,cap,flow;
};

vector<edge>e;
vector<int>v[MAX];
queue<int>q;
int d[MAX],ptr[MAX];
int n,s,t,m,aa,bb,w;

void addEdge(lld a,lld b,lld cap){
    edge e1={a,b,cap,0};
    edge e2={b,a,0,0};
    v[a].pb(e.size());
    e.pb(e1);
    v[b].pb(e.size());
    e.pb(e2);
}

bool bfs(){
    for(int i=1;i<=n;++i) d[i]=-1;
    q.push(s);
    d[s]=0;
    while(!q.empty()&&d[t]==-1){
        int from=q.front();
        q.pop();
        for(int i=0;i<v[from].size();++i){
            int id=v[from][i];
            int to=e[id].b;
            if(d[to]==-1&&e[id].flow<e[id].cap){
                d[to]=d[from]+1;
                q.push(to);
            }
        }
    }
    while(!q.empty()) q.pop();
    return d[t]!=-1;
}

lld dfs(int from,lld flow){
    if(flow==0) return 0;
    if(from==t) return flow;

    for(;ptr[from]<v[from].size();ptr[from]++){
        int id=v[from][ptr[from]];
        int to=e[id].b;
        if(d[to]!=d[from]+1) continue;
        int pushed=dfs(to,min(flow,(int)e[id].cap-e[id].flow));
        if(pushed>0){
            e[id].flow+=pushed;
            e[id^1].flow-=pushed;
            return pushed;
        }

    }
    return 0;
}

lld dinic(){
    int fl=0;
    for(;;){
        //cout<<"A";
        if(!bfs())break;
        for(int i=1;i<=n;++i) ptr[i]=0;
        while(int pushed=dfs(s,INF))fl+=pushed;
    }
    return fl;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d",&aa,&bb);
        addEdge(aa,bb,1);
    }
    //scanf("%d%d",&s,&t);
    s=1;
    t=n;
    int yeah=dinic();
    printf("%d",yeah);
    return 0;
}
/*
5 5
1 2
1 3
2 4
3 4
4 5
*/
