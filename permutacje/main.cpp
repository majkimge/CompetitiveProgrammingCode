#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200009
#define INF 1000000009
#define llu unsigned long long
#define lld long long

using namespace std;

int n,kk=1,ilej,ost,kt=-1;
pair<int,int> tree[600000][3];
int ostree[600000];
int tab[MAX];
vector<int> wynik;

void ustaw(int gdzie,int co,int jak){
    gdzie+=kk;
    tree[gdzie][jak]=mp(co,gdzie-kk);
    gdzie>>=1;
    while(gdzie>0){
        if(tree[gdzie*2][jak].f<=tree[gdzie*2+1][jak].f){
            tree[gdzie][jak]=mp(tree[gdzie*2][jak].f,tree[gdzie*2][jak].s);
        }else{
            tree[gdzie][jak]=mp(tree[gdzie*2+1][jak].f,tree[gdzie*2+1][jak].s);
        }
        gdzie>>=1;
    }
}

pair<int,int> check(int l, int p, int jak){
    l+=kk;
    p+=kk;
    pair<int,int> wyn=mp(INF,0);
    //wyn=min(tree[l],tree[p]);
    if(tree[l][jak].f>=tree[p][jak].f){
        wyn=mp(tree[p][jak].f,tree[p][jak].s);
    }else{
        wyn=mp(tree[l][jak].f,tree[l][jak].s);
    }
    while(l/2!=p/2){
        if(l%2==0){
            if(tree[l+1][jak].f<=wyn.f){
                wyn=mp(tree[l+1][jak].f,tree[l+1][jak].s);
            }
        }
        if(p%2==1){
            if(tree[p-1][jak].f<=wyn.f){
                wyn=mp(tree[p-1][jak].f,tree[p-1][jak].s);
            }
        }
        l>>=1;
        p>>=1;
    }
    return wyn;
}

void osustaw(int l,int p, int co){
    l+=kk;
    p+=kk;
    ostree[l]=min(ostree[l],co);
    ostree[p]=min(ostree[p],co);
    while(l/2!=p/2){
        if(l%2==0){
            ostree[l+1]=min(ostree[l+1],co);
        }
        if(p%2==1){
            ostree[p-1]=min(ostree[p-1],co);
        }
        l>>=1;
        p>>=1;
    }

}

int oscheck(int gdzie){
    gdzie+=kk;
    int wyn=ostree[gdzie];
    gdzie>>=1;
    while(gdzie>0){
        if(ostree[gdzie]<wyn){
            wyn=ostree[gdzie];
        }
        gdzie>>=1;
    }
    return wyn;
}


int main()
{
    scanf("%d",&n);
    while(kk<n){
        kk<<=1;
    }
    ost=n-1;
    for(int i=0;i<600000;++i){
        tree[i][0]=mp(INF,0);
        tree[i][1]=mp(INF,0);
        tree[i][2]=mp(INF,0);
    }
    for(int i=0;i<n*2;++i){
        ostree[i]=n-1;
    }
    kt++;
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
        if(i!=n-1){
            ustaw(i,tab[i],0);
        }else{
            ustaw(i,INF,0);
        }

        if(i%2==1){
            ustaw(i,tab[i],1);
            ustaw(i,INF,2);
        }else{
            ustaw(i,tab[i],2);
            ustaw(i,INF,1);
        }

    }
    //cout<<check(0,n-1,0).s;
    while(ilej<n){
        pair<int,int> temp=check(0,n-1,0);
        ustaw(temp.s,INF,2-temp.s%2);
        ustaw(temp.s,INF,0);
        if(temp.s){
            ustaw(temp.s-1,INF,0);
        }
        wynik.pb(temp.f);
        pair<int,int> part=check(temp.s,oscheck(temp.s),2-(temp.s+1)%2);
        wynik.pb(part.f);
        ustaw(part.s,INF,2-(part.s)%2);
        ustaw(part.s,INF,0);
        ustaw(part.s-1,INF,0);
        osustaw(0,temp.s,temp.s);
        osustaw(0,part.s,part.s);
        ilej+=2;
    }
    for(int i=0;i<wynik.size();++i){
        printf("%d ",wynik[i]);
    }
    return 0;

}
