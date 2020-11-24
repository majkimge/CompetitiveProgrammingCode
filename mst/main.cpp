#include <bits/stdc++.h>
#define lld int
#define MAX 200009
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000

using namespace std;

lld n,k,m,a,b,w;
lld odl[MAX][6];
lld kk[10];
priority_queue<pair<lld,lld> >q;
vector<pair<lld,lld> >kraw[MAX];
vector<pair<lld,lld> >goodkraw[MAX];
vector<pair<lld,pair<lld,lld> > >krawy;
lld wynik;
lld rep[MAX];


void dijkstra(int od){
    while(!q.empty()){
        int odl1=-q.top().f;
        int vert=q.top().s;
        q.pop();
        if(odl1==odl[vert][od]){
            for(int i=0;i<kraw[vert].size();++i){
                if(odl[kraw[vert][i].s][od]>odl1+kraw[vert][i].f){
                    odl[kraw[vert][i].s][od]=odl1+kraw[vert][i].f;
                    q.push(mp(-odl[kraw[vert][i].s][od],kraw[vert][i].s));
                }
            }
        }

    }

}

int main()
{
    scanf("%d",&n);
    scanf("%d",&k);
    scanf("%d",&m);
    for(int i=0;i<k;++i){
        scanf("%d",&kk[i]);
    }
    for(int i=0;i<m;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&w);
        kraw[a].pb(mp(w,b));
        kraw[b].pb(mp(w,a));
    }
    for(int i=0;i<k;++i){
        for(int j=0;j<=n;++j){
            odl[j][i]=INF;
        }
        odl[kk[i]][i]=0;
        q.push(mp(0,kk[i]));
        dijkstra(i);
    }
    for(int i=0;i<k;++i){
        for(int j=0;j<k;++j){
            if(i!=j){
                for(int z=1;z<=n;++z){
                    goodkraw[kk[i]].pb(mp(odl[z][i]+odl[z][j],kk[j]));
                    goodkraw[kk[j]].pb(mp(odl[z][i]+odl[z][j],kk[i]));
                    krawy.pb(mp(odl[z][i]+odl[z][j],mp(i,j)));
                }
            }
        }
    }
    sort(krawy.begin(),krawy.end());
    for(int i=0;i<krawy.size();++i){
        cout<<krawy[i].f<<" "<<krawy[i].s.f<<" "<<krawy[i].s.s<<endl;
    }
    for(int i=0;i<k;++i){
        rep[kk[i]]=kk[i];
    }
    for(int i=0;i<krawy.size();++i){
        if(rep[krawy[i].s.f]!=rep[krawy[i].s.s]){
            wynik+=krawy[i].f;
            int temp=rep[krawy[i].s.s];
            for(int j=0;j<=k;++j){

                if(temp==rep[j]){
                    rep[j]=rep[krawy[i].s.f];
                }
            }
        }
    }
    printf("%d",wynik);
    return 0;
}
