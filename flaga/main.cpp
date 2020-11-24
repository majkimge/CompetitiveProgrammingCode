#include<bits/stdc++.h>
#define lld long long
#define lld1 long long
#define pb push_back
#define mp make_pair
#define MAX 200009
#define f first
#define s second

using namespace std;

lld x;

int main()
{
    scanf("%lld",&x);
    for(int i=1;i<=x;++i){
        for(int j=1;j<=i;++j){
            printf("%c",'A'+i-1);
        }
        cout<<endl;
    }
    return 0;
}
