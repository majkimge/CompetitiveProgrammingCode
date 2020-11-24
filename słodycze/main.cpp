#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lld long long
#define MAX 100009
#define INF 2000000000
#define MOD 1000000033

using namespace std;

lld a,b,n,maxi,mmax;
char slo[101];
lld dyn[2][100009];
int main()
{
    scanf("%lld",&a);
    scanf("%lld",&b);
    scanf("%lld",&n);
    cin>>slo;
    for(int i=0;i<n;++i){
        if(slo[i]=='1'){
            b--;
        }else{
            a--;
        }

    }
    if(a<0||b<0||(a+b)%n!=0){
        printf("-1");
    }else{
        maxi=(a+b)/n;
        mmax=max(a,b)+1;
        dyn[0][0]=0;
        dyn[0][1]=1;
        for(int i=2;i<=maxi+1;++i){
            dyn[0][i]=(dyn[0][i-1]+1)%MOD;
            //cout<<dyn[0][i]<<"C";
            //dyn[1][i]=1;
        }
        for(int i=maxi+2;i<=mmax+1;++i){
            dyn[0][i]=(dyn[0][i-1])%MOD;
            //cout<<dyn[0][i]<<"C";
            //dyn[1][i]=1;
        }
//cout<<endl;
        for(int i=2;i<=n;++i){
                dyn[1][0]=0;
                dyn[1][1]=1;
            for(int j=2;j<=mmax+1;++j){
                dyn[1][j]=((dyn[0][min((lld)j,(j)*maxi+1)])%MOD-(dyn[0][min((j)*maxi+1,max(j-maxi-1,(lld)0))])%MOD+MOD)%MOD;
                //cout<<dyn[1][j]<<" ";
            }
//cout<<endl;
            for(int j=2;j<=mmax+1;++j){
                dyn[0][j]=(dyn[1][j]%MOD+dyn[0][j-1]%MOD)%MOD;
                //cout<<dyn[0][j]<<" ";
            }
            //cout<<endl;
        }
        printf("%lld",(dyn[1][mmax])%MOD);
    }
    return 0;
}
