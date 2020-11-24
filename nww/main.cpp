#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 100000

using namespace std;

lld INF=2000000000000000000;
map<lld,pair<lld,lld> > m;
lld z,n;

pair<lld,lld> lcm2(lld nn){
    lld od=(lld)sqrt((double)nn);
    pair<lld,lld> ret=mp(0,0);
    for(lld i=max(od-4,(lld)1);i<=od+4;++i){
        if(i*(i+1)==nn){
            ret=mp(i,i+1);
            break;
        }
    }
    return ret;
}

pair<lld,lld> lcm3np(lld nn){
    lld od=(lld)cbrt((double)nn);
    pair<lld,lld> ret=mp(0,0);
    for(lld i=max(od-8,(lld)1);i<=od+8;++i){
        if(i%2==1){
            if(i*(i+1)*(i+2)==nn){
                ret=mp(i,i+2);
                break;
            }
        }

    }
    return ret;
}

pair<lld,lld> lcm3p(lld nn){
    lld od=(lld)cbrt((double)nn*2);
    pair<lld,lld> ret=mp(0,0);
    for(lld i=max(od-8,(lld)1);i<=od+8;++i){
        if(i%2==0){
            if(i*(i+1)*(i+2)==2*nn){
                ret=mp(i,i+2);
                break;
            }
        }

    }
    return ret;
}

int main()
{
    for(lld i=1;i<=MAX;++i){
        lld lcm=i;
        for(lld j=1;j<=70;++j){

            if((i+j)/__gcd(lcm,(i+j))>INF/lcm)break;
            lcm=lcm/__gcd(lcm,(i+j));
            lcm*=(i+j);
            if(m[lcm].f==0)m[lcm]=mp(i,i+j);
            //if(i<8&&j<5)cout<<i<<" "<<j<<" "<<m[lcm].f<<endl;
        }
    }
    scanf("%lld",&z);
    for(int xd=0;xd<z;++xd){
        scanf("%lld",&n);
        pair<lld,lld> tem=m[n];
        //if(n>(lld)1000000)
        if(tem.f){
            if(lcm2(n).f)tem=min(tem,lcm2(n));

        }else{
            tem=lcm2(n);
        }
        if(tem.f){
            if(lcm3np(n).f)tem=min(tem,lcm3np(n));
        }else{
            tem=lcm3np(n);
        }//cout<<tem.f;
        if(tem.f){
            if(lcm3p(n).f)tem=min(tem,lcm3p(n));
        }else{
            tem=lcm3p(n);
        }
        if(tem.f){
            printf("%lld %lld\n",tem.f,tem.s);
        }else{
            printf("NIE\n");
        }
    }
    return 0;
}
