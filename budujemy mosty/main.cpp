#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define ff first
#define s second
#define MAX 100009
#define pii pair<lld,lld>
#define pdd pair<double,double>
#define C 1000

using namespace std;

int n;
lld wys[MAX];
lld cost[MAX];
lld dp[MAX];
lld pref[MAX],kk=1;
lld INF = 1000000000000000000;
pii func[MAX];
lld lichao[4100000];

lld f(int kt, lld xx){
    return func[kt].ff*xx+func[kt].s;
}

void akt(lld gdz, lld zakl, lld zakp, lld kt){
    if(gdz>=kk){
        if(f(kt,zakl)<f(lichao[gdz],zakl)){
            lichao[gdz]=kt;
        }
        return;
    }
    if(f(kt,zakl)<=f(lichao[gdz],zakl)&&f(kt,(zakl+zakp)/2)<=f(lichao[gdz],(zakl+zakp)/2)){
        akt(gdz*2+1,(zakl+zakp)/2+1,zakp,lichao[gdz]);
        lichao[gdz]=kt;

    }else if(f(kt,zakl)>=f(lichao[gdz],zakl)&&f(kt,(zakl+zakp)/2)>=f(lichao[gdz],(zakl+zakp)/2)){
        akt(gdz*2+1,(zakl+zakp)/2+1,zakp,kt);
    }else{
        if(f(kt,(zakl+zakp)/2+1)<=f(lichao[gdz],(zakl+zakp)/2+1)&&f(kt,zakp)<=f(lichao[gdz],zakp)){
            akt(gdz*2,zakl,(zakl+zakp)/2,lichao[gdz]);
            lichao[gdz]=kt;

        }else{
            akt(gdz*2,zakl,(zakl+zakp)/2,kt);
        }

    }
    return;
}

lld check(lld gdz){

    lld argu=gdz;
    gdz+=kk;
    lld wyn=INF;
    while(gdz){
        wyn=min(wyn,f(lichao[gdz],argu));
        gdz>>=1;
    }
    return wyn;
}

int main()
{
    scanf("%d",&n);
    srand(time(0)+n);
    while(kk<1000000)kk<<=1;
    for(int i=1;i<=n;++i){
        scanf("%lld",&wys[i]);
    }
    for(int i=1;i<=n;++i){
        scanf("%lld",&cost[i]);
    }
    cost[1]=INF;
    cost[n]=INF;
    for(int i=1;i<=n;++i){
        pref[i]=cost[i]+pref[i-1];
    }
    func[1]=mp((lld)-2*wys[1],-pref[1]+wys[1]*wys[1]);
    //akt(1,0,kk-1,1);
    for(int i=0;i<4100000;++i){
        lichao[i]=1;
    }
    for(int i=2;i<=n;++i){
        dp[i]=check(wys[i])+wys[i]*wys[i]+pref[i-1];
        //cout<<dp[i]<<" ";
        func[i]=mp((lld)-2*wys[i],-pref[i]+wys[i]*wys[i]+dp[i]);
        akt((lld)1,(lld)0,(lld)kk-1,i);
    }
    printf("%lld",dp[n]);
    return 0;
}
/*
6
1 4 6 3 7 8
0 9 3 5 4 0
*/
