#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 10009
#define INF 100000000009
#define llu unsigned long long
#define lld long long

using namespace std;

lld a,b;
lld wynik;
int main()
{
    scanf("%lld%lld",&a,&b);
    if(a<=1&&b<=1){
        printf("Bob");
    }else{
        if(abs(a-b)<2){
            printf("Bob");
        }else{
            printf("Alicja");
        }

    }


    return 0;
}
