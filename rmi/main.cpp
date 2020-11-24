#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 4009
#define pii pair<int,int>

using namespace std;

int n,m,a,b;
vector<int> kraw[MAX];
vector<pii> punkty[MAX];
int kol[MAX];
int odw[MAX];
int uzko[MAX];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&a,&b);
        punkty[a].pb(mp(b,i));
    }
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        kraw[a].pb(b);
        kraw[b].pb(a);
    }
    for(int i=0;i<MAX;++i){
        sort(punkty[i].begin(),punkty[i].end());
    }
    for(int i=0;i<MAX;++i){
        for(int j=0;j<punkty[i].size();++j){
            for(int k=0;k<kraw[punkty[i][j].s].size();++k){
                if(odw[kraw[punkty[i][j].s][k]]){
                    uzko[kol[kraw[punkty[i][j].s][k]]]=1;
                }
            }
            odw[punkty[i][j].s]=1;
            for(int k=1;k<=4;++k){
                if(!uzko[k]){
                    kol[punkty[i][j].s]=k;
                    break;
                }
            }
            for(int k=1;k<=4;++k){
                uzko[k]=0;
            }
        }
    }
    for(int i=1;i<=n;++i){
        printf("%d ",kol[i]);
    }
    return 0;
}
