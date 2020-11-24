#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define MAX 100009
#define INF 2000000000

using namespace std;

lld n,a,best;

lld wys[MAX];
lld koszt[MAX];
lld wyny[MAX];



int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&wys[i]);
    }
    scanf("%lld",&a);
    koszt[1]=a;
    for(int i=2;i<=n;++i){
        scanf("%lld",&a);
        koszt[i]=koszt[i-1]+a;
        //cout<<koszt[i];
    }

    for(int i=2;i<=n;++i){
        best=INF;
        for(int j=1;j<i;++j){

                best=min(best,(wys[i]-wys[j])*(wys[i]-wys[j])+koszt[i-1]-koszt[j]+wyny[j]);


        }
        wyny[i]=best;
    }
    printf("%lld",wyny[n]);
    return 0;
}
