#include <bits/stdc++.h>
#define lld long long
#define MAX 1000009
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000

using namespace std;

int p,n,ile,c,d,ilenie,wyn;
vector<pair<int,int> >v;
pair<int,int> tab[MAX];

int main()
{
    scanf("%d",&p);
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&c);
        scanf("%d",&d);
        tab[i]=mp(c,d);
    }
    v.pb(mp(INF,p));
    ile=p;
    for(int i=0;i<n;++i){
        c=tab[i].f;
        d=tab[i].s;
        int j=ilenie;
        int iledod=0;
        while(v[v.size()-1].f>c&&v.size()>ilenie){
            iledod+=v[v.size()-1].s;
            v.pop_back();
        }
        v.push_back(mp(c,iledod+p-ile));
        int ilezab=0;
        while(ilezab<d){
            if(v[j].s<=d-ilezab){
                ilenie++;
                ilezab+=v[j].s;
                wyn+=v[j].s*v[j].f;
                v[j].s=0;
                ++j;
            }else{
                v[j].s-=(d-ilezab);
                wyn+=(d-ilezab)*v[j].f;
                ilezab=d;
            }
        }
        ile-=d;
    }
    printf("%d",wyn);
    return 0;
}
