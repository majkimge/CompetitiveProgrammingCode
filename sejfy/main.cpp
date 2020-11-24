#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 3009
#define piii pair<lld,pair<lld,lld> >
#define INF 1000000000

using namespace std;

lld n,s,t,fl,wyn;
lld lud[MAX];
lld sejf[MAX];
piii kraw[MAX];
queue<int> q;
int vis[MAX];
lld d[MAX];
lld from[MAX];

void SPFA(){
    while(!q.empty()){
        int ter=q.front();
        q.pop();
        vis[ter]=0;
        for(int i=0;i<kraw[ter].size();++i){
            if(d[kraw[ter][i].s.s]>d[ter]+kraw[ter][i].f){
                d[kraw[ter][i].s.s]=d[ter]+kraw[ter][i].f;
                from[kraw[ter][i].s.s]=ter;
                if(!vis[kraw[ter][i].s.s]){
                    q.push(kraw[ter][i].s.s);
                    vis[kraw[ter][i].s.s]=1;
                }
            }
        }
    }
}

void flow(){
    for(int i=0;i<MAX;++i){
        d[i]=INF;
    }
    d[s]=0;
    q.push(s);
    SPFA();


}

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&lud[i]);
    }

    for(int i=0;i<n;++i){
        scanf("%lld",&sejf[i]);
    }
    s=2002;
    t=2004;
    for(int i=0;i<n;++i){
        kraw[s].pb(mp(1,mp(sejf[i],i)));
        kraw[i].pb(mp(0,mp(lud[i],1000+i)));
        kraw[i].pb(mp(0,mp(lud[(i+1)%n],1000+(i+1)%n));
        kraw[1000+i].pb(mp(0,mp(lud[i],t)));

        //powrotne
        kraw[i].pb(mp(-1,mp(0,s)));
        kraw[1000+i].pb(mp(0,mp(0,i)));
        kraw[1000+(i+1)%n].pb(mp(0,mp(0,i));
        kraw[t].pb(mp(0,mp(0,1000+i)));

    }
    return 0;
}
