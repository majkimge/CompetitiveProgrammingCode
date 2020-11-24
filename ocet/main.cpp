#include <bits/stdc++.h>
#define N 1000009
#define MLD 1000000000
#define lld long long

using namespace std;

lld n,co,ktora=1,ile,k=1;

lld tree[40000];

lld check(lld a,lld b){
    lld a1=a+k;
    lld b1=b+k;
    lld wyn=0;

    if(a1!=b1){
        wyn+=tree[a1];
        wyn+=tree[b1];
    }
    while(a1/2!=b1/2){
        if(a1%2==0){
            wyn+=tree[a1+1];
        }
        if(b1%2==1){
            wyn+=tree[b1-1];
        }
        a1>>=1;
        b1>>=1;
    }
    return wyn;
}

lld bin(lld a){
    lld l=0;
    lld p=10001;
    lld wyn=1000000;
    lld s=(l+p)/2;
    while(p>=l){
        s=(l+p)/2;
        if(check(0,s)>=a){
            //cout<<tree[<<s<<" "<<check(0,s)<<" "<<l<<" "<<p<<endl;
            wyn=s;
            p=s-1;
        }else{
            //cout<<"B"<<s<<" "<<check(0,s)<<" "<<l<<" "<<p<<endl;
            l=s+1;
        }
    }
    return wyn;
}

void dodaj(lld gdz){
    lld gdz1=gdz+k;
    while(gdz1>0){
        tree[gdz1]+=1;
        gdz1>>=1;
    }
}

int main()
{
    scanf("%lld",&n);
    while(k<10000){
        k<<=1;
    }

    for(int i=0;i<n;++i){
        scanf("%lld",&co);
        if(co==1){
            scanf("%lld",&ile);
            dodaj(ile-1);
            /*for(int i=1;i<2*k;++i){
                cout<<tree[i];
            }*/
        }else{
            printf("%lld\n",bin(ktora)+1);
            ktora++;
        }
    }
    return 0;
}
