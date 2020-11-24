#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define piii pair<int,pair<int,int> >
#define pii pair<lld,lld>
#define MAX 100009
#pragma GCC optimalize ("ofast")

using namespace std;

int n,wynik;
pii points[MAX];
lld a,b;
lld INF=100000000000000000;
set<pii> s[MAX];

int czy(int gdz, pii wsp){
    pii przed=(*(--s[gdz].lower_bound(wsp)));
    pii po=(*(s[gdz].lower_bound(wsp)));
    //cout<<gdz<<" "<<przed.f<<" "<<wsp.f<<" "<<po.f<<endl;
    if(wsp.f-przed.f>=przed.s-wsp.s&&-wsp.f+po.f>=po.s-wsp.s){
        return 1;
    }
    return 0;
}

int bin(int l, int p, pii co){
    int ss=(l+p)/2;
    int ret=p+1;
    while(l<=p){
        ss=(l+p)/2;
        if(czy(ss,co)){
            ret=ss;
            p=ss-1;
        }else{
            l=ss+1;
        }
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        s[i].insert(mp(-INF,0));
        s[i].insert(mp(INF,0));
        scanf("%lld%lld",&a,&b);
        points[i]=mp(-b,a);
    }
    sort(points,points+n);
    points[0].f=-points[0].f;
    pii temp=mp(points[0].s,points[0].f);
    s[0].insert(temp);
    //cout<<temp.f<<" "<<temp.s<<endl;
    wynik=1;
    for(int i=1;i<n;++i){
        points[i].f=-points[i].f;
        pii temp=mp(points[i].s,points[i].f);

        int dok=bin(0,wynik-1,temp);
        if(dok==wynik)++wynik;
        s[dok].insert(temp);
    }
    printf("%d",wynik);
    return 0;
}
