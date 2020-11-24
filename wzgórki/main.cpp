#include <bits/stdc++.h>
#define lld long long
#define MAX 100009
#define mp make_pair
#define f first
#define s second

using namespace std;

lld tab[MAX];
lld wier[MAX*4];
lld wys[MAX*4];
lld n,m,l,p,d,wyn,ost,spad,tempwyn,ros,stal;
lld rosy [MAX];
lld spady [MAX];
lld staly [MAX];

lld checkmax(lld l1,lld p1){
    l1+=k;
    p1+=k;
    lld wyn=0;
    if(l1==p1){
        return wier[l1];
    }else{
        wyn=max(wier[l1],wier[p1]);
        while(l1/2!=p1/2){
            if(l1%2==0){
                wyn=max(wier[l1+1],wyn);
            }
            if(p1%2==1){
                wyn=max(wier[p1-1],wyn);
            }
            l1>>=1;
            p1>>=1;
        }
    }
    return wyn;
}

void ustawmax(lld gdzie,lld co){
    gdzie+=k;
    wier[gdzie]+=co;
    gdzie>>=1;
    while(gdzie>0){
        wier[gdzie]=max(wier[2*gdzie],wier[2*gdzie+1]);
    }
}

lld dodaj(lld l1,lld p1,lld ile){
    l1+=k;
    p1+=k;

    if(l1==p1){
        wier[l1]+=ile;
    }else{
        wier[l1]+=ile;
        wier[p1]+=ile;
        while(l1/2!=p1/2){
            if(l1%2==0){
                wier[l1+1]+=ile;
            }
            if(p1%2==1){
                wier[p1-1]+=ile;
            }
            l1>>=1;
            p1>>=1;
        }
    }
    return wyn;
}

int main()
{
    lld k=1;
    while(k<n){
        k<<=1;
    }
    scanf("%lld",&n);
    scanf("%lld",&m);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
    }
    tempros=0;
    tempspad=0;
    tempstal=0;
    for(int i=1;i<n;++i){
        if(tab[i]>tab[i-1]){
            if(!ros){
                ros=1;
                tempros=i-1;
                if(spad){
                    spad=0;
                    spady[tempspad]=i-1;
                }
            }
        }else if(tab[i]<tab[i-1]){
            if(!spad){
                spad=1;
                tempspad=i-1;
                if(ros){
                    ros=0;
                    rosy[tempros]=i-1;
                }
            }
        }else{

                if(ros){
                    ros=0;
                    rosy[tempros]=i-1;
                }
                if(spad){
                    spad=0;
                    spady[tempspad]=i-1;
                }

            }
        }

        for(int i=0;i<m;++i){

        scanf("%lld",&l);
        scanf("%lld",&p);
        scanf("%lld",&d);

        }


    return 0;
}
