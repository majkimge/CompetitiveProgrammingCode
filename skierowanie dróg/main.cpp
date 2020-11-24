#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 100009

using namespace std;

int n,m,p,a,b;
pair<int,pair<int,int> > zapy[MAX];
vector<pair<int,int> > kraw[MAX], dwukraw[MAX];
int rep[MAX],gl[MAX],low[MAX],odw[MAX],dwugl[MAX],dwuojc[MAX],dwuodw[MAX];
vector<int> korz[MAX];
int czykorz[MAX];
int ojc[MAX];
int iledwu;
pair<int,int> krawy[MAX];
int dwu[MAX];
int dokus[MAX];
int LCA[MAX][30];

int odwu[MAX];
int wyn[MAX];
int wynik[MAX];

int Find(int x){
    if(rep[x]!=x)rep[x]=Find(rep[x]);
    return rep[x];
}

int Union(int x, int y){
    int rx=Find(x);
    int ry=Find(y);
    if(rx!=ry){
        rep[rx]=ry;
    }
}



void dfs(int gdz, int gleb,int oczy){
    odw[gdz]=1;
    gl[gdz]=gleb;
    low[gdz]=gleb;
    ojc[gdz]=oczy;
    for(int i=0;i<kraw[gdz].size();++i){
        if(!odw[kraw[gdz][i].f]){
            dfs(kraw[gdz][i].f,gleb+1,gdz);
        }
    }
    int ilej=0;
    for(int i=0;i<kraw[gdz].size();++i){
        if(ojc[gdz]!=kraw[gdz][i].f||ilej>0){
            low[gdz]=min(low[gdz],low[kraw[gdz][i].f]);
        }else{
            ++ilej;
        }
    }
}

void dwudfs(int gdz, int gleb, int oczy){
    dwuodw[gdz]=1;
    dwugl[gdz]=gleb;
    dwuojc[gdz]=oczy;
    dwu[iledwu]=gdz;
    ++iledwu;
    for(int i=0;i<dwukraw[gdz].size();++i){
        if(!dwuodw[dwukraw[gdz][i].f]){
            dwudfs(dwukraw[gdz][i].f,gleb+1,gdz);
        }
    }
}

int skoczdogl(int z, int dok){
    int ite=29;
    while(ite>=0&&dwugl[LCA[z][ite]]>dok){
        z=LCA[z][ite];
        --ite;
    }
    if(dwugl[z]!=dok){
        z=LCA[z][0];
    }
    return z;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        kraw[a].pb(mp(b,i));
        kraw[b].pb(mp(a,i));
        krawy[i]=mp(a,b);
    }
    scanf("%d",&p);
    for(int i=0;i<p;++i){
        scanf("%d%d",&a,&b);
        zapy[i]=mp(0,mp(a,b));
    }
    for(int i=1;i<=n;++i){
        rep[i]=i;
        if(!odw[i]){
            dfs(i,0,0);
        }
    }
    for(int i=1;i<=n;++i){
        if(gl[i]>low[i]&&ojc[i])Union(i,ojc[i]);
    }
    //for(int i=1;i<=n;++i)cout<<Find(i);
    for(int i=0;i<m;++i){
        if(Find(krawy[i].f)!=Find(krawy[i].s)){
            dwukraw[Find(krawy[i].f)].pb(mp(Find(krawy[i].s),i));
            dwukraw[Find(krawy[i].s)].pb(mp(Find(krawy[i].f),i));
        }
    }
    for(int i=1;i<=n;++i){
        if(!dwuodw[Find(i)]){
            dwudfs(Find(i),0,0);
        }
    }
    for(int i=0;i<iledwu;++i){
        //cout<<dwuojc[dwu[i]];
        LCA[dwu[i]][0]=dwuojc[dwu[i]];
    }
    for(int i=1;i<30;++i){
        for(int j=1;j<iledwu;++j){
            LCA[dwu[j]][i]=LCA[LCA[dwu[j]][i-1]][i-1];
        }
    }
    //cout<<LCA[4][4];
    for(int xd=0;xd<p;++xd){
        int aa=Find(zapy[xd].s.f);
        int bb=Find(zapy[xd].s.s);

        if(aa==bb){
            zapy[xd]=mp(0,mp(0,0));
            continue;
        }
        //cout<<aa<<" "<<bb<<endl;
        int a1=aa;
        int b1=bb;
        int ite=29;
        while(ite>=0){
            if(dwugl[LCA[a1][ite]]>dwugl[b1]){
                a1=LCA[a1][ite];
            }
            --ite;
        }
        if(dwugl[a1]>dwugl[b1])a1=dwuojc[a1];
        ite=29;
        while(ite>=0){
            if(dwugl[LCA[b1][ite]]>dwugl[b1]){
                b1=LCA[b1][ite];
            }
            --ite;
        }

        if(dwugl[b1]>dwugl[a1])b1=dwuojc[b1];
       // cout<<dwugl[b1]<<" "<<LCA[7][1];
        ite=29;
        while(ite>=0){
            if(LCA[a1][ite]!=LCA[b1][ite]){
                a1=LCA[a1][ite];
                b1=LCA[b1][ite];
            }
            --ite;
        }
        if(a1!=b1){
            a1=LCA[a1][0];
        }
        //cout<<dwugl[5];
        zapy[xd]=mp(dwugl[a1],mp(aa,bb));
    }
    sort(zapy,zapy+p);
    for(int i=0;i<p;++i){
        int aa=zapy[i].s.f;
        int bb=zapy[i].s.s;
        if(aa==bb)continue;
        int lca=zapy[i].f;
        //cout<<aa<<" "<<bb;
        while(!odwu[aa]&&dwugl[aa]>lca){
            wyn[aa]=1;
            odwu[aa]=1;
            aa=LCA[aa][0];
        }
        while(!odwu[bb]&&dwugl[bb]>lca){
            wyn[bb]=2;
            odwu[bb]=2;
            bb=LCA[bb][0];
        }
    }
    //cout<<wyn[5];
    for(int i=0;i<iledwu;++i){
        if(wyn[dwu[i]]){
            //cout<<dwu[i];
            for(int j=0;j<dwukraw[dwu[i]].size();++j){
                if(dwukraw[dwu[i]][j].f==dwuojc[dwu[i]]){
                    if(Find(krawy[dwukraw[dwu[i]][j].s].f)==dwu[i]){
                        if(wyn[dwu[i]]==1){
                            wynik[dwukraw[dwu[i]][j].s]=1;
                        }else{
                            wynik[dwukraw[dwu[i]][j].s]=2;
                        }
                    }else{
                        if(wyn[dwu[i]]==1){
                            wynik[dwukraw[dwu[i]][j].s]=2;
                        }else{
                            wynik[dwukraw[dwu[i]][j].s]=1;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<m;++i){
        if(wynik[i]==0){
            printf("B");
        }else if(wynik[i]==1){
            printf("R");
        }else{
            printf("L");
        }
    }
    return 0;
}
/*
14 14
1 2
1 5
5 6
2 4
2 3
4 7
1 2
8 9
8 12
12 13
9 11
9 10
11 14
8 9
4
7 5
3 1
14 12
10 8
*/
