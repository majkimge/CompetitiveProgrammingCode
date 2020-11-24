#include <bits/stdc++.h>
#define lld long long
#define MAX 300009

using namespace std;

lld n,k,y=1,x=1,wyn=1;
char s[MAX];

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&k);
    scanf("%s",s);
    for(int i=0;i<k;++i){
        if(s[i]=='G'){
            y--;
        }else if(s[i]=='D'){
            y++;
        }else if(s[i]=='P'){
            x++;
        }else if(s[i]=='L'){
            x--;
        }
        lld r=x+y-1;
        if(x+y-1<=n){
            if((x+y-1)%2==1){
                //cout<<r*(r+1)/2-y+1<<" ";
                wyn+=r*(r+1)/2-y+1;
            }else{
                //cout<<r*(r+1)/2-x+1<<" ";
                wyn+=r*(r+1)/2-x+1;
            }
        }else{
            if((x+y-1)%2==1){
                wyn+=n*(n+1)/2+n*(n-1)/2-(2*n-r-1)*(2*n-r)/2+(r-n-y)+1;
                //cout<<n*(n+1)/2+n*(n-1)/2-(2*n-r-1)*(2*n-r)/2+(r-n-y)+1<<" ";
            }else{
                wyn+=n*(n+1)/2+n*(n-1)/2-(2*n-r-1)*(2*n-r)/2+(r-n-x)+1;
                //cout<<n*(n+1)/2+n*(n-1)/2-(2*n-r-1)*(2*n-r)/2+(r-n-x)+1<<" ";
            }
        }
    }
    cout<<wyn;
    return 0;
}
