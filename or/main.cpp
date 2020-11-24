#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 500009
#define INF 1000000009

using namespace std;

lld a,b,wynik;
lld poty[62];
vector<lld> roz;


void rr(lld co){
    while(co>0){
        //cout<<co;
        if(co%2==0){
            roz.pb(0);
        }else{
            roz.pb(1);
        }
        co=co/2;
    }
}

int main()
{
    poty[0]=1;
    for(int i=1;i<=61;++i){
        poty[i]=poty[i-1]*2;
    }
    scanf("%lld",&a);
    scanf("%lld",&b);
    lld pocz=0;
    lld dl=-1;
    rr(b);
    lld od=0;
    for(int i=0;i<roz.size()/2;++i){
        swap(roz[i],roz[roz.size()-1]);
    }
    for(int i=0;i<roz.size();++i){
        //cout<<roz[i]<<" ";
    }
    for(int i=0;i<roz.size();++i){

        pocz+=poty[roz.size()-1-i]*roz[i];
        dl++;
        if(pocz>=a){
            //od=pocz-pot[roz.size()-1-i];
            break;
        }
    }
    //cout<<dl;
    int czy=0;
    lld kon=0;
    for(int i=dl;i>=0;--i){
        if(czy&&roz[i]==0){
            czy=1;
            kon=pocz+poty[roz.size()-1-i];
            for(int j=dl+1;j<roz.size();++j){
                kon+=poty[roz.size()-1-j];
            }
        }else if(!czy&&roz[i]){
            kon-=poty[roz.size()-1-i];
            break;
        }
    }
    //cout<<"X"<<kon<<"X";
    lld rozni=b-pocz+1;
    lld rozsz=1;
    while(rozsz<rozni){
        rozsz<<=1;
    }
    lld kon1=pocz+rozsz-1;
    wynik=kon1-a+1+(poty[roz.size()]-kon1);
    printf("%lld",wynik-1);
    return 0;
}
