#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 30009
#define MOD 1000000009
#define INF 1000000000000000

using namespace std;

lld x,y,n,x2,y2;

int main()
{
    scanf("%lld",&n);
    for(lld i=0;i<2*n;++i){
        scanf("%lld%lld",&x,&y);
        x2+=x;
        y2+=y;
    }
    cout<<x2/n<<" "<<y2/n;
    return 0;
}
