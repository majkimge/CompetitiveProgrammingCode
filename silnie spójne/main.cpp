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


    for(int i=1;i<=n;++i){
        if(!odw[i])dfstopo(i);
    }
    for(int i=n-1;i>=0;--i){
        if(odw[topo[i]]<2){
            dfsss(topo[i]);
            iless++;
        }
    }
    for(int i=0;i<iless;++i){
        for(int j=0;j<sss[i].size();++j){
            for(int p=0;p<kraw[sss[i][j]].size();++p){
                if(wsss[sss[i][j]]!=wsss[kraw[sss[i][j]][p].f]){
                    sskraw[i].pb(wsss[kraw[sss[i][j]][p].f]);
                }
            }
        }
    }

    for(int i=0;i<iless;++i){
        if(odw[i]<3){
            dfstoposs(i);
        }
    }

    topo.clear();

    printf("%d\n",topo.size());
    for(int i=0;i<topo.size();++i){
        printf("%d ",topo[i]);
    }
    return 0;
}
