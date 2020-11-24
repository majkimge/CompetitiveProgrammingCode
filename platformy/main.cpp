#include <bits/stdc++.h>

#define lld long long
#define MAX 500009
using namespace std;

lld n,m;
lld in[MAX][2];
lld out[MAX][2];
bool czy=false;
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    cin>>m;
    for(int i=0;i<n;++i){
        cin>>in[i][0];
        in[in[i][0]-1][1]=i;
    }
    for(int i=0;i<n;++i){
        cin>>out[i][0];
        out[out[i][0]-1][1]=i;
    }

    for(int i=0;i<n;++i){
        if(in[i][1]-out[i][1]>m-1){
            czy=true;
        }
    }
    if(czy){
        cout<<"NIE";
    }else{
        cout<<"TAK";
    }
    return 0;
}
