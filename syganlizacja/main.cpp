#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lld long long
#define MAX 10009
#define INF 2000000000

using namespace std;

lld x,y,n,m,a,b,w,g,r;

vector<pair<lld,lld> >kraw[MAX];
pair<lld,lld> syg[MAX];
lld odl[MAX];
lld odw[MAX];
priority_queue<pair<lld,lld> >q;

void dijkstra(lld a1){
    while(!q.empty()){
        pair<lld,lld> ter=q.top();
        ter=mp(-ter.f,ter.s);
        q.pop();
        odw[ter.s]=1;
        if(odl[ter.s]==ter.f){
            for(int i=0;i<kraw[ter.s].size();++i){
                if((ter.f+kraw[ter.s][i].f)%(syg[kraw[ter.s][i].s].f+syg[kraw[ter.s][i].s].s)>=syg[kraw[ter.s][i].s].f&&kraw[ter.s][i].s!=y){
                        if(ter.f+kraw[ter.s][i].f+syg[kraw[ter.s][i].s].s-(ter.f+kraw[ter.s][i].f)%(syg[kraw[ter.s][i].s].f+syg[kraw[ter.s][i].s].s)+syg[kraw[ter.s][i].s].f<odl[kraw[ter.s][i].s]){
                            odl[kraw[ter.s][i].s]=ter.f+kraw[ter.s][i].f+syg[kraw[ter.s][i].s].s-(ter.f+kraw[ter.s][i].f)%(syg[kraw[ter.s][i].s].f+syg[kraw[ter.s][i].s].s)+syg[kraw[ter.s][i].s].f;
                    q.push(mp(-odl[kraw[ter.s][i].s],kraw[ter.s][i].s));
                        }

                }else{
                    if(ter.f+kraw[ter.s][i].f<odl[kraw[ter.s][i].s]){
                        odl[kraw[ter.s][i].s]=ter.f+kraw[ter.s][i].f;
                    q.push(mp(-odl[kraw[ter.s][i].s],kraw[ter.s][i].s));
                    }

                }
            }
        }
    }

}

int main()
{
    scanf("%lld",&x);
    scanf("%lld",&y);
    scanf("%lld",&n);
    scanf("%lld",&m);
    for(int i=0;i<m;++i){
        scanf("%lld",&a);
        scanf("%lld",&b);
        scanf("%lld",&w);
        kraw[a].pb(mp(w,b));
        kraw[b].pb(mp(w,a));
    }
    for(int i=1;i<=n;++i){
        odl[i]=INF;
        scanf("%lld",&g);
        scanf("%lld",&r);
        syg[i]=mp(g,r);
    }
    odl[x]=0;
    q.push(mp(0,x));
    dijkstra(x);
    if(odl[y]!=INF){
        printf("%lld",odl[y]);
    }
    else{
        printf("-1");
    }
    return 0;
}
