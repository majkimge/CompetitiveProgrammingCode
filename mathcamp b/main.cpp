#include <bits/stdc++.h>

using namespace std;

int n;
double licz,mian,wyn;

int main()
{
    cin>>n;
    licz=2;
    mian=2;
    for(int i=0;i<n;++i){
        wyn+=licz/mian;
        licz+=1;
        mian*=2;
    }
    cout<<wyn;
    return 0;
}
