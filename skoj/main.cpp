#include <bits/stdc++.h>
#define lld long long
#define MAX 300009
#define DOD 100001
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

lld odw[MAX];
pair<lld,lld> krawy[200009];
vector<lld> v[MAX];
lld partner[MAX];
lld wsk,wyn=1,n,m,a,b;


bool skoj(int x)
{
    odw[x]=wsk;
    for (int i=0; i<(int)v[x].size(); i++)
    {
        if(odw[v[x][i]]!=wsk&&partner[v[x][i]]==0)
        {
            partner[v[x][i]]=x;
            partner[x]=v[x][i];
            return true;
        }
    }
    for (int i=0; i<(int)v[x].size(); i++)
    {
        if (odw[partner[v[x][i]]]!=wsk && skoj(partner[v[x][i]]))
        {
            partner[v[x][i]]=x;
            partner[x]=v[x][i];
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%lld%lld",&a,&b);
        krawy[i]=mp(a,b);
        v[a].pb(i+DOD);
        v[b].pb(i+DOD);
        v[i+DOD].pb(a);
        v[i+DOD].pb(b);
    }
    for(int i=1;i<=n;++i){
            wsk++;
        //cout<<skoj(i);
        if(skoj(i)==0){
            wyn=0;
        }


    }
    if(wyn){
        printf("TAK\n");
        for(int i=1;i<=n;++i){
            if(krawy[partner[i]-DOD].f==i){
                printf("%lld\n",krawy[partner[i]-DOD].s);
            }else{
                printf("%lld\n",krawy[partner[i]-DOD].f);
            }

        }
    }else{
        printf("NIE\n");
    }
    return 0;
}
