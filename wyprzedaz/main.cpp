#include <bits/stdc++.h>
#define lld long long
#define MAX 100009
#define mp make_pair
#define f first
#define s second

using namespace std;

lld n,k=1,suma,wynik;
lld tab[MAX];
pair<lld,lld> maxy[MAX*4];
lld wyny[MAX];
lld wyr[MAX];
lld doktorego[MAX];
lld ilewyr;

pair<lld,lld> check(lld a1,lld b1){
    a1+=k;
    b1+=k;
    lld wyn=0;
    lld ktoryon;

    wyn=max(wyn,maxy[a1].f);
    wyn=max(wyn,maxy[b1].f);
    if(wyn==maxy[a1].f){
        ktoryon=maxy[a1].s;
    }else{
        ktoryon=maxy[b1].s;
    }

    while(a1/2!=b1/2){
        if(a1%2==0){
            wyn=max(wyn,maxy[a1+1].f);
            if(wyn==maxy[a1+1].f){
                ktoryon=maxy[a1+1].s;
            }
        }
        if(b1%2==1){
            wyn=max(wyn,maxy[b1-1].f);
            if(wyn==maxy[b1-1].f){
                ktoryon=maxy[b1-1].s;
            }
        }

        a1>>=1;
        b1>>=1;
    }

    //cout<<wyn<<ktoryon<<endl;
    pair<lld,lld> cozwra=mp(wyn,ktoryon);
    return cozwra;
}

void ustaw(lld gdzie,lld co){
    gdzie+=k;
    lld tempy=gdzie;
    maxy[gdzie]=mp(co,gdzie-k);
    gdzie>>=1;
    while(gdzie>0){
        maxy[gdzie]=mp(max(maxy[gdzie*2].f,maxy[gdzie*2+1].f),0);
        if(maxy[gdzie*2].f==maxy[gdzie].f){
            maxy[gdzie]=maxy[gdzie*2];
        }else{
            maxy[gdzie]=maxy[gdzie*2+1];
        }
        gdzie>>=1;
    }
}

lld bin(lld l1,lld p1,lld co){
    lld s=(l1+p1)/2;
    lld wyn=-1;
    while(l1<=p1){
            //cout<<"B";
        s=(l1+p1)/2;
        if(tab[s]<co){
            wyn=s;
            l1=s+1;
        }else{
            p1=s-1;
        }
    }
    return wyn;

}

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
        suma+=tab[i];
    }

    while(k<n){
        k<<=1;
    }
    sort(tab,tab+n);
    while(ilewyr<n){

            lld ost=0;
        lld pl=1;
    wyny[pl-1]=0;
     if(!wyr[pl-1])
    ustaw(pl-1,tab[pl-1]);

    while(tab[pl]==tab[pl-1]){

        wyny[pl]=0;
        if(!wyr[pl])
        ustaw(pl,tab[pl]);//cout<<"V";
        pl++;

    }
    for(int i=pl;i<n;++i){
        if(!wyr[i]){
            ost=i;
            lld od=bin(0,i,tab[i]);
        //cout<<od;
        if(od>=0){
            pair<lld,lld> odp=check(0,od);
            wyny[i]=odp.f;
            doktorego[i]=odp.s;
            ustaw(doktorego[i],0);
            ustaw(i,tab[i]-wyny[i]);
        }
        }

    }
    wynik+=tab[ost];
    wyr[ost]=1;
    //cout<<ost<<" ";
    ilewyr++;
    ustaw(ost,0);
    if(wyny[ost]>0){
            ilewyr++;
        wyr[doktorego[ost]]=1;
        //cout<<doktorego[ost]<<endl;
        ustaw(doktorego[ost],0);
    }

        for(int i=0;i<2*n+10;++i){
            maxy[i]=mp(0,0);
        }
    }


    printf("%lld",wynik);

    return 0;
}
