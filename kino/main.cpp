#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 109
#define MOD 1000000007
#define INF 1000696969

using namespace std;

char s[MAX];
int n,ile;

int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;++i){
        if(s[i]=='L') ++i;
        ile++;
    }
    printf("%d",min(ile+1,n));
    return 0;
}
