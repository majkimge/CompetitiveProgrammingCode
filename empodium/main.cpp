#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1100009
using namespace std;

typedef uint_fast32_t lld;
lld tab[MAX],kk=1,temp;
lld tree[4200000];
int odw[MAX];
priority_queue<int> gdz[2200009];
priority_queue<lld> duz;
int n,last=-1,wynik,a;
vector<pair<lld,lld> >v;

void add(int gd, int ile){
    gd+=kk;
    tree[gd]+=ile;
    while(gd/2){
        tree[gd/2]=max(tree[gd/2*2],tree[gd/2*2+1]);
        gd>>=1;
    }

}
lld check(int l, int p){
    lld wyn=0;
    l+=kk;
    p+=kk;
    wyn=max(tree[l],tree[p]);
    while(l/2!=p/2){
        if(l%2==0){
            wyn=max((lld)wyn,tree[l+1]);
        }
        if(p%2==1){
            wyn=max((lld)wyn,tree[p-1]);
        }
        l>>=1;
        p>>=1;
    }
    return wyn;
}

int zer(int odc, int gd){
    return n+gd-odc;
}

int main()
{
    scanf("%d",&n);
    while(kk<n){
        kk<<=1;
    }
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
        duz.push(tab[i]);
        add(i,tab[i]);
        while(!duz.empty()&&duz.top()>tab[i]){
            odw[duz.top()]=1;
            duz.pop();
        }
        while(!gdz[zer(tab[i],i)].empty()&&odw[tab[gdz[zer(tab[i],i)].top()]]){
            gdz[zer(tab[i],i)].pop();
        }
        if(!gdz[zer(tab[i],i)].empty()){
            temp=check(gdz[zer(tab[i],i)].top(),i);
            if(gdz[zer(tab[i],i)].top()>last&&temp<=tab[i]){
            last=gdz[zer(tab[i],i)].top();
            v.pb(mp(last,i));
        }
        }

        gdz[zer(tab[i],i)].push(i);
    }
    sort(v.begin(),v.end());
    printf("%d\n",v.size());
    for(int i=0;i<v.size();++i){
        printf("%d %d\n",v[i].f+1,v[i].s+1);
    }
    return 0;
}
