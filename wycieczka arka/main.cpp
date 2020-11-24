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
int gleby[MAX];
int odw[MAX];
int skal[MAX];
int ktor[MAX];
int atr[MAX];
map<int,int> ma;

int dfs(int from,int gleb,int oczy){
    gleby[from]=gleb;
    LCA[from][0]=oczy;
    odw[from]=1;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            dfs(kraw[from][i],gleb+1,from);
        }
    }
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
    dfs(1,0,0);
    for(int i=1;i<20;++i){
        for(int j=1;j<=n;++j){
            LCA[j][i]=LCA[LCA[j][i-1]][i-1];
        }
    }
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        if(gleby[a]<gleby[b]){
            swap(a,b);
        }

        aa=a;
        bb=b;
        for(int i=19;i>=0;--i){
            if(gleby[LCA[a][i]]>gleby[b]){
                a=LCA[a][i];
            }
        }
        if(gleby[a]!=gleby[b]){
            a=LCA[a][0];
        }

        int lca=0;
        for(int i=19;i>=0;--i){
            if(LCA[a][i]!=LCA[b][i]){
                a=LCA[a][i];
                b=LCA[b][i];
            }
        }
        lca=a;
        if(a!=b)lca=LCA[a][0];
        //cout<<lca;

    int wyn=0;

    while(aa!=a){
        if(atr[rodz[aa]]==0){
            wyn++;
        }
        atr[rodz[aa]]++;
        aa=LCA[aa][0];
    }
    while(aa!=lca){
        if(atr[rodz[aa]]==0){
            wyn++;
        }
        atr[rodz[aa]]++;
        aa=LCA[aa][0];
    }
    while(bb!=lca){
        if(atr[rodz[bb]]==0){
            wyn++;
        }
        atr[rodz[bb]]++;
        bb=LCA[bb][0];
    }
    if(atr[rodz[lca]]==0){
        wyn++;
    }
    printf("%d\n",wyn);
    for(int i=1;i<=n;++i){
        atr[i]=0;
    }
    }

    return 0;
}
