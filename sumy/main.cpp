#include <bits/stdc++.h>
#define lld long long
#define MAX 50009
#define INF 2000000000

using namespace std;

lld n,k,temp,p,akt;
lld reszty[MAX];
lld odw[MAX];
lld a[5009];

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&a[i]);

    }sort(a,a+n);
    p=a[0];
    for(int i=1;i<p;++i){
        reszty[i]=INF;

    }

    for(int i=1;i<n;++i){
        akt=a[i];
        while(odw[akt%p]<i&&akt<1000000000){
            reszty[akt%p]=min(akt,reszty[akt%p]);
            odw[akt%p]=i;
            akt+=a[i];
        }
    }
    for(int i=1;i<n;++i){
        akt=a[i];
        for(int j=0;j<p;++j){
        reszty[(j+akt)%p]=min(reszty[(j+akt)%p],reszty[j]+akt);
        //cout<<reszty[j]<<endl;
    }
    }

    scanf("%lld",&k);
    for(int i=0;i<k;++i){
        scanf("%lld",&temp);
        if(temp>=reszty[temp%p]){
            printf("TAK\n");
        }else{
            printf("NIE\n");
        }
    }
    return 0;
}
