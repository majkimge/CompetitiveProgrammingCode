#include <bits/stdc++.h>
#define lld long long

using namespace std;

lld n,nn,a;
char s[12];

int main()
{
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        nn=0;
        for(int j=0;j<12;++j){
            s[j]=0;
        }
        scanf("%s",&s);
        while(s[nn]){
            nn++;
        }
        scanf("%lld",&a);
        if(a%10==7){
            for(int j=0;j<nn;++j){
                printf("%c",s[j]);
            }
            puts("");
        }
    }
    return 0;
}
