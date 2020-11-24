#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200009

using namespace std;

int n,tab[MAX],wyny[MAX],czy[MAX],cogdz[MAX],rep[MAX],odw[MAX];

int Find(int x){
    if(x!=rep[x])rep[x]=Find(rep[x]);
    return rep[x];
}

int Union(int x, int y){
    int rx=Find(x);
    int ry=Find(y);
    if(rx!=ry){
        rep[rx]=ry;
    }
}

vector<int> jakie[MAX];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&tab[i]);
        cogdz[tab[i]]=i;
    }
    for(int i=1;i<=n;++i){
        rep[i]=i;
        wyny[i]=tab[i];
    }
    jakie[0].pb(tab[1]);
    for(int i=1;i<=n;++i){
        jakie[i]=jakie[i/2];
        for(int j=0;j<jakie[i].size();++j){
            if(jakie[i][j]==tab[i+1]){
                swap(jakie[i][j],jakie[i][jakie[i].size()-1]);
                jakie[i].pop_back();
                break;
            }
        }
        if(i*2<=n)jakie[i].pb(tab[i*2]);
        if(i*2+1<=n)jakie[i].pb(tab[i*2+1]);

        sort(jakie[i].begin(),jakie[i].end());
        /*for(int j=0;j<jakie[i].size();++j)cout<<jakie[i][j]<<" ";
            cout<<endl;*/
        for(int j=0;j<jakie[i].size();++j){
            //cout<<"X";
            if(!odw[jakie[i][j]]){
                wyny[i]=jakie[i][j];
                odw[jakie[i][j]]=1;
                break;
            }
        }
    }
    for(int i=1;i<=n;++i){
        printf("%d ",wyny[i]);
    }
    return 0;
}
