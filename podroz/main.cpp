#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define INF 1000000000000000

using namespace std;

lld n,m,p,t,a,b,c,d,g,h;
lld inf = 1000000000000000;
set<pair<lld,lld> > kiedy[MAX];
pair<pair<pair<lld,lld>,pair<lld,lld> >,pair<lld,lld> >kraw[MAX];

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&m);
    scanf("%lld",&p);
    scanf("%lld",&t);
    for(int i=0;i<m;++i){
        scanf("%lld",&a);
        scanf("%lld",&b);
        scanf("%lld",&c);
        scanf("%lld",&d);
        scanf("%lld",&g);
        scanf("%lld",&h);
        kraw[i]=mp(mp(mp(h,g),mp(c,d)),mp(a,b));
    }
    sort(kraw,kraw+m);
    for(int i=2;i<=n;++i){
        kiedy[i].insert(mp((lld)0,inf));
    }
    kiedy[1].insert(mp((lld)0,0));
    for(int i=0;i<m;++i){
        a=kraw[i].s.f;
        b=kraw[i].s.s;
        h=kraw[i].f.f.f;
        g=kraw[i].f.f.s;
        c=kraw[i].f.s.f;
        d=kraw[i].f.s.s;
        lld najm=(*(--kiedy[a].lower_bound(mp(c,0)))).s;
        lld kd=(*(--kiedy[a].lower_bound(mp(c,0)))).f;

        najm+=d-kd;

        if(kiedy[a].lower_bound(mp(c,0))!=kiedy[a].end()){

            lld najmm=(*kiedy[a].lower_bound(mp(c,0))).s;
            lld kdd=(*kiedy[a].lower_bound(mp(c,0))).f;
            //cout<<kdd;
            if(najmm+(d-c)<najm&&kdd==c){
                najm=najmm+(d-c);
                kd=kdd;
            }
        }
        //cout<<a<<" "<<d<<" "<<kd<<" "<<najm<<endl;
        if(najm<inf){
            lld najm1=(*(--kiedy[b].lower_bound(mp(h,0)))).s;

            lld kd1=(*(--kiedy[b].lower_bound(mp(h,0)))).f;
            najm1+=h-kd1;
            if(kiedy[b].lower_bound(mp(h,0))!=kiedy[b].end()){
                lld najm11=(*kiedy[b].lower_bound(mp(h,0))).s;
                lld kd11=(*kiedy[b].lower_bound(mp(h,0))).f;
                if(najm11<najm1&&kd11==h){
                    najm1=najm11;
                }else if(najm11>=najm1&&kd11==h){
                    kiedy[b].erase(mp(kd11,najm11));
                }
            }
            if(najm1<inf){

                if(najm+h-g<najm1){
                    if(kiedy[b].lower_bound(mp(h,0))!=kiedy[b].end()){
                        lld najm11=(*kiedy[b].lower_bound(mp(h,0))).s;
                        lld kd11=(*kiedy[b].lower_bound(mp(h,0))).f;
                        if(kd11==h){
                            kiedy[b].erase(mp(kd11,najm11));
                        }
                    }
                    kiedy[b].insert(mp(h,najm+h-g));
                }
            }else{
                if(kiedy[b].lower_bound(mp(h,0))!=kiedy[b].end()){
                        lld najm11=(*kiedy[b].lower_bound(mp(h,0))).s;
                        lld kd11=(*kiedy[b].lower_bound(mp(h,0))).f;
                        if(kd11==h){
                            kiedy[b].erase(mp(kd11,najm11));
                        }
                    }
                kiedy[b].insert(mp(h,najm+h-g));
            }
        }
    }
    lld najm2=(*(--kiedy[p].lower_bound(mp(t,0)))).s;
    lld kd2=(*(--kiedy[p].lower_bound(mp(t,0)))).f;
    najm2+=t-kd2;
    if(kiedy[p].lower_bound(mp(t,0))!=kiedy[p].end()){
        lld najm22=(*kiedy[p].lower_bound(mp(t,0))).s;
        lld kd22=(*kiedy[p].lower_bound(mp(t,0))).f;
        if(najm22<najm2&&kd22==t) najm2=najm22;
    }
    //lld wynik=najm2+t-kd2;
    if(najm2<=t){
        printf("%lld",najm2);
    }else{
        printf("-1");
    }
    return 0;
}
/*
2 4 2 100
1 2 0 3 50 52
1 2 99 99 100 100
1 1 0 4 98 99
2 2 52 53 100 100

2 3 2 100
1 2 0 3 50 52
1 1 0 4 98 99
2 2 52 53 100 100
*/
