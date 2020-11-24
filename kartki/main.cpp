#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200009
#define MOD 1000000007

using namespace std;

int n,a,b,kk=1;
lld tree[2130000],wynik;
pair<lld,lld> kartki[MAX];

int add(int gdz, int ile){
    gdz+=kk;
    while(gdz){
        tree[gdz]+=ile;
        gdz>>=1;
    }
}

lld zap(int l, int p){
    lld ret=0;
    l+=kk;
    p+=kk;
    ret+=tree[l];
    if(l!=p){
        ret+=tree[p];
    }
    while(l/2!=p/2){
        if(l%2==0){
            ret+=tree[l+1];
        }
        if(p%2==1){
            ret+=tree[p-1];
        }
        l>>=1;
        p>>=1;
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&a,&b);
        if(a>b)swap(a,b);
        kartki[i]=mp(a,b);
    }
    while(kk<1000000)kk<<=1;
    sort(kartki,kartki+n);
    for(int i=0;i<n;++i){//cout<<"A";
        wynik+=zap(0,kartki[i].s-1);
        while(i+1<n&&kartki[i].f==kartki[i+1].f){
            ++i;
            wynik+=zap(0,kartki[i].s-1);
        }
        //cout<<i<<" "<<wynik<<endl;
        while(i>0&&kartki[i].f==kartki[i-1].f){
            --i;
        }
        add(kartki[i].s,1);
        while(i+1<n&&kartki[i].f==kartki[i+1].f){
            ++i;
            add(kartki[i].s,1);
        }

    }
    printf("%lld",wynik);
    return 0;
}
