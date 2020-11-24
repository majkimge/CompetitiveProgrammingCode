#include <bits/stdc++.h>
#define lld long long
#define MAX 1009
#define ILE 100009

using namespace std;

lld n,m,q,x3,y3,x4,y4,k=1,p;

lld tree[2500][MAX];

void ustaw(lld a,lld b,lld co,lld kol){
    lld a1=a+k;
    lld b1=b+k;
    if(a1==b1){
        tree[a1][kol]=co;
    }else{
        tree[a1][kol]=co;
        tree[b1][kol]=co;
        while(a1/2!=b1/2){
            if(a1%2==0){
                tree[a1+1][kol]=co;
            }
            if(b1%2==1){
                tree[b1-1][kol]=co;
            }
            a1>>=1;
            b1>>=1;
        }
    }
}

lld check(lld gdzie,lld kol){
    lld gdzie1=gdzie+k;
    lld wyn=0;
    while(gdzie1>0){
            //cout<<wyn;
        wyn=max(wyn,tree[gdzie1][kol]);
        gdzie1>>=1;
    }
    return wyn;
}

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&m);
    scanf("%lld",&q);
    while(k<m){
        k<<=1;
    }
    for(lld i=0;i<q;++i){
        scanf("%lld",&y3);
        scanf("%lld",&x3);
        scanf("%lld",&y4);
        scanf("%lld",&x4);
        for(lld j=y3;j<=y4;++j){
            ustaw(x3,x4,i+1,j);
        }

    }
    for(lld i=1;i<=n;++i){
        for(lld j=1;j<=m;++j){
            printf("%lld ",check(j,i));

        }

            puts("");



    }

    return 0;
}
