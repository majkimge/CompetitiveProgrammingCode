#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 300009
#define pii pair<lld,lld>
#define pdd pair<double,double>


using namespace std;

lld n,m,a,b,c,d,kk=1,wynik=100000000000000000,mini=1000000000000,maxi;
pair<pii, pii> wart[MAX];
pair<pii, pii> orgwart[MAX];
pair<lld,pii> skal[MAX];
lld INF =100000000000001;
pii tree[1100000][2];

void ust(lld l, lld p, lld ile, lld kto,lld jaki){
    l+=kk;
    p+=kk;
    if(tree[l][jaki].f>ile){
        //cout<<"A";
        tree[l][jaki]=mp(ile,kto);
    }
    if(l!=p){
        if(tree[p][jaki].f>ile){
            tree[p][jaki]=mp(ile,kto);
        }
    }
    while(l/2!=p/2){
        if(l%2==0){
            if(tree[l+1][jaki].f>ile){
                tree[l+1][jaki]=mp(ile,kto);
            }
        }
        if(p%2){
            if(tree[p-1][jaki].f>ile){
                tree[p-1][jaki]=mp(ile,kto);
            }

        }
        l>>=1;
        p>>=1;
    }
}

pii check(lld gdz, lld jaki){
    pii wyn=mp(INF,0);
    gdz+=kk;
    while(gdz){
        if(wyn.f>tree[gdz][jaki].f){
            wyn=tree[gdz][jaki];
        }
        gdz>>=1;
    }
    return wyn;
}

int main()
{
    scanf("%lld%lld",&m,&n);
    for(int i=0;i<m;++i){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        wart[i]=mp(mp(a,b),mp(c,d));
        mini=min(mini,a);
        maxi=max(maxi,b);
        orgwart[i]=mp(mp(a,b),mp(c,d));
        skal[i*3]=mp(a,mp(i,0));
        skal[i*3+1]=mp(b,mp(i,1));
        skal[i*3+2]=mp(c,mp(i,2));
    }
    //skal[m*3]
    sort(skal,skal+3*m);
    lld kt=0;
    for(int i=0;i<3*m;++i){
        if(skal[i].s.s==0){
            wart[skal[i].s.f].f.f=kt;
        }else if(skal[i].s.s==1){
            wart[skal[i].s.f].f.s=kt;
        }else{
            wart[skal[i].s.f].s.f=kt;
        }
        while(i+1<3*m&&skal[i].f==skal[i+1].f){
            ++i;
            if(skal[i].s.s==0){
                wart[skal[i].s.f].f.f=kt;
            }else if(skal[i].s.s==1){
                wart[skal[i].s.f].f.s=kt;
            }else{
                wart[skal[i].s.f].s.f=kt;
            }
        }
        ++kt;
    }
//cout<<"A";
    while(kk<MAX)kk<<=1;
    for(int i=0;i<1100000;++i){
        tree[i][0]=mp(INF,0);
        tree[i][1]=mp(INF,0);
    }
    ust(0,0,0,0,0);
    ust(kt-1,kt-1,0,0,1);
//cout<<check(0,0).f;
    if(mini!=1||maxi!=n){
            //cout<<maxi;
        printf("-1");
        return 0;
    }
    for(int i=0;i<m;++i){
        wynik=min(wynik,check(wart[i].f.f,0).f+check(wart[i].f.s,1).f+wart[i].s.s);

        ust(wart[i].f.f,wart[i].s.f,wart[i].s.s+check(wart[i].f.f,0).f,0,0);
        ust(wart[i].s.f,wart[i].f.s,wart[i].s.s+check(wart[i].f.s,1).f,0,1);
        //if(i==1)cout<<check(wart[i].f.f,0).f;
    }

    if(wynik>100000000000000){
        printf("-1");
    }else{
        printf("%lld",wynik);
    }
    return 0;
}
