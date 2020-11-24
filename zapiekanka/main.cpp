#include <bits/stdc++.h>
#define N 1000009
#define MLD 1000000000
#define lld long long
using namespace std;

int n, co,a1,b1,w1,zap, m;
int k=1;
vector<pair<lld, lld> > tree[2*N];

void add(int a,int b,int w){
    if(a!=b){
        tree[a]+=w;
        tree[b]+=w;
        if(a/2!=b/2){
            if(a%2==0){
                tree[a+1]+=w;
            }
            if(b%2==1){
                tree[b-1]+=w;
            }
            a>>=1;
            b>>=1;
        }
    }
    bool zparz=false;
    bool zniep=false;
    while(a/2!=b/2){
       if(a%2==0){
        tree[a+1]+=w;
        zparz=false;
        }else{
        zparz=true;
        }
        if(b%2==1){
        tree[b-1]+=w;
        zniep=false;
        }else{
        zniep=true;
        }
        a>>=1;
        b>>=1;
    }

}

lld check(int x){
    lld wynik=0;
    while(x>0){
        wynik+=tree[x];
        x>>=1;
    }
    return wynik;
}
int main()
{
    //std::ios_base::sync_with_stdio(0);
    while(k<N){
        k<<=1;
    }
    scanf("%i",&n);
    for(int i=0;i<n;i++){
        scanf("%i",&co);
        if(co==0){
            scanf("%i",&a1);
            scanf("%i",&b1);
            scanf("%i",&w1);
            add(a1+k-1,b1+k-1,w1);
        }else{
            scanf("%i",&zap);
            printf("%lld\n",check(zap+k-1));
        }
    }
    return 0;
}
