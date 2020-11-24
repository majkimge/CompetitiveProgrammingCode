#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009

using namespace std;

lld a,b,c,wynik=1;

int main()
{
    scanf("%lld%lld%lld",&a,&b,&c);
    for(lld i=b+1;i<=a;++i){
        wynik*=(i%c);
        wynik%=c;
        if(wynik==0) break;
    }
    printf("%lld",wynik);
    return 0;
}
