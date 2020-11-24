#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 500000
#define MOD 1000000007
#define piii pair<lld,pair<pair<lld,lld>,pair<lld,lld> > >

using namespace std;

lld n,q,kk=1,ll,pp,ilek;
char cot;


piii tree[MAX];

void push(int gdz){
    if(gdz<kk){
            tree[gdz*2].s.s.s+=tree[gdz].s.s.s;
            tree[gdz*2].s.s.f+=tree[gdz].s.s.f;
            tree[gdz*2+1].s.s.s+=tree[gdz].s.s.s;
            tree[gdz*2+1].s.s.f+=tree[gdz].s.s.f;
            tree[gdz*2].s.s.s%=MOD;
            tree[gdz*2].s.s.f%=MOD;
            tree[gdz*2+1].s.s.s%=MOD;
            tree[gdz*2+1].s.s.f%=MOD;
        }
        tree[gdz].s.s.f=0;
        tree[gdz].s.s.s=0;
}

void akt(lld gdz, lld zakl, lld zakp){
        tree[gdz].f+=(tree[gdz].s.f.f*tree[gdz].s.s.s)%MOD;

        tree[gdz].s.f.s+=(tree[gdz].s.s.s*(zakp-zakl+1))%MOD;
        tree[gdz].s.f.s%=MOD;
        tree[gdz].f+=(tree[gdz].s.f.s*tree[gdz].s.s.f)%MOD;

        tree[gdz].s.f.f+=(tree[gdz].s.s.f*(zakp-zakl+1))%MOD;
        tree[gdz].s.f.f%=MOD;
        tree[gdz].f%=MOD;

}

void add(lld gdz, lld l, lld p, lld zakl, lld zakp, lld ile, lld tr){
    if(l<=zakl&&p>=zakp){
        lld dod=0;
        if(tr==0){
            tree[gdz].s.s.f+=ile;
        }else{
            tree[gdz].s.s.s+=ile;
        }
        akt(gdz,zakl,zakp);
        push(gdz);
        //return dod;

    }else if(l>zakp||p<zakl){
        akt(gdz,zakl,zakp);
        push(gdz);
    }else{
        push(gdz);
        add(gdz*2,l,p,zakl,(zakl+zakp)/2,ile,tr);
        add(gdz*2+1,l,p,(zakl+zakp)/2+1,zakp,ile,tr);
        tree[gdz].s.f.f=(tree[gdz*2+1].s.f.f+tree[gdz*2].s.f.f)%MOD;
        tree[gdz].s.f.s=(tree[gdz*2+1].s.f.s+tree[gdz*2].s.f.s)%MOD;
        tree[gdz].f=(tree[gdz*2+1].f+tree[gdz*2].f)%MOD;
    }
}

lld check(lld gdz, lld l, lld p, lld zakl, lld zakp){
    lld wyn=0;
    if(l<=zakl&&p>=zakp){
        akt(gdz,zakl,zakp);

        push(gdz);
        return tree[gdz].f;
        //return dod;

    }else if(l>zakp||p<zakl){
        akt(gdz,zakl,zakp);
        push(gdz);
        return 0;
    }else{
        push(gdz);
        wyn+=check(gdz*2,l,p,zakl,(zakl+zakp)/2);
        wyn+=check(gdz*2+1,l,p,(zakl+zakp)/2+1,zakp);
        tree[gdz].s.f.f=(tree[gdz*2+1].s.f.f+tree[gdz*2].s.f.f)%MOD;
        tree[gdz].s.f.s=(tree[gdz*2+1].s.f.s+tree[gdz*2].s.f.s)%MOD;
        tree[gdz].f=(tree[gdz*2+1].f+tree[gdz*2].f)%MOD;
        return wyn%MOD;
    }
}

int main()
{
    scanf("%lld%lld",&n,&q);
    while(kk<n)kk<<=1;

    for(int i=0;i<q;++i){
        scanf("%c",&cot);
        scanf("%c",&cot);
        if(cot=='*'){
                //cout<<"X";
            scanf("%lld%lld%lld",&ll,&pp,&ilek);
            add(1,ll-1,pp-1,0,kk-1,ilek,0);
        }else if(cot=='.'){
            scanf("%lld%lld%lld",&ll,&pp,&ilek);
            add(1,ll-1,pp-1,0,kk-1,ilek,1);
        }else{
            scanf("%lld%lld",&ll,&pp);
            //cout<<tree[1].s.f.f;
            printf("%lld\n",check(1,ll-1,pp-1,0,kk-1));
        }
    }
    return 0;
}
