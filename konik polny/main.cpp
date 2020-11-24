#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
using namespace std;

int n,s,a,nwd;

int main()
{
    scanf("%d%d",&n,&s);
    scanf("%d",&a);
    nwd=abs(s-a);
    for(int i=1;i<n;++i){

        scanf("%d",&a);
        nwd=__gcd(nwd,abs(s-a));
    }
    printf("%d",nwd);
    return 0;
}
