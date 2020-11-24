#include <bits/stdc++.h>

#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back


using namespace std;

lld n,x,y,pole,br=0;

pair<lld,lld> wier[2];
pair<lld,lld> pier;



using namespace std;

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&x);
        scanf("%lld",&y);
        if(i==0){
            pier=mp(x,y);
            wier[0]=pier;
        }else
        if(i==1){
            wier[1]=mp(x,y);
            if(wier[0].f-wier[1].f==0){
                br+=abs(wier[0].s-wier[1].s);
            }else if(abs(wier[0].s-wier[1].s)==0){
                br+=abs(wier[0].f-wier[1].f);
            }else if(abs(wier[0].f-wier[1].f)!=1&&abs(wier[0].s-wier[1].s)!=1&&__gcd(abs(wier[0].f-wier[1].f),abs(wier[0].s-wier[1].s))!=0){
                br+=__gcd(abs(wier[0].f-wier[1].f),abs(wier[0].s-wier[1].s));
            }else{br++;}
            pole+=(wier[0].f*wier[1].s-wier[1].f*wier[0].s);
            //cout<<br;
        }else{
            wier[0]=wier[1];
            wier[1]=mp(x,y);
            if(wier[0].f-wier[1].f==0){
                br+=abs(wier[0].s-wier[1].s);
            }else if(abs(wier[0].s-wier[1].s)==0){
                br+=abs(wier[0].f-wier[1].f);
            }else if(abs(wier[0].f-wier[1].f)!=1&&abs(wier[0].s-wier[1].s)!=1&&__gcd(abs(wier[0].f-wier[1].f),abs(wier[0].s-wier[1].s))!=0){
                br+=__gcd(abs(wier[0].f-wier[1].f),abs(wier[0].s-wier[1].s));
            }else{br++;}
            pole+=(wier[0].f*wier[1].s-wier[1].f*wier[0].s);
            //cout<<br;
        }

    }
    if(wier[1].f-pier.f==0){
        br+=abs(wier[1].s-pier.s);
    }else if(abs(wier[1].s-pier.s)==0){
        br+=abs(wier[1].f-pier.f);
    }else if(abs(wier[1].f-pier.f)!=1&&abs(wier[1].s-pier.s)!=1&&__gcd(abs(wier[1].f-pier.f),abs(wier[1].s-pier.s))!=0){
        br+=__gcd(abs(wier[1].f-pier.f),abs(wier[1].s-pier.s));
    }else{br++;}
    pole+=(wier[1].f*pier.s-pier.f*wier[1].s);

    pole=abs(pole)/2;
    //cout<<pole<<endl;
    //cout<<br<<endl;
    cout<<pole-br/2+1<< endl;
    return 0;
}
