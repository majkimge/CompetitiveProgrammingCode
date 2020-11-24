#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define MAX 2009

using namespace std;

int n,k;
int ile[2009];
int ilez,ileroz;
int tab[MAX];
int dp[MAX][MAX];
lld sil[MAX*MAX];
int odwsil[MAX*MAX];
int wynik;



int rob(int kt, int dok){
    if(kt==dok){
        for(int i=0;i<=n;++i){
            ile[i]=0;
        }
        ilez=0;
        ileroz=0;
        int przyps=0;
        for(int i=0;i<n*k;++i){
            if(tab[i]==0){
                ilez++;
            }else{
                ile[tab[i]]++;
                if(ile[tab[i]]==1)ileroz++;
                if(ileroz>ilez)przyps=1;
            }


        }
        for(int i=1;i<=n;++i){
            if(ile[i]!=k-1)przyps=1;
        }
        if(ilez!=n||(ileroz!=n&&k>1))przyps=1;
        if(!przyps)wynik++;
    }else{
        for(int i=0;i<=n;++i){
            tab[kt]=i;
            rob(kt+1,dok);

        }
    }
}

lld pot(lld cok, lld dok){
    if(dok==0)return 1;
    if(dok%2==0){
        lld temp=pot(cok,dok/2);
        return (temp*temp)%MOD;
    }else{
        lld temp=pot(cok,dok-1);
        return (temp*cok)%MOD;
    }

}

lld odwr(lld co){
    return pot(co,MOD-2);
}

int main()
{
    scanf("%d%d",&n,&k);
    dp[0][0]=1;

    sil[0]=1;
//    odwrsil[0]=1;
    for(lld i=1;i<MAX*MAX;++i){
        sil[i]=sil[i-1]*i;
        sil[i]%=MOD;
        //odwr[i]=pot(i,MOD-2);
        //odwrsil[i]=pot(sil[i],MOD-2);
    }
    odwsil[MAX*MAX-1]=pot(sil[MAX*MAX-1],MOD-2);
    for(lld i=MAX*MAX-2;i>=0;--i){
        odwsil[i]=(odwsil[i+1]*(i+1))%MOD;
    }
    //cout<<odwsil[2];
    dp[0][1]=1;
    if(k==1){
        cout<<1;
        return 0;
    }
    //cout<<sil[100];
    for(int i=0;i<=n;++i){
        for(int j=max(i,1);j<=n;++j){
            if(i==0&&j==1)continue;
            if(i)dp[i][j]+=dp[i-1][j];
            lld dod=dp[i][j-1]*sil[(lld)i+(j-1)*(k-1)+k-2];
            dod%=MOD;
            dod*=odwsil[k-2];
            dod%=MOD;
            dod*=odwsil[i+(j-1)*(k-1)];
            dod%=MOD;

            dp[i][j]+=(int)dod;
            dp[i][j]%=MOD;
        }
    }
    //cout<<dp[0][2];
    printf("%lld",((lld)(dp[n][n])*sil[n])%MOD);
    return 0;
}
