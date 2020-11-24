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

lld dwum(lld g, lld d){
    return (((sil[g]*odwsil[d])%MOD)*odwsil[g-d])%MOD;
}

int main()
{
    scanf("%d%d",&n,&k);
    sil[0]=1;
    for(int i=1;i<=n;++i){
        sil[i]=sil[i-1]*i;
        sil[i]%=MOD;
    }
    odwsil[n]=pot(sil[n],MOD-2);
    for(int i=n-1;i>=0;--i){
        odwsil[i]=odwsil[i+1]*(i+1);
        odwsil[i]%=MOD;
    }
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    for(int xd=0;xd<k;++xd){
        scanf("%d",&a);
        --a;
        int l=a-1;
        int p=a+1;

        lld wyn=1;
        for(int i=n;i>0;--i){
            int ll=0;
            int pp=0;
            while(l>=0&&tab[l]>=i){
                if(tab[l]==i)ll++;
                --l;
            }
            while(p<n&&tab[p]>=i){
                if(tab[p]==i)pp++;
                ++p;
            }
            wyn*=dwum(ll+pp,ll);
            wyn%=MOD;
        }
        printf("%lld\n",wyn);
    }
    return 0;
}
