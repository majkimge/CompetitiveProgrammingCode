#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1100000
#define pii pair<int,int>

using namespace std;

int n,a,b,m;
vector<int> kraw[MAX];
int LCA[MAX][30];
int odw[MAX];
int gl[MAX];

void dfs(int gdz,int ojc,int gleb){
    odw[gdz]=1;
    LCA[gdz][0]=ojc;
    gl[gdz]=gleb;
    for(int i=0;i<kraw[gdz].size();++i){
        if(!odw[kraw[gdz][i]]){
            dfs(kraw[gdz][i],gdz,gleb+1);
        }
    }
}

void inLCA(){
    for(int i=1;i<30;++i){
        for(int j=1;j<=n;++j){
            LCA[j][i]=LCA[LCA[j][i-1]][i-1];
        }
    }
}

int lca(int a1, int b1){
    if(gl[a1]<gl[b1])swap(a1,b1);
    int aa=a1;
    int bb=b1;//cout<<aa;
    for(int i=29;i>=0;--i){
        if(gl[LCA[aa][i]]>=gl[b1]){
            aa=LCA[aa][i];
        }
    }

    if(aa==bb)return aa;
    for(int i=29;i>=0;--i){
        if(LCA[aa][i]!=LCA[bb][i]){
            aa=LCA[aa][i];
            bb=LCA[bb][i];
        }
    }
    return LCA[aa][0];
}

int main()
{
    scanf("%d",&n);
    gl[0]=-1;
    for(int i=0;i<n-1;++i){
        scanf("%d%d",&a,&b);
        kraw[a].pb(b);
        kraw[b].pb(a);
    }
    dfs(1,0,0);
    inLCA();
    cout<<LCA[4][2];
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        printf("%d\n",lca(a,b));
    }

    return 0;
}
/*
10
1 2
1 3
1 9
2 4
2 5
3 6
3 7
3 8
8 10
100
*/
