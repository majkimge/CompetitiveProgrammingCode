#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define MOD 1000000009

using namespace std;

int n,a,b,c,wynik;
vector<pair<int,int> >kraw[MAX];
vector<int> sciez[MAX];
pair<int,pair<int,int> >krawy[MAX];
int zapy[MAX];
int wyny[MAX];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;++i){
        scanf("%d%d%d",&a,&b,&c);
        kraw[a].pb(mp(b,c));
        kraw[b].pb(mp(a,c));
        krawy[i]=(mp(c,mp(a,b)));
    }
    for(int i=1;i<=n;++i){
        sciez[i].pb(0);
    }
    for(int i=1;i<=n-1;++i){
        scanf("%d",&zapy[n-i]);

    }
    for(int i=1;i<=n-1;++i){
        for(int j=0;j<sciez[krawy[zapy[i]].s.f].size();++j){
            for(int z=0;z<sciez[krawy[zapy[i]].s.s].size();++z){
                if((sciez[krawy[zapy[i]].s.f][j]^sciez[krawy[zapy[i]].s.s][z]^krawy[zapy[i]].f)==0){
                    wynik++;
                }
            }
        }
        wyny[i]=wynik;
        int jj=sciez[krawy[zapy[i]].s.f].size();
        int zz=sciez[krawy[zapy[i]].s.s].size();
        for(int j=0;j<jj;++j){
            for(int z=0;z<zz;++z){
                sciez[krawy[zapy[i]].s.f].pb((sciez[krawy[zapy[i]].s.s][z]^krawy[zapy[i]].f));
                sciez[krawy[zapy[i]].s.s].pb((sciez[krawy[zapy[i]].s.f][j]^krawy[zapy[i]].f));
            }
        }
    }
    for(int i=n-1;i>=0;--i){
        printf("%d\n",wyny[i]);
    }
    return 0;
}
