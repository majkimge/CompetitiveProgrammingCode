#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define MOD 1000000007
#define INF 1000696969

using namespace std;

int n,a,b,wynik=1;
pair<int,int> tab[MAX];

set<int> s;
set<int>::iterator it;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&a,&b);
        tab[i]=mp(a,b);
    }
    sort(tab,tab+n);
    s.insert(tab[0].s);
    s.insert(INF);
    s.insert(-1);
    for(int i=1;i<n;++i){
        it=s.upper_bound(tab[i].s);
        --it;
        if((*(it))==-1){
            wynik++;
            s.insert(tab[i].s);
        }else{
            s.erase(it);
            s.insert(tab[i].s);
        }
    }
    printf("%d",wynik);
    return 0;
}
