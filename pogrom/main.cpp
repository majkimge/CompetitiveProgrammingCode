#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define MAX 100009

using namespace std;

lld n,pot,k;

vector<lld> wyny[MAX];

int main()
{
    scanf("%lld",&n);
    pot=1;
    for(int i=1;i<=n;++i){
        if(i==pot){
            pot<<=1;
        }
        //cout<<pot-i;
        wyny[pot-i].pb(i);
    }
    for(int i=1;i<=n;++i){
        if(wyny[i].size()>0){
            k++;
        }
    }
    printf("%lld\n",k);
    for(int i=1;i<=n;++i){
            if(wyny[i].size()>0){
                printf("%lld ",wyny[i].size());
        for(int j=0;j<wyny[i].size();++j){
        printf("%lld ",wyny[i][j]);

    }
    puts("");
            }

    }
    return 0;
}
