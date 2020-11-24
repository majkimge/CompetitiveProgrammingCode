#include <bits/stdc++.h>
#define MAX 3002
#define lld short
#define pb push_back

using namespace std;

short tab[MAX][MAX];
lld n,m,co,a,b;
vector<lld> kraw[MAX];
lld poile[MAX];
lld odw[MAX];
lld ilesyn[MAX];
lld poile[MAX];

lld dfs(lld z){
    odw[z]=1;
    lld wy=0;
    for(int i=0;i<kraw[z].size();++i){
        if(!odw[kraw[z][i]]){
            wy+=dfs(kraw[z][i]);
        }
    }
    return wy+1;
}
void dfs1(lld z,lld oczy){
    odw[z]=1;
    //lld wy=0;
    poile[ilesyn[z]]++;
    for(int i=0;i<kraw[z].size();++i){
        if(!odw[kraw[z][i]]){
            //wy+=dfs(kraw[z][i]);
        }
    }
    //return wy+1;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        kraw[a].pb(b);
        kraw[b].pb(a);
    }
    return 0;
}
