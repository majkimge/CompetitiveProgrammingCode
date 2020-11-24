#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 100009
#define MOD 1000000007

using namespace std;

int n,m,z,k,a,b,czy4=1;
int deg[MAX];
int zapy[1009];
int adj[100][100];
lld poly[100];
int delnode[100];
vector<int>kraw[MAX];
vector<int> nodes;

lld pot(lld co, lld dok){
    if(dok==0)return 1;
    if(dok%2==0){
        lld temp=pot(co,dok/2);
        return (temp*temp)%MOD;
    }
    lld temp1=pot(co,dok-1);
    return (temp1*co)%MOD;
}

vector<lld> sol1(int ilk, int ilw, vector<int> wierz){
    vector<lld> v;
    for(int i=0;i<26;++i)v.pb(0);
    if(!ilk){
        v[ilw]=1;
        return v;
    }
    int ileus=0;
    int us[30];
    int jest[30];
    for(int i=1;i<30;++i){
        us[i]=0;
        jest[i]=0;
    }
    for(int i=0;i<wierz.size();++i){
        if(deg[wierz[i]]==1){
            ++ileus;
            us[wierz[i]]=1;

        }
    }
}



int main()
{
    scanf("%d%d%d",&n,&m,&z);
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        kraw[a].pb(b);
        kraw[b].pb(a);
        deg[a]++;
        deg[b]++;
    }
    for(int i=1;i<=n;++i){
        if(deg[i]!=2)czy4=0;
    }
    for(int i=0;i<z;++i){
        scanf("%d",&zapy[i]);
    }
    if(czy4){
        lld mno=1;
        if(n%2)mno=-1;
        for(int i=0;i<z;++i){
            lld wynik=(pot((lld)zapy[i]-1,(lld)n)+mno*(lld)(zapy[i]-1)+MOD)%MOD;
            printf("%lld\n",wynik);
        }
        return 0;
    }else if(m<=24){

    }
    return 0;
}
