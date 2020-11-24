#include <bits/stdc++.h>
#define lld long long
#define ld double
#define MAX 100009
#define LOG 18
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000

using namespace std;

lld n,a,b,w,wyn;
vector<pair<lld,lld> > kraw[MAX];
lld odw[MAX];
lld ilesyn[MAX];
lld gleby[MAX];



lld dfs1(lld a1,lld gleb){
    odw[a1]=1;
    gleby[a1]=gleb;
    lld sy=0;
    for(int i=0;i<kraw[a1].size();++i){
        if(!odw[kraw[a1][i].f]){

            //wyn++;
            sy+=dfs(kraw[a1][i].f,czas+1);
        }
    }
    ilesyn[a1]=sy;
    return sy+1;
}

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n-1;++i){
        scanf("%lld",&a);
        scanf("%lld",&b);
        scanf("%lld",&w);
        kraw[a].pb(mp(b,w));
        kraw[b].pb(mp(a,w));
    }

    dfs(1,0);
    for(int i=1;i<=n;++i){

        printf("%lld\n",ilesyn[i]);
    }
    return 0;
}
