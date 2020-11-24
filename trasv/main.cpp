#include <bits/stdc++.h>

#define lld long long
#define mp make_pair
#define f first
#define s second
#define N 3000
#define INF 1000000000

using namespace std;

lld n, co,a1,b1,w1,zap,m,kk,temp,wyn;
lld k=1;
lld tree[2*N];

void add(lld a,lld b,lld w){
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
    scanf("%lld",&n);
    scanf("%lld",&m);
    scanf("%lld",&kk);
    while(k<n){
        k<<=1;
    }
    for(int i=0;i<m;++i){
        scanf("%lld",&temp);
        if(temp-kk<1){
            a1=k;
        }else{
            a1=temp-kk+k-1;
        }
        if(temp+kk>n){
            b1=n+k-1;
        }else{
            b1=temp+kk+k-1;
        }
        add(a1,b1,1);
    }
    for(int i=0;i<n;++i){
        if(check(i+k)==0){
            wyn++;
            //cout<<i<<endl;

        if(i+kk+kk>n-1){
            b1=n+k-1;
        }else{
            b1=i+kk+kk+k;
        }
        add(i+k,b1,1);

        }
    }

    printf("%lld",wyn);
    return 0;
}
