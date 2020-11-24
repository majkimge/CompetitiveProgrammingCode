#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define s second
#define f first
#define MAX 2000209
#define INF 1000000000
#define pb push_back
#define pii pair<int,char>

using namespace std;

int n,m,a,b,c;
vector<pii> kraw[MAX/2];

vector<int> satkraw[MAX];
//vector<int> odwsatkraw[MAX];
vector<int> topo;
vector<int> sss[MAX];
vector<int> sskraw[MAX];
int wsss[MAX];
int wsk[MAX/2];
char wart[MAX];
char odw[MAX];
int iless;
//vector<int> wyniki;

void dfstopo(int gdz){
    odw[gdz]=1;
    for(int i=0;i<satkraw[gdz].size();++i){
        if(!odw[satkraw[gdz][i]]){
            dfstopo(satkraw[gdz][i]);
        }
    }
    topo.pb(gdz);
}

void dfsss(int gdz){
    odw[gdz]=2;
    sss[iless].pb(gdz);
    wsss[gdz]=iless;
    for(int i=0;i<satkraw[gdz].size();++i){
        if(odw[satkraw[gdz][i]]<2){
            dfsss(satkraw[gdz][i]);
        }
    }
}

void dfstoposs(int gdz){
    odw[gdz]=3;
    for(int i=0;i<sskraw[gdz].size();++i){
        if(odw[sskraw[gdz][i]]<3){
            dfstoposs(sskraw[gdz][i]);
        }
    }
    topo.pb(gdz);
}

void ustaw(int gdz, int czyk){
    odw[gdz]=4;
    int jaki=0;
    for(int i=0;i<sss[gdz].size();++i){
        jaki=wart[sss[gdz][i]^1];
    }
    if(jaki==1||czyk){
        for(int i=0;i<sss[gdz].size();++i){
            wart[sss[gdz][i]]=2;
        }
        czyk=1;
    }else{

            for(int i=0;i<sss[gdz].size();++i){
                wart[sss[gdz][i]]=1;
            }

    }
    for(int i=0;i<sskraw[gdz].size();++i){
        if(odw[sskraw[gdz][i]]<4){
            ustaw(sskraw[gdz][i],czyk);
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&a,&b,&c);
        //a=i+1;
        //b=i+2;
        //c=1;
        kraw[a].pb(mp(b,c));
        kraw[b].pb(mp(a,c));
    }
    int licz=0;
    for(int i=1;i<=n+1;++i){
        wsk[i]=licz;
        licz+=2;
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<kraw[i].size();++j){
            if(kraw[i][j].s){
                satkraw[wsk[i]].pb(wsk[kraw[i][j].f]);
                satkraw[wsk[i]^1].pb(wsk[kraw[i][j].f]^1);
            }else{
                satkraw[wsk[i]].pb(wsk[kraw[i][j].f]^1);
                satkraw[wsk[i]^1].pb(wsk[kraw[i][j].f]);
            }
        }
    }

    for(int i=0;i<wsk[n+1];++i){
        if(!odw[i])dfstopo(i);
    }
    for(int i=wsk[n+1]-1;i>=0;--i){
        if(odw[topo[i]]<2){
            dfsss(topo[i]);
            iless++;
        }
    }
    for(int i=0;i<iless;++i){
        for(int j=0;j<sss[i].size();++j){
            for(int p=0;p<satkraw[sss[i][j]].size();++p){
                if(wsss[sss[i][j]]!=wsss[satkraw[sss[i][j]][p]]){
                    sskraw[i].pb(wsss[satkraw[sss[i][j]][p]]);
                }
            }
        }
    }
    for(int i=0;i<MAX;++i){
        satkraw[i].clear();
    }
    for(int i=1;i<=n;++i){
        kraw[i].clear();

        if(wsss[wsk[i]]==wsss[wsk[i]^1]){
            printf("NIE");
            return 0;
        }
    }
    topo.clear();
    for(int i=0;i<iless;++i){
        if(odw[i]<3){
            dfstoposs(i);
        }
    }
    for(int i=iless-1;i>=0;--i){
        if(odw[topo[i]]<4){
            ustaw(topo[i],0);
        }
    }
    topo.clear();
    for(int i=1;i<=n;++i){
        if(wart[wsk[i]]==2){
            topo.pb(i);
        }
    }
    printf("%d\n",topo.size());
    for(int i=0;i<topo.size();++i){
        printf("%d ",topo[i]);
    }
    return 0;
}
