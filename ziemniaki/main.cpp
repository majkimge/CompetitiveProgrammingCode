#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 100009
#define INF 2000000000

using namespace std;

lld n,d,x,y,xx,yy,miniy,minix,pos,ln;
pair<lld,lld> tab[MAX];
pair<lld,lld> potab[MAX];
vector<lld> miny;
lld otoczka[MAX];
lld minx,xma,yma,ls,odlmega;
long double odl;

bool cmp(pair<lld,lld> a1,pair<lld,lld> a2){
    if(!a1.f&&!a1.s){
        return 1;
    } else if(!a2.f&&!a2.s){
        return 0;
    }else

    if(a1.f*a2.s-a1.s*a2.f<0){
        return 1;
    }else if(a1.f*a2.s-a1.s*a2.f>0){
        return 0;
    }else{
        if(abs(a1.f)+abs(a1.s)>abs(a2.f)+abs(a2.s)) return 1;
        return 0;
    }
}


int main()
{
    scanf("%lld",&n);
    scanf("%lld",&d);
    for(int i=0;i<n;++i){
        scanf("%lld",&x);
        scanf("%lld",&y);
        tab[i]=mp(x,y);
    }
    xma=INF;
    yma=INF;
    for(int i=0;i<n;++i){
        if(tab[i].s<yma||(tab[i].s==yma&&tab[i].f<xma)){
            xma=tab[i].f;
            yma=tab[i].s;
        }
    }


    for(int i=0;i<n;++i){
        tab[i]=mp(tab[i].f-xma,tab[i].s-yma);
    }

    sort(tab,tab+n,cmp);
    tab[n+1]=mp(0,0);

    if(n<=1){
        cout<<"TAK";
    }else if(n==2){
        if(d>=2*sqrt(abs((tab[1].f-tab[0].f)*(tab[1].f-tab[0].f)+(tab[1].s-tab[0].s)*(tab[1].s-tab[0].s)))){cout<<"TAK";}else cout<<"NIE";
    }else{
        otoczka[++ls]=0;
        otoczka[++ls]=1;
        for(int i=2;i<=n;++i){
            //ln=otoczka.size();
            //pos=-1;
            while(ls>1&&(((tab[otoczka[ls]].f - tab[otoczka[ls-1]].f) * (tab[i].s - tab[otoczka[ls]].s) - (tab[otoczka[ls]].s - tab[otoczka[ls-1]].s)
                * (tab[i].f - tab[otoczka[ls]].f))<=0)){
                    ls--;

                //cout<<pos;

            }
            otoczka[++ls]=i;

        }
        for(int i=1;i<ls;++i){
                //cout<<otoczka[i]<<" ";
                //cout<<sqrt(abs((potab[otoczka[i]].f-potab[otoczka[i-1]].f)*(potab[otoczka[i]].f-potab[otoczka[i-1]].f)
                      //+(potab[otoczka[i]].f-potab[otoczka[i-1]].f)*(potab[otoczka[i]].s-potab[otoczka[i-1]].s)))<<endl;
            odl+=sqrt(abs((tab[otoczka[i]].f-tab[otoczka[i-1]].f)*(tab[otoczka[i]].f-tab[otoczka[i-1]].f)
                      +(tab[otoczka[i]].s-tab[otoczka[i-1]].s)*(tab[otoczka[i]].s-tab[otoczka[i-1]].s)));
        }
        odlmega=(lld)ceil(odl);
        if(odlmega<=(long double)d){
            cout<<"TAK";//cout<<odl;
        }else{

            cout<<"NIE";//cout<<odl;
        }
    }


    return 0;
}
