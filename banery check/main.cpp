#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second

#define llu unsigned long long

using namespace std;

llu wyn;
llu MAX=50000;
llu INF=100000;
int main()
{
    for(llu i=0;i<MAX;++i){
        wyn+=(INF-i)*(INF+1-i)/2-(INF-MAX)*(INF+1-MAX)/2;
    }
    printf("%llu",wyn);
    return 0;
}
//4323726905516851200
