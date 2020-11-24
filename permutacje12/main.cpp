#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 300009
#define PIER 550

using namespace std;

lld n,M;
lld tab[MAX];
lld ile[MAX];
lld wynik,mian=1,licz=1,sil[MAX],kk=1,ilep;
lld ilepier[MAX];
lld ilepp[MAX],cal;

lld tree[1100000];

lld pot(lld co, lld dok){
    if(dok<=0)return 1;
    if(dok%2==0){
        lld temp=pot(co,dok/2);
        return (temp*temp)%M;
    }
    return (pot(co,dok-1)*co)%M;
}

void add(int gdz, int iled){
    gdz+=kk;
    while(gdz){
        tree[gdz]+=iled;
        gdz>>=1;
    }
}

void rozk(lld co,lld jak){
    int temp;
    int czy=1;
    int pocz=2;
    while(czy){
        czy=0;
        for(int i=pocz;i<PIER&&i<=co;++i){
            if(co%i==0){
                while(co%i==0){
                    ilepier[i]+=jak;
                    co=co/i;
                }
                czy=1;
                pocz=i+1;
                break;
            }
        }
    }

    ilepp[0]=1;
    for(int i=2;i<PIER;++i){

        ilepp[0]*=pot(i,ilepier[i]);
        ilepp[0]%=M;
    }
    if(co>1){
        ilepier[co]+=jak;
        ilepp[co/PIER]=1;
        for(int i=0;i<PIER;++i){
            ilepp[co/PIER]*=pot(i+co/PIER*PIER,ilepier[i+co/PIER*PIER]);
            ilepp[co/PIER]%=M;
        }
    }
    cal=1;
    for(int i=0;i<PIER;++i){

        cal*=max((lld)1,ilepp[i]);
        cal%=M;
    }
}

lld check(lld l, lld p){
    lld wyn=0;
    l+=kk;
    p+=kk;
    wyn+=tree[l];
    if(l!=p)wyn+=tree[p];
    while(l/2!=p/2){
        if(l%2==0){
            wyn+=tree[l+1];
        }
        if(p%2){
            wyn+=tree[p-1];
        }
        l>>=1;
        p>>=1;
    }
    return wyn;
}

lld gcdExtended(lld a, lld b, lld *x, lld *y);

lld modInverse(lld b, lld m)
{
    lld x, y;
    lld g = gcdExtended(b, m, &x, &y);

    if (g != 1)
        return -1;

    return (x%m + m) % m;
}


lld modDivide(lld a, lld b, lld m)
{
    a = a % m;
    lld inv = modInverse(b, m);

    return(inv * a) % m;
}


lld gcdExtended(lld a, lld b, lld *x, lld *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    lld x1, y1;
    lld gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

int main()
{
    scanf("%lld%lld",&n,&M);
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
    }
    while(kk<MAX)kk<<=1;
    ile[tab[n-1]]++;
    add(tab[n-1],1);
    for(int i=n-2;i>=0;--i){
        ile[tab[i]]++;
        add(tab[i],1);
        rozk(ile[tab[i]],-1);
        //mian%=M;
        //cout<<"A";
        if((check(0,tab[i]-1))){
        rozk((check(0,tab[i]-1)),1);
            //cout<<(check(0,tab[i]-1))<<" "<<cal<<" "<<ilepp[1]<<endl;
            //cout<<cal<<endl;
             wynik+=cal;

            rozk((check(0,tab[i]-1)),-1);
        }
        wynik%=M;
        rozk(n-i,1);
        //licz%=M;
    }
    printf("%lld",wynik+1);
    return 0;
}

/*
4 1000000009
2 1 10 2
*/
