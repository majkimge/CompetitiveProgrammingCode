#include <bits/stdc++.h>

#define lld long long
#define MOD 1000000033
using namespace std;

lld a=1;
lld b=1;
lld c=1;
lld d=2;
lld a1=1;
lld b1=1;
lld c1=1;
lld d1=2;
lld n;
int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n-1;i++){
        a=b%MOD;
        b=c%MOD;
        c=d%MOD;
        d=(a+c)%MOD;
    }
    printf("%lld",b);
    return 0;
}
