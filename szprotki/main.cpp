#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 300009

using namespace std;

int n,q;
lld tab[MAX],a,b,c;
lld pref[MAX];

vector<pair<lld,lld> >v;



int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%lld",&tab[i]);
    }
    sort(tab,tab+n);
    scanf("%d",&q);
    for(int i=1;i<=n;++i){
        pref[i]=pref[i-1]+tab[i];
    }


    return 0;
}
