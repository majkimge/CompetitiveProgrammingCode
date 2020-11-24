#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 200009
#define pii pair<int,int>
#define MOD 1000000007

using namespace std;

pii tree[1000000];
int n,tab[MAX],kk=1;
set<int> v[MAX];
vector<int> kony[MAX];
lld wyny[MAX];
int nast[MAX][2];
lld wyniki[MAX];
vector<int> wyne;

pii mini(int l,int p){
    l+=kk;
    p+=kk;
    if(p<l)return mp(MAX,MAX);
    pii ret=tree[l];
    if(l!=p){
        ret=min(tree[l],tree[p]);

    }
    while(l/2!=p/2){
        if(l%2==0){
            ret=min(ret,tree[l+1]);
        }
        if(p%2){
            ret=min(ret,tree[p-1]);
        }
        l>>=1;
        p>>=1;
    }
    return ret;
}

void dod(int gdz, int co){
    gdz+=kk;
    tree[gdz].f+=co;
    gdz>>=1;
    while(gdz){
        tree[gdz]=min(tree[gdz*2],tree[gdz*2+1]);
        gdz>>=1;
    }
}

int main()
{
    scanf("%d",&n);
    while(kk<n)kk<<=1;
    for(int i=1;i<=n;++i){
        kony[i].pb(0);
        scanf("%d",&tab[i]);
        dod(i,tab[i]);
        v[tab[i]].insert(i);
    }
    dod(n+1,MAX);
    dod(n+2,MAX);
    wyny[0]=1;
    for(int i=0;i<MAX;++i){
        sort(v[i]);
        /*for(int j=0;j<v[i].size();++j){
            if(j==v[i].size()){
                nast[v[i][j]][0]=MAX;
                nast[v[i][j]][1]=MAX;
            }else{
                nast[v[i][j]][0]=v[i][j+1];
                if(j==v[i].size()-1){
                    nast[v[i][j]][1]=MAX;
                }else{
                    nast[v[i][j]][1]=v[i][j+2];
                }
            }
        }*/

    }
    wyne.pb(0);
    for(int i=1;i<=n;++i){
        pii mm=mini(i,nast[i]);
        if(wyne.empty&&)
        if(mm.f<=tab[i]){

        }
    }
    return 0;
}
