#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int xyz,n,m,d,x,y,a,b,c1;
bitset<128> tab[102][102];
bitset<128> wyn[102][102];
bitset<128> pom[102][102];
bitset<128> ttt[102][102];
bitset<128> tab1[102][102];
bitset<128> pom1[102][102];
int czy[102];
vector<int> v;
vector<int> v1;

void spm(int c,int dok){

    if(dok<=1){
        //return;
    }else if(dok%2==0){
        spm(c,dok/2);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                //cout<<wyn[i][c][j]<<" ";
                pom[i][c][j]=wyn[i][c][j];
                pom1[j][c][i]=wyn[i][c][j];
                wyn[i][c][j]=0;
            }
            //cout<<endl;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n+1;++j){
                    //cout<<"XD"<<i;
                    //cout<<pom[i][c]<<endl<<pom1[j][c]<<endl<<endl;
                    if((pom[i][c]&pom1[j][c]).any()){
                        //cout<<i<<" "<<j<<endl;
                        wyn[i][c][j]=1;
                       // break;
                    }


            }
        }//cout<<"DDDDDDDDDDDD"<<endl;

    }else{
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                ttt[i][c][j]=wyn[i][c][j];

            }
        }
        spm(c,dok-1);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                pom[j][c][i]=wyn[i][c][j];
                wyn[i][c][j]=0;
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){

                    if((ttt[i][c]&pom[j][c]).any()){
                        wyn[i][c][j]=1;
                        //break;
                    }


            }
        }
    }
}

int main()
{
    scanf("%d",&xyz);
    for(int xx=0;xx<xyz;++xx){
        scanf("%d",&n);
        scanf("%d",&m);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                for(int z=0;z<=100;++z){
                    tab[i][z][j]=0;
                }

            }
            }
        for(int i=0;i<m;++i){
            scanf("%d",&a);
            scanf("%d",&b);
            scanf("%d",&c1);
            tab[a][c1][b]=1;
            tab1[b][c1][a]=1;
        }
        scanf("%d",&d);
        v.clear();
        v1.clear();
        v.pb(1);
        for(int ss=0;ss<d;++ss){
            scanf("%d",&x);
            scanf("%d",&y);
            if(x>0){
                for(int i=0;i<=n;++i){
                czy[i]=0;
            }
            //if(ss==0) czy[1]=1;
            //czy[1]
            for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                wyn[i][y][j]=tab[i][y][j];
            }
            }
            spm(y,x);
            for(int i=0;i<v.size();++i){

                for(int j=1;j<=n;++j){
                    if(!czy[j]&&wyn[v[i]][y][j]){
                        v1.pb(j);
                        czy[j]=1;
                    }
                }
            }
            v.clear();
            for(int i=0;i<v1.size();++i){
                //cout<<"AAAAAA"<<v1[i]<<endl;
                v.pb(v1[i]);
            }
            v1.clear();
            }

        }
        if(v.size()>1){
            sort(v.begin(),v.end());
        }

        printf("%d\n",v.size());
        for(int i=0;i<v.size();++i){

            printf("%d ",v[i]);
        }
        printf("\n");
    }
    return 0;
}
