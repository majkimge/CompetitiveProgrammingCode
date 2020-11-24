#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define MAX1 131072


using namespace std;

int LCA[MAX][20];
vector<int> kraw[MAX];
int n,m,a,b,aa,bb;
int rodz[MAX];
int odw[MAX];
int skal[MAX];
map<int,int> ma;
int ett[MAX];
int S[MAX];
int E[MAX];
int calc=1;
int pier=320;
int gleby[MAX];
int wyny[MAX];
int poile[MAX];
int koly[MAX];

vector<pair<pair<int,int>,pair<int,int> > >zapy[320];

void dfs(int from,int gl){
    S[from]=calc;
    ett[calc]=from;
    odw[from]=1;
    calc++;
    gleby[from]=gl;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            LCA[kraw[from][i]][0]=from;
            dfs(kraw[from][i],gl+1);
        }
    }
    E[from]=calc;
    ett[calc]=from;
    calc++;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&rodz[i]);
        skal[i]=rodz[i];
    }
    sort(skal+1,skal+n+1);
    int kt=1;
    for(int i=1;i<=n;++i){
        while(skal[i+1]==skal[i]){
            ++i;
        }
        ma[skal[i]]=kt;
        kt++;
    }
    for(int i=1;i<=n;++i){
        rodz[i]=ma[rodz[i]];
    }

    for(int i=1;i<n;++i){
        scanf("%d%d",&a,&b);
        kraw[a].pb(b);
        kraw[b].pb(a);
    }
    dfs(1,1);
    for(int i=1;i<20;++i){
        for(int j=1;j<=n;++j){
            LCA[j][i]=LCA[LCA[j][i-1]][i-1];
        }
    }
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        //zapy[a/320].pb(mp(a,b));
        if(gleby[a]<gleby[b]) swap(a,b);
        int gdz=a;
        for(int j=19;j>=0;--j){
            if(gleby[LCA[gdz][j]]>=gleby[b]){
                gdz=LCA[gdz][j];
            }
        }
        //cout<<gdz<<" ";
        if(gdz==b){
            //cout<<S[a]<<" "<<S[b]<<" "<<i<<endl;
            zapy[S[b]/320].pb(mp(mp(S[a],S[b]),mp(i,0)));
        }else{
            int lca=0;
            int aa=gdz;
            int bb=b;
            for(int j=19;j>=0;--j){
                if(LCA[aa][j]!=LCA[bb][j]){
                    aa=LCA[aa][j];
                    bb=LCA[bb][j];
                }
            }
            lca=aa;
            //cout<<bb;
            if(aa!=bb)lca=LCA[aa][0];
            if(E[a]>S[b]) swap(a,b);
            zapy[E[a]/320].pb(mp(mp(S[b],E[a]),mp(i,lca)));
        }
    }
    for(int i=0;i<319;++i){
        sort(zapy[i].begin(),zapy[i].end());
    }
    for(int i=0;i<319;++i){
        for(int j=0;j<=n;++j){
            koly[j]=poile[j]=0;
        }
        if(!zapy[i].empty()){

            int itl=zapy[i][0].f.s;
            int itp=zapy[i][0].f.f;
            //cout<<itl<<" "<<itp<<" "<<zapy[i][0].s.f<<" "<<zapy[i][0].s.s<<endl;
            int iler=0;
            for(int j=itl;j<=itp;++j){
                poile[ett[j]]++;
                if(poile[ett[j]]==1){
                    //cout<<"A";
                    koly[rodz[ett[j]]]++;
                    if(koly[rodz[ett[j]]]==1){
                        iler++;
                    }
                }else{
                    koly[rodz[ett[j]]]--;
                    if(koly[rodz[ett[j]]]==0){
                        iler--;
                    }
                }
            }
            if(zapy[i][0].s.s){
                if(koly[rodz[zapy[i][0].s.s]]==0){
                    iler++;
                    wyny[zapy[i][0].s.f]=iler;
                    iler--;
                }else{
                    wyny[zapy[i][0].s.f]=iler;
                }
            }else{
                wyny[zapy[i][0].s.f]=iler;
                //cout<<iler;
            }

            for(int j=1;j<zapy[i].size();++j){
                    //cout<<zapy[i][j].f.s<<" "<<zapy[i][j].f.f<<" "<<zapy[i][j].s.f<<" "<<zapy[i][j].s.s<<endl;
                while(itp<zapy[i][j].f.f){
                    itp++;
                    poile[ett[itp]]++;
                    if(poile[ett[itp]]==1){
                        koly[rodz[ett[itp]]]++;
                        if(koly[rodz[ett[itp]]]==1){
                            iler++;
                        }
                    }else{
                        koly[rodz[ett[itp]]]--;
                        if(koly[rodz[ett[itp]]]==0){
                            iler--;
                        }
                    }
                }

                while(itl<zapy[i][j].f.s){
                    poile[ett[itl]]--;
                    if(poile[ett[itl]]==1){
                        koly[rodz[ett[itl]]]++;
                        if(koly[rodz[ett[itl]]]==1){
                            iler++;
                        }
                    }else{
                        koly[rodz[ett[itl]]]--;
                        if(koly[rodz[ett[itl]]]==0){
                            iler--;
                        }
                    }
                    itl++;
                }
                while(itl>zapy[i][j].f.s){
                    itl--;
                    poile[ett[itl]]++;
                    if(poile[ett[itl]]==1){
                        koly[rodz[ett[itl]]]++;
                        if(koly[rodz[ett[itl]]]==1){
                            iler++;
                        }
                    }else{
                        koly[rodz[ett[itl]]]--;
                        if(koly[rodz[ett[itl]]]==0){
                            iler--;
                        }
                    }
                }//cout<<iler<<endl;
                if(zapy[i][j].s.s){
                    if(koly[rodz[zapy[i][j].s.s]]==0){
                        iler++;
                        wyny[zapy[i][j].s.f]=iler;
                        iler--;
                    }else{
                        wyny[zapy[i][j].s.f]=iler;
                    }
                }else{
                    wyny[zapy[i][j].s.f]=iler;
                }
            }
        }
    }
    //cout<<"X"<<E[3]<<endl;
    for(int i=0;i<m;++i){
        printf("%d\n",wyny[i]);
    }
    return 0;
}
