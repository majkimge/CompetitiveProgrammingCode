#include<bits/stdc++.h>
#define MAX 2000009
#define lld long long
using namespace std;

lld n,k,moc=1,wynik,ta,tb;
lld tree[MAX*2];
lld tab[MAX];
void update(lld a,lld b){
    lld a1=moc+a;
    lld b1=moc+b;
    if(a!=b){
        tree[a1]++;
        tree[b1]++;
    }else{
        tree[a1]++;
    }
    while(a1/2!=b1/2){
        if(a1%2==0){
            tree[a1+1]++;
        }
        if(b1%2==1){
            tree[b1-1]++;
        }
        a1>>=1;
        b1>>=1;
    }
}
void check(lld gdzie){
    lld gdzie1=moc+gdzie;
    lld wyn=0;
    while(gdzie1>0){
        wyn+=tree[gdzie1];
        gdzie1>>=1;
        //cout<<wyn;
    }
    wynik=max(wynik,wyn);
}
int main()
{

    scanf("%lld",&n);
    scanf("%lld",&k);
    while(moc<MAX){
        moc<<=1;
    }
    //cout<<moc<<endl;
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);

    }
    for(int i=0;i<n;++i){
        if(tab[i]-k<0){
            ta=0;
        }else{
            ta=tab[i]-k;
        }
        if(tab[i]+k>MAX-1){
            tb=MAX-1;
        }else{
            tb=tab[i]+k;
        }
        //cout<<ta<<tb<<endl;
        update(ta,tb);
    }
    for(int i=0;i<n;++i){
        check(tab[i]);
    }
    printf("%lld",wynik);
    return 0;
}
