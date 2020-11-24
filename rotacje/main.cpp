#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define pii pair<int,int>
#define MOD 1000000007
using namespace std;

int tab[MAX][3];
int czyk[MAX];

int dp,dl,n,przyps,ddp,ddl;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<3;++i){
        for(int j=0;j<n;++j){
            scanf("%d",&tab[j][i]);
            tab[j][i]--;
        }
    }
    for(int i=0;i<n;++i){
        if(tab[i][0]/3!=tab[i][1]/3||tab[i][0]/3!=tab[i][2]/3||abs(i-tab[i][0]/3)%2){
            przyps=1;
        }
    }
    if(przyps){
        printf("NIE");
        return 0;
    }
    for(int i=0;i<n;++i){
        czyk[i]=((tab[i][0]>tab[i][2])+abs(i-tab[i][0]/3)/2)%2;
        if(i%2==0){
            dp+=abs(i-tab[i][0]/3)/2;
            ddp+=czyk[i];
        }else{
            dl+=abs(i-tab[i][0]/3)/2;
            ddl+=czyk[i];
        }
    }
    dp>>=1;
    dl>>=1;
    //cout<<dp;
    if(dl%2!=ddp%2||ddl%2!=dp%2){
        printf("NIE");
    }else{
        printf("TAK");
    }
    return 0;
}
