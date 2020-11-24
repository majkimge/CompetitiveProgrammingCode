#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define s second
#define f first
#define MAX 309
#define INF 1000000000
#define pb push_back
#define pii pair<int,int>

using namespace std;

int n,m,a,b,g,wynik;
pair<pii,int> zak[MAX];
int tab[MAX];
int czy[3];

void check(){

    int pp=0;
    for(int i=0;i<m;++i){
        czy[0]=czy[1]=czy[2]=0;
        for(int j=zak[i].f.f;j<=zak[i].f.s;++j){
            czy[tab[j]]=1;
        }
        int il=czy[0]+czy[1]+czy[2];
        if(il!=zak[i].s)pp=1;
    }
    if(!pp)wynik++;

}

void rob(int ter, int dok){
    if(ter==dok){
        check();
    }else{
        for(int i=0;i<3;++i){
            tab[ter]=i;
            rob(ter+1,dok);
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&a,&b,&g);
        a--;
        b--;
        zak[i]=mp(mp(a,b),g);
    }
    rob(0,n);
    printf("%d",wynik);
    return 0;
}
