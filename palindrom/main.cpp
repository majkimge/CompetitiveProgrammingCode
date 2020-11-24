#include <bits/stdc++.h>
#define lld long long
#define MAX 10009

using namespace std;

int n,k,v;
char s[MAX];
int tab[MAX][2];

int main()
{
    scanf("%d",&n);
    scanf("%d",&k);
    scanf("%s",s);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(s[i-1]==s[n-j]){
                tab[j][v^1]=tab[j-1][v]+1;
            }else{
                tab[j][v^1]=max(tab[j][v],tab[j-1][v^1]);
            }
        }
        v=v^1;
    }
    if(n-tab[n][v]<=k){
        printf("TAK");
    }else{
        printf("NIE");
    }
    return 0;
}
