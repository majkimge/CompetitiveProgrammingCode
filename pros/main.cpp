#include <bits/stdc++.h>
#define lld unsigned int
#define MAX 10000
#define MOD 1000000007
#define mp make_pair
#define f first
#define s second

using namespace std;

int n,a,b,c,d,wyn,k=1;

pair<pair<int,int>, pair<int,int> >tab[MAX*2];
pair<pair<int,int>, pair<int,int> >tab1[MAX*2];
int czy[MAX*2];
pair<int,int> tree[MAX*4];

void wroc(int wh,int co){
    wh>>=1;
    while(wh>0){
        tree[wh]=mp(tree[wh].f+co,tree[wh].s);
        wh>>=1;
    }
}

void push(int wh,int co){
    tree[wh]=mp(tree[wh].f,tree[wh].s-co);
    tree[wh*2]=mp(tree[wh*2].f,tree[wh*2].s+co);
    tree[wh*2+1]=mp(tree[wh*2+1].f,tree[wh*2+1].s+co);
}

int check(int wh,int a, int b, int pocz, int kon){
    int ww=0;
    if(pocz>=a&&kon<=b){
        ww+=tree[wh].f+(kon-pocz+1)*tree[wh].s;
        wroc(wh,(kon-pocz+1)*tree[wh].s);
        return ww;
    }else if(pocz>b||kon<a){
        wroc(wh,(kon-pocz+1)*tree[wh].s);
        return 0;
    }else{
        push(wh,tree[wh].s);
        ww+=check(wh*2,a,b,pocz,(pocz+kon)/2);
        ww+=check(wh*2+1,a,b,(pocz+kon)/2+1,kon);
        return ww;
    }

}

void add(int wh,int a, int b, int pocz, int kon, int co){
    //int ww=0;
    if(pocz>=a&&kon<=b){
        tree[wh]=mp(tree[wh].f,tree[wh].s+co);
        wroc(wh,(kon-pocz+1)*tree[wh].s);
        return;
    }else if(pocz>b||kon<a){
        return;
    }else{
        add(wh*2,a,b,pocz,(pocz+kon)/2,co);
        add(wh*2+1,a,b,(pocz+kon)/2+1,kon,co);
        return;
    }

}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        scanf("%d",&d);
        tab[i*2]=mp(mp(a,1),mp(b,d));
        tab[i*2+1]=mp(mp(c,0),mp(b,d));

    }
    sort(tab,tab+2*n);
    while(k<n){
        k<<=1;
    }

    for(int i=0;i<2*n;++i){
        int jj=i;
        int ttt=tab[i].f.f;
        while(tab[jj].f.f==ttt){
            if(tab[i].f.s==0){
            int tt=check(1,tab[i].s.f-1,tab[i].s.s,0,k-1);
            if(tt==0){
                //cout<<tab[i].f.f<<" "<<tab[i].s.s<<endl;
                wyn++;
            }
            add(1,tab[i].s.f,tab[i].s.s-1,0,k-1,1);
        }else{
            add(1,tab[i].s.f,tab[i].s.s-1,0,k-1,-1);
        }

        }


    }
    printf("%d",wyn);
    return 0;
}
