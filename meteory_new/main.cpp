#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 300009

using namespace std;

int n,m,obs[MAX],a,k,kk=1,wyniki[MAX];
lld il[MAX],b,l,r,p;
pair<pair<int,int>,lld> opad[MAX];
vector<pair<pair<int,int>,int> >bin[MAX];
lld tree[1100000];
vector<int> obpan[MAX];

void dod(int od, int dok, lld il){
    od+=kk;
    dok+=kk;
    tree[od]+=il;
    if(od!=dok){
        tree[dok]+=il;
    }
    while(od/2!=dok/2){
        if(od%2==0){
            tree[od+1]+=il;
        }
        if(dok%2==1){
            tree[dok-1]+=il;
        }
        od>>=1;
        dok>>=1;
    }
}

lld sum(int gdz){
    gdz+=kk;
    lld ret=0;
    while(gdz){
        ret+=tree[gdz];
        gdz>>=1;
    }
    return ret;
}

void cltr(){
    for(int i=0;i<1100000;++i)tree[i]=0;
}

int main()
{
    scanf("%d%d",&n,&m);
    while(kk<m)kk<<=1;
    for(int i=0;i<m;++i){
        scanf("%d",&a);
        obs[i]=a;
        obpan[a].pb(i);
    }
    for(int i=0;i<n;++i){
        scanf("%lld",&b);
        il[i]=b;

    }
    scanf("%d",&k);
    for(int i=0;i<k;++i){
        scanf("%lld%lld%lld",&l,&r,&p);
        --l;
        --r;
        opad[i]=mp(mp(l,r),p);
    }

    for(int i=0;i<n;++i){
        bin[(k-1)/2].pb(mp(mp(0,k-1),i));
        wyniki[i]=MAX;
    }
    for(int xdd=0;xdd<50;++xdd){
        cltr();
        for(int i=0;i<k;++i){
            if(opad[i].f.f<=opad[i].f.s){
                dod(opad[i].f.f,opad[i].f.s,opad[i].s);
            }else{
                dod(opad[i].f.f,m-1,opad[i].s);
                dod(0,opad[i].f.s,opad[i].s);
            }
            for(int j=0;j<bin[i].size();++j){
                int ter=bin[i][j].s;
                lld ilek=0;
                for(int u=0;u<obpan[ter].size();++u){
                    ilek+=sum(obpan[ter][u]);
                }
                if(ilek>=il[ter]){
                    wyniki[ter]=i;
                    int ll=bin[i][j].f.f;
                    int pp=bin[i][j].f.s;
                    swap(bin[i][j],bin[i][bin[i].size()-1]);
                    --j;
                    bin[i].pop_back();
                    pp=max(0,i-1);

                    if((ll+pp)/2!=i)bin[(ll+pp)/2].pb(mp(mp(ll,i-1),ter));

                }else{
                   // wyniki[ter]=i;
                    int ll=bin[i][j].f.f;
                    int pp=bin[i][j].f.s;
                    swap(bin[i][j],bin[i][bin[i].size()-1]);
                    --j;
                    ll=i+1;
                    ll=min(ll,MAX-3);
                    bin[i].pop_back();

                    if((ll+pp)/2!=i)bin[(ll+pp)/2].pb(mp(mp(ll,pp),ter));
                }
            }
        }
    }
    for(int i=0;i<n;++i){
        if(wyniki[i]!=MAX){
            printf("%d\n",wyniki[i]+1);
        }else{
            printf("NIE\n");
        }
    }
    return 0;
}
