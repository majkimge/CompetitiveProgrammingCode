#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 5000009
#define f first
#define s second
#define INF 1000000000
#define MOD 1000696951
#define MOD1 1000000009

using namespace std;

int n,m,jakie,ile,wyn,t;
char tab[309][309];

int main()
{
    scanf("%d",&t);
    for(int a=0;a<t;++a){
        wyn=0;
        scanf("%d",&n);
        scanf("%d",&m);
    for(int i=1;i<=n;++i){
        scanf("%s",tab[i]);
    }
    printf("0\n");
    for(int i=0;i<300;++i){
        for(int j=0;j<300;++j){
            printf("#");
        }
        if(i!=n-1){
            printf("\n");
        }

    }
    }
    return 0;
}
