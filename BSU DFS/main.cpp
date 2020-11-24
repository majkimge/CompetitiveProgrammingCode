#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009
#define INF 1000000009
using namespace std;


int n,a,b,wyn=1,przyps,maxi;
int kt=1;
int odw[MAX];
vector<int> wyny;
vector<int> warto;
int war[MAX*2];
pair<int,int> tab[MAX];
//pair<int,int> tab1[MAX];
int m[MAX*2];
map<int,int> m1;
int poile[MAX*2];
vector<int >kraw[MAX];

int dfs(int from){
    if(!odw[from]){
        wyny.pb(from);
        poile[from]--;
        int temp=0;
        while(poile[from]>0&&temp<kraw[from].size()){
            if(!odw[kraw[from][temp]]){
                dfs(kraw[from][temp]);
            }
        }
        if(poile[from]){
            przyps=1;
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        scanf("%d",&b);
        tab[i]=mp(b,a);
//        tab1[i]=mp(a,b);
        warto.pb(a);
        warto.pb(b);
        war[i*2]=a;
        war[i*2+1]=b;

    }
    sort(tab,tab+n);
//    sort(tab1,tab1+n);
    sort(war,war+2*n);
    for(int i=0;i<2*n;++i){
        m1[war[i]]=i;
        //cout<<war[i];
    }
    for(int i=0;i<n;++i){
        tab[i].f=m1[tab[i].f];
        tab[i].s=m1[tab[i].s];
        poile[tab[i].f]++;
        poile[tab[i].s]++;
        kraw[tab[i].f].pb(tab[i].s);
        kraw[tab[i].s].pb(tab[i].f);
        //cout<<tab[i].f<<" "<<tab[i].s;
    }
    for(int i=0;i<2*n;++i){
        vector<int>::iterator it;

        sort(kraw[i].begin(),kraw[i].end());
        it=unique(kraw[i].begin(),kraw[i].end());
        kraw[i].resize(distance(kraw[i].begin(),it));
        //cout<<tab[i].f<<" "<<tab[i].s;
    }
    sort(warto.begin(),warto.end());
    vector<int>::iterator it1;
    it1=unique(warto.begin(),warto.end());
    warto.resize(distance(warto.begin(),it1));

    for(int i=0;i<warto.size();++i){
        dfs(i);//cout<<"D";
    }
    for(int i=0;i<wyny.size();++i){
        maxi=max(maxi,wyny[i]);
    }
    if(!przyps){
        printf("%d",war[maxi]);
    }else{
        printf("-1");
    }

    return 0;
}
