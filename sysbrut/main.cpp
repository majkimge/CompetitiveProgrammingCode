#include <bits/stdc++.h>
#define lld long long
#define MAX 100009
#define MOD 1000696969
#define mp make_pair
#define f first
#define s second

using namespace std;

lld n,m,co,a,b,c,k=1;
pair<lld,lld> tree[MAX*4];
lld tab[MAX];

void add(){
    lld gdzie=k/2;
    lld kk=k;
    while(kk>0){
        gdzie=kk/2;
        while(gdzie<kk){
            tree[gdzie]=mp((tree[gdzie*2].f+tree[gdzie*2+1].f)%MOD,(tree[gdzie*2].s+tree[gdzie*2+1].s)%MOD);
            gdzie++;
        }
        kk>>=1;
    }
}

void wroc(lld wh,lld il){
    while(wh>0){
        tree[wh]=mp((tree[wh].f+MOD)%MOD,(tree[wh].s+il+MOD)%MOD);
        wh>>=1;
    }
}

void ustaw(lld wh,lld na){
    wh+=k;
    lld tsum=0;
        lld tt=tree[wh].f;
        lld in=1;
        while(tt>0){
            tsum+=(tt%10)*in+MOD;
            tsum%=MOD;
            tt=tt/10;
            in*=na;
            in%=MOD;
        }
        lld zm=tsum-tree[wh].s;

        wroc(wh,zm);
}

lld check(lld wh,lld x,lld y,lld pocz,lld kon){
    lld wyn=0;
    if(x<=pocz&&y>=kon){
        return tree[wh].s;
    }else if(x>kon||y<pocz){
        return 0;
    }else{
        wyn+=check(wh*2,x,y,pocz,(pocz+kon)/2);
        wyn%=MOD;
        wyn+=check(wh*2+1,x,y,(pocz+kon)/2+1,kon);
        wyn%=MOD;
        return wyn;
    }
}

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&m);
    while(k<n){
        k<<=1;
    }
    for(int i=0;i<n;++i){
            lld t2=0;
        scanf("%lld",&t2);
        tab[i]=t2;
    tree[i+k]=mp(t2,t2);
    }
    if(n<3002&&m<3002){
            for(int i=0;i<m;++i){
        scanf("%lld",&co);
        if(co==0){
            scanf("%lld",&a);
            scanf("%lld",&b);
            scanf("%lld",&c);
            for(int j=a-1;j<b;++j){
                lld tsum=0;
        lld tt=tree[j+k].f;
        lld in=1;
        while(tt>0){
            tsum+=(tt%10)*in+MOD;
            tsum%=MOD;
            tt=tt/10;
            in*=c;
            in%=MOD;
        }
        tab[j]=tsum;
            }
        }

    else{
            scanf("%lld",&a);
            scanf("%lld",&b);
            lld www=0;
            for(int j=a-1;j<b;++j){
                www+=tab[j];
            }
            printf("%lld\n",www%MOD);
        }
        }

    }else{
    add();

    for(int i=0;i<m;++i){
        scanf("%lld",&co);
        if(co==0){
            scanf("%lld",&a);
            scanf("%lld",&b);
            scanf("%lld",&c);
            ustaw(a-1,c);

        }else{
            scanf("%lld",&a);
            scanf("%lld",&b);
            printf("%lld\n",(check(1,a-1,b-1,0,k-1))%MOD);
        }
    }


    }


    return 0;
}
