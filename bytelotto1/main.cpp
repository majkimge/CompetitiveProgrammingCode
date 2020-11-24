#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define s second
#define f first
#define MAX 10009
#define INF 1000000000
#define pb push_back
#define pii pair<int,int>

using namespace std;

int n,l,m,k,kt;
vector<int> skal;
map<int,int> ma;
int tab[MAX];
pii zapy[109];
int wyny[MAX][109];
vector<int> wyst[MAX];
//vector<int> odl[MAX];
int odtab[MAX];
int odp[MAX];
int lastl[MAX];
int pierl[MAX];

int akt(int p){
    for(int i=0;i<l;++i){
        while(lastl[p+i]<wyst[tab[p+i]].size()-1&&wyst[tab[p+i]][lastl[p+i]+1]<=n-l+i){

            lastl
        }
    }
}

int main()
{
    scanf("%d%d",&n,&l);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
        skal.pb(tab[i]);
    }
    sort(skal.begin(),skal.end());
    for(int i=0;i<skal.size();++i){
        ma[skal[i]]=kt;
        while(i!=skal.size()-1&&skal[i]==skal[i+1]){
            ++i;
        }
        ++kt;
    }
    for(int i=0;i<n;++i){
        tab[i]=ma[tab[i]];
        wyst[tab[i]].pb(i);
    }
    return 0;
}
