#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lld uint16_t
#define MAX 250009


using namespace std;



int n, m,a,b;
vector<int> kraw[MAX];
vector<int> odwkraw[MAX];
vector<int> topo;
int wsss[MAX];

bool czyp[MAX];
vector<int> sss[MAX];
short odw[MAX];
int xd,kt=0;
lld wyny[MAX];
lld maxi;
int ile,cel;

void dfs(int from){
    odw[from]=1;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            dfs(kraw[from][i]);
        }
    }
    topo.pb(from);
}

bool dfs2(int from){
    odw[from]=2;
    bool ret=0;
    if(from==n+1){
        ret=1;
    }
    for(int i=0;i<kraw[from].size();++i){
        if(odw[kraw[from][i]]<2){
            ret=(ret|dfs2(kraw[from][i]));
        }
    }
    if(!ret)czyp[from]=0;
    return ret;
}


void dfs3(int from){
    odw[from]=3;
    wsss[from]=kt;
    if(czyp[from])wyny[kt]=35001;
    if(from==n+1){
        wyny[kt]=(lld)max(wyny[kt],(lld)1);
        cel=kt;
    }
    sss[kt].pb(from);
    for(int i=0;i<odwkraw[from].size();++i){
        if(odw[odwkraw[from][i]]<3){
            dfs3(odwkraw[from][i]);
        }
    }
}

bool dfs4(int from){
    odw[from]=4;
    bool ret=0;
    if(from==cel){
        ret=1;
    }
    for(int i=0;i<odwkraw[from].size();++i){
        if(odw[odwkraw[from][i]]<4){
            ret=(ret|dfs4(odwkraw[from][i]));
        }
    }
    if(ret&&sss[from].size()>1){
            wyny[from]=(lld)35001;
            //cout<<"A";
    }
    return ret;
}

void dfs5(int from){
    odw[from]=5;
    //int wyn=wyny[from];
    for(int i=0;i<odwkraw[from].size();++i){
        if(odw[odwkraw[from][i]]==5){
            //wyn+=wyny[odwkraw[from][i]];
            if(wyny[odwkraw[from][i]]>=35001-wyny[from]||wyny[from]>35000){
                wyny[from]=35001;

            }else{
                wyny[from]+=wyny[odwkraw[from][i]];
            }
        }else {
            dfs5(odwkraw[from][i]);
            if(wyny[odwkraw[from][i]]>=35001-wyny[from]||wyny[from]>35000){
                wyny[from]=35001;//cout<<"A";
            }else{
                wyny[from]+=wyny[odwkraw[from][i]];
            }
        }
    }
    //wyny[from]=wyn;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        if(a==b){
            czyp[a]=1;
            if(a==n+1)xd=1;
        }else{
            kraw[a].pb(b);
            odwkraw[b].pb(a);
        }

    }

    for(int i=1;i<=n+1;++i){
        if(!odw[i])dfs(i);
    }
    for(int i=1;i<=n+1;++i){
        if(odw[i]<2)dfs2(i);
    }
    for(int i=topo.size()-1;i>=0;--i){
        if(odw[topo[i]]<3){
            dfs3(topo[i]);
            kt++;
        }
    }
    for(int i=0;i<=n+1;++i){
        odwkraw[i].clear();
    }

    for(int i=0;i<kt;++i){
        for(int j=0;j<sss[i].size();++j){
            for(int z=0;z<kraw[sss[i][j]].size();++z){
                if(wsss[sss[i][j]]!=wsss[kraw[sss[i][j]][z]]){
                    odwkraw[i].pb(wsss[kraw[sss[i][j]][z]]);
                }
            }
        }
    }
    for(int i=0;i<=n+1;++i){
        kraw[i].clear();
    }

    for(int i=0;i<kt;++i){
        if(odw[i]<4){
            dfs4(i);
        }
    }

    //for(int i=0;i<kt;++i)cout<<wyny[i]<<endl;
    for(int i=0;i<kt;++i){
        if(odw[i]<5){
            dfs5(i);
        }
    }
    topo.clear();
    for(int i=0;i<kt;++i){
        if(wyny[i]>maxi){
            topo.clear();
            for(int j=0;j<sss[i].size();++j){
                topo.pb(sss[i][j]);
            }
            maxi=wyny[i];
        }else if(wyny[i]==maxi){
            for(int j=0;j<sss[i].size();++j){
                topo.pb(sss[i][j]);
            }
        }
    }
    if(maxi>35000){
        printf("zawsze\n");
    }else{
        printf("%d\n",maxi);
    }
    sort(topo.begin(),topo.end());
    printf("%d\n",topo.size());
    for(int i=0;i<topo.size();++i){
        printf("%d ",topo[i]);
    }
    return 0;
}
