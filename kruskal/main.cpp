#include <bits/stdc++.h>
#define lld long long
#define MAX 100009
#define LOG 18
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000

using namespace std;

lld n,e,a,b,w,czy;
vector<pair<lld,lld> > kraw[MAX];
lld wier[MAX];
lld rep[MAX];
pair< lld,pair<lld,lld> > kr[MAX];
pair< lld,pair<lld,lld> > dbr[MAX];

lld Find(lld x){
    if(rep[x]!=x){
        rep[x]=Find(rep[x]);
    }else{
        return x;
    }

}

lld Union(lld s,lld d){
    lld s1=Find(s);
    lld d1=Find(d);
    if(s1!=d1){
        rep[s1]=rep[d1];
        return 1;
    }else{
        return 0;
    }
}


int main()
{
    scanf("%lld",&n);
    scanf("%lld",&e);
    for(int i=0;i<n;++i){
        rep[i]=i;
    }
    for(int i=0;i<e;++i){
        scanf("%lld",&a);
        scanf("%lld",&b);
        scanf("%lld",&w);
        kraw[a].pb(mp(w,b));
        kraw[b].pb(mp(w,a));
        kr[i]=mp(w,(mp(a,b)));
    }
    sort(kr,kr+e);

    for(int i=0;i<e;++i){
        czy=Union(kr[i].s.f,kr[i].s.s);
        if(czy){
            dbr[i]=mp(kr[i].f,(mp(kr[i].s.f,kr[i].s.s)));
        }
    }
    for(int i=0;i<e;++i){

        if(dbr[i].s.s!=0){
            cout<<dbr[i].s.s<<" "<<dbr[i].s.f<<" "<<dbr[i].f<<endl;
        }
    }

    return 0;
}

/*7
11
1 2 7
1 4 5
2 4 9
2 5 7
2 3 8
3 5 5
4 5 15
4 6 6
5 6 8
5 7 9
6 7 11*/
