#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int n,m,a;
int czy[10];
vector<int> pier;
vector<int> wyn;

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        pier.pb(a);
    }
    for(int i=0;i<m;++i){
        scanf("%d",&a);
        czy[a]=1;
    }
    for(int i=0;i<n;++i){
        if(czy[pier[i]]){
            wyn.pb(pier[i]);
        }
    }
    for(int i=0;i<wyn.size();++i){
        printf("%d ",wyn[i]);
    }
    return 0;
}
