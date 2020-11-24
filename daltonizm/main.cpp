#include<bits/stdc++.h>
#define lld long long
#define lld1 long long
#define pb push_back
#define mp make_pair
#define MAX 200009
#define f first
#define s second

using namespace std;

int p,n;
bool czy=0;
char naw[309];
char wyn[309];
vector<int> otw;
vector<int> otwr;
vector<int> zam;
vector<int> zamr;
char lasto[2];
char lastz[2];
int co[309];

int main()
{
    scanf("%d",&p);
    if(p==1){
        scanf("%d",&n);
        for(int i=0;i<n;++i){
                czy=0;
            for(int j=0;j<=300;++j){
                naw[j]=0;
                co[j]=0;
            }
            scanf("%s",&naw);
            int dl=0;
            while(naw[dl]){
                dl++;
            }
            int xd=0;
            for(int j=0;j<dl;++j){
                if(naw[j]=='('){
                    xd+=2;
                    //otw.pb(j);
                }else{
                    zam.pb(j);
                    if(xd<2){
                        if(zam.size()<2){
                            czy=1;
                            break;
                        }else{
                            co[zam[zam.size()-1]]=1;
                            co[zam[zam.size()-2]]=2;
                            zam.pop_back();
                            zam.pop_back();
                            //xd--;
                        }
                    }else{
                        xd-=2;
                    }
                }
            }

            xd=0;
            for(int j=dl-1;j>=0;--j){
                if(naw[j]==')'){
                    xd+=2;

                    //otw.pb(j);
                }else{
                    otw.pb(j);//cout<<"G";
                    if(xd<2){
                        if(otw.size()<2){
                                //cout<<"F";
                            czy=1;
                            break;
                        }else{
                            co[otw[otw.size()-1]]=1;
                            co[otw[otw.size()-2]]=2;
                            otw.pop_back();
                            otw.pop_back();
                            //xd--;
                        }
                    }else{
                        xd-=2;
                    }
                }
            }
            if(czy){
                printf("rambutan\n");
            }else{
            for(int i=0;i<dl;++i){
                if(co[i]==0){
                    printf("G");
                }else if(co[i]==1){
                    printf("R");
                }else if(co[i]==2){
                    printf("B");
                }
            }
            printf("\n");
            }
        zam.clear();
        otw.clear();
        }
    }

    return 0;
}
