#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 909
#define INF 1000000009

using namespace std;

int n;
int tab[MAX];
vector<pair<int,int> >bloki;
vector<pair<lld,lld> >com[2009];
int poile[901*2001];
vector<int> doz;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    sort(tab,tab+n);
    for(int i=0;i<n;++i){
        int temp=tab[i];
        int ile=1;
        ++i;
        while(tab[i]==temp){
            ile++;
            ++i;
        }
        bloki.pb(mp(temp,ile));
        i--;
    }
    for(int i=0;i<bloki.size();++i){
        int l=1;
        int p=bloki[i].s-1;
        lld suma=bloki[i].f;
        lld nai=bloki[i].s;
        com[bloki[i].f].pb(mp(bloki[i].f,bloki[i].s));
        while(l<bloki[i].s){
            nai*=p;
            nai/=(l+1);
            suma+=bloki[i].f;
            l++;
            p--;
            com[bloki[i].f].pb(mp(suma,nai));
        }
    }
    doz.pb(0);

    for(int i=0;i<bloki.size();++i){
        lld co=bloki[i].f;
        for(int j=0;j<com[co].size();++j){
            for(int z=0;z<doz.size();++z){
                if(!poile[com[co][j].f+doz[z]]){
                    doz.pb(com[co][j].f+doz[z]);
                }
                poile[com[co][j].f+doz[z]]+=poile[doz[z]]*com[co][j].s;
            }
        }
    }
    for(int i=0;i<)

    return 0;
}
