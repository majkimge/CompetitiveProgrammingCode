#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define MAX 1000009
using namespace std;

lld a,b,k;
lld fib[MAX];
lld wynik=0;
lld temp=0,p,o,okres,ogran;
int main()
{
    scanf("%lld%lld%lld",&a,&b,&k);
    fib[1]=1%k;
    fib[2]=1%k;
    for(int i=3;i<=b;++i){
        fib[i]=fib[i-1]+fib[i-2];
        fib[i]=fib[i]%k;
        if(fib[i]==0){
            if(temp==0){
                temp++;
                p=i;
            }else{
                o=i;
                break;
            }

        }
    }
    okres=o-p;
    if(a%okres==0) wynik=(b-b%okres-a)/okres+1;
    else wynik=(b-b%okres-(a+(okres-a%okres)))/okres+1;

    //for(int i=a;i<=b;++i){


    //}
    printf("%lld",wynik);
    return 0;
}
