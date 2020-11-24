#include <bits/stdc++.h>
#define lld long long
#define ld double
#define MAX 1000
#define LOG 18
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000

using namespace std;

lld n,m,ilet,wco,x,y;
lld wyn[1000][1000];

void spirala(lld x1,lld y1,lld jaka){
    lld cnt=1;
    lld ile=0;
    lld so=1;
    while(ile<=n*m){

        if(so%2==1){
            for(int i=0;i<so;++i){
                wyn[x1][y1]=min(wyn[x1][y1],cnt);
                if(x1>=500&&x1<500+m&&y1>=500&&y1<500+m){
                    ile++;
                }
                y1++;
            }
        }else{
            for(int i=0;i<so;++i){
                wyn[x1][y1]=min(wyn[x1][y1],cnt);
                if(x1>=500&&x1<500+m&&y1>=500&&y1<500+m){
                    ile++;
                }
                y1--;
            }
        }
        if(so%2==1){
            for(int i=0;i<so;++i){
                wyn[x1][y1]=min(wyn[x1][y1],cnt);
                if(x1>=500&&x1<500+m&&y1>=500&&y1<500+m){
                    ile++;
                }
                x1--;
            }
        }else{
        for(int i=0;i<so;++i){
                wyn[x1][y1]=min(wyn[x1][y1],cnt);
                if(x1>=500&&x1<500+m&&y1>=500&&y1<500+m){
                    ile++;
                }
                x1++;
            }
        }
        so++;
    }


}

void spirala1(lld x1,lld y1,lld jaka){
    lld cnt=1;
    lld ile=0;
    lld so=1;
    while(ile<n*m){
            //cout<<x1<<" "<<y1<<endl;

        if(so%2==1){
            for(int i=0;i<so;++i){
                wyn[x1][y1]=min(wyn[x1][y1],cnt);
                cnt++;
                if(x1>=500&&x1<500+m&&y1>=500&&y1<500+m){
                    ile++;
                    //cout<<"B";
                }
                y1++;
            }
        }else{
            for(int i=0;i<so;++i){
                wyn[x1][y1]=min(wyn[x1][y1],cnt);
                cnt++;
                if(x1>=500&&x1<500+m&&y1>=500&&y1<500+m){
                    ile++;
                    //cout<<"B";
                }
                y1--;
            }
        }
        if(so%2==1){
            for(int i=0;i<so;++i){
                wyn[x1][y1]=min(wyn[x1][y1],cnt);
                cnt++;
                if(x1>=500&&x1<500+m&&y1>=500&&y1<500+m){
                    ile++;
                    //cout<<"B";
                }
                x1++;
            }
        }else{
        for(int i=0;i<so;++i){
                wyn[x1][y1]=min(wyn[x1][y1],cnt);
                cnt++;
                if(x1>=500&&x1<500+m&&y1>=500&&y1<500+m){
                    ile++;
                    //cout<<"B";
                }
                x1--;
            }
        }
        so++;
    }


}


int main()
{
    scanf("%lld",&n);
    scanf("%lld",&m);
    for(int i=0;i<=50;++i){
        fill(wyn[500+i],wyn[500+i]+1000,INF);
    }

    scanf("%lld",&ilet);
    for(int i=0;i<ilet;++i){
        scanf("%lld",&x);
        scanf("%lld",&y);
        scanf("%lld",&wco);
        if(wco==0){
            spirala1(x+500-1,n-y+501-1,wco);
        }else{
            spirala(x+500-1,n-y+501-1,wco);
        }
    }
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<m;++j){
            if(j<m-1){
                printf("%lld ",wyn[j+500][i+500]);
            }else{
                printf("%lld\n",wyn[j+500][i+500]);
            }

        }
    }
    return 0;
}
