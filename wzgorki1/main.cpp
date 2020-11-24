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
lld wys1[MAX*4];
lld n,m,l,p,d,wyn,ost,spad,tempwyn,ros,stal;
lld gory[MAX];
lld doly[MAX];
lld rosy [MAX];
lld spady [MAX];
lld staly [MAX];

void dodaj(lld l1,lld p1,lld ile){
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
    //return wyn;
}

lld checkgor(lld l1,lld p1){
    l1+=k;
    p1+=k;
    lld wyn=0;
    if(l1==p1){
        wyn+=wys[l1];
    }else{
        wyn+=wys[l1];
        wyn+=wys[p1];
        while(l1/2!=p1/2){
            if(l1%2==0){
                wyn+=wys[l1+1];
            }
            if(p1%2==1){
                wyn+=wys[p1-1];
            }
            l1>>=1;
            p1>>=1;
        }
    }
    return wyn;
}

void addgor(lld gdzie){
    gdzie+=k;
    wyn=0;
    wys[gdzie]+=1;
    gdzie>>=1;
    while(gdzie>0){
        wys[gdzie]+=1;
    }

}

lld checkdol(lld l1,lld p1){
    l1+=k;
    p1+=k;
    lld wyn=0;
    if(l1==p1){
        wyn+=wys1[l1];
    }else{
        wyn+=wys1[l1];
        wyn+=wys1[p1];
        while(l1/2!=p1/2){
            if(l1%2==0){
                wyn+=wys1[l1+1];
            }
            if(p1%2==1){
                wyn+=wys1[p1-1];
            }
            l1>>=1;
            p1>>=1;
        }
    }
    return wyn;
}

void adddol(lld gdzie){
    gdzie+=k;
    wyn=0;
    wys1[gdzie]+=1;
    gdzie>>=1;
    while(gdzie>0){
        wys1[gdzie]+=1;
    }

}


lld check(lld gdzie){
    gdzie+=k;
    wyn=0;
    wyn+=wier[gdzie];
    gdzie>>=1;
    while(gdzie>0){
        wyn+=wier[gdzie];
    }
    return wyn;
}

lld bin(lld l1,p1,co){
    lld l2=l1;
    lld p2=p1;
    lld s=(l2+p2)/2;
    lld wyng=0;
    lld wynd=0;
    while(l2<=p2){
          s=(l2+p2)/2;
        if(checkgor==co){
            p2=s-1;
            wyng=s;
        }else{
            l2=s+1;

        }
    }
    while(l1<=p1){
          s=(l1+p1)/2;
        if(checkgor==co){
            p1=s-1;
            wynd=s;
        }else{
            l1=s+1;

        }
    }
    if(wyng>wynd){
        return 1;
    }else{
        return 0;
    }
}

using namespace std;

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
    for(int i=1;i<n;++i){
        if(tab[i]>tab[i-1]){
            if(!ros){
                ros=1;
                tempros=i-1;
                if(spad){
                    spad=0;
                    spady[tempspad]=i-1;
                    doly[i-1]=1;
                }
            }
        }else if(tab[i]<tab[i-1]){
            if(!spad){
                spad=1;
                tempspad=i-1;
                if(ros){
                    ros=0;
                    rosy[tempros]=i-1;
                    gory[i-1]=1;
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
        ost=0;
        spad=0;
            wyn=0;
        scanf("%lld",&l);
        scanf("%lld",&p);
        scanf("%lld",&d);
        dodaj(l,p,d);
            if(bin(0,l)=1){

            }
        }

    return 0;
}
