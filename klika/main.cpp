#include <bits/stdc++.h>
#define lld long long
#define MAX 2000
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000

using namespace std;

lld n;
lld oile;
lld oile1;
lld wyn[MAX];
lld kraw[MAX][MAX];
lld mac[MAX][MAX];
bool dok=1;
bool start=0;

int main()
{
    scanf("%lld",&n);
    wyn[3]=1;
    wyn[4]=2;
    oile=1;
    oile1=1;
    for(int i=5;i<=n;++i){
        if(i%2){
            oile1++;
            oile+=oile1;
        }
        wyn[i]=wyn[i-1]+oile;
    }
    printf("%lld\n",wyn[n]);

    for(int i=1;i<=n*(n-1)/2;++i){
        printf("%d",dok);
        dok=!dok;
    }

    return 0;
}
