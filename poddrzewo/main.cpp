#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009
#define MOD 1000000007
#define INF 1000000000000000

using namespace std;

int n,a;
int sum;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        if(a==1)sum++;
    }
    printf("%d\n2\n1 2",max(0,2-sum));
    return 0;
}
