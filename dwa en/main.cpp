#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second

using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    if(n&1){
        printf("%d",2*n);
    }else{
        printf("%d",n);
    }
    return 0;
}
