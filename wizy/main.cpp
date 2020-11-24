#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define piii pair<int,pair<int,int> >
#define pii pair<int,int>
#define MAX 10009
#pragma GCC optimalize ("ofast")

using namespace std;

int n,a,b,c;
piii lud[MAX];
pii tab[MAX][2];
int ite=0,wlk;
int pudla[MAX][2];
lld wynik;

int czy(int il, pii ter){
    int kt=0;
    int czyt=0;
    for(int i=0;i<il;++i){
        if(ter<tab[i][ite]&&!czyt){
            tab[kt][ite^1]=ter;
            ++kt;
            czyt=1;
        }
        tab[kt][ite^1]=tab[i][ite];
        ++kt;
    }
    if(!czyt){
        tab[kt][ite^1]=ter;
        ++kt;
    }
    pudla[0][ite^1]=tab[0][ite^1].f;
    int przyps=0;
    /*for(int i=0;i<il+1;++i){
        cout<<tab[i][ite^1].f<<" "<<tab[i][ite^1].s<<" < ";
    }
    cout<<endl;*/
    for(int i=1;i<il+1;++i){
        pudla[i][ite^1]=max(pudla[i-1][ite^1]+1,tab[i][ite^1].f);
        if(pudla[i][ite^1]>tab[i][ite^1].s){
            przyps=1;
            break;
        }
    }
    if(przyps){
        return 0;
    }
    ite=ite^1;
    return 1;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d%d",&a,&b,&c);
        lud[i]=mp(-c,mp(a,b));
    }
    sort(lud,lud+n);
    for(int i=0;i<n;++i){
        lud[i].f=-lud[i].f;
        //cout<<lud[i].f<<endl;
        if(czy(wlk,lud[i].s)){
            ++wlk;
            wynik+=(lld)lud[i].f;
        }
    }
    printf("%lld",wynik);
    return 0;
}
