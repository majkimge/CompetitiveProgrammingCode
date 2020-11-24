#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define INF 1000000000

using namespace std;

int n,k;
char sl[109];
int dp[109][109][109];
vector<int> v;

int main()
{
    scanf("%d%d",&n,&k);
	scanf("%s",sl);
	for(int i=0;i<n;++i){
		if(sl[i]=='0'){
			v.pb(i);
		}
	}
	for(int i=2;i<=n;++i){
        dp[1][v[0]][i]=1;
	}
	for(int i=1;i<v.size();++i){
        for(int j=1;j<v.size();++j){
            for(int z=1;z<v.size();++z){
                for(int kk=v[j]-k;kk<=v[j]+k;++kk){
                    dp[i][v[j]][v[z]]+=dp[i-1][kk][]
                }

            }
        }
	}
    return 0;
}
