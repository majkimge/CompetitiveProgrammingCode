#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 10009
#define INF 1000000009

using namespace std;

int t,n,co;
int poile[MAX];
pair<double,int> wyn;
vector<int> kraw;

int main()
{
    scanf("%d",&t);
    for(int zz=0;zz<t;++zz){
        wyn=mp(1000000,0);
        kraw.clear();
        scanf("%d",&n);
        for(int i=0;i<MAX;++i){
            poile[i]=0;
        }
        for(int i=0;i<n;++i){
            scanf("%d",&co);
            poile[co]++;
            if(poile[co]>=2){
                poile[co]=0;
                kraw.pb(co);
            }
        }
        sort(kraw.begin(),kraw.end());
        for(int i=1;i<kraw.size();++i){
            if((double)kraw[i]/kraw[i-1]<wyn.f){
                wyn.f=(double)kraw[i]/kraw[i-1];
                wyn.s=i;
            }
        }
        printf("%d %d %d %d\n",kraw[wyn.s],kraw[wyn.s],kraw[wyn.s-1],kraw[wyn.s-1]);
    }
    return 0;
}
