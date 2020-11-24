#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 20009
#define INF 1000000
#define MOD 1000000009

using namespace std;

int a,b,n,m,x,y,z;
int odl[109][209];
vector<pair<pair<int,int>,int> >kraw[109][209];
pair<int,int> ojc[109][209];
priority_queue<pair<pair<int,int>,int> >q;
vector<pair<pair<int,int>,pair<int,int> > >wyniki;

void dijkstra(){
    while(!q.empty()){
        int from=q.top().s;
        int dz = -q.top().f.f;
        int gdz = -q.top().f.s;
        q.pop();
        if(odl[from][dz]==gdz){
            for(int i=0;i<kraw[from][dz].size();++i){
                if(gdz+kraw[from][dz][i].s<=12&&gdz+kraw[from][dz][i].s<odl[kraw[from][dz][i].f.f][kraw[from][dz][i].f.s]){
                    if(kraw[from][dz][i].f.s==dz){
                        odl[kraw[from][dz][i].f.f][kraw[from][dz][i].f.s]=gdz+kraw[from][dz][i].s;
                        q.push(mp(mp(-dz,-odl[kraw[from][dz][i].f.f][kraw[from][dz][i].f.s]),kraw[from][dz][i].f.f));
                        ojc[kraw[from][dz][i].f.f][dz]=mp(from,kraw[from][dz][i].s);
                    }else{
                        odl[kraw[from][dz][i].f.f][kraw[from][dz][i].f.s]=0;
                        q.push(mp(mp(-dz-1,0),kraw[from][dz][i].f.f));
                        ojc[kraw[from][dz][i].f.f][dz+1]=mp(from,kraw[from][dz][i].s);
                    }

                }
            }
        }
    }
}

int main()
{
    scanf("%d%d",&a,&b);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&x,&y,&z);
        for(int j=0;j<208;++j){
            if(j%2==0){
                kraw[x][j].pb(mp(mp(y,j),z));
            }else{
                kraw[y][j].pb(mp(mp(x,j),z));
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<208;++j){
            odl[i][j]=INF;
            kraw[i][j].pb(mp(mp(i,j+1),0));
        }
    }
    odl[a][0]=0;
    q.push(mp(mp(0,0),a));
    dijkstra();
    int dzion=0;
    for(int i=0;i<204;++i){
        if(odl[b][i]<204){
            dzion=i;
            break;
        }
    }
    int gdzie=b;
    while(gdzie!=a){
        int jd=dzion;
        while(ojc[gdzie][dzion].f==gdzie) dzion--;
        //printf("%d %d %d %d\n",ojc[gdzie][dzion].f,gdzie,dzion,ojc[gdzie][dzion].s);
        wyniki.pb(mp(mp(ojc[gdzie][dzion].f,gdzie),mp(dzion+1,ojc[gdzie][dzion].s)));
        gdzie=ojc[gdzie][dzion].f;
    }
    for(int i=wyniki.size()-1;i>=0;--i){
        printf("%d %d %d %d\n",wyniki[i].f.f,wyniki[i].f.s,wyniki[i].s.f,wyniki[i].s.s);
    }
    return 0;
}

/*
1 3
6 7
1 2 9
1 6 2
1 5 10
5 4 1
4 6 2
4 3 4
2 3 5
*/
