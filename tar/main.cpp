#include <bits/stdc++.h>
#define lld long long

using namespace std;

lld x,n,suma,wyn,x1;

int main()
{
    scanf("%lld",&x1);
    scanf("%lld",&n);
    wyn=x1*n;
    for(int i=0;i<n;++i){
        scanf("%lld",&x);
        suma+=x;
    }
    printf("%lld",wyn-suma+x1);
    return 0;
}
