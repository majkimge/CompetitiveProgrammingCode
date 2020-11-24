#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define MAX 500009

using namespace std;

lld n;
lld w,w1,odle;
vector<lld> kraw[MAX];
lld gleb[MAX];
lld odw[MAX];
lld odw1[MAX];
lld odw2[MAX];
lld poile[MAX];
lld wyniki[MAX];

void dfs(int x, int glebo){
    odw[x]=1;
    gleb[x]=glebo;

    for(int i=0;i<kraw[x].size();i++){
        if(odw[kraw[x][i]]==0){
            odle+=glebo+1;
            dfs(kraw[x][i],glebo+1);
        }
    }

}

lld dfs1(int x, int glebo){
    odw1[x]=1;
    //gleb[x]=glebo;
    lld czy=0;
    for(int i=0;i<kraw[x].size();i++){
        if(odw1[kraw[x][i]]==0){
            czy++;
            //odle+=glebo+1;
            poile[x]+=dfs1(kraw[x][i],glebo+1)+1;
        }
    }
    if(czy==0){
        return 0;
    }
    return poile[x];

}

void dfs2(int x, int glebo, int wyn){
    odw2[x]=1;
    gleb[x]=glebo;
    lld czy=0;
    if(x!=1){
        wyniki[x]=wyn-poile[x]+n-1-poile[x]-1;
    }else{
        wyniki[x]=odle;
    }

    for(int i=0;i<kraw[x].size();i++){
        if(odw2[kraw[x][i]]==0){
            //czy++;
            //odle+=glebo+1;
            dfs2(kraw[x][i],glebo+1,wyniki[x]);
        }
    }


}

int main()
{

     scanf("%lld",&n);

    for(int i=0;i<n-1;i++){
        scanf("%lld",&w);
        scanf("%lld",&w1);
        kraw[w].push_back(w1);
        kraw[w1].push_back(w);
    }
    dfs(1,0);
    dfs1(1,0);
    dfs2(1,0,0);
    for(int i=1;i<=n;++i){
        printf("%lld\n",wyniki[i]);
    }
    return 0;
}
