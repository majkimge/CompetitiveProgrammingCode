#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1000000007

using namespace std;

lld dp[1000000],l,r;
lld wynik;
map<lld,lld> m;

lld poj(lld gdz){
    //if(gdz<13)cout<<"D";
    if(m[gdz])return m[gdz];
    m[gdz]=poj(gdz/2)+poj(gdz/2-1)+poj(gdz/2-2)+poj(gdz/2-3)+poj(gdz/2-4);
    m[gdz]%=MOD;
    return m[gdz];
}

lld reku(lld ll, lld p){
    if(ll>p)return 0;
    lld ret=0;
    if(p-ll<35){
        for(lld i=ll;i<=p;++i){
            ret+=poj(i);
            ret%=MOD;
        }
        return ret;
    }
    if(ll<30){
        for(lld i=ll;i<=30;++i){
            ret+=dp[i];
        }
        ll=31;
    }
    ret+=poj(ll/2-4)+3*poj(ll/2-3)+5*poj(ll/2-2)+7*poj(ll/2-1)+9*poj(ll/2)+poj(p/2)+3*poj(p/2-1)+5*poj(p/2-2)+7*poj(p/2-3)+9*poj(p/2-4);
    if(ll%2==0)ret+=poj(ll/2-4)+poj(ll/2-3)+poj(ll/2-2)+poj(ll/2-1)+poj(ll/2);
    if(p%2)ret+=poj(p/2)+poj(p/2-1)+poj(p/2-2)+poj(p/2-3)+poj(p/2-4);
    ret%=MOD;
    ret+=10*reku(ll/2+1,p/2-5);
    ret%=MOD;
    return ret;
}
int main()
{
    scanf("%lld%lld",&l,&r);
    dp[1]=1;
    dp[0]=1;
    dp[2]=2;
    dp[3]=2;
    dp[4]=4;
    dp[5]=4;
    dp[6]=6;
    dp[7]=6;
    dp[8]=10;
    dp[9]=10;
    dp[10]=13;
    for(lld i=11;i<=1000;++i){
        dp[i]=dp[i/2]+dp[i/2-1]+dp[i/2-2]+dp[i/2-3]+dp[i/2-4];
        dp[i]%=MOD;
    }
    for(lld i=0;i<=min(r,(lld)999);++i)m[i]=dp[i];
    if(l<1000){
        for(lld i=l;i<=min(r,(lld)1000);++i)wynik+=dp[i];
        wynik%=MOD;
        l=min(r,(lld)1000)+1;
    }
    //cout<<poj(10000000000000000)<<endl;
    printf("%lld",(wynik+reku(l,r))%MOD);
    return 0;
}
/*
235189
235189
235968
235968
237066
237066
237834
237834
239090
239090
239897
239897
240992
240992
241768
241768
242952
242952
243648
243648
244633
244633
245330
245330
246524
*/
