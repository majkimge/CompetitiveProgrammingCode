#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 1000009


using namespace std;

int n,m,n1,lh,rh,kk=1;
lld wynik;

char s[MAX],s1[MAX];
int nextos[MAX][4][2],last[4],ss[MAX],ss1[MAX],prevos[MAX][4][2],poczil,tree[2100000];

pair<pair<int,int>,int> poczkon[5000000];

void dod(int gdz, int co){
    gdz+=kk;
    while(gdz){
        tree[gdz]+=co;
        gdz>>=1;
    }
}

int sum(int l, int p){
    if(p<l)return 0;
    l+=kk;
    p+=kk;
    int ret=0;
    ret+=tree[l];
    if(l!=p)ret+=tree[p];

    while(l/2!=p/2){
        if(l%2==0){
            ret+=tree[l+1];
        }
        if(p%2==1){
            ret+=tree[p-1];
        }
        l>>=1;
        p>>=1;
    }
    return ret;
}


void fill_next(){
    for(int i=1;i<n;++i){
        while(last[ss[i]]<i){
            nextos[last[ss[i]]][ss[i]][0]=i;
            ++last[ss[i]];
        }
    }
    for(int i=0;i<4;++i)last[i]=0;

    for(int i=1;i<n1;++i){
        while(last[ss1[i]]<i){
            nextos[last[ss1[i]]][ss1[i]][1]=i;
            ++last[ss1[i]];
        }
    }

    for(int i=0;i<4;++i)last[i]=n+1;

    for(int i=n;i>0;--i){
        while(last[ss[i]]>i){
            prevos[last[ss[i]]][ss[i]][0]=i;
            last[ss[i]]--;
        }
    }

    for(int i=0;i<4;++i)last[i]=n1+1;

    for(int i=n1;i>0;--i){
        while(last[ss1[i]]>i){
            prevos[last[ss1[i]]][ss1[i]][1]=i;
            last[ss1[i]]--;
        }
    }
}

void fill_pocz(int dl, int p1, int p2){
    if(dl==lh){
        poczkon[poczil]=mp(mp(p1,1),p2);
        ++poczil;
        return;
    }
    for(int i=0;i<4;++i){
        int np1=n+1;
        int np2=n1+1;
        if(nextos[p1][i][0])np1=nextos[p1][i][0];
        if(nextos[p2][i][1])np2=nextos[p2][i][1];
        fill_pocz(dl+1,np1,np2);
    }
}

void fill_kon(int dl, int p1, int p2){
    if(dl==rh){
        poczkon[poczil]=mp(mp(p1,0),p2);
        poczil++;
        return;
    }
    for(int i=0;i<4;++i){
        int np1=0;
        int np2=0;
        if(prevos[p1][i][0])np1=prevos[p1][i][0];
        if(prevos[p2][i][1])np2=prevos[p2][i][1];
        fill_kon(dl+1,np1,np2);
    }
}

int main()
{
    scanf("%s",s);
    scanf("%s",s1);
    scanf("%d",&m);
    while(s[n])++n;
    while(s1[n1])++n1;

    for(int i=1;i<=n;++i){
        if(s[i-1]=='A'){
            ss[i]=0;
        }
        if(s[i-1]=='C'){
            ss[i]=1;
        }
        if(s[i-1]=='G'){
            ss[i]=2;
        }
        if(s[i-1]=='T'){
            ss[i]=3;
        }
    }

    for(int i=1;i<=n1;++i){
        if(s1[i-1]=='A'){
            ss1[i]=0;
        }
        if(s1[i-1]=='C'){
            ss1[i]=1;
        }
        if(s1[i-1]=='G'){
            ss1[i]=2;
        }
        if(s1[i-1]=='T'){
            ss1[i]=3;
        }
    }
    lh=m/2;
    rh=m-lh;
    fill_next();
    fill_pocz(0,0,0);
    fill_kon(0,n+1,n1+1);
    while(kk<max(n+1,n1+1))kk<<=1;

    sort(poczkon,poczkon+poczil);
    for(int i=poczil-1;i>=0;--i){
        if(poczkon[i].f.s==0){
            dod(poczkon[i].s,1);
        }else{
            wynik+=(lld)sum(poczkon[i].s+1,n1);
        }
    }

    for(int i=poczil-1;i>=0;--i){
        if(poczkon[i].f.s==0){
            dod(poczkon[i].s,-1);
        }
    }

    for(int i=0;i<poczil;++i){
        if(poczkon[i].f.s==0){
            dod(poczkon[i].s,1);
        }else{
            wynik+=(lld)sum(0,poczkon[i].s);
        }

    }
    printf("%lld",wynik);
    return 0;
}
