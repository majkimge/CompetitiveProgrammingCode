#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200009

using namespace std;

int n,m,a,b,c,d;
vector<int> kraw[MAX];
int gl[MAX];
int gl1[MAX];
int odw[MAX];
int odw1[MAX];

int dfs(int gdz,int gleb){
    odw[gdz]=1;
    gl[gdz]=gleb;
    for(int i=0;i<kraw[gdz].size();++i){
        if(!odw[kraw[gdz][i]]){
            dfs(kraw[gdz][i],gleb+1);
        }
    }
}

int dfs1(int gdz,int gleb){
    odw1[gdz]=1;
    gl1[gdz]=gleb;
    for(int i=0;i<kraw[gdz].size();++i){
        if(!odw1[kraw[gdz][i]]){
            dfs1(kraw[gdz][i],gleb+1);
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;++i){
        scanf("%d%d",&a,&b);
        kraw[a].pb(b);
        kraw[b].pb(a);
    }
    scanf("%d",&m);
    for(int p=0;p<m;++p){
        scanf("%d%d",&c,&d);
        for(int i=1;i<=n;++i){
            gl[i]=gl1[i]=odw[i]=odw1[i]=0;
        }
        dfs(c,0);
        dfs1(d,0);
        int wynik=0;
        for(int i=1;i<=n;++i){
            wynik=max(wynik,min(gl[i],gl1[i]));
        }
        printf("%d\n",wynik);
    }
    return 0;
}
