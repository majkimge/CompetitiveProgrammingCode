#include <bits/stdc++.h>
#define mp make_pair
#define lld long long
#define f first
#define s second
#define pb push_back
#define MAX 1000009
using namespace std;

lld n,m,a,b,c,x,qq;
priority_queue<pair<lld,lld> >q;
vector<pair<lld,lld> >v[MAX];
lld droga[MAX];

void dijstra(){
    while(!q.empty()){
        lld pierwszy=q.top().f*-1;
        lld drugi=q.top().s;
        q.pop();
        if(droga[drugi]!=pierwszy) continue;
        for(int i=0;i<v[drugi].size();++i){
            if(droga[drugi]+v[drugi][i].f<droga[v[drugi][i].s]){
                droga[v[drugi][i].s]=droga[drugi]+v[drugi][i].f;
                q.push(mp(droga[v[drugi][i].s]*-1,v[drugi][i].s));
            }
        }

    }

}

int main()
{
    scanf("%lld%lld%lld",&n,&m,&qq);
    for(int i=0;i<m;++i){
        scanf("%lld%lld%lld",&a,&b,&c);
        v[a].pb(mp(c,b));
        v[b].pb(mp(c,a));
    }
    for(int i=2;i<=n;++i){
        droga[i]=999999999;
    }
    q.push(mp(0,1));
    dijstra();
    for(int i=0;i<qq;++i){
        scanf("%lld",&x);
        cout<<droga[x]<<endl;
    }


    return 0;
}
