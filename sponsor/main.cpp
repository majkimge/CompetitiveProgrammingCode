#include <bits/stdc++.h>
#define lld long long
#define MAX 120000
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

double a;
lld tree[MAX];
lld tab[MAX];
lld n,k=1,wyn,twyn;

lld check(lld l,lld p){
    lld wyni=0;
    l+=k;
    p+=k;
    if(l==p){
        wyni=tree[l];
    }else{
        wyni=max(tree[l],tree[p]);
        while(l/2!=p/2){
            if(l%2==0){
                wyni=max(wyni,tree[l+1]);
            }
            if(p%2==1){
                wyni=max(wyni,tree[p-1]);
            }
            l>>=1;
            p>>=1;
        }
    }
    //cout<<wyni;
    return wyni;
}

void add(lld co,lld gdzie){
    gdzie+=k;
    tree[gdzie]=max(tree[gdzie],co);
    //cout<<gdzie;
    while(gdzie/2>0){
        tree[gdzie/2]=max(tree[gdzie/2*2],tree[gdzie/2*2+1]);
        gdzie>>=1;
    }
}

int main()
{
    scanf("%lf",&a);
    while(a!=0){
            a=a*1000;
        tab[n]=(lld)(a);
        //cout<<tab[n];
        n++;
        scanf("%lf",&a);
    }
    while(k<30010){
        k<<=1;
    }
    add(1,tab[0]);
    //cout<<tree[1];
    for(int i=1;i<n;++i){
           // cout<<tab[i];
            twyn=check(tab[i]+1,30000)+1;
        wyn=max(wyn,twyn);
        add(twyn,tab[i]);
    }
    printf("%lld",wyn*100);
    return 0;
}
