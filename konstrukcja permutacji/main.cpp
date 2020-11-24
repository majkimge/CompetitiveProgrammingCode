#include<bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 200009
#define pii pair<int,int>
#define pdd pair<double,double>
#define C 1000
#define INF 1000000000

using namespace std;

int n,kk=1;
int tab[MAX];
int cogdz[MAX];
pair<pii, int> tree[MAX*4];
vector<int> wynik;
set<int> wyk;
set<int>::iterator it;

int akt(int gdz){
    if(tree[gdz].s%2){
        swap(tree[gdz].f.f,tree[gdz].f.s);
    }
    //tree[gdz].s=0;
}

int push(int gdz){
    if(gdz<kk){
        tree[gdz*2].s+=tree[gdz].s;
        tree[gdz*2+1].s+=tree[gdz].s;
    }
    tree[gdz].s=0;
}

void zmiana(int gdz, int l, int p, int zakl, int zakp){
    if(l<=zakl&&p>=zakp){
        tree[gdz].s++;
        akt(gdz);
        push(gdz);
    }else if(l>zakp||p<zakl){
        akt(gdz);
        push(gdz);
    }else{
        push(gdz);
        zmiana(gdz*2,l,p,zakl,(zakl+zakp)/2);
        zmiana(gdz*2+1,l,p,(zakl+zakp)/2+1,zakp);
        tree[gdz].f.f=min(tree[gdz*2].f.f,tree[gdz*2+1].f.f);
        tree[gdz].f.s=min(tree[gdz*2].f.s,tree[gdz*2+1].f.s);
    }
}

void wpun(int gdz, int l, int p, int zakl, int zakp, int na, int spos){
    if(l<=zakl&&p>=zakp){
        if(spos==2){
            tree[gdz].s=0;
            tree[gdz].f=mp(na,na);
        }else if(spos==0){
            tree[gdz].f=mp(na,INF);
        }else{
            tree[gdz].f=mp(INF,na);
        }

    }else if(l>zakp||p<zakl){
        akt(gdz);
        push(gdz);
    }else{
        push(gdz);
        wpun(gdz*2,l,p,zakl,(zakl+zakp)/2,na,spos);
        wpun(gdz*2+1,l,p,(zakl+zakp)/2+1,zakp,na,spos);
        tree[gdz].f.f=min(tree[gdz*2].f.f,tree[gdz*2+1].f.f);
        tree[gdz].f.s=min(tree[gdz*2].f.s,tree[gdz*2+1].f.s);
    }
}

int check(int gdz, int l, int p, int zakl, int zakp,int jaki){
    if(l<=zakl&&p>=zakp){
        //tree[gdz].s++;
        akt(gdz);
        push(gdz);
        if(jaki==0){
            return tree[gdz].f.f;
        }else{
            return tree[gdz].f.s;
        }
    }else if(l>zakp||p<zakl){
        akt(gdz);
        push(gdz);
        return INF;
    }else{
        push(gdz);
        int wyn=INF;
        wyn=min(wyn,check(gdz*2,l,p,zakl,(zakl+zakp)/2,jaki));
        wyn=min(wyn,check(gdz*2+1,l,p,(zakl+zakp)/2+1,zakp,jaki));
        tree[gdz].f.f=min(tree[gdz*2].f.f,tree[gdz*2+1].f.f);
        tree[gdz].f.s=min(tree[gdz*2].f.s,tree[gdz*2+1].f.s);
        return wyn;
    }
}



int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&tab[i]);
        cogdz[tab[i]]=i;
    }
    wyk.insert(0);
    wyk.insert(n+1);
    while(kk<n+2)kk<<=1;
    for(int i=1;i<=n;++i){
        if(i%2){
            wpun(1,i,i,0,kk-1,tab[i],0);
        }else{
            wpun(1,i,i,0,kk-1,tab[i],1);
        }
    }

    for(int i=1;i<=n/2;++i){
        int pocz=check(1,1,n,0,kk-1,0);
        int pospocz=cogdz[pocz];
        it=wyk.lower_bound(pospocz);//cout<<(*it);
        int kon=check(1,pospocz,(*it)-1,0,kk-1,1);
        int poskocz=cogdz[kon];
        wynik.pb(pocz);
        wynik.pb(kon);
        if(pospocz!=poskocz-1){
            zmiana(1,pospocz+1,poskocz-1,0,kk-1);
        }
        wpun(1,pospocz,pospocz,0,kk-1,INF,2);
        wpun(1,poskocz,poskocz,0,kk-1,INF,2);
        wyk.insert(pospocz);
        wyk.insert(poskocz);
    }
    for(int i=0;i<wynik.size();++i){
        printf("%d ",wynik[i]);
    }
    return 0;
}
