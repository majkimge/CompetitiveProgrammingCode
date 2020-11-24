#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 300009
#define pii pair<lld,lld>
#define MOD 1000000007

using namespace std;

lld n,a;
vector<lld> kraw[MAX];
lld wyny[MAX];
lld odw[MAX];
lld tewyny[MAX];

lld pot(lld co, lld dok){
    if(dok==1){
        return co;
    }else if(dok%2==0){
        lld temp=pot(co,dok/2);
        return (temp*temp)%MOD;
    }else{
        lld temp=pot(co,dok-1);
        return (co*temp)%MOD;
    }
}

lld dfs(int from){
    odw[from]=1;
    tewyny[from]=1;
    for(int i=0;i<kraw[from].size();++i){
        if(!odw[kraw[from][i]]){
            tewyny[from]*=(dfs(kraw[from][i])+1);
            tewyny[from]%=MOD;
        }

    }
    return tewyny[from];
}

void dfs1(int from, int z){
    odw[from]=2;
    wyny[from]=tewyny[from];
    wyny[from]*=((wyny[z]*pot(tewyny[from]+1,MOD-2)+1)%MOD);
    for(int i=0;i<kraw[from].size();++i){
        if(odw[kraw[from][i]]<2){
            dfs1(kraw[from][i],from);
        }
    }
}

int main()
{

    scanf("%lld",&n);
    for(int i=2;i<=n;++i){
        scanf("%lld",&a);
        //a=1;
        kraw[a].pb(i);
        kraw[i].pb(a);
    }
    dfs(1);
    dfs1(1,0);
    for(int i=1;i<=n;++i){
        printf("%lld ",wyny[i]);
    }
    return 0;
}
