#include<bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 300009
#define pii pair<lld,lld>
#define pdd pair<double,double>
#define C 1000

using namespace std;

int n,m;
lld a,b;
pii zub[MAX];
pii osa[MAX];
pair<pii,pii> points[MAX*2];
set<pii> pros;
set<pii>::iterator it;
lld rep[MAX];
lld INF = 1000000009;
lld wynik[MAX];
lld rep1[MAX];
vector<int> nad[MAX];
lld ostwyny[MAX];

int Find(int x){
    if(rep[x]!=x)rep[x]=Find(rep[x]);
    return rep[x];
}

void Union(int x, int y){
    int rx=Find(x);
    int ry=Find(y);
    if(rx!=ry){
        rep[rx]=ry;
        wynik[ry]+=wynik[rx];
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lld%lld",&a,&b);
        zub[i]=mp(a,b);
        points[i]=mp(mp(-b,1),mp(a,i));
    }
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%lld%lld",&a,&b);
        osa[i]=mp(a,b);
        points[i+n]=mp(mp(-b,0),mp(a,i));
    }
    sort(points,points+n+m);
    pros.insert(mp(INF,-1));
    pros.insert(mp(0,0));
    for(int i=0;i<n+m;++i){
        if(points[i].f.s==0){

            it=(--pros.lower_bound(mp(points[i].s.f,0)));//
            while((*it).f>0&&(*it).s>points[i].s.s){//cout<<(*it).f<<" ";
                pros.erase(it);
                //--it;
                it=(--pros.lower_bound(mp(points[i].s.f,0)));
            }
            it=(pros.lower_bound(mp(points[i].s.f,0)));
            if((*it).f!=INF){
                rep1[points[i].s.s]=(*it).s;
            }else{
                rep1[points[i].s.s]=-1;
            }

            nad[(*it).s].pb(points[i].s.s);
            pros.insert(mp(points[i].s.f,points[i].s.s));
            //cout<<points[i].s.f;
        }else{
            it=(pros.lower_bound(mp(points[i].s.f,0)));
            if((*it).s!=-1){
                wynik[(*it).s]++;
            }
        }
    }
    for(int i=0;i<m;++i){
        rep[i]=i;
        //cout<<rep1[i]<<" ";
    }
    for(int i=m-1;i>=0;--i){
        ostwyny[i]=wynik[i];
        if(rep1[i]!=-1){
            Union(i,rep1[i]);
        }

        //
    }
    for(int i=0;i<m;++i){
        printf("%lld\n",ostwyny[i]);
    }
    return 0;
}
