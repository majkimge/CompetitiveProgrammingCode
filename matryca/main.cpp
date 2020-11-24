#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009
#define MOD 1000000007
#define INF 1000696969

using namespace std;

int n;
char s[MAX];
char last;
int gdzl;
int mini=MAX;
vector<int> wyst;


int main()
{
    //scanf("%d",&n);
    scanf("%s",s);
    while(s[n])++n;
    for(int i=0;i<n;++i){
        if(s[i]!='*'){
            gdzl=i;
            break;
        }
    }
    for(int i=gdzl+1;i<n;++i){
        if(s[i]!='*'&&s[i]!=s[gdzl]){
            mini=min(mini,i-gdzl);
            //gdzl=i;
        }
        if(s[i]!='*'){
            gdzl=i;
        }
    }
    if(mini==MAX){
        printf("1");
        return 0;
    }
    printf("%d",n-mini+1);
    return 0;
}
//*A***B**C*
