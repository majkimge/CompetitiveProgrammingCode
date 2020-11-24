#include <bits/stdc++.h>
#define lld long long

using namespace std;

lld n;
lld moz[10000];
lld sum;
lld licz;

lld rob(lld kt, lld ss){
    if(kt==n-1){
        for(lld i=1;i<=6;++i){
            moz[ss+i]++;
            sum++;
        }
    }else{
        for(lld i=1;i<=6;++i){
            rob(kt+1,ss+i);
        }
    }
}

int main()
{
    cin>>n;
    rob(0,0);
    for(lld i=1;i<=n*6;i+=2){
        licz+=i*moz[i];
    }
    //cout<<sum<<endl;
    cout<<(double)licz/sum;
    return 0;
}
