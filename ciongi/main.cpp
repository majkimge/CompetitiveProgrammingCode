#include <bits/stdc++.h>

#define lld long long
#define mp make_pair
#define f first
#define s second
#define MAX 100000
#define INF 1000000000000000

using namespace std;

pair<lld,lld> dyn[MAX][11];
lld n;
lld tab[3][MAX];
lld mindlawier=INF;
int main(){
	scanf("%lld",&n);
	for(int i=0;i<3;i++){
		for(int j=0;j<n;++j){
			scanf("%lld",&tab[i][j]);
		}
	}
	dyn[0][0]=mp(0,tab[0][0]);
	dyn[0][1]=mp(0,tab[1][0]);
	dyn[0][2]=mp(0,tab[2][0]);
	for(int i=1;i<n;++i){
        for(int j=1;j<=9;j++){
            if(mindlawier>max(dyn[i-1][(j-1)%3].f,abs(dyn[i-1][(j-1)%3].s-tab[(j-1)/3][i]))){
                mindlawier=max(dyn[i-1][(j-1)%3].f,abs(dyn[i-1][(j-1)%3].s-tab[(j-1)/3][i]));
                dyn[i][(j-1)/3]=mp(mindlawier,tab[(j-1)/3][i]);
            }
            if((j)%3==0&&j!=0){

                //cout<<mindlawier;
                mindlawier=INF;
            }

        }

	}
	printf("%lld",min(min(dyn[n-1][0].f,dyn[n-1][1].f),dyn[n-1][2].f));

	return 0;
}
