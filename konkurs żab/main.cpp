#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define INF 1000000000

using namespace std;

int n,k,kon,pier=INF,czyz,wynik,ite;
char[109] sl;
int tab[109];
vector<pair<pair<int,int>,pair<int,int> > >jakie[109];
vector<pair<pair<int,int>,pair<int,int> > >jakiew[109][109][2];
pair<int,int> ile[109][109][2];

int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",sl);
	for(int i=0;i<n;++i){
		if(sl[i]=='0'){
			pier=min(pier,i);
			kon=i;
			tab[i]=0;
		}
		if(sl[i]=='1') tab[i]=1;
	}
	for(int i=pier+1;i<=kon;++i){
		if(tab[i]==0){
			if(i-pier<=k){
				jakie[i].pb(mp(mp(pier,i),mp(1,1)));
				jakie[i].pb(mp(mp(i,pier),mp(1,1)));
				jakiew[pier][i][0].pb(mp(mp(i,pier),mp(1,1)));
				jakiew[i][pier][0].pb(mp(mp(pier,i),mp(1,1)));
				pier=i;
				ile[i][pier][0]=1;
				ile[pier][i][0]=1;
				wynik=1;
			}else{
				czyz=1;
				break;
			}

		}
	}

	for(int i=pier+1;i<=kon;++i){
		if(tab[i]==1){
			for(int j=0;j<jakie[i-1].size();++j){
				jakie[i].pb(jakie[i-1]);
			}
		}else{
		    wynik=0;

			for(int j=max(0,i-k);j<i;++j){
                for(int z=max(0,i-k);z<i;++z){
                    jakiew[j][z][ite^1].clear();
                    ile[j][z][ite^1]=0;
                }
			}
			for(int j=max(0,i-k);j<i;++j){
                for(int z=max(0,i-k);z<i;++z){
                    wynik+=ile[j][z][ite];
                    ile[j][i][ite^1]+=ile[j][z][ite];
                    ile[i][z][ite^1]+=ile[j][z][ite];
                    for(int xx=0;xx<jakiew[j][z][ite].size();++xx){
                        ile[jakiew[j][z][ite][xx].f][jakiew[j][z][ite][xx].s][ite^1]+=ile[j][z][ite];
                        for(int yy=0;yy<jakiew[j][z][ite].size();++yy){
                            if(yy!=xx){
                                jakiew[jakiew[j][z][ite][xx].f][jakiew[j][z][ite][xx].s][ite^1].pb(mp(mp(jakiew[j][z][ite][yy].f,
                                    jakiew[j][z][ite][yy].s)))
                            }

                        }
                    }
                }
			}
		}
	}
	return 0;
}
