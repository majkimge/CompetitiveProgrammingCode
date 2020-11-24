#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define MAX 131079

using namespace std;

lld n,m,q,ilemocy=1,currmax,temp,temp1,poczym;
pair<lld,lld> tab[MAX];
lld wyniki[MAX];
lld tree[MAX*2];

void add(lld a,lld b){
    lld a1=a+ilemocy;
    lld b1=b+ilemocy;
    if(a1!=b1){
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

lld check(lld a){
    lld wyn=0;
    lld a1=a+ilemocy;
    while(a1>0){
        wyn+=tree[a1];
        a1>>=1;
    }
    return wyn;
}
lld bin(lld a,lld b, lld co){
    lld l=a;
    lld p=b;
    lld sr=(l+p)/2;
    lld maxi=-1;
    while(p>=l){

        sr=(l+p)/2;
        //cout<<check(sr);
        if(check(sr)>co){
            p=sr-1;
        }else{
            l=sr+1;
            maxi=max(maxi,sr);
        }
    }
    return maxi;
}
bool cmp(const pair<lld,lld> &a,const pair<lld,lld> &b)
{
       return a.f<b.f;
}
int main()
{
    scanf("%lld",&n);
    scanf("%lld",&m);

    while(ilemocy<n){
        ilemocy<<=1;
    }
    for(int i=0;i<n;++i){
        scanf("%lld",&temp);
        tab[i]=mp(temp,i);
    }
    sort(tab,tab+n,cmp);
    for(int i=0;i<n;++i){
        tree[ilemocy+i]=tab[i].f;
    }
    for(int i=0;i<m;++i){
        scanf("%lld",&temp1);
        //cout<<"A";
        poczym=bin(0,n-1,temp1);
        if(poczym!=-1){
            add(0,poczym);
        }

    }
    for(int i=0;i<n;i++){
        lld t=i;
        lld tw=0;
        tw=check(i);
        wyniki[tab[i].s]=tw;
    }
    for(int i=0;i<n;++i){
        printf("%lld ",wyniki[i]);
    }

    return 0;
}
