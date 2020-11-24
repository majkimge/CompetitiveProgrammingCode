#include <bits/stdc++.h>
#define N 1000000
#define MLD 1000000000
using namespace std;

vector<int> kraw[N];
queue <int> kol;
int odw[N];
int gleb[N];
int odl[N];
int n, m;
int w, w1;

void dfs(int x, int glebo){
    odw[x]=1;
    gleb[x]=glebo;
    for(int i=0;i<kraw[x].size();i++){
        if(odw[kraw[x][i]]==0){
            dfs(kraw[x][i],glebo+1);
        }
    }

}
void bfs(){
    while(!kol.empty()){
        int x=kol.front();
        kol.pop();
        for(int i=0;i<kraw[x].size();i++){
            if(odl[x]+1<odl[kraw[x][i]]){
                odl[kraw[x][i]]=odl[x]+1;
                kol.push(kraw[x][i]);
            }
        }
    }
}
int main()
{

    scanf("%i",&n);
    scanf("%i",&m);
    for(int i=0;i<n;i++){
        odl[i]=MLD;
    }
    for(int i=0;i<m;i++){
        scanf("%i",&w);
        scanf("%i",&w1);
        kraw[w].push_back(w1);
        kraw[w1].push_back(w);
    }
    odl[1]=0;
    kol.push(1);
    //dfs(0,0);
    bfs();

    for(int i=0;i<n;i++){
        printf("%i-%i\n",i,odl[i]);
    }
    return 0;
}
