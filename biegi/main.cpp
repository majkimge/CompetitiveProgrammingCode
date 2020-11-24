#include <bits/stdc++.h>
#define MAX 500009
#define pb push_back

using namespace std;

int LCA[MAX][21];
int n,m,a,b,k=1;
vector<int> kraw[MAX];
vector<int> dod[MAX];
vector<int> moc;
int gleb[MAX];
int odw[MAX];
int odw1[MAX];
int odw2[MAX];
int tree[MAX*4];
int wyny[MAX];

void add(int aa, int bb, int co){
    aa+=k;
    bb+=k;
    if(aa==bb){
        tree[aa]+=co;
    }else{
        tree[aa]+=co;
        tree[bb]+=co;
        while(aa/2!=bb/2){
            if(aa%2==0){
                tree[aa+1]+=co;
            }
            if(bb%2==1){
                tree[bb-1]+=co;
            }
            aa>>=1;
            bb>>=1;
        }
    }
}

int check(int gdz){
    gdz+=k;
    int www=0;
    while(gdz>0){
        www+=tree[gdz];
        gdz>>=1;
    }
    return www;
}

int dfs(int z, int g, int oc){
    odw[z]=1;
    gleb[z]=g;
    LCA[z][0]=oc;
    for(int i=0;i<kraw[z].size();++i){
        if(!odw[kraw[z][i]]){
            dfs(kraw[z][i],g+1,z);
        }
    }
}

void dfs1(int z){
    odw1[z]=1;
    moc.pb(z);
    for(int i=0;i<dod[z].size();++i){
            /*cout<<z<<" "<<dod[z][i]<<endl;
            for(int j=0;j<moc.size();++j){
                cout<<moc[j]<<" ";
            }
            cout<<endl;*/
        add(moc.size()-1-(gleb[z]-dod[z][i]),moc.size()-1,1);
        /*for(int j=0;j<moc.size();++j){
                cout<<j<<" "<<check(j)<<" ";
            }
            cout<<endl;*/
    }

    for(int i=0;i<kraw[z].size();++i){
        if(!odw1[kraw[z][i]]){
            dfs1(kraw[z][i]);
        }
    }
    int pom=check(moc.size()-1);
    wyny[z]+=pom;
    add(moc.size()-1,moc.size()-1,-pom);
    moc.pop_back();
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        kraw[a].pb(b);
        kraw[b].pb(a);
    }
    dfs(1,0,0);
    for(int i=1;i<21;++i){
        for(int x=1;x<=n;++x){
            LCA[x][i]=LCA[LCA[x][i-1]][i-1];
        }

    }
    scanf("%d",&m);
    gleb[0]=-1;
    for(int i=0;i<m;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        int a1=a;
        int b1=b;
        if(gleb[a1]<gleb[b1]){
            for(int i=20;i>=0;--i){
                if(gleb[LCA[b1][i]]>=gleb[a1]){
                    b1=LCA[b1][i];
                }
            }
            if(a1==b1){
                dod[b].pb(gleb[a1]);
            }
        }else if(gleb[a1]>gleb[b1]){
            for(int i=20;i>=0;--i){
                if(gleb[LCA[a1][i]]>=gleb[b1]){
                    a1=LCA[a1][i];
                }
            }
            if(a1==b1){
                dod[a].pb(gleb[b1]);
            }
        }
        if(a1!=b1){
            for(int i=20;i>=0;--i){
                if(LCA[a1][i]!=LCA[b1][i]){
                    a1=LCA[a1][i];
                    b1=LCA[b1][i];
                }
            }
            wyny[LCA[a1][0]]++;
            dod[a].pb(gleb[b1]);
            dod[b].pb(gleb[b1]);
        }

    }
    while(k<n){
        k<<=1;
    }
    dfs1(1);
    for(int i=1;i<=n;++i){
        printf("%d ",wyny[i]);
    }
    return 0;
}
