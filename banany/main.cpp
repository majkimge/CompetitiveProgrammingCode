#include <bits/stdc++.h>
#define lld long long
#define N 100009
#define MLD 100000000000000000
#define mp make_pair
#define f first
#define s second
using namespace std;

vector<pair<lld,lld> > kraw[N];
queue <int> kol;
lld odw[N];
lld gleb[N];
lld odl[N];
lld ceny[N];
lld n, q;
lld w, w1,counter=0;
lld a,b,t,wynik=-MLD, co,gdzie, oile,od1,do1,gdziejest=1;

void dfs(int x, int glebo){
    odw[x]=1;
    odl[x]=glebo;
    if(counter!=0){
        if(wynik<=ceny[x]-odl[x]){
             wynik=ceny[x]-odl[x];
            gdziejest=x;
        }
    }
    counter++;
    for(int i=0;i<kraw[x].size();i++){
            //cout<<"B";
        if(odw[kraw[x][i].f]==0){
            dfs(kraw[x][i].f,glebo+kraw[x][i].s);
        }
    }

}

int main()
{

    scanf("%lld",&n);
    scanf("%lld",&q);
    for(int i=1;i<=n;++i){
        scanf("%lld",&ceny[i]);
    }
    for(int i=0;i<n-1;++i){
        scanf("%lld",&a);
        scanf("%lld",&b);
        scanf("%lld",&t);
        kraw[a].push_back(mp(b,t));
        kraw[b].push_back(mp(a,t));
    }
    for(int i=0;i<q;++i){
        for(int p=1;p<=n;p++) odw[p]=0;
        counter=0;
        wynik=-MLD;
        scanf("%lld",&co);
        if(co==1){
            scanf("%lld",&gdzie);
            scanf("%lld",&oile);
            ceny[gdzie]=oile;
            dfs(gdziejest,0);
            printf("%lld ",gdziejest);
        }else{
            scanf("%lld",&od1);
            scanf("%lld",&do1);
            scanf("%lld",&oile);
            for(int z=0;z<kraw[od1].size();z++){
                if(kraw[od1][z].f==do1){
                    kraw[od1][z]=mp(kraw[od1][z].f,oile);
                }
            }
            dfs(gdziejest,0);
            printf("%lld ",gdziejest);
        }
    }
    return 0;
}
