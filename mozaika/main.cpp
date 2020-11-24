#include <bits/stdc++.h>

#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
using namespace std;

lld t, n, x, y, wi, ko, ilewier=1, ilekol=1;
pair<lld, lld> punkty[6000];
lld wiersze[6000];
lld kolumny[6000];
vector<lld> wyniki;
vector<vector<pair<lld,lld> > > wier;
vector<vector<pair<lld,lld> > > kol;

bool compares(const pair<lld, lld>&i, const pair<lld, lld>&j)
{
    return i.s < j.s;
}

bool comparef(const pair<lld, lld>&i, const pair<lld, lld>&j)
{
    return i.first < j.first;
}

int main()
{
    scanf("%lld",&t);
    for(int i=0;i<t;++i){
        scanf("%lld",&n);
        for(int j=0;j<n;++j){
            scanf("%lld",&x);
            scanf("%lld",&y);
            punkty[j]=mp(x,y);
        }
        sort(punkty,punkty+n,comparef);
        sort(punkty,punkty+n,compares);

        wi=0;
        vector<pair< lld,lld> > temp;
        for(int k=0;k<n;++k){
            if(k==0){
                wi=punkty[k].s;
            }
            if(punkty[k].s>wi){
                wier.pb(temp);
                temp.clear();
                wiersze[ilewier]=punkty[k].s;
                ilewier++;

            }else{
                temp.pb(punkty[k]);
            }
        }
        sort(punkty,punkty+n,comparef);
        ko=0;
        temp.clear();
        for(int k=0;k<n;++k){
            if(k==0){
                ko=punkty[k].f;
            }
            if(punkty[k].f>ko){
                kol.pb(temp);
                temp.clear();
                kolumny[ilekol]=punkty[k].f;
                ilewkol++;

            }else{
                temp.pb(punkty[k]);
            }
        }
        for()

    }
    return 0;
}
