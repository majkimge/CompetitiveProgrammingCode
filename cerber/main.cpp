#include <bits/stdc++.h>
#define lld int
#define MAX 2100000

using namespace std;

int tree[MAX];
lld n,k=1;
int wyny[MAX/2];
int pier[MAX/2];

lld check(lld p){
    lld wyn=0;
    p+=k;
    lld l=k;
    if(p==k){
        wyn+=tree[p];
    }else{
        wyn+=tree[p];
        wyn+=tree[l];
        while(p/2!=l/2){
            if(l%2==0){
                wyn+=tree[l+1];
            }
            if(p%2==1){
                wyn+=tree[p-1];
            }
            p>>=1;
            l>>=1;

        }
    }
    return wyn;

}

void add(lld gdzie,lld co){
    gdzie+=k;
    while(gdzie>0){
        tree[gdzie]+=co;
        gdzie>>=1;
    }
}

lld bin(lld co){
    lld l=0;
    lld p=n-1;
    lld wyn=0;
    lld s=(l+p)/2;
    while(l<=p){
            s=(l+p)/2;
        if(check(s)>=co){
            wyn=s;
            p=s-1;

        }else{
            l=s+1;
        }
    }
    return wyn;
}

int main()
{
    scanf("%d",&n);
    while(k<n){
        k<<=1;
    }
    for(int i=0;i<n;++i){
        add(i,1);
    }


    for(int i=1;i<=n;++i){
        scanf("%d",&pier[i]);
        //cout<<pier[i]<<" ";
    }
    for(int i=n;i>0;--i){
        wyny[i]=bin(pier[i]+1);
        add(wyny[i],-1);

    //cout<<wyny[i];
    }
    for(int i=1;i<=n;++i){
        printf("%d ",wyny[i]+1);
    }
    return 0;
}
