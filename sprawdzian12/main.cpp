#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200009
#define DOK 10000
#define int uint_fast32_t

using namespace std;



int n,a[2009][2009],b[2009][2009],c[2009][2009],sum[2009],sum1,sum2[2009],czy;

int mult(int ii, int jj){
    int ret=0;
    for(int i=0;i<n;++i){
        ret+=a[ii][i]*b[i][jj];
    }
    return ret;
}

int32_t main()
{
    scanf("%d",&n);
    czy=1;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            //scanf("%d",&a[i][j]);
            a[i][j]=rand()%1000;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            //scanf("%d",&b[i][j]);
            b[i][j]=rand()%1000;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            //scanf("%d",&c[i][j]);
            c[i][j]=rand()%1000000000;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            sum[i]+=b[i][j];
            sum2[i]+=c[i][j];
        }
    }
    for(int i=0;i<n;++i){
        sum1=0;
        for(int j=0;j<n;++j){
            sum1+=a[i][j]*sum[j];
        }
        if(sum1!=sum2[i]){
            czy=0;
            printf("NIE");
            return 0;
        }
    }
    srand(time(0));
    for(int xd=0;xd<min((uint_fast32_t) DOK,n*n);++xd){
        int ii=rand()%n;
        int jj=rand()%n;
        if(mult(ii,jj)!=c[ii][jj]){
            czy=0;
            //printf("NIE");
            //return 0;
        }
    }
    printf("TAK");
    return 0;
}
