#include<bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 100007
#define pii pair<int,int>
#define pdd pair<double,double>
#define C 1000
#define INF 1000000000

using namespace std;


bool kwad[4009][4009][4];
int malej[4009][4009];
bool malej1[4009][4009];
int rosn[4009][4009];
int jest[4009][4009];
lld wynik;
int prefdodod[4009][4009];
int n,a,b,c;
char co[1];
pair<pii,int> sr[200009];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%s",co);
        scanf("%d%d%d",&a,&b,&c);
        a+=2002;
        b+=2002;
        if(co[0]=='A'){
            for(int j=b+c/2;j>b-c/2;--j){
                //cout<<"A";
                jest[a-c/2+1][j]++;
                jest[a+c/2+1][j]--;
            }
        }else{
            sr[i]=mp(mp(a,b),c);
            malej[a-c/2+1][b]++;
            rosn[a-c/2+1][b+1]++;
            rosn[a+1][b+c/2+1]--;
            malej[a+1][b-c/2]--;
            for(int j=b+c/2;j>b-c/2;--j){
                jest[a+1][j]--;
            }
        }
    }
    for(int i=1;i<4008;++i){
        for(int j=4007;j>0;--j){
            if(malej[i][j]>0)kwad[i][j][1]=1;
            if(rosn[i][j]>0)kwad[i][j][0]=1;
            jest[i+1][j]+=jest[i][j]+malej[i][j]+rosn[i][j];
            malej[i+1][j-1]+=malej[i][j];

            rosn[i+1][j+1]+=rosn[i][j];
            if(jest[i][j]>0){
                kwad[i][j][0]=1;
                kwad[i][j][1]=1;
                kwad[i][j][2]=1;
                kwad[i][j][3]=1;
            }
            malej[i][j]=0;
            jest[i][j]=0;
            rosn[i][j]=0;
        }
    }
    for(int i=0;i<n;++i){
        if(sr[i].s>0){
            //cout<<"A";
            //sr[i]=mp(mp(a,b),c);
            a=sr[i].f.f;
            b=sr[i].f.s;
            c=sr[i].s;
            //cout<<a+c/2;
            malej[a+c/2][b]++;
            rosn[a+c/2][b+1]++;
            rosn[a][b+c/2+1]--;
            malej[a][b-c/2]--;
            for(int j=b+c/2;j>b-c/2;--j){
                jest[a][j]--;
            }
        }
    }
    //cout<<malej[2004][2002];
    for(int i=4005;i>0;--i){
        for(int j=4007;j>0;--j){
            if(malej[i][j]>0){
                kwad[i][j][2]=1;
                //cout<<i<<" "<<j;
            }
            if(rosn[i][j]>0)kwad[i][j][3]=1;
            jest[i-1][j]+=jest[i][j]+malej[i][j]+rosn[i][j];
            malej[i-1][j-1]+=malej[i][j];

            rosn[i-1][j+1]+=rosn[i][j];
            if(jest[i][j]>0){
                kwad[i][j][0]=1;
                kwad[i][j][1]=1;
                kwad[i][j][2]=1;
                kwad[i][j][3]=1;
            }
            malej[i][j]=0;
            jest[i][j]=0;
            rosn[i][j]=0;
        }
    }
   // cout<<kwad[2004][2002][2];
    for(int i=4005;i>0;--i){
        for(int j=4007;j>0;--j){
            int sumka=0;
            for(int z=0;z<4;++z){
                sumka+=kwad[i][j][z];
            }
            //if(sumka>0)
            if(sumka>=3){
                wynik+=4;//cout<<sumka<<" "<<i<<" "<<j<<endl;
            }else if(sumka==2){
                if((kwad[i][j][0]&&kwad[i][j][2])||(kwad[i][j][1]&&kwad[i][j][3])){
                    wynik+=4;
                }else{
                    wynik+=3;
                }
            }else if(sumka==1){
                wynik+=2;
            }
        }
    }
    printf("%.2lf",(double)wynik/4.0);
    return 0;
}
