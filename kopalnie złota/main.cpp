#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define MAX 40000

using namespace std;

int s,h,x,y,kk=1,n,wynik;
pair<int,int> tree[1000000];


pair<pair<int,int>,pair<int,int> >tab[MAX];

int akt(int gdz){
    tree[gdz].f+=tree[gdz].s;
}

int push(int gdz){
    if(gdz<kk){
        tree[gdz*2].s+=tree[gdz].s;
        tree[gdz*2+1].s+=tree[gdz].s;
    }
    tree[gdz].s=0;
}

void add(int gdz, int l, int p, int zakl, int zakp, int ile){
    if(l<=zakl&&p>=zakp){
        tree[gdz].s+=ile;
        akt(gdz);
        push(gdz);
    }else if(l>zakp||p<zakl){
        akt(gdz);
        push(gdz);
    }else{
        push(gdz);
        add(gdz*2,l,p,zakl,(zakl+zakp)/2,ile);
        add(gdz*2+1,l,p,(zakl+zakp)/2+1,zakp,ile);
        tree[gdz].f=max(tree[gdz*2].f,tree[gdz*2+1].f);
    }
}

int check(int gdz,int l, int p, int zakl, int zakp){
    if(l<=zakl&&p>=zakp){
        akt(gdz);
        push(gdz);
        return tree[gdz].f;
    }else if(l>zakp||p<zakl){
        akt(gdz);
        push(gdz);
        return 0;
    }else{
        push(gdz);
        int wyn=0;
        wyn=max(wyn,check(gdz*2,l,p,zakl,(zakl+zakp)/2));
        wyn=max(wyn,check(gdz*2+1,l,p,(zakl+zakp)/2,zakp));
        tree[gdz].f=max(tree[gdz*2].f,tree[gdz*2+1].f);
        return wyn;
    }
}

int main()
{
    while(kk<200000){
        kk<<=1;
    }
    scanf("%d%d",&s,&h);
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&x,&y);
        y+=100000;
        tab[i*2]=mp(mp(x,-1),mp(y,y+h));
        tab[i*2+1]=mp(mp(x+s,1),mp(y,y+h));
    }
    sort(tab,tab+2*n);
    for(int i=0;i<2*n;++i){
        if(tab[i].f.s==-1){//cout<<"X";
            add(1,tab[i].s.f-h,tab[i].s.f,0,kk-1,1);

        }else{
            wynik=max(wynik,tree[1].f);
            add(1,tab[i].s.f-h,tab[i].s.f,0,kk-1,-1);
        }
    }
    printf("%d",wynik);
    return 0;
}
