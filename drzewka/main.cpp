#include <bits/stdc++.h>

#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back


using namespace std;

lld n,x,y,pole,br;

pair<lld,lld> wier[2];
pair<lld,lld> pier;

int main()
{
    scanf("%lld",&n);

    scanf("%lld",&x);
    scanf("%lld",&y);
    pier=mp(x,y);
    scanf("%lld",&x);
    scanf("%lld",&y);
    wier[0]=mp(x,y);
    if(wier[0].f-pier.f==0){
        br+=abs(wier[0].s-pier.s);
    }else if(abs(wier[0].s-pier.s)==0){
        br+=abs(wier[0].f-pier.f);
    }else if(abs(wier[0].f-pier.f)!=1&&abs(wier[0].s-pier.s)!=1&&__gcd(abs(wier[0].f-pier.f),abs(wier[0].s-pier.s))!=0){
        br+=__gcd(abs(wier[0].f-pier.f),abs(wier[0].s-pier.s));
    }else{br++;}
    //cout<<br;
    scanf("%lld",&x);
    scanf("%lld",&y);
    wier[1]=mp(x,y);

    if(wier[0].f-wier[1].f==0){
        br+=abs(wier[0].s-wier[1].s);
    }else if(abs(wier[0].s-wier[1].s)==0){
        br+=abs(wier[0].f-wier[1].f);
    }else if(abs(wier[0].f-wier[1].f)!=1&&abs(wier[0].s-wier[1].s)&&__gcd(abs(wier[0].f-wier[1].f),abs(wier[0].s-wier[1].s))!=0){
        br+=__gcd(abs(wier[0].f-wier[1].f),abs(wier[0].s-wier[1].s));
    }else{br++;}
    //cout<<br;
    //br+=__gcd(abs(wier[0].f-wier[1].f),abs(wier[0].s-wier[1].s));
    pole+=((wier[0].f-pier.f)*(wier[1].s-pier.s)-(wier[0].s-pier.s)*(wier[1].f-pier.f))/2;
    for(int i=3;i<n;++i){
        scanf("%lld",&x);
        scanf("%lld",&y);
        wier[0]=wier[1];
        wier[1]=mp(x,y);
        pole+=((wier[0].f-pier.f)*(wier[1].s-pier.s)-(wier[0].s-pier.s)*(wier[1].f-pier.f))/2;
        if(wier[0].f-wier[1].f==0){
        br+=abs(wier[0].s-wier[1].s);
    }else if(abs(wier[0].s-wier[1].s)==0){
        br+=abs(wier[0].f-wier[1].f);
    }else if(abs(wier[0].f-wier[1].f)!=1&&abs(wier[0].s-wier[1].s)!=1&&__gcd(abs(wier[0].f-wier[1].f),abs(wier[0].s-wier[1].s))!=0){
        br+=__gcd(abs(wier[0].f-wier[1].f),abs(wier[0].s-wier[1].s));
    }else{br++;}
    //cout<<br;
    }
    pole=abs(pole);
     if(wier[1].f-pier.f==0){
        br+=abs(wier[1].s-pier.s);
    }else if(abs(wier[1].s-pier.s)==0){
        br+=abs(wier[1].f-pier.f);
    }else if(abs(wier[1].f-pier.f)!=1&&abs(wier[1].s-pier.s)!=1&&__gcd(abs(wier[1].f-pier.f),abs(wier[1].s-pier.s))!=0){
        br+=__gcd(abs(wier[1].f-pier.f),abs(wier[1].s-pier.s));
    }else{br++;}
    //br+=n-1;
    cout<<pole<<endl;
    cout<<br<<endl;
    cout<<pole-br/2+1;
    return 0;
}
/*5
2 1
2 6
10 6
10 1
-2 0*/

