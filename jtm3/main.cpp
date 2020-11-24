#include <bits/stdc++.h>
#define lld long long
#define MOD 397483969


using namespace std;

lld pot(lld co, lld dok){
    if(dok==0)return 1;
    if(dok%2==0){
        lld temp=pot(co,dok/2);
        return (temp*temp)%MOD;
    }
    lld tempi=pot(co,dok-1);
    return (tempi*co)%MOD;
}


lld a=0,x=6561000000,wyn;
double dp[100][2];

int main()
{
    /*for(int i=1;i<=19936;++i){
        a+=pot(i,39873);
        a%=MOD;
    }*/


    /*dp[0][1]=1.00000000;
    for(int i=1;i<=32;++i){
        dp[i][1]=(double)6.000000000/17.0000000000*dp[i-1][1]+(double)5.000000000/13.0000000000*dp[i-1][0];
        dp[i][0]=(double)1.000000000-dp[i][1];
    }
    cout<<setprecision(8)<<dp[32][1];*/
    for(lld i=1;i*i<=x;++i){
        if(x%i==0&&i%3!=(x/i)%3)++wyn;
    }
    cout<<wyn;
    return 0;
}
