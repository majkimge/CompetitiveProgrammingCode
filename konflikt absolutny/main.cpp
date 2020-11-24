#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 100009

using namespace std;

int n,m,a,b,kt,wynik;
vector<int> kraw[MAX];
vector<int> odwkraw[MAX];
int jaks[MAX];
vector<int> skraw[MAX];
vector<int> sss[MAX];
vector<int> topo;
int odw[MAX];
int odw1[MAX];
int czymog[MAX];
int ileod[MAX];
map<pair<int,int>,int> mapka;
int ilezost;
queue<pair<int,int> >doroz;
int rozpat[MAX];
vector<int> jakiedo[MAX];

int dfs(int z){
    odw[z]=1;
    for(int i=0;i<kraw[z].size();++i){
        if(!odw[kraw[z][i]]){
            dfs(kraw[z][i]);
        }
    }
    topo.pb(z);
}

int dfs1(int z,int ktor){
    odw1[z]=1;
    sss[ktor].pb(z);
    jaks[z]=ktor;
    for(int i=0;i<odwkraw[z].size();++i){
        if(!odw1[odwkraw[z][i]]){
            dfs1(odwkraw[z][i],ktor);
        }
    }
    //topo.pb(z);
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        kraw[a].pb(b);
        odwkraw[b].pb(a);
    }
    for(int i=1;i<=n;++i){
        if(!odw[i]){
            dfs(i);
        }
    }
    for(int i=topo.size()-1;i>=0;--i){
        if(!odw1[topo[i]]){
            dfs1(topo[i],kt);
            kt++;
        }
    }
    for(int i=0;i<kt;++i){
        for(int j=0;j<sss[i].size();++j){
            for(int xx=0;xx<kraw[sss[i][j]].size();++xx){
                if(jaks[kraw[sss[i][j]][xx]]!=i&&!mapka[mp(i,jaks[kraw[sss[i][j]][xx]])]){
                    skraw[i].pb(jaks[kraw[sss[i][j]][xx]]);
                    ileod[i]++;
                    jakiedo[jaks[kraw[sss[i][j]][xx]]].pb(i);
                    mapka[mp(i,jaks[kraw[sss[i][j]][xx]])]=1;
                }
            }
        }
    }
    //cout<<sss[0].size();
    ilezost=kt;

    for(int i=0;i<kt;++i){
        if(ileod[i]==0){
            doroz.push(mp(i,1));
            rozpat[i]=1;
        } //wynik++;
    }
    while(!doroz.empty()){
        int temp=doroz.front().f;
        wynik=doroz.front().s;
        doroz.pop();
        for(int j=0;j<jakiedo[temp].size();++j){
            ileod[jakiedo[temp][j]]--;
            if(ileod[jakiedo[temp][j]]==0){
                doroz.push(mp(jakiedo[temp][j],wynik+1));
            }
        }
    }

    printf("%d",max(wynik,1));
    return 0;
}
