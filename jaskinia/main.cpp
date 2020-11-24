#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 50009

using namespace std;

int n,a,b,kk=1,wynik;
vector<int> kraw[MAX];

int iles[MAX];
int ojc[MAX];
int odw[MAX];
int usy[MAX];
int maxik[MAX];



int dfs(int from,int oczy){
    odw[from]=1;
    pair<int,int> maxi;
    maxi=mp(0,0);

    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            //if(maxi.f<dfs(kraw[from][i],from);
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
    while(kk<=n){
        wynik++;
        kk<<=1;
    }
    cout<<wynik-1;
    return 0;
}
