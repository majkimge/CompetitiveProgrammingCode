#include <bits/stdc++.h>

#define lld long long
#define MOD 1000000033
lld n;
lld wynik=1;
lld k=5;
using namespace std;

int main()
{
    scanf("%lld",&n);
    if(n>=3){
        wynik+=n-2;
    }
    for(int i=0;i<n/3-1;i++){
        //if(n%3==0&&i==n/3-2){
            wynik+=(((n-k)*(n-k+1))/2)%MOD;
        //}else{
            //wynik+=(((n-k)*(n-k+1))/2*(i+1))%MOD;
        //}
        wynik=wynik%MOD;
        k+=3;
    }
    printf("%lld",wynik%MOD);
    return 0;
}
