#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 100009
#define f first
#define s second
#define INF 1000000000

using namespace std;

lld n,a,b;

int main()
{
    scanf("%lld",&a);
    scanf("%lld",&b);
    scanf("%lld",&n);
    if(n%3==0){
        cout<<(a^b);
    }else if(n%3==1){
        cout<<a;
    }else{
        cout<<b;
    }
    return 0;
}
