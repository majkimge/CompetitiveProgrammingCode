#include <bits/stdc++.h>
#define lld long long
#define ld double
#define MAX 200009
#define LOG 18
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000

using namespace std;

lld n,a;
lld odw[MAX];
lld odw1[MAX];
lld wyny[MAX];
lld ilesyn[MAX];
vector<lld> kraw[MAX];

lld dfs(lld a1,lld gleb){
    odw[a1]=1;
    //gleby[a1]=gleb;
    lld sy=0;

    for(int i=0;i<kraw[a1].size();++i){
        if(!odw[kraw[a1][i]]){

            //wyn++;
            sy+=dfs(kraw[a1][i],gleb+1);
        }
    }
    ilesyn[a1]=sy;
    return sy+1;
}

lld dfs1(lld a1,lld gleb){
    odw1[a1]=1;
    //gleby[a1]=gleb;
    lld wyn=0;

    for(int i=0;i<kraw[a1].size();++i){
        if(!odw1[kraw[a1][i]]){

            //wyn++;
            //cout<<"B";
            wyn+=dfs1(kraw[a1][i],gleb+1);
        }
    }
    //cout<<ilesyn[a1]+wyn+1;
    wyny[a1]=ilesyn[a1]+wyn+1;
    return ilesyn[a1]+wyn+1;
}

int main()
{
    scanf("%lld",&n);
    for(int i=2;i<=n;++i){
        scanf("%lld",&a);

        kraw[i].pb(a);
        kraw[a].pb(i);
    }
    dfs(1,0);
    //fill(odw,odw+n+1,0);
    dfs1(1,0);
    for(int i=1;i<=n;++i){
        printf("%lld ",wyny[i]);
    }
    return 0;
}
