#include <bits/stdc++.h>
#define lld unsigned int
#define MAX 2009
#define MOD 1000000007
#define mp make_pair
#define f first
#define s second

using namespace std;

lld m,d,wyn;
string a;
string b;
lld dyn[MAX][MAX][3];
lld dp1[MAX][MAX][3];

int main()
{
    scanf("%u",&m);
    scanf("%u",&d);
    cin>>a;
    cin>>b;


    for(int i=1;i<10;++i){
        if(i!=d){
            if(a[0]-48>i){
                dyn[1][i%m][0]++;
            }else if(a[0]-48<i){
                dyn[1][i%m][2]++;
            }else{
                dyn[1][i%m][1]++;
            }
        }
    }
    for(int i=1;i<10;++i){
        if(i!=d){
            if(b[0]-48>i){
                dp1[1][i%m][0]++;
            }else if(b[0]-48<i){
                dp1[1][i%m][2]++;
            }else{
                dp1[1][i%m][1]++;
            }
        }
        //cout<<dp1[1][0][2];
    }
    for(int i=2;i<=a.length();++i){
        for(int j=0;j<m;++j){
            for(int z=0;z<=9;++z){
                if((i%2==0&&z==d)||(i%2==1&&z!=d)){
                dyn[i][(j*10+(z))%m][0]+=dyn[i-1][j][0];
                dyn[i][(j*10+(z))%m][0]%=MOD;
            if(z==a[i-1]-48){
                dyn[i][(j*10+(z))%m][1]+=dyn[i-1][j][1];
                dyn[i][(j*10+(z))%m][1]%=MOD;
            }else if(z>a[i-1]-48){
                dyn[i][(j*10+(z))%m][2]+=dyn[i-1][j][1];
                dyn[i][(j*10+(z))%m][2]%=MOD;
            }else{
                dyn[i][(j*10+(z))%m][0]+=dyn[i-1][j][1];
                dyn[i][(j*10+(z))%m][0]%=MOD;
            }
                dyn[i][(j*10+(z))%m][2]+=dyn[i-1][j][2];
                dyn[i][(j*10+(z))%m][2]%=MOD;
            }
            }

        }
    }

    for(int i=2;i<=b.length();++i){
        for(int j=0;j<m;++j){
            for(int z=0;z<=9;++z){
                if((i%2==0&&z==d)||(i%2==1&&z!=d)){
                dp1[i][(j*10+(z))%m][0]+=dp1[i-1][j][0];
                dp1[i][(j*10+(z))%m][0]%=MOD;
            if(z==b[i-1]-48){
                dp1[i][(j*10+(z))%m][1]+=dp1[i-1][j][1];
                dp1[i][(j*10+(z))%m][1]%=MOD;
            }else if(z>b[i-1]-48){
                dp1[i][(j*10+(z))%m][2]+=dp1[i-1][j][1];
                dp1[i][(j*10+(z))%m][2]%=MOD;
            }else{
                dp1[i][(j*10+(z))%m][0]+=dp1[i-1][j][1];
                dp1[i][(j*10+(z))%m][0]%=MOD;
            }
                dp1[i][(j*10+(z))%m][2]+=dp1[i-1][j][2];
                dp1[i][(j*10+(z))%m][2]%=MOD;
            }
            }

        }
    }
    for(int i=1;i<b.length();++i){
        wyn+=dp1[i][0][1]%MOD;
        wyn%=MOD;
        wyn+=dp1[i][0][2]%MOD;
        wyn%=MOD;
        wyn+=dp1[i][0][0]%MOD;
        wyn%=MOD;
    }
    wyn+=dp1[b.length()][0][1]%MOD+dp1[b.length()][0][0]%MOD;
    wyn%=MOD;
    for(int i=1;i<a.length();++i){
        wyn-=dyn[i][0][1]%MOD;
        wyn+=MOD;
        wyn%=MOD;
        wyn-=dyn[i][0][2]%MOD;
        wyn+=MOD;
        wyn%=MOD;
        wyn-=dyn[i][0][0]%MOD;
        wyn+=MOD;
        wyn%=MOD;
    }

    //cout<<dp1[b.length()][0][1]+dp1[b.length()][0][2]<<dyn[a.length()][0][0];
    printf("%u",(wyn-dyn[a.length()][0][0]+MOD)%MOD);

    return 0;
}
