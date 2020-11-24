#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1100000
#define pii pair<int,int>

using namespace std;

int tree1[MAX];
int n,kk=1,a,b,c,d;
pair<int,pii> tree[MAX];

void dod(int gdz, int co){
    gdz+=kk;
    tree1[gdz]=co;
    gdz>>=1;
    while(gdz){
        tree1[gdz]=max(tree1[gdz*2],tree1[gdz*2+1]);
        gdz>>=1;
    }
}

int pod(int l, int p){
    l+=kk;
    p+=kk;
    int wyn=0;
    wyn=max(tree1[l],tree1[p]);
    while(l/2!=p/2){
        if(l%2==0){
            wyn=max(wyn,tree1[l+1]);
        }
        if(p%2){
            wyn=max(wyn,tree1[p-1]);
        }
        l>>=1;
        p>>=1;
    }
    return wyn;
}

void akt(int gdz, int zakl, int zakp){
    tree[gdz].s.f+=tree[gdz].s.s;
    if(tree[gdz].s.f){
        tree[gdz].f=zakp-zakl+1;
    }else if(gdz<kk){
        tree[gdz].f=tree[gdz*2].f+tree[gdz*2+1].f;
    }else{
        tree[gdz].f=0;
    }
}

void push(int gdz){
    if(gdz<kk){
        tree[gdz*2].s.s+=tree[gdz].s.s;
        tree[gdz*2+1].s.s+=tree[gdz].s.s;
    }
    tree[gdz].s.s=0;
}

void dod(int gdz, int zakl, int zakp, int l, int p, int ile){
    if(l<=zakl&&zakp<=p){
        //cout<<gdz<<endl;
        tree[gdz].s.s+=ile;
        akt(gdz,zakl,zakp);
        push(gdz);
    }else if(zakl>p||zakp<l){
        akt(gdz,zakl,zakp);
        push(gdz);
    }else{
        akt(gdz,zakl,zakp);
        push(gdz);
        dod(gdz*2,zakl,(zakl+zakp)/2,l,p,ile);
        dod(gdz*2+1,(zakl+zakp)/2+1,zakp,l,p,ile);
        akt(gdz,zakl,zakp);

    }
}

int zap(int gdz, int zakl, int zakp ,int l, int p){
    if(zakl>=l&&zakp<=p){
        akt(gdz,zakl,zakp);
        push(gdz);
        return tree[gdz].f;
    }else if(zakl>p||zakp<l){
        return 0;
    }else{
        int wyn=0;
        akt(gdz,zakl,zakp);
        push(gdz);
        wyn+=zap(gdz*2,zakl,(zakl+zakp)/2,l,p);
        wyn+=zap(gdz*2+1,(zakl+zakp)/2+1,zakp,l,p);
        akt(gdz,zakl,zakp);
        return wyn;
    }
}

int main()
{
    scanf("%d",&n);
    while(kk<=8)kk<<=1;
    for(int i=0;i<n;++i){
        scanf("%d",&d);
        if(d==0){
            scanf("%d%d",&a,&b);
            printf("%d",zap(1,0,kk-1,a,b));
        }else{
            scanf("%d%d%d",&a,&b,&c);
            dod(1,0,kk-1,a,b,c);
        }
    }
    return 0;
}
/*
100
1 0 10 3
1 3 5 2
1 0 10 -3
0 0 10
*/
