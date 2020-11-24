#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 150009
#define INF 2000000000

using namespace std;

lld n,temp,best,ktor=1,jaki,m;
pair<lld,lld> ter;
lld czy[MAX][3];
vector<pair<lld,lld> > jak;
char co;

int main()
{
    scanf("%lld",&n);
    scanf("%lld",&m);
    for(int i=0;i<m;++i){
        cin>>co;
        //cout<<co;
        if(co=='E'){
            for(int j=1;j<=n;++j){
                for(int z=1;z<=2;++z){
                    if(czy[j][z]!=0){
                        jak.pb(mp(j,z));
                    }
                }
            }
            best=0;
            for(int k=1;k<=n;++k){
            for(int z=1;z<=2;++z){
            temp=INF;
            for(int j=0;j<jak.size();++j){



                    if(czy[k][z]==0){
                        temp=min((jak[j].f-k)*(jak[j].f-k)+(jak[j].s-z)*(jak[j].s-z),temp);
                    }
                }
                if(temp==INF&&jak.size()!=0){
                    temp=0;
                }
                if(temp>best){
                    ter=mp(k,z);
                    best=temp;
                }
            }
            }
            czy[ter.f][ter.s]=ktor;
            ktor++;
            printf("%lld %lld\n",ter.f,ter.s);
            jak.clear();
        }else{
            ktor++;
            scanf("%lld",&jaki);
            for(int k=1;k<=n;++k){
            for(int z=1;z<=2;++z){
                if(jaki==czy[k][z]){
                    czy[k][z]=0;
                }
            }
            }
        }

    }
    return 0;
}
