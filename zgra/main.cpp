#include <bits/stdc++.h>
#define lld long long

using namespace std;

lld n,ile;
bool sito[10000000];

int main()
{
    scanf("%lld",&n);
    lld pier=sqrt(n);
    for(int i=2;i<pier;++i){
        if(sito[i]==0){
            for(int j=i*i;j<n;j+=i){
                sito[j]=1;
            }
        }
    }
    for(int i=2;i<n;++i){
        if(sito[i]==0){
            ile++;
        }
    }
    cout<<ile;
    return 0;
}
