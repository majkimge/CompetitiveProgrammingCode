#include <bits/stdc++.h>

#define lld long long
#define mp make_pair
#define f first
#define s second
#define N 1000009
#define M 1000009
#define MOD 1000000007

using namespace std;

lld n,m,k,co,a1,b1,wyn,pojw,pojk;
lld wier[N];
lld kol[M];
char co1;

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&m);
    scanf("%lld",&k);
    for(int i=0;i<n;++i){
        wier[i]=((m*(m-1))/2+m*m*i)%MOD;
    }
    for(int i=0;i<m;++i){
        kol[i]=(n+(((n-1)*n)/2)*m+n*i)%MOD;
    }
    wyn=(((n*m)%MOD)*(((n*m)%MOD)-1))/2;
    for(int i=0;i<k;++i){
        scanf("%c",&co1);
        scanf("%lld",&a1);
        scanf("%lld",&b1);
        if(co=='R'){
            wyn+=wier[a1-1]*(b1-1);
            wyn%=MOD;
            wier[a1-1]+=wier[a1-1]*(b1-1);
            wier[a1-1]%=MOD;
        }else{
            wyn+=kol[a1-1]*(b1-1);
            wyn%=MOD;
            kol[a1-1]+=kol[a1-1]*(b1-1);
            kol[a1-1]%=MOD;
        }
    }
    printf("%lld",wyn);
    return 0;
}
