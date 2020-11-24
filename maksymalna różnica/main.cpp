#include <bits/stdc++.h>
#define lld long long

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define MOD 1000000009

using namespace std;

lld tab[MAX],n,t,sumik;
lld tab1[MAX];
pair<lld,lld> mini;
priority_queue<pair<lld,lld> >q;

lld solve(lld ile){
    lld wyn=0;
    lld last=mini.f;
    for(lld i=mini.s-1;i>=0;--i){
        lld dod=max(tab[i]-last-ile,(lld)0);
        wyn+=dod;
        last=tab[i]-dod;
    }
    last=mini.f;
    for(lld i=mini.s+1;i<n;++i){
        lld dod=max(tab[i]-last-ile,(lld)0);
        wyn+=dod;
        last=tab[i]-dod;
    }
    return wyn;
}

lld solve1(lld ile){
    lld wyn=0;
    lld last=mini.f;
    for(lld i=mini.s-1;i>=0;--i){
        lld dod=max(tab[i]-last-ile,(lld)0);
        wyn+=dod;
        lld tempor=tab[i];
        tab[i]=min(tab[i],last+ile);
        last=tempor-dod;

    }
    last=mini.f;
    for(lld i=mini.s+1;i<n;++i){
        lld dod=max(tab[i]-last-ile,(lld)0);
        wyn+=dod;
        lld tempor=tab[i];
        tab[i]=min(tab[i],last+ile);
        last=tempor-dod;
    }
    return wyn;
}

pair<lld,lld> bin(){
    lld l=1;
    lld p=1000000000;
    lld s=(l+p)/2;
    pair<lld,lld> wyn;
    while(l<=p){
        s=(l+p)/2;
        lld tempixon=solve(s);
        if(tempixon<=t){
            wyn=mp(s,tempixon);
            p=s-1;
        }else{
            l=s+1;
        }
    }
    return wyn;
}

int main()
{
    scanf("%lld%lld",&n,&t);
    mini=mp(MOD,0);
    for(lld i=0;i<n;++i){
        scanf("%lld",&tab[i]);
        if(tab[i]<mini.f){
            mini.f=tab[i];
            mini.s=i;
        }
    }
    for(lld i=0;i<n;++i){
        sumik+=tab[i]-mini.f;
    }
    if(t-sumik>=0&&(t-sumik)%n==0){
        for(lld i=0;i<n;++i){
            printf("%lld ",mini.f-(t-sumik)/n);
        }
    }else{
        lld doko=bin().f;
        //cout<<solve(19);
        lld zost=t-solve1(doko);
        lld ileod=zost/n;
        ileod=min(ileod,(lld)mini.f-1);
        zost-=ileod*n;
        for(lld i=0;i<n;++i){
            tab[i]-=ileod;
        }
        for(lld i=0;i<n;++i){
            q.push(mp(tab[i],i));
        }
        for(lld i=0;i<zost;++i){
            pair<lld,lld> gdzie=q.top();
            q.pop();
            tab[gdzie.s]--;
            q.push(mp(tab[gdzie.s],gdzie.s));
        }
        for(lld i=0;i<n;++i){
            printf("%lld ",tab[i]);
        }
    }

    return 0;
}
