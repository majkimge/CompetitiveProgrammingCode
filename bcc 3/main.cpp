#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define MAX 200009

using namespace std;


int t,n,kt;
int tab[MAX];
vector<pair<int,int> >skal;
int iler[MAX];

int rozw(int l, int p){
    if(p<=l)return 1;
    int pl=-1;
    int pp=-1;
    for(int i=l;i<=p;++i){
        iler[tab[i]]++;
    }

    for(int i=(l+p)/2;i>=l;--i){
        if(iler[tab[i]]==1){
            pl=i;
            break;
        }
    }




    for(int i=(l+p)/2+1;i<=p;++i){
        if(iler[tab[i]]==1){
            pp=i;
            break;
        }
    }
    for(int i=l;i<=p;++i){
        iler[tab[i]]=0;
    }

    if(pl==-1&&pp==-1)return 0;
    int ret=1;
    int rl=0;
    int rp=0;
    if(((l+p)/2-pl<pp-(l+p)/2&&pl!=-1)||pp==-1){
        rl=rozw(l,pl-1);
        rp=rozw(pl+1,p);
    }else{
        rl=rozw(l,pp-1);
        rp=rozw(pp+1,p);
    }
    return (rl&rp);
}

int main()
{
    scanf("%d",&t);
    for(int xd=0;xd<t;++xd){
            scanf("%d",&n);
            skal.clear();
        for(int i=0;i<n;++i){
            scanf("%d",&tab[i]);
            skal.pb(mp(tab[i],i));
        }
        sort(skal.begin(),skal.end());
        for(int i=0;i<skal.size();++i){
            int ter=skal[i].f;
            tab[skal[i].s]=kt;
            while(i<skal.size()-1&&skal[i+1].f==ter){
                ++i;
                tab[skal[i].s]=kt;
            }
            ++kt;
        }
        int wyn=rozw(0,n-1);
        if(wyn){
            printf("TAK\n");
        }else{
            printf("NIE\n");
        }
    }
    return 0;
}
