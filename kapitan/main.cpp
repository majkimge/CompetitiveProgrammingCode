#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009
#define INF 10000000000

using namespace std;

lld n,x,y;
lld tab[MAX][2];
vector<pair<lld,lld> >kraw[MAX];
priority_queue<pair<lld,lld> >q;
lld odl[MAX];

void dijkstra(){
    while(!q.empty()){
        int od=-q.top().f;
        int z=q.top().s;
        q.pop();
        if(od==odl[z]){
            for(int i=0;i<kraw[z].size();++i){
                if(odl[kraw[z][i].s]>od+kraw[z][i].f){
                    odl[kraw[z][i].s]=od+kraw[z][i].f;
                    q.push(mp(-odl[kraw[z][i].s],kraw[z][i].s));
                }
            }
        }
    }


}

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&x);
        scanf("%lld",&y);
        tab[i][0]=x;
        tab[i][1]=y;
        for(int j=1;j<i;++j){
            kraw[i].pb(mp(min(abs(tab[i][0]-tab[j][0]),abs(tab[i][1]-tab[j][1])),j));
            kraw[j].pb(mp(min(abs(tab[i][0]-tab[j][0]),abs(tab[i][1]-tab[j][1])),i));
        }
    }
    for(int i=2;i<=n;++i){
        odl[i]=INF;
    }
    odl[1]=0;
    q.push(mp(0,1));
    dijkstra();
    printf("%lld",odl[n]);
    return 0;
}
