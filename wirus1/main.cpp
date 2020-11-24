#include <bits/stdc++.h>

#define lld long long
#define mp make_pair
#define f first
#define s second
#define INF 1000000000000

using namespace std;

lld a,c,n,x,wyn,wyn1;

int main()
{
    scanf("%lld",&a);
    scanf("%lld",&c);
    scanf("%lld",&n);
    scanf("%lld",&x);
    lld t1=x;
    lld t2=x;
    t1=(a*t1+c)%n;
    //t2=(a*t2+c)%n;
    t2=(a*((a*t2+c)%n)+c)%n;
        wyn++;


    while(t1!=t2){
        t1=(a*t1+c)%n;
        //t2=(a*t2+c)%n;
       t2=(a*((a*t2+c)%n)+c)%n;
        wyn++;
    }
    t1=(a*t1+c)%n;
    t2=(a*t2+c)%n;
    t2=(a*t2+c)%n;
        wyn1++;


    while(t1!=t2){
        t1=(a*t1+c)%n;
       t2=(a*((a*t2+c)%n)+c)%n;
        //t2=(a*t2+c)%n;
        wyn1++;
    }
    t2=x;

    //cout<<t1<<t2;
    while(t1!=t2){
        //cout<<"B";
        t1=(a*t1+c)%n;
        t2=(a*t2+c)%n;
        wyn1++;
    }
    printf("%lld",wyn1);
    return 0;
}
