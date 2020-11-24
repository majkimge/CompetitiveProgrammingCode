#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 2100
#define MAX1 20009
#define INF 1000000000

using namespace std;

lld m,n,kk=1024;
lld tree[MAX];
lld kub[MAX1];
lld temp[MAX1];

void add(lld gdzie,lld co){
    gdzie+=kk;
    while(gdzie!=0){
        tree[gdzie]+=co;
        gdzie>>=1;
    }
}

lld check(lld a,lld b){
    lld wyn=0;
    a+=kk;
    b+=kk;
    if(a==b){
        wyn+=tree[a];
    }else{
    wyn+=tree[a];
    wyn+=tree[b];
    }
    while(a/2!=b/2){
        if(a%2==0){
            wyn+=tree[a+1];
        }
        if(b%2==1){
            wyn+=tree[b-1];
        }
        a>>=1;
        b>>=1;
    }
    return wyn;
}

lld czy(lld k){
    lld odj=0;
    lld wyn=1;
    for(int i=0;i<k;++i){
        temp[i]=kub[i];
    }
    sort(temp,temp+k);
    for(int i=k;i<k*2;++i){
        add(kub[i],1);
    }
    cout<<check(0,10)<<" ";
    for(int i=k;i>=0;--i){
        if(check(temp[i]+1,m+1)-odj<=0){
            for(int j=k;j<k*2;++j){
                add(kub[j],-1);
            }
            return 0;
        }else{
            odj++;
        }
    }
    for(int j=k;j<k*2;++j){
        add(kub[j],-1);
    }
    return 1;
}

lld bin(){
    lld l=0;
    lld wyn=0;
    lld p=n/2;
    lld s=0;
    while(p>=l){
        s=(l+p)/2;
        if(czy(s)){
            l=s+1;
            wyn=s;
        }else{
            p=s-1;
        }
    }
    return wyn;
}

int main()
{
    scanf("%lld",&m);
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&kub[i]);

    }
    printf("%lld",bin());
    return 0;
}
