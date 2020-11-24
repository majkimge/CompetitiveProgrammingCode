#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200009
#define MOD 1000000007

using namespace std;

vector<short>plec[100009];
pair<int,int> part[309];
int n,sum;

vector<int> wyn;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&part[i].f);
        part[i].s=i;
        sum+=part[i].f;
    }
    sort(part+1,part+n+1);
    reverse(part+1,part+n+1);
    plec[0].pb(-1);
    for(int i=1;i<=n;++i){
        for(int j=part[i].f+sum/2;j>=part[i].f;--j){
            if(!plec[j-part[i].f].empty()){
                plec[j]=plec[j-part[i].f];
                plec[j].pb(part[i].s);
            }
        }
    }
    for(int i=sum;i>=0;i--){
        if(!plec[i].empty()){
               // cout<<i;
             printf("%d\n",plec[i].size()-1);
             for(int j=1;j<plec[i].size();++j){
                 printf("%d ",plec[i][j]);
             }
             return 0;
        }
    }

    return 0;
}
