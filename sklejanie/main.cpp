#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define MAX 100009

using namespace std;

lld n;
lld tab[MAX];
lld poty[MAX];
lld czydod[MAX];
lld zaop[MAX];
lld wynik;
lld dp[MAX][2];

void rob(lld l, lld p){
    lld mini=MOD;
    if(p<l)return;
    for(lld i=l;i<=p;++i){
        mini=min(mini,poty[i]);
    }
    for(lld i=l;i<=p;++i){
        poty[i]-=mini;
    }
    wynik+=mini;
    lld nl=l;
    lld np=l;
    for(lld i=l;i<=p;++i){
        if(poty[i]==0){
            rob(nl,i-1);
            nl=i+1;
        }
    }
    rob(nl,p);

}

int main()
{
    scanf("%d",&n);
    srand(time(0)+n);
    for(lld i=1;i<=n;++i){
        scanf("%d",&tab[i]);
        //tab[i]=rand()%1000000000+1;
        lld temp=1;
        lld ile=0;
        while(temp<tab[i]){
            ++ile;
            temp<<=1;
        }
        if(temp>tab[i]){
            poty[i]=ile-1;
            czydod[i]=1;
        }else{
            poty[i]=ile;
        }
    }
    dp[1][0]=poty[1]+czydod[1];
    dp[1][1]=poty[1]+czydod[1];
    for(int i=2;i<=n;++i){
        dp[i][0]=min(dp[i-1][0]+poty[i]+czydod[i]-min(poty[i-1],poty[i]+czydod[i]),dp[i-1][1]+poty[i]+czydod[i]-min(poty[i-1]+czydod[i-1],poty[i]+czydod[i]));
        dp[i][1]=min(dp[i-1][0]+poty[i]+czydod[i]-min(poty[i-1],poty[i]),dp[i-1][1]+poty[i]+czydod[i]-min(poty[i-1]+czydod[i-1],poty[i]));
        dp[i][0]%=MOD;
        dp[i][1]%=MOD;
    }

    printf("%lld",min(dp[n][0],dp[n][1]));
    return 0;
}
