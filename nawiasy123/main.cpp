#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 30009
#define INF 1000000000000000
#define MOD 1000000009

using namespace std;

int n;
lld catalan[MAX];
lld sym[MAX];

lld pot(lld co,lld dok){
    if(dok==0) return 1;
    if(dok%2){
        lld temp=pot(co,dok/2);
        return (temp*temp)%MOD
    }
    return (pot(co,dok-1)*co)%MOD;
}

int main()
{
    catalan[0]=1;
    sym[0]=0;
    for(int i=1;i<=n;++i){
        sym[i]=((((sym[i-1]*(2*i-1)*(2*i))%MOD)*((pot(i,MOD-2))%MOD)%MOD)*((pot(i,MOD-2))%MOD))%MOD;
    }
    for(int i=1;i<=n;++i){
        catalan[i]=(sym[i]*((pot(i+1,MOD-2))%MOD))%MOD;
    }
    return 0;
}
