#include <bits/stdc++.h>
#define lld int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 4100
#define K 2048
#define INF 2000000000

using namespace std;

lld n;
int tree[MAX][MAX];

lld check(lld x,lld y,lld z){
    lld a=y+K;
    lld b=z+K;
    lld wyn=0;
    if(a!=b){
        wyn+=tree[x][a];
        wyn+=tree[x][b];
    }else{
        wyn+=tree[x][a];
    }
    while(a/2!=b/1){
        if(a%2==0){
            wyn+=tree[x][a+1];
        }
        if(b%2==1){
            wyn+=tree[x][b-1];
        }
        a>>=1;
        b>>=1;
    }
    return wyn;

}

lld check1(lld x,lld y,lld z){
    lld a=K;
    lld b=x+K-1;
    lld wyn=0;
    if(a!=b&&b>=a){
        wyn+=check(a,0,max(y-1,0));
        wyn+=check(b,0,max(y-1,0));
    }else{
        wyn+=check(a,0,max(y-1,0));
    }
    while(a/2!=b/1){
        if(a%2==0){
            wyn+=check(a+1,0,max(y-1,0));
        }
        if(b%2==1){
            wyn+=check(b-1,0,max(y-1,0));
        }
        a>>=1;
        b>>=1;
    }
    a=x+1;
    b=K+K-1;

    if(a!=b&&b>=a){
        wyn+=check(a,min(y+1,K-1),K-1);
        wyn+=check(b,min(y+1,K-1),K-1);
    }else{
        wyn+=check(a,min(y+1,K-1),K-1);
    }
    while(a/2!=b/1){
        if(a%2==0){
            wyn+=check(a+1,min(y+1,K-1),K-1);
        }
        if(b%2==1){
            wyn+=check(b-1,min(y+1,K-1),K-1);
        }
        a>>=1;
        b>>=1;
    }
    return wyn;

}

void add(lld x,lld y,lld co){
    x+=K;
    y1=y;
    y1+=K;
    while(x>0){
        y1=y+K;
        while(y1>=0){
            tree[x][y1]+=co;
        }
    }
}

int main()
{
    scanf("%lld",&n);
    return 0;
}
