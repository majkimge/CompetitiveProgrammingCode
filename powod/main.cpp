#include <bits/stdc++.h>

#define MAX 1000009
#define lld long long
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
using namespace std;

lld n,m,h;
lld parent[MAX];
lld wynik=1;
lld wyniki[MAX];
lld rangi[MAX];
lld najm[MAX];
lld najmnajw=0;
lld o;
pair<lld, pair<lld, lld> > kraw[MAX];

bool compare(const pair<lld, pair<lld,lld> > &a, const pair<lld, pair<lld,lld> > &b)
{
    return a.first < b.first;
}
lld Find(lld x){

    if(parent[x]!=x){
        parent[x]=Find(parent[x]);
    }
    return parent[x];

}
void Union(lld x, lld y, lld kr){
    lld a=Find(x);
    lld b=Find(y);
    if(a!=b){
        if(rangi[a]<rangi[b]){
            parent[a]=b;
            if(rangi[a]==0){
                wyniki[b]=((kr+1)%MOD)*((kr-najm[b]+wyniki[b])%MOD);
                wyniki[b]=wyniki[b]%MOD;
                najm[b]=kr;
            }else{
                wyniki[b]=((kr-najm[b]+wyniki[b])%MOD)*((kr-najm[a]+wyniki[a])%MOD);
                wyniki[b]=wyniki[b]%MOD;
                najm[b]=kr;
            }

        }else if(rangi[b]<rangi[a]){
            parent[b]=a;
            if(rangi[b]==0){
                wyniki[a]=((kr+1)%MOD)*((kr-najm[a]+wyniki[a])%MOD);
                wyniki[a]=wyniki[a]%MOD;
                najm[a]=kr;
            }else{
                wyniki[a]=((kr-najm[a]+wyniki[a])%MOD)*((kr-najm[b]+wyniki[b])%MOD);
                wyniki[a]=wyniki[a]%MOD;
                najm[a]=kr;
            }

        }else{
            parent[b]=a;
            if(rangi[a]==0){
                wyniki[a]=((kr+1)%MOD)*((kr+1)%MOD);
                wyniki[a]=wyniki[a]%MOD;
                najm[a]=kr;
            }else{
                wyniki[a]=((kr-najm[a]+wyniki[a])%MOD)*((kr-najm[b]+wyniki[b])%MOD);
                wyniki[a]=wyniki[a]%MOD;
                najm[a]=kr;
            }
            rangi[a]=rangi[a]+1;
        }
    }
}

int main()
{
    scanf("%lld",&m);
    scanf("%lld",&n);
    scanf("%lld",&h);
    //cout<<"b";

            for(lld j=0;j<m;j++){
                for(lld z=0;z<n-1;z++){
                    scanf("%lld",&o);
                    kraw[j*(n-1)+z]=mp(o,mp(j*n+z,j*n+z+1));

                }
            }

            for(lld j=0;j<m-1;j++){
                for(lld z=0;z<n;z++){
                    scanf("%lld",&o);
                    kraw[(m-1)*(n-1)+n-1+j*n+z]=mp(o,mp(j*n+z,(j+1)*n+z));

                }
            }



    sort(&kraw[0],&kraw[m*n*2-m-n],compare);
    for(lld i=0;i<n*m;++i){
        parent[i]=i;
        wyniki[i]=1;



    }
    for(lld i=0;i<m*n*2-m-n;i++){
        Union(kraw[i].s.f,kraw[i].s.s,kraw[i].f);
    }
    if(m!=0||n!=0){
        printf("%lld",(wyniki[Find(0)]+h-najm[Find(0)])%MOD);
    }else{
        printf("%lld",(h+1)%MOD);
    }

    return 0;
}
