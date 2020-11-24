#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define INF 1000000009
#define MOD 1000696969

using namespace std;

lld check(lld co){
    lld wyn=co;
    while(co>0){
        if(co%10==0||co%10==1){
            co/=10;
        }else{
            return 0;
        }
    }
    return wyn;
}

int main()
{
    lld dwa=6;
    for(int i=1;i<100000000;++i){
        dwa+=6;
        if(check(dwa)){
            printf("%lld",dwa);
            break;
        }
    }
    return 0;
}
