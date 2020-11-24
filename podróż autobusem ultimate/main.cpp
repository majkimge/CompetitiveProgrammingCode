#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define INF 1000000000000000

using namespace std;

lld n,m,p,t,a,b,c,d,g,h,wynik;
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
    for(int i=2;i<=n;++i){
        kiedy[i].insert(mp(0,inf));
    }
    kiedy[1].insert(mp(0,0));
    sort(kraw,kraw+m);
    for(int i=0;i<m;++i){
        pair<lld,lld> temp=*(--kiedy[kraw[i].s.s].upper_bound(mp(kraw[i].f.f.f,inf)));

        lld pocz=kraw[i].f.s.s-(*(--kiedy[kraw[i].s.f].upper_bound(mp(kraw[i].f.s.f,inf)))).f+(*(--kiedy[kraw[i].s.f].upper_bound(mp(kraw[i].f.s.f,inf)))).s;
        //cout<<i<<" "<<temp.f<<" "<<temp.s<<" "<<pocz<<endl;
        if(kraw[i].f.f.f-temp.f+temp.s>pocz+kraw[i].f.f.f-kraw[i].f.f.s){
            if(temp.f==kraw[i].f.f.f) kiedy[kraw[i].s.s].erase(temp);
            kiedy[kraw[i].s.s].insert(mp(kraw[i].f.f.f,pocz+kraw[i].f.f.f-kraw[i].f.f.s));
        }
    }
    wynik=t-(*(--kiedy[p].upper_bound(mp(t,inf)))).f+(*(--kiedy[p].upper_bound(mp(t,inf)))).s;
    if(wynik>inf-1){
        printf("-1");
    }else{
        printf("%lld",wynik);
    }

    return 0;
}
