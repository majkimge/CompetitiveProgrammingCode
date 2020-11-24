#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lld uint16_t
#define MAX 1000009

using namespace std;

int n,m,a,b,kt,maxi;
vector<int> kraw[MAX];
bool czym[MAX];
vector<int> odwkraw[MAX];
//vector<int> krawsss[MAX];
vector<int> sss[MAX];
vector<int> topo;
int wsss[MAX];
char odw[MAX];
bool czymsss[MAX];
int wyny[MAX];

void dfs(int from){
    odw[from]=1;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            dfs(kraw[from][i]);
        }
    }
    topo.pb(from);
}

void dfs1(int from){
    odw[from]=2;
    if(czym[from])czymsss[kt]=1;
    sss[kt].pb(from);
    wsss[from]=kt;
    for(int i=0;i<odwkraw[from].size();++i){
        if(odw[odwkraw[from][i]]<2){
            dfs1(odwkraw[from][i]);
        }
    }
}
void dfs3(int from){
    odw[from]=3;
    //int wyn=0;
    for(int i=0;i<odwkraw[from].size();++i){
        if(odw[odwkraw[from][i]]<3){
            dfs3(odwkraw[from][i]);
        }
        wyny[from]+=wyny[odwkraw[from][i]];
    }
    if(wsss[n+1]==from)wyny[from]++;
    if(wyny[from]&&(czymsss[from]||sss[from].size()>1||wyny[from]>36500))wyny[from]=36501;
    //wyny[from]=wyn;
    //return wyny[from];
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        if(a==b){
            czym[a]=1;
        }else{
            kraw[a].pb(b);
            odwkraw[b].pb(a);
        }
    }
    for(int i=1;i<=n+1;++i){
        if(!odw[i])dfs(i);
    }
    for(int i=topo.size()-1;i>=0;--i){
        if(odw[topo[i]]<2){
            dfs1(topo[i]);
            kt++;
        }
    }
    for(int i=1;i<=n+1;++i){
        odwkraw[i].clear();
    }
    for(int i=0;i<kt;++i){
        for(int j=0;j<sss[i].size();++j){
            for(int z=0;z<kraw[sss[i][j]].size();++z){
                if(wsss[kraw[sss[i][j]][z]]!=i){
                    odwkraw[i].pb(wsss[kraw[sss[i][j]][z]]);
                }
            }
            kraw[sss[i][j]].clear();
        }
    }
    /*for(int i=1;i<=n+1;++i){
        cout<<wsss[i];
    }*/
    for(int i=0;i<kt;++i){
        if(odw[i]<3)dfs3(i);
    }
    for(int i=0;i<kt;++i){
        maxi=max(maxi,wyny[i]);
    }
    topo.clear();
    for(int i=0;i<kt;++i){
        if(wyny[i]==maxi){
            for(int j=0;j<sss[i].size();++j){
                if(sss[i][j]!=n+1)topo.pb(sss[i][j]);
            }
        }
    }
    sort(topo.begin(),topo.end());
    if(topo.size()==0){
        printf("0\n0");
    }else{
        if(maxi>36500){
            printf("zawsze\n");
        }else{
            printf("%d\n",maxi);
        }
        printf("%d\n",topo.size());
        for(int i=0;i<topo.size();++i){
            printf("%d ",topo[i]);
        }
    }


    return 0;
}
/*
4 4
4 3
3 4
1 2
2 3
*/
