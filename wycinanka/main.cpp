#include <bits/stdc++.h>
#define lld long long
#define MAX 2509

using namespace std;

lld s,d,n,x,y,wyn;

lld tab[52][52];

int main()
{
    scanf("%lld",&s);
    scanf("%lld",&d);
    scanf("%lld",&n);
    for(int i=0;i<d;++i){
        tab[i][0]=1;
    }
    for(int i=0;i<s;++i){
        tab[0][i]=1;
    }
    for(int i=0;i<n;++i){
        scanf("%lld",&x);
        scanf("%lld",&y);
        x--;
        y--;
        y=d-y-1;
        tab[x][y]=-1;
        tab[x+1][y]=1;
        tab[x+1][y+1]=1;
        tab[x][y+1]=1;
    }
    for(int i=1;i<d;++i){
        for(int j=1;j<s;++j){
            if(tab[j][i]==0){
                tab[j][i]=min(tab[j-1][i],min(tab[j][i-1],tab[j-1][i-1]))+1;
                wyn=max(wyn,tab[j][i]);
            }
            //cout<<tab[j][i];

        }
        //cout<<endl;
    }
    printf("%lld",wyn*wyn);

    return 0;
}
