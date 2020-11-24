#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 109
#define INF 1000000000

using namespace std;

lld n,d,a,b,w,k,s,e;

lld odl[109];
lld odw[MAX];
vector<pair<pair<lld,lld>, lld> >kraw[MAX];
priority_queue <pair<pair<lld,lld>, lld> >q;
vector<pair<lld,lld> >drogi[MAX];



int cmp(pair<lld,lld> t1,pair<lld,lld> t2){
    if((t2.f<t1.f&&t2.s<=t1.s)||(t2.f<=t1.f&&t2.s<t1.s)){
        return 0;//better second
    }else if((t2.f>t1.f&&t2.s>=t1.s)||(t2.f>=t1.f&&t2.s>t1.s)){
        return 1;//worse second
    }else if((t2.f==t1.f&&t2.s==t1.s)){
        return 2;//same
    }else {
        return 3;//equal
    }
}

void dijkstra(){
    while(!q.empty()){
        pair<pair<lld,lld>, lld> temp=q.top();
        pair<lld,lld> kos=temp.f;
        lld z=temp.s;

    }
}

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&d);
    scanf("%lld",&s);
    scanf("%lld",&e);
    for(int i=0;i<d;++i){
        scanf("%lld",&a);
        scanf("%lld",&b);
        scanf("%lld",&w);
        scanf("%lld",&k);
        kraw[a].pb(mp(mp(w,k),b));
        kraw[b].pb(mp(mp(w,k),a));
    }
    for(int i=1;i<=n;++i){
        odl[i]=INF;
    }
    odl[s]=0;
    drogi[s].pb(mp(0,0));
    q.push(s);
    bfs();
     /*for(int i=1;i<=n;++i){
        for(int j=0;j<drogi[i].size();++j){
            cout<<drogi[i][j].f<<" "<<drogi[i][j].s<<endl;
        }
        cout<<endl;
    }*/
    cout<<drogi[e].size();
    return 0;
}
