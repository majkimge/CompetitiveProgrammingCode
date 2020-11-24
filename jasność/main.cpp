#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define INF 100000000009
#define llu unsigned long long
#define lld long long

using namespace std;

lld n,m,wyn,wynik=INF,kk=1;
pair<lld,lld> tree[300000];
lld tab[MAX];

void add(lld l, lld p, lld co){
    l+=kk;
    p+=kk;
    if(l!=p){
        tree[l].f++;
        tree[l].s+=co;
        tree[p].f++;
        tree[p].s+=co;
    }else{
        tree[l].f++;
        tree[l].s+=co;
    }
    while(l/2!=p/2){
        if(l%2==0){
            tree[l+1].f++;
            tree[l+1].s+=co;
        }
        if(p%2==1){
            tree[p-1].f++;
            tree[p-1].s+=co;
        }
        l>>=1;
        p>>=1;
    }
}
lld check(lld gdzie){
    gdzie+=kk;
    lld co=gdzie-kk;
    lld ile=0;
    lld sumix=0;
    while(gdzie>0){
        ile+=tree[gdzie].f;
        sumix+=tree[gdzie].s;
        gdzie>>=1;
    }
    //cout<<"F"<<co<<" "<<sumix<<endl;
    return ile*(co+1)-sumix;
}

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&m);
    while(kk<m){
        kk<<=1;
    }
    //cout<<kk;
    for(lld i=0;i<n;++i){
        scanf("%d",&tab[i]);
        //tab[i]=m-i;
    }
    for(lld i=0;i<n-1;++i){
        if(tab[i]<tab[i+1]){
            wyn+=tab[i+1]-tab[i];
        }else{
            wyn+=m-tab[i]+tab[i+1];
        }
        if((tab[i]+1)%m!=tab[i+1]){
            if(tab[i]<tab[i+1]){
                add(tab[i]+2,tab[i+1],tab[i]+2);
            }else{
                if(tab[i]+2<=m){
                    //cout<<"A"<<tab[i]<<" ";
                    add(tab[i]+2,m,tab[i]+2);
                    add(1,tab[i+1],tab[i]+2-m);
                }else{
                    //cout<<"B"<<tab[i]<<" ";
                    add((tab[i]+2)%m,tab[i+1],(tab[i]+2)%m);
                }
            }
        }
    }
    //cout<<wyn;
    for(lld i=1;i<=m;++i){
        wynik=min(wynik,wyn-check(i));
        //cout<<"XD"<<check(i)<<" ";
    }
    printf("%lld",wynik);
    return 0;
}
