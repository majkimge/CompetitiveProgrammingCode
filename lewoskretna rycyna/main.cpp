#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 200009
#define f first
#define s second
#define INF 1000000000

using namespace std;

int n,x,y,kk=1,q;
int tab[MAX];
int tree[MAX*4];
vector<pair<int,int> >v;

void ustaw(int gdzie,int co){
    gdzie+=kk;
    tree[gdzie]=co;
    gdzie>>=1;
    while(gdzie>0){
        tree[gdzie]=min(tree[gdzie*2],tree[gdzie*2+1]);
        gdzie>>=1;
    }
}

int check(int a,int b){
    a+=kk;
    b+=kk;
    int wyn=INF;
    wyn=min(tree[a],tree[b]);
    while(a/2!=b/2){
        if(a%2==0){
            wyn=min(wyn,tree[a+1]);
        }
        if(b%2){
            wyn=min(wyn,tree[b-1]);
        }
        a>>=1;
        b>>=1;
    }
    return wyn;
}

int main()
{
    scanf("%d",&n);
    while(kk<MAX){
        kk<<=1;
    }
    for(int i=1;i<=n;++i){
        scanf("%d",&tab[i]);
    }
    for(int i=0;i<MAX-2;++i){
        ustaw(i,INF);
    }
    scanf("%d",&q);
    for(int z=0;z<q;++z){
        scanf("%d",&x);
        scanf("%d",&y);
        int ww=0;
        pair<int,int> to;
        for(int i=x;i<=y;++i){
            v.pb(mp(tab[i],i));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();++i){
            int tt=v[i];

        }
        v.clear();
        if(ww){
            printf("%d %d\n",to.f,to.s);
        }else{
            printf("-1 -1\n");
        }

    }
    return 0;
}
