#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>

using namespace std;

lld kody[50];
lld poty[50];
lld n,ss,kt1,kt2;
pii pier[1100000];
pii sec[1100000];
vector<int> v1;
vector<int> v2;

void pi(int kol,lld sum, lld ind){
    if(kol==n/2){
        pier[ind]=mp(sum,ind);
        ++kt1;
    }else{
        pi(kol+1,sum+kody[kol],poty[kol]+ind);
        pi(kol+1,sum,ind);
    }
}

void se(int kol,lld sum, lld ind){
    if(kol==n){
        sec[ind]=mp(sum,ind);
        ++kt2;
    }else{
        se(kol+1,sum+kody[kol],poty[kol-n/2]+ind);
        se(kol+1,sum,ind);
    }
}

lld bin(lld co){
    lld l=0;
    lld p=kt2-1;
    lld s=(l+p)/2;
    lld wyn=-1;
    while(l<=p){
        s=(l+p)/2;
        if(sec[s].f>co){
            p=s-1;
        }else if(sec[s].f<co){
            l=s+1;
        }else{
            return s;
        }
    }
    return -1;
}

void rozb(int l, int p){
    int ter=pier[l].s;
    for(int i=0;i<n/2;++i){
        v1.pb(ter%2);
        ter>>=1;
    }
    ter=sec[p].s;
    for(int i=n/2;i<n;++i){
        v1.pb(ter%2);
        ter>>=1;
    }
}

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&kody[i]);
    }
    poty[0]=1;
    for(int i=1;i<24;++i){
        poty[i]=poty[i-1]*2;
    }
    scanf("%lld",&ss);
    pi(0,0,0);
    se(n/2,0,0);
    sort(sec,sec+kt2);
    for(int i=0;i<kt1;++i){
        int xd=bin(ss-pier[i].f);
        if(xd!=-1){
            rozb(i,xd);
            break;
        }
    }
    for(int i=0;i<v1.size();++i){
        printf("%d",v1[i]);
    }
    return 0;
}
