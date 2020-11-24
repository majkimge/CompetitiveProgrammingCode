#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define piii pair<int,pair<int,int> >
#define pii pair<int,int>
#define MAX 200009

using namespace std;

typedef int int_fast32_t;

int n,x,tab[MAX][3],kt=1,wynik,xd,dok;
int lisl[MAX], lisp[MAX], lisd[MAX], lism[MAX];
int pot[1100000];
int pot1[1100000];
piii skal[MAX*3];

/*int check(int l,int p){
    if(p<l)return 0;
    l+=kk;
    p+=kk;
    int wyn=0;

    wyn=max(tree[l],tree[p]);
    while((l>>1)!=(p>>1)){
        if(!(l&1)){
            wyn=max(wyn,tree[l+1]);
        }
        if(p&1){
            wyn=max(tree[p-1],wyn);
        }
        l>>=1;
        p>>=1;
    }
    return wyn;
}

void ust(int gdz, int na){
    gdz+=kk;
    tree[gdz]=max(tree[gdz],na);
    gdz>>=1;
    while(gdz){
        tree[gdz]=max(tree[(gdz<<1)],tree[(gdz<<1)+1]);
        gdz>>=1;
    }
}*/

void ust(int gdz,int ile){
    if(gdz>1100000)return;
    pot[gdz]=max(pot[gdz],ile);
    ust(gdz+(gdz&(-gdz)),ile);
}

int check(int dok){
    if(dok==0)return 0;
    return max(pot[dok],check(dok-(dok&(-dok))));
}

void ust1(int gdz,int ile){
    if(gdz>1100000)return;
    pot1[gdz]=max(pot1[gdz],ile);
    ust1(gdz+(gdz&(-gdz)),ile);
}

int check1(int dok){
    if(dok==0)return 0;
    return max(pot1[dok],check1(dok-(dok&(-dok))));
}

int main()
{
    scanf("%d%d",&n,&x);

    for(int i=0;i<n;++i){
        scanf("%d",&tab[i][1]);
        xd=i*3;
        skal[xd]=mp(tab[i][1],mp(i,1));
        skal[xd+1]=mp(tab[i][1]+x,mp(i,2));
        skal[xd+2]=mp(tab[i][1]-x,mp(i,0));
    }
    dok=3*n;
    sort(skal,skal+dok);

    for(int i=0;i<dok;++i){
        tab[skal[i].s.f][skal[i].s.s]=kt;
        while(i+1<dok&&skal[i].f==skal[i+1].f){
            ++i;
            tab[skal[i].s.f][skal[i].s.s]=kt;
        }
        ++kt;
    }
    for(int i=0;i<n;++i){

        lisl[i]=check(tab[i][1]-1)+1;
        lisd[i]=check(tab[i][2]-1);
        ust(tab[i][1],lisl[i]);
    }
    for(int i=n-1;i>=0;--i){
        lisp[i]=check1(kt-tab[i][1]-1)+1;
        lism[i]=check1(kt-tab[i][0]-1);
        ust1(kt-tab[i][1],lisp[i]);

    }
    for(int i=0;i<n;++i){
        wynik=max(lisp[i]+lisd[i],max(wynik,lisl[i]+lism[i]));
    }
    printf("%d",wynik);
    return 0;
}

/*
8 10
7 3 5 12 2 7 3 4
*/
