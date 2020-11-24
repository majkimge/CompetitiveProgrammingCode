#include <bits/stdc++.h>
#define lld unsigned int
#define MAX 1000009
#define MOD 1000000007
#define mp make_pair
#define f first
#define s second

using namespace std;

int t,d,cnt=1,sum,wyn,n;
pair<int,int> tab[39];
char c;


int main()
{
    scanf("%d",&t);
    for(int i=1;i<=t;++i){

        scanf("%d",&d);
        sum=0;
        wyn=0;
        cnt=1;
        n=0;
        c='C';//cout<<"G";
        getchar();
        for(int j=0;j<35;++j){
            tab[j]=mp(0,0);
        }
        int z=0;
        while(c=='C'||c=='S'){
            c=getchar();

            if(c=='S'){
                tab[z]=mp(1,cnt);
                sum+=cnt;
                n++;
            }else if(c=='C'){
                cnt<<=1;
                tab[z]=mp(2,0);
                n++;
            }
            z++;

        }
        lld czy=1;
        while(sum>d&&czy==1){
            czy=0;//cout<<"G";
            for(int j=n-1;j>=1;--j){
                if(tab[j].f==1&&tab[j-1].f==2){
                    tab[j-1]=mp(1,tab[j].s/2);
                    tab[j]=mp(2,0);
                    sum-=tab[j-1].s;
                    czy=1;
                    wyn++;
                    break;
                }
            }
        }
        if(sum<=d){
            printf("Case #%d: %d\n",i,wyn);
        }else{
            printf("Case #%d: IMPOSSIBLE\n",i);
        }
    }
    return 0;
}
