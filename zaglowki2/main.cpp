#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 409
#define f first
#define s second

#define INF 1000000000

using namespace std;

int n,m;
char char co1[MAX][MAX];
char co;
int tab[MAX*MAX];

int main()
{
    scanf("%d%d",&n,&m);
    n1=n+2;
    m1=m+2;
    for(int i=1;i<=n;++i){
        scanf("%s",&co1[i][1]);
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            co=co1[i][j];
            if(co=='Z'){
                tab[i*m1+j]=1;

            }else{
                tab[i*m1+j]=2;
            }
        }
    }
    return 0;
}
