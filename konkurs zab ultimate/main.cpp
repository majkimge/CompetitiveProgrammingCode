#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000007

using namespace std;

lld n,k,pier=INF,ost,sum,sum1,it,zl,wynik;
char s[109];
lld dp[50000][2];
lld pio[10];
lld tab[109];
lld roz[10];
lld troz[10];
int main()
{
    scanf("%lld%lld",&n,&k);
    scanf("%s",s);
    for(int i=0;i<n;++i){
        if(s[i]=='0'){
            pier=min(pier,(lld)i);
            tab[i]=0;
            sum++;
        }else{
            tab[i]=1;
        }
    }
    for(int i=0;i<n;++i){
        if(tab[i]==0){
            sum1++;
            if(sum1==sum){
                ost=i;
                break;
            }
        }
    }
    if(sum<=2){
        if(ost-pier<=k){
            printf("1");
        }else{
            printf("0");
        }
    }else{
        //cout<<pier<<ost;
        k++;
        pio[0]=1;
        for(int i=1;i<8;++i){
            pio[i]=k*pio[i-1];
            pio[i]%=INF;
        }

        sum1=1;//cout<<"A";
        for(int i=pier+1;i<=ost;++i){
            if(tab[i]==0){
                if(i-pier>k-1){
                    zl=1;
                    //cout<<i;
                    break;
                }
                dp[(pio[k-1]*(k-1-(i-pier))+pio[(k-1-(i-pier))]*(k-1))/k*k][it]=1;
                pier=i;
                break;
            }

        }
        //cout<<dp[176][0];
        sum1=2;
        it=1;

        for(int i=pier+1;i<=ost;++i){
            if(tab[i]==0){
                if(i-pier>k-1){
                    zl=1;
                    //cout<<"X";
                    break;
                }
                for(int j=0;j<50000;j+=k){
                    dp[j][it]=0;
                }
                for(int j=0;j<50000;j+=k){

                    int twyn=dp[j][it^1];
                    if(twyn){
                        int temp=j;
                        for(int z=0;z<k;++z){

                            roz[z]=temp%k;
                            temp=temp/k;
                            //if(twyn)
                                //cout<<roz[z]<<endl;
                                //cout<<"X"<<twyn<<endl;
                                //cout<<endl;
                        }
                        /*if(twyn){
                            cout<<"X"<<twyn<<endl;
                                cout<<endl;

                        }*/
                        for(int z=0;z<k;++z){
                            roz[z]=roz[z+(i-pier-1)]-(i-pier-1);
                            roz[z]=max((lld)0,roz[z]);
                        }
                        for(int x=1;x<k;++x){
                            troz[x]=roz[x];
                        }
                        for(int x=1;x<k;++x){
                            troz[x]=max((lld)0,troz[x+1]-1);
                        }
                        for(int z=1;z<k;++z){
                            if(roz[z]){
                                int t1=troz[z-1];
                                int t2=troz[k-1];
                                troz[z-1]=k-1;
                                troz[k-1]=roz[z]-1;

                                int now=0;
                                troz[0]=0;
                                for(int x=1;x<k;++x){
                                    now+=troz[x]*pio[x];
                                }
                                if(twyn)
                                dp[now][it]+=twyn;
                                troz[z-1]=t1;
                                troz[k-1]=t2;
                                dp[now][it]%=INF;
                            }
                        }
                    }
                }

                it=(it^1);
                //cout<<dp[120][1];
                pier=i;
            }
        }
        for(int i=0;i<50000;++i){
            wynik+=dp[i][it^1];
            wynik%=INF;
        }
        if(!zl){
            printf("%lld",wynik);
        }else{
            printf("0");
        }
    }

    return 0;
}
