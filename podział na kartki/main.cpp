#include <bits/stdc++.h>
#define lld long long

using namespace std;

int n,a,b;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&a,&b);
        if(a%2==0||b%2==0){
            printf("A\n");
        }else{
            printf("B\n");
        }
    }

    return 0;
}
