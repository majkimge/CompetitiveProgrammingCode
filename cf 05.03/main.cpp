#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200009
#define piii pair<lld,pair<lld,lld> >

using namespace std;

piii tree[540000];
lld a,b,n,kk=1,k;
pair<lld,lld> lap[MAX];
piii info[MAX];

void push(int gdz){
    if(gdz<kk){
        tree[gdz*2].s.s+=tree[gdz].s.s;
        tree[gdz*2+1].s.s+=tree[gdz].s.s;
    }
    tree[gdz].s.s=0;
}

void akt(int gdz){
    tree[gdz].f+=tree[gdz].s.s;
}

void dod(int gdz, int l, int p, int zakl, int zakp, int ile){
    if(l<=zakl&&p>=zakp){
        tree[gdz].s.s+=ile;
        akt(gdz);
        push(gdz);
    }else if(l>zakp||p<zakl){
        akt(gdz);
        push(gdz);
    }else{
        push(gdz);
        dod(gdz*2,l,p,zakl,(zakl+zakp)/2,ile);
        dod(gdz*2+1,l,p,(zakl+zakp)/2+1,zakp,ile);
        if(tree[gdz*2].f<=tree[gdz*2+1].f){
            tree[gdz].f=tree[gdz*2].f;
            tree[gdz].s.f=tree[gdz*2].s.f;
        }else{
            tree[gdz].f=tree[gdz*2+1].f;
            tree[gdz].s.f=tree[gdz*2+1].s.f;
        }

    }
}

int check(lld moc){
    for(int i=0;i<=2*kk;++i){
        tree[i].f=tree[i].s.f=tree[i].s.s=0;
    }
    for(int i=kk;i<=kk*2-1;++i){
        tree[i].s.f=i-kk;
    }
    for(int i=0;i<n;++i){
        info[i].f=0;
        info[i].s.f=lap[i].f;
        info[i].s.s=lap[i].s;
        dod(1,i,i,0,kk-1,0);
    }
    for(int i=0;i<n;++i){
        dod(1,i,i,0,kk-1,info[i].s.f/info[i].s.s+1);
    }
    for(int i=n;i<=kk-1;++i){
        dod(1,i,i,0,kk-1,10000000);
    }
    for(int i=0;i<=k;++i){
        int dok=tree[1].s.f;

        int zost=tree[1].f;

        if(zost<1)return 0;
        info[dok].s.f-=(i+1-info[dok].f)*info[dok].s.s;
        info[dok].s.f+=moc;

        info[dok].f=i+1;
        //cout<<dok<<" "<<zost<<" "<<tree[2].f<<endl;
        dod(1,dok,dok,0,kk-1,info[dok].s.f/info[dok].s.s+1-zost);

        if(dok!=0){
            dod(1,0,dok-1,0,kk-1,-1);
        }
        dod(1,dok+1,kk-1,0,kk-1,-1);
    }
    return 1;
}

lld bin(){
    lld l=0;
    lld p=(lld)2000000000;
    lld s=(l+p)/2;
    lld wyn=-1;
    while(l<=p){
        s=(l+p)/2;
        if(check(s)){
            wyn=s;
            p=s-1;
        }else{
            l=s+1;
        }
    }
    return wyn;
}

int main()
{
    scanf("%d%d",&n,&k);
    while(kk<n)kk<<=1;
    for(int i=0;i<n;++i){
        scanf("%d%d",&a,&b);
        lap[i]=mp(a,b);
    }

    cout<<bin();

    return 0;
}
