#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 10009

using namespace std;

int n,m,a,b,wynik;
vector<int> kraw[MAX];
int odw[MAX];

int dfs(int from,int oczy){
    odw[from]=1;
    //int czy=0;
    int wyn=0;
    if(from==oczy&&kraw[from].size()==0)wyn++;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            if(from==oczy){
                wyn++;
                //czy=1;
            }
            wyn+=dfs(kraw[from][i],oczy);
        }

    }
    return wyn;

}

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        kraw[a].pb(b);
        //odwkraw[b].pb(a);
    }

        for(int i=1;i<=n;++i){
            odw[i]=0;

        }
        int suma=0;
        for(int i=1;i<=n;++i){
            if(!odw[i]) suma+=dfs(i,i);

        }
        wynik=max(wynik,suma);

    printf("%d",wynik);
    return 0;
}
