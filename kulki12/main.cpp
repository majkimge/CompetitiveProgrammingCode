#include <bits/stdc++.h>

using namespace std;

int n;
char st[1009];

int main()
{
    scanf("%d",&n);
    long long wyn=1;
    for(int i=1;i<=n;++i){
        wyn*=i;
        wyn%=1000000009;
    }
    cout<<wyn;
    return 0;
}
