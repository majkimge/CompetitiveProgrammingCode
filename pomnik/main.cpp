#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define piii pair<int,pair<int,int> >
#define pii pair<int,int>
#define MAX 10009
#pragma GCC optimalize ("ofast")

using namespace std;

int p,q,r,wynik,pp,qq,rr;
char inp[159][159][159];
char s[159];
char blok[159][159][159];
int wys[159][159][159];
int minimwier[159][159][159];
int minimkol[159][159][159];

void policz(){
    for(int i=0;i<p;++i){
        for(int j=0;j<q;++j){

            for(int k=0;k<r;++k){
                int mini=159;
                for(int d=k;d<r;++d){
                    mini=min(mini,wys[i][j][d]);
                    minimwier[j][k][d]=mini;
                }
            }
        }
        for(int j=0;j<r;++j){

            for(int k=0;k<q;++k){
                int mini=159;
                for(int d=k;d<q;++d){
                    mini=min(mini,wys[i][d][j]);
                    minimkol[j][k][d]=mini;
                }
            }
        }
        for(int j=0;j<q;++j){
            for(int k=0;k<r;++k){
                int mini=159;
                for(int d=0;d<=min(r-k,q-j);++d){
                    mini=min(mini,minimwier[j+d][k][k+d]);
                    mini=min(mini,minimkol[k+d][j][j+d]);
                    /*for(int e=k;e<=k+d;++e){
                        mini=min((int)wys[i][j+d][e],mini);
                    }
                    for(int e=j;e<=j+d;++e){
                        mini=min((int)wys[i][e][k+d],mini);
                    }*/
                    wynik=(int)max((int)wynik,(int)(d+1)*4*mini);
                }

            }
        }
    }
}

int main()
{
    scanf("%d%d%d",&qq,&pp,&rr);
    q=qq;
    p=pp;
    r=rr;
    for(int i=0;i<p;++i){
        for(int j=0;j<q;++j){
            scanf("%s",s);
            for(int k=0;k<r;++k){
                if(s[k]=='N'){
                    inp[i][j][k]=1;
                    blok[i][j][k]=1;
                }else{
                    inp[i][j][k]=0;
                    blok[i][j][k]=0;
                }
            }
        }
    }

    for(int i=0;i<p;++i){
        for(int j=0;j<q;++j){
            for(int k=0;k<r;++k){
                int temp=0;
                while(i+temp<p&&blok[i+temp][j][k]){
                    ++temp;
                }
                wys[i][j][k]=temp;
            }
        }
    }

    policz();

    r=pp;
    p=rr;
    for(int i=0;i<p;++i){
        for(int j=0;j<q;++j){
            for(int k=0;k<r;++k){
                 blok[i][j][k]=inp[k][j][i];
            }
        }
    }

    for(int i=0;i<p;++i){
        for(int j=0;j<q;++j){
            for(int k=0;k<r;++k){
                int temp=0;
                while(i+temp<p&&blok[i+temp][j][k]){
                    ++temp;
                }
                wys[i][j][k]=temp;
            }
        }
    }

    policz();

    p=pp;
    q=qq;
    r=rr;
    p=qq;
    q=pp;
    for(int i=0;i<p;++i){
        for(int j=0;j<q;++j){
            for(int k=0;k<r;++k){
                 blok[i][j][k]=inp[j][i][k];
            }
        }
    }

    for(int i=0;i<p;++i){
        for(int j=0;j<q;++j){
            for(int k=0;k<r;++k){
                int temp=0;
                while(i+temp<p&&blok[i+temp][j][k]){
                    ++temp;
                }
                wys[i][j][k]=temp;
            }
        }
    }

    policz();

    printf("%d",wynik);
    return 0;
}
