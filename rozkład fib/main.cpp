#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define ss second
#define MAX 1000009
#define INF 1000000000000000009
#define MOD 1000696969

using namespace std;

lld p,k;
lld fib[200];
int main()
{
    scanf("%lld",&p);
    fib[0]=0;
    fib[1]=1;

    for(int i=2;i<100;++i){
        fib[i]=fib[i-1]+fib[i-2];
        if(fib[i]>INF/2) break;
    }
    for(int g=0;g<p;++g){
        scanf("%lld",&k);
        int kt=1;
        lld mini=INF;
        //cout<<mini;
        lld wyn=0;
        lld co=k;
        while(co!=0){
           //cout<<co;
           kt=1;
            while(fib[kt-1]<co){
                mini=min(mini,abs(fib[kt]-co));
                //if(wyn==0) cout<<mini<<endl;
                kt++;
            }
            wyn++;
            co=mini;
            mini=INF;
        }
        printf("%lld\n",wyn);
    }

    return 0;
}
