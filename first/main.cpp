#include <bits/stdc++.h>
#define lld long long
#define MAX 209
#define MOD 1000000009
#define mp make_pair
#define f first
#define s second


using namespace std;

lld t,n,d,temp,mini;
lld prob[MAX];
lld used[MAX];
lld cust[MAX];

int main()
{
    scanf("%lld",&t);

    for(int z=1;z<=t;++z){
        scanf("%lld",&n);
        if(n==-1){
                z=t+1;
                exit(0);
                return 0;
            }
        for(int j=0;j<n;++j){
                cust[j]=0;
                prob[j]=0;
                used[j]=0;
            }
        for(int i=0;i<n;++i){
            scanf("%lld",&d);
            if(d==-1){
                z=t+1;
                i=n;
        exit(0);
                return 0;
            }
            for(int j=0;j<d;++j){
                scanf("%lld",&temp);
                if(temp==-1){
                z=t+1;
                i=n;
                exit(0);
                return 0;
            }
                cust[temp]++;
            }
            mini=MOD;
            temp=-1;
            for(int j=0;j<n;++j){
                if(cust[j]>=1&&used[j]==0&&prob[j]<mini){
                    temp=j;
                    mini=prob[j];
                }
            }
            if(temp!=-1){
                used[temp]=1;
            }
            printf("%lld\n",temp);
            fflush(stdout);
            for(int j=0;j<n;++j){
                if(cust[j]){
                    prob[j]++;
                }
                cust[j]=0;
            }
        }
    }
    return 0;
}
