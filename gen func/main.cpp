#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 200009
#define pii pair<int,int>
#define MOD 1000000007
#define NAD 500000004

using namespace std;

int n,k,tab[MAX],a;

lld pot(lld co, lld dok){
    if(dok==0)return 1;
    if(dok%2==0){
        lld temp=pot(co,dok/2);
        return (temp*temp)%MOD;
    }
    lld temp=pot(co,dok-1);
    return (temp*co)%MOD;
}

lld sil[MAX];
lld odwsil[MAX];
lld poty[MAX];
lld dwumy[MAX];
lld wyny[MAX];

lld dwum(lld g, lld d){
    return (((sil[g]/sil[d])%MOD)/sil[g-d])%MOD;
}

int main()
{


    poty[0]=1;
    scanf("%d",&n);

    sil[0]=1;
    for(int i=1;i<=n*2;++i){
        sil[i]=sil[i-1]*i;
        sil[i]%=MOD;
    }
    odwsil[n]=pot(sil[n],MOD-2);
    for(int i=n-1;i>=0;--i){
        odwsil[i]=odwsil[i+1]*(i+1);
        odwsil[i]%=MOD;
    }
    dwumy[0]=0;
    for(int i=1;i<=n;++i){
        poty[i]=poty[i-1]*2;
        dwumy[i]=dwum(2*i,i);
    }
//    cout<<;
//poty[0]=0;
//dwumy[0]=1;
    for(int i=0;i<=n;++i){
        for(int j=0;j<=i;++j){
            wyny[i+1]+=dwumy[j]*poty[i-j];
        }
    }
    for(int i=0;i<=n;++i){
        cout<<dwumy[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<=n;++i){
        cout<<wyny[i]<<" ";
    }
    cout<<endl;
    return 0;
}
