#include<bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 100007
#define pii pair<int,int>
#define pdd pair<double,double>
#define C 1000
#define INF 1000000000

using namespace std;



int a,b,n,x,y,c,kk=1;
set<int> tree[270000][2];
set<int>::iterator it;

pii zap(int gdz, int tr, int war){
    gdz+=kk;
    int gor;
    int dol=0;
    if(tr==0){
        gor=a;
    }else{
        gor=b;
    }
    while(gdz){
        gor=min(gor,(*tree[gdz][tr].lower_bound(war)));
        dol=max(dol,(*(--tree[gdz][tr].lower_bound(war))));
        gdz>>=1;
    }
    return mp(dol,gor);
}

void dod(int l, int p, int war, int tr){
    l+=kk;
    p+=kk;
    tree[l][tr].insert(war);
    if(l!=p){
        tree[p][tr].insert(war);
    }
    while(l/2!=p/2){
        if(l%2==0){
            tree[l+1][tr].insert(war);
        }
        if(p%2==1){
            tree[p-1][tr].insert(war);
        }
        l>>=1;
        p>>=1;
    }
}

int main()
{
    scanf("%d%d",&a,&b);
    while(kk<max(a,b)+2)kk<<=1;
    scanf("%d",&n);
    for(int i=0;i<270000;++i){
        tree[i][0].insert(0);
        tree[i][0].insert(a);
        tree[i][1].insert(0);
        tree[i][1].insert(b);
    }
    for(int i=0;i<n;++i){
        scanf("%d%d%d",&x,&y,&c);
        if(c==1){
            pii ogr1=zap(y,0,x);
            lld szer=ogr1.s-ogr1.f;
            pii ogr=zap(x,1,y);
            lld d1=ogr.s-y;
            lld d2=y-ogr.f;
            if(d1>d2)swap(d1,d2);
            dod(ogr1.f,ogr1.s,y,1);
            printf("%lld %lld\n",d1*szer,d2*szer);
        }else{
            pii ogr1=zap(x,1,y);
            lld szer=ogr1.s-ogr1.f;
            pii ogr=zap(y,0,x);
            lld d1=ogr.s-x;
            lld d2=x-ogr.f;
            if(d1>d2)swap(d1,d2);
            dod(ogr1.f,ogr1.s,x,0);
            printf("%lld %lld\n",d1*szer,d2*szer);
        }
    }
    return 0;
}
