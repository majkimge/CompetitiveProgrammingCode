#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define s second
#define f first
#define MAX 1000000
#define INF 1000000000
#define pb push_back

using namespace std;

int n,m,a,b,c,ss,t;
vector<pair<int,int > >kraw[MAX];
queue<int> q;
int d[MAX];
int vis[MAX];
int from[MAX];

void SPFA(){
    while(!q.empty()){
        int ter=q.front();
        q.pop();
        vis[ter]=0;
        for(int i=0;i<kraw[ter].size();++i){
            if(d[kraw[ter][i].s]>d[ter]+kraw[ter][i].f){
                d[kraw[ter][i].s]=d[ter]+kraw[ter][i].f;
                from[kraw[ter][i].s]=ter;
                if(!vis[kraw[ter][i].s])q.push(kraw[ter][i].s);
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&ss,&t);
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&a,&b,&c);
        kraw[a].pb(mp(c,b));
    }
    for(int i=1;i<=n;++i){
        d[i]=INF;
    }
    d[ss]=0;
    q.push(ss);
    SPFA();
    cout<<d[t];
    return 0;
}
