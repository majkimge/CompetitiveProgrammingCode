#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 100009
#define f first
#define s second
#define INF 1000000000

using namespace std;

int n;
lld tab[109];
lld wyny[1000009];
lld co[10];

int main()
{
    scanf("%d",&n);
    wyny[0]=1;
    for(int i=1;i<MAX*10;++i){
        for(int j=0;j<10;++j){
            co[j]=0;
        }
        int temp=i;
        while(temp>0){
            if(!co[temp%10]){
                wyny[i]++;
                co[temp%10]=1;
            }
            temp=temp/10;
        }
        wyny[i]+=wyny[i-1];
    }
    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
        printf("%.12lf\n",(double)wyny[tab[i]-1]/tab[i]);
    }

    return 0;
}
