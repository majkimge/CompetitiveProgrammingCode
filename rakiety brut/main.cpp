#include <bits/stdc++.h>
#define lld int
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200000
#define piiii pair<pair<lld,lld>,pair<lld,lld> >

using namespace std;

lld n,x,y,p;
piiii ter;
piiii nast;
long long wynik;

lld bin(){
    lld l=0;
    lld pp=MAX;
    lld wyn=MAX;
    lld ss=(l+pp)/2;
    while(l<=pp){
        ss=(l+pp)/2;
        if(ter.f.f+ss>=nast.f.s&&ter.f.s-ss<=nast.f.f&&ter.s.f+ss>=nast.s.s&&ter.s.s-ss<=nast.s.f){
            wyn=ss;
            pp=ss-1;
        }else{
            l=ss+1;
        }
    }
    return wyn;
}

int main()
{
    scanf("%d",&n);
    scanf("%d%d%d",&x,&y,&p);
    ter=mp(mp(y+p,y-p),mp(x+p,x-p));
    for(int i=1;i<n;++i){
        scanf("%d%d%d",&x,&y,&p);
        nast=mp(mp(y+p,y-p),mp(x+p,x-p));
        lld temp=bin();
        wynik+=temp;
        ter.f.f=min(ter.f.f+temp,nast.f.f);
        ter.f.s=max(ter.f.s-temp,nast.f.s);
        ter.s.f=min(ter.s.f+temp,nast.s.f);
        ter.s.s=max(ter.s.s-temp,nast.s.s);
    }
    printf("%lld",wynik);
    return 0;
}
