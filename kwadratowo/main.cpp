#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 2009
#define DOK 10000



using namespace std;

lld n,a,tab[MAX*MAX],kt,odl[MAX*MAX],INF=(lld)100000000000000000;
vector<pair<lld,lld> >kraw[MAX*MAX];
priority_queue<pair<lld,lld> >q;
vector<lld>lasty;

void dijkstra(){
    while(!q.empty()){
        lld od=-q.top().f;
        lld gdz=q.top().s;
        q.pop();
        if(odl[gdz]==od){
            for(int i=0;i<kraw[gdz].size();++i){
                if(odl[kraw[gdz][i].s]>od+kraw[gdz][i].f){
                    odl[kraw[gdz][i].s]=od+kraw[gdz][i].f;
                    q.push(mp(-odl[kraw[gdz][i].s],kraw[gdz][i].s));
                }
            }
        }
    }
}

int main()
{
    scanf("%lld",&a);
    scanf("%lld",&n);
    for(int i=0;i<MAX*MAX;++i){
        odl[i]=INF;
    }
    for(int i=0;i<2*n+1;++i){
        for(int j=0;j<n+(i%2);++j){
            ++kt;
            scanf("%lld",&a);

            if(i==2*n||((i%2)&&j==0)){
                lasty.pb(kt);

            }
            if(i==0||((i%2)&&j==n)){
                q.push(mp(-a,kt));
                odl[kt]=a;
                //cout<<"X"<<kt<<" "<<a<<endl;
            }

            if(i%2){
                if(j){
                    kraw[kt].pb(mp(a,kt-1));
                    kraw[kt-1].pb(mp(a,kt));
                    kraw[kt-n-1].pb(mp(a,kt));
                    kraw[kt].pb(mp(a,kt-n-1));
                }
                if(j!=n){
                    kraw[kt-n].pb(mp(a,kt));
                    kraw[kt].pb(mp(a,kt-n));
                }

            }else{
                if(i!=0){


                    kraw[kt-n-1].pb(mp(a,kt));
                    kraw[kt].pb(mp(a,kt-n-1));


                    kraw[kt-n].pb(mp(a,kt));
                    kraw[kt].pb(mp(a,kt-n));
                    kraw[kt-2*n-1].pb(mp(a,kt));
                    kraw[kt].pb(mp(a,kt-2*n-1));

                }
            }
        }
    }

    dijkstra();
    lld mini=INF;
    /*for(int i=1;i<=kt;++i){
        //cout<<odl[i]<<endl;
    }*/
    for(int i=0;i<lasty.size();++i){
        mini=min(mini,odl[lasty[i]]);
    }
    printf("%lld",mini);
    return 0;
}
