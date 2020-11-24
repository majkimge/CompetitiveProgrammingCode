#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 2000009

using namespace std;

lld a,k,ilep,sumix;
lld pier[MAX/10];
int sito[MAX*2];
lld ost[MAX];
pair<lld,lld> czyn[MAX][16];

int main()
{
    scanf("%lld%lld",&a,&k);
    if(a==1) a=2;
    for(lld i=2;i<=MAX;++i){
            //cout<<"F";
        if(!sito[i]){
            pier[ilep]=i;
            ilep++;
            for(lld j=i*i;j<=MAX;j=j+i){
                sito[j]=1;
            }
        }
    }
    for(int i=a;i<=a+k;++i){
        ost[i-a]=i;
    }
    for(lld i=0;i<ilep;++i){
        for(lld j=(a-1)/pier[i]*pier[i]+pier[i];j<=a+k;j+=pier[i]){
            lld temp=j;
            lld dod=0;
            while(temp%pier[i]==0){
                dod++;
                temp/=pier[i];
                ost[j-a]/=pier[i];
            }
            czyn[j-a][0].f++;
            czyn[j-a][0].s+=dod;
            czyn[j-a][czyn[j-a][0].f]=mp(pier[i],dod);
        }
    }
    int done=0;
    for(lld j=a;j<=a+k;j++){
            sumix+=czyn[j-a][0].s;

            if(done){
                break;
            }
            if(sumix>=k){
                sumix-=czyn[j-a][0].s;
                for(int i=1;i<=czyn[j-a][0].f;++i){

                    sumix+=czyn[j-a][i].s;
                    //cout<<sumix<<endl;
                    if(sumix>=k){
                        printf("%lld ",czyn[j-a][i].f);
                        done=1;
                        break;
                    }
                }
            }
            if(done) break;
            sumix+=(ost[j-a]!=1);
            if(sumix>=k){
                printf("%lld ",ost[j-a]);
                done=1;
                break;
            }
    }
    return 0;
}
