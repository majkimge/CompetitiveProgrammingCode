#include <bits/stdc++.h>

#define lld long long
#define MAX 500009
#define pb push_back
using namespace std;

lld n,a,b,c,d,temp;
vector<lld> kraw[MAX];
lld dlug[MAX];
vector<lld> odw;
lld tdlu,tempi,moda=1,pocz,kon,nww=1;
int main()
{
    scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&d);
c=c+1;
    //cout<<__gcd(n,a);
    for(int i=1;i<=n;++i){
        scanf("%lld",&temp);
        kraw[i].push_back(temp);
    }
    for(int i=1;i<=n;++i){
        tdlu=0;
        tempi=i;
        odw.clear();
        while(dlug[tempi]==0){
            odw.pb(tempi);
            dlug[tempi]=1;#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAX = 1000005;

long long a, b, period = 1ll;
int cikl[ MAX ], overflow = 0;
int n, c, d, niz[ MAX ];

        tdlu++;
            tempi=kraw[tempi][0];
        }
        for(int j=0;j<odw.size();++j){
            dlug[odw[j]]=tdlu;
        }
    }
    for(int i=c;i<=n-d;++i){
        temp=__gcd(moda,dlug[i]);
        //cout<<temp;
        moda=(moda*dlug[i])/temp;

        //nww*=dlug[i]
    }
//cout<<moda;
    if((a-1)%moda==0){
        pocz=a;
    }else{
        pocz=a+moda-(a-1)%moda;
    }
    if((b-1)%moda==0){
        kon=b;
    }else{
        kon=b-(b-1)%moda;
    }
    if(pocz<=b&&kon>=a){
        printf("%lld",(kon-pocz)/moda+1);
    }else{
        printf("0");
    }

    //cout<<"B:"<<moda<<pocz<<kon;

    return 0;
}
