#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200009
#define pii pair<int,int>

using namespace std;

vector<int> sss[MAX];
int n,m,a,b;
int wsss[MAX];
vector<int> topo;
vector<int> kraw[MAX];
vector<int> odwkraw[MAX];
vector<int> skraw[MAX];
int odw[MAX];
int wynik,ilesss,ilekomp;

void clearodw(){
    for(int i=0;i<MAX;++i){
        odw[i]=0;
    }
}

void dfstopo(int gdz){
    odw[gdz]=1;
    for(int i=0;i<kraw[gdz].size();++i){
        if(odw[kraw[gdz][i]]<1){
            dfstopo(kraw[gdz][i]);
        }

    }
    topo.pb(gdz);
}

void dfsss(int gdz){
    odw[gdz]=1;
    wsss[gdz]=ilesss;
    sss[ilesss].pb(gdz);
    for(int i=0;i<odwkraw[gdz].size();++i){
        if(odw[odwkraw[gdz][i]]<1){
            dfsss(odwkraw[gdz][i]);
        }

    }
}

void dfsstopo(int gdz){
    odw[gdz]=1;
    for(int i=0;i<skraw[gdz].size();++i){
        if(odw[skraw[gdz][i]]<1){
            dfsstopo(skraw[gdz][i]);
        }

    }
    topo.pb(gdz);
}

int dfswyn(int gdz){
    odw[gdz]=1;
    int ret=0;
    int ile=0;
    for(int i=0;i<skraw[gdz].size();++i){
        if(odw[skraw[gdz][i]]<1){
            ret+=dfswyn(skraw[gdz][i]);
            ++ile;
        }

    }
    ret+=(skraw[gdz].size()==0);
    return ret;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        if(a!=b){
            kraw[a].pb(b);
            odwkraw[b].pb(a);
        }

    }
    for(int i=1;i<=n;++i){
        if(!odw[i])dfstopo(i);
    }
    clearodw();
    for(int i=topo.size()-1;i>=0;--i){
        if(!odw[topo[i]]){
            dfsss(topo[i]);
            ilesss++;
        }
    }
    clearodw();
    for(int i=0;i<ilesss;++i){
        for(int j=0;j<sss[i].size();++j){
            for(int z=0;z<kraw[sss[i][j]].size();++z){
                if(wsss[sss[i][j]]!=wsss[kraw[sss[i][j]][z]]){
                    skraw[i].pb(wsss[kraw[sss[i][j]][z]]);
                }
            }
        }
    }
    topo.clear();
    for(int i=0;i<ilesss;++i){
        if(!odw[i])dfsstopo(i);
    }
    clearodw();
    for(int i=topo.size()-1;i>=0;--i){
        //cout<<sss[topo[i]][0]<<" ";
        if(!odw[topo[i]]){
            wynik+=dfswyn(topo[i])-1;
            ilekomp++;
        }
    }
    //cout<<wynik;
    if(ilekomp==1&&ilesss==1){
        printf("%d",wynik);
    }else{
        printf("%d",wynik+ilekomp);
    }

    return 0;
}

/*
12 14
4 6
4 7
6 5
7 1
1 9
1 2
3 8
3 10
7 3
6 1
1 5
4 5
3 5
1 4


5 7
5 4
5 3
5 2
5 1
1 2
3 4
2 3


4 9
1 2
4 3
1 3
3 4
2 1
1 4
2 3
2 4
4 2
*/
