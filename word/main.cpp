#include <bits/stdc++.h>
#define lld long long
#define MAX 2009
#define MOD 1000000009
#define mp make_pair
#define f first
#define s second

using namespace std;

lld t,n,l,czy;

char words[MAX][2];
char two[2];
char one;
lld used[300][300];

int main()
{
    scanf("%lld",&t);
    for(int z=1;z<=t;++z){
        scanf("%lld",&n);
        scanf("%lld",&l);
        for(int i=0;i<290;++i){
            for(int j=0;j<290;++j){
            used[i][j]=0;
        }
        }

        for(int i=0;i<n;++i){
            cin>>words[i];
            if(l==2){
                used[(int)words[i][0]][(int)words[i][1]]=1;
            }

        }
        czy=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(used[(int)words[i][0]][(int)words[j][1]]==0&&czy==0&&l==2){
                    if(l==2){
                        two[0]=words[i][0];
                        two[1]=words[j][1];
                    }
                    printf("Case #%d: %s\n",z,two);

                    czy=1;
                }
            }
        }
        if(czy==0){
            printf("Case #%d: %c\n",z,45);
        }
    }

    return 0;
}
