#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 5000009
using namespace std;

int n,m,kk=1,itlp,itlk,itpp,itpk;
lld wynik;
int tab[MAX];
pair<int,int> tree[MAX*2];      //f and; s or
pair<int,int> suma;
pair<int,int> sumal;
pair<int,int> sumap;

void ustaw(int gdzie,int co){
    gdzie+=kk;
    tree[gdzie].f=co;
    tree[gdzie].s=co;
    gdzie>>=1;
    while(gdzie>0){
        if(tree[gdzie].f==-1){
            tree[gdzie].f=co;
            tree[gdzie].s=co;
        }else{
            tree[gdzie].f=(tree[gdzie].f&co);
            tree[gdzie].s=(tree[gdzie].s|co);
        }
        gdzie>>=1;
    }
}

pair<int,int> check(int l,int p){
    pair<int,int> wyn=mp(-1,-1);
    l+=kk;
    p+=kk;
    if(l==p){
        if(tree[l].f!=-1){
            wyn.f=tree[l].f;
            wyn.s=tree[l].s;
        }
    }else{
        if(tree[l].f!=-1){
            wyn.f=tree[l].f;
            wyn.s=tree[l].s;
        }
        if(wyn.f==-1){
            wyn.f=tree[p].f;
            wyn.s=tree[p].s;
        }else if(tree[p].f!=-1){
            wyn.f=(tree[p].f&wyn.f);
            wyn.s=(tree[p].s|wyn.s);
        }
    }
    while(l/2!=p/2){
        if(l%2==0){
            if(wyn.f==-1){
                wyn.f=tree[l+1].f;
                wyn.s=tree[l+1].s;
            }else{
                if(tree[l+1].f!=-1){
                    wyn.f=(tree[l+1].f&wyn.f);
                    wyn.s=(tree[l+1].s|wyn.s);
                }
            }
        }
        if(p%2==1){
            if(wyn.f==-1){
                wyn.f=tree[p-1].f;
                wyn.s=tree[p-1].s;
            }else{
                if(tree[p-1].f!=-1){
                    wyn.f=(tree[p-1].f&wyn.f);
                    wyn.s=(tree[p-1].s|wyn.s);
                }
            }
        }
        l>>=1;
        p>>=1;
    }
    return wyn;
}

int main()
{
    scanf("%d%d",&n,&m);
    while(kk<m*2){
        kk<<=1;
    }
    for(int i=0;i<MAX*2-2;++i){
        tree[i].f=tree[i].s=-1;
    }
    for(int i=0;i<m;++i){
        scanf("%d",&tab[i]);
        tab[i+m]=tab[i];
        ustaw(i,tab[i]);
        ustaw(i+m,tab[i]);
    }
    suma.f=tab[0];
    suma.s=tab[0];
    for(int i=0;i<m;++i){
        suma.f=(suma.f&tab[i]);
        suma.s=(suma.s|tab[i]);
    }
    //cout<<suma.s;
    //cout<<check(2,3).s;
    itlp=0;
    itlk=0;
    itpp=m-1;
    itpk=m-1;
    while(check(itpk,itpp)!=suma){
        itpk--;
    }
    //cout<<itpk;
    while(itlk<m){
        while(itlk<m-1&&check(itlp,itlk)!=suma){
            itlk++;
        }
        while(itpk<itpp&&check(itpk+1,itpp)==suma&&itpk<m-1){
            itpk++;
        }
        //cout<<itlp<<" "<<itlk<<" "<<itpk<<" "<<itpp<<endl;
        if(check(itlp,itlk)==suma&&check(itpk,itpp)==suma&&itlk<m){
            wynik+=(lld)max((lld)0,(lld)itpk-itlk);
        }

        itlp++;
        itpp++;
        itlk=max(itlk,itlp);
        itpk=min(itpk,itpp);
    }
    printf("%lld",wynik);
    return 0;
}
