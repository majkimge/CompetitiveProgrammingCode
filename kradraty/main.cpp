#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 10000009

using namespace std;

lld kwad[MAX];
vector<lld> pier;
lld czyp[MAX],coto[MAX],n,m;
lld czykw[MAX],ktor=2;
int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=2;i<n;++i){

        if(!czyp[i]){
            pier.pb(i);
        }
        for(int j=i*i;j<n;j+=i){
            czyp[j]=1;
        }
    }

    for(int i=0;i<=n;++i){
        kwad[i]=i*i;
        czykw[i*i]=1;
        coto[i*i]=i;
    }
    for(lld i=1;i<n;++i){
        for(lld j=i+1;j<n;++j){
            for(lld z=1;z<n;++z){
                if(z!=j&&z!=i&&czykw[kwad[i]+kwad[z]]&&czykw[kwad[j]+kwad[z]]){
                    printf("%lld || %lld => %lld",i,j,z);
                    cout<<endl;
                    break;
                }
            }

        }
        /*
        //if(pier[i]%4==1){
            lld cot=kwad[i];//cout<<"XXX"<<pier[i];
             printf("%lld || ",i);
            for(int j=1;j<=m;++j){
                for(int z=i+1;z<n;++z){
                    if(czykw[cot+kwad[z]]){
                        printf("%lld || ",z);
                        cot+=kwad[z];
                        break;
                    }
                }
            }
            cout<<endl;
        /*printf("%lld  ",cot);
        int sum=0;
            for(lld j=0;j*j<cot;++j){
                if(czykw[cot-kwad[j]]){
                    sum++;
                    printf("%lld %lld || ",j,coto[cot-kwad[j]]);
                }
            }
            cout<<endl;
        //}
        */

    }
    return 0;
}
