#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 100009
#define f first
#define s second

using namespace std;

int n,d;
int tab[MAX];
vector<int> v;
int wynik[MAX];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    wynik[tab[0]]=0;
    v.pb(MAX);
    d=1;
    for(int i=1;i<n;++i){
        while(tab[i]>v[v.size()-1]){
            v.pop_back();
        }
        if(v.size()==1){
            wynik[tab[i]]=tab[0];
        }else{
            wynik[tab[i]]=v[v.size()-1];
        }
        v.pb(tab[i]);
        d=max(d,(int)v.size());
    }
    printf("%d\n",d);
    for(int i=1;i<=n;++i){
        printf("%d ",wynik[i]);
    }
    return 0;
}
