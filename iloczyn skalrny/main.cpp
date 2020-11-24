#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 500000
#define MOD 1000000007

using namespace std;

lld n,q,kk;

pair<lld,lld> tree[MAX][2];
pair<lld,pair<lld,lld> >tree1[MAX];

void push(int gdz, int zak, int tr){
    if(gdz<kk){
        tree[gdz*2][tr].f+=(zak/2*tree[gdz][tr].s)%MOD;
        tree[gdz*2+1][tr].f+=(zak/2*tree[gdz][tr].s)%MOD;
        tree[gdz*2][tr].s+=(tree[gdz][tr].s)%MOD;
        tree[gdz*2+1][tr].s+=(tree[gdz][tr].s)%MOD;
        tree[gdz*2][tr].f%=MOD;
        tree[gdz*2][tr].s%=MOD;
        tree[gdz*2+1][tr].f%=MOD;
        tree[gdz*2+1][tr].s%=MOD;

    }
    tree[gdz][tr].s=0;
}

lld add1(int gdz, int l, int p, int zakl, int zakp, int ile, int tr){
    if(l<=zakl&&p>=zakp){
        tree[gdz][tr].f+=(ile*(zakp-zakl+1))%MOD;
        tree[gdz][tr].s+=ile;

        tree[gdz][tr].f%=MOD;
        tree[gdz][tr].s%=MOD;
        return (ile*(zakp-zakl+1))%MOD;
    }else if(l>zakp||p<zakl){
        return 0;
    }

    lld co1=add(gdz*2,l,p,zakl,(zakl+zakp)/2,ile,tr);
    lld co2=add(gdz*2+1,l,p,(zakl+zakp)/2+1,zakp,ile,tr);
    tree[gdz][tr].f+=co1+co2;
    tree[gdz][tr].f%=MOD;
    return (co1+co2)%MOD;
}

lld zap(int gdz, int l, int p, int zakl, int zakp, int tr){
    lld wyn=0;
    if(l<=zakl&&p>=zakp){
        wyn+=tree[gdz][tr].f;
        return (wyn)%MOD;
    }else if(l>zakp||p<zakl){
        return 0;
    }
    push(gdz,(zakp-zakl+1),tr);
    lld co1=zap(gdz*2,l,p,zakl,(zakl+zakp)/2,tr);
    lld co2=zap(gdz*2+1,l,p,(zakl+zakp)/2+1,zakp,tr);
    return (co1+co2)%MOD;
}

lld push1(int gdz, int aa, int bb){
    if(gdz<kk){
        tree1[gdz*2].s.f+=tree1[gdz].s.f;
        tree1[gdz*2+1].s.f+=tree1[gdz].s.f;
        tree1[gdz*2].s.s+=tree1[gdz].s.s;
        tree1[gdz*2+1].s.s+=tree1[gdz].s.s;


        tree1[gdz*2].s.f%=MOD;
        tree1[gdz*2+1].s.f%=MOD;
        tree1[gdz*2].s.s%=MOD;
        tree1[gdz*2+1].s.s%=MOD;
    }


    tree1[gdz].s.f=0;
    tree1[gdz].s.s=0;
}

int akt1(int gdz, int zakl, int zakp){
    tree1[gdz].f+=zap(1,zakl,zakp,0,kk-1,1)*tree1[gdz].s.f;
    add1(1,zakl,)
}

int main()
{
    scanf("%lld%lld",&n,&q);
    while(kk<n){
        kk<<=1;
    }
    return 0;
}
