#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 200009
#define INF 1000000009

using namespace std;

lld n,wynik=1000000000000000009,mini1,maxi1,mini2,maxi2;
lld tab[MAX][2];
lld t1[MAX*2];
vector<lld> temp;

int main(){
	scanf("%lld",&n);
	for(int i=0;i<n;++i){
		scanf("%lld",&tab[i][0]);
		t1[i*2]=tab[i][0];
		scanf("%lld",&tab[i][1]);
		t1[i*2+1]=tab[i][1];
	}
	sort(t1,t1+2*n);
	if(n<2509){
		for(int i=0;i<2*n;++i){
			mini1=mini2=INF;
			maxi1=maxi2=0;
			for(int j=0;j<n;++j){
				if(abs(t1[i]-tab[j][0])<abs(t1[i]-tab[j][1])){
					mini1=min(mini1,tab[j][0]);
					maxi1=max(maxi1,tab[j][0]);
					mini2=min(mini2,tab[j][1]);
					maxi2=max(maxi2,tab[j][1]);
				}else{
					mini1=min(mini1,tab[j][1]);
					maxi1=max(maxi1,tab[j][1]);
					mini2=min(mini2,tab[j][0]);
					maxi2=max(maxi2,tab[j][0]);
				}
			}
			wynik=min(wynik,(maxi1-mini1)*(maxi2-mini2));
		}
		printf("%lld",wynik);
	}else{
		
			mini1=mini2=INF;
			maxi1=maxi2=0;
			for(int j=0;j<n;++j){
				if(abs(t1[2*n-1]-tab[j][0])<abs(t1[2*n-1]-tab[j][1])){
					mini1=min(mini1,tab[j][0]);
					maxi1=max(maxi1,tab[j][0]);
					mini2=min(mini2,tab[j][1]);
					maxi2=max(maxi2,tab[j][1]);
				}else{
					mini1=min(mini1,tab[j][1]);
					maxi1=max(maxi1,tab[j][1]);
					mini2=min(mini2,tab[j][0]);
					maxi2=max(maxi2,tab[j][0]);
				}
			}
			wynik=min(wynik,(maxi1-mini1)*(maxi2-mini2));
			
			mini1=mini2=INF;
			maxi1=maxi2=0;
			for(int j=0;j<n;++j){
				if(abs(t1[0]-tab[j][0])<abs(t1[0]-tab[j][1])){
					mini1=min(mini1,tab[j][0]);
					maxi1=max(maxi1,tab[j][0]);
					mini2=min(mini2,tab[j][1]);
					maxi2=max(maxi2,tab[j][1]);
				}else{
					mini1=min(mini1,tab[j][1]);
					maxi1=max(maxi1,tab[j][1]);
					mini2=min(mini2,tab[j][0]);
					maxi2=max(maxi2,tab[j][0]);
				}
			}
			wynik=min(wynik,(maxi1-mini1)*(maxi2-mini2));
			
			mini1=mini2=INF;
			maxi1=maxi2=0;
			for(int j=0;j<n;++j){
				if(abs(t1[n]-tab[j][0])<abs(t1[n]-tab[j][1])){
					mini1=min(mini1,tab[j][0]);
					maxi1=max(maxi1,tab[j][0]);
					mini2=min(mini2,tab[j][1]);
					maxi2=max(maxi2,tab[j][1]);
				}else{
					mini1=min(mini1,tab[j][1]);
					maxi1=max(maxi1,tab[j][1]);
					mini2=min(mini2,tab[j][0]);
					maxi2=max(maxi2,tab[j][0]);
				}
			}
			wynik=min(wynik,(maxi1-mini1)*(maxi2-mini2));
			
			mini1=mini2=INF;
			maxi1=maxi2=0;
			for(int j=0;j<n;++j){
				if(abs(t1[n-1]-tab[j][0])<abs(t1[n-1]-tab[j][1])){
					mini1=min(mini1,tab[j][0]);
					maxi1=max(maxi1,tab[j][0]);
					mini2=min(mini2,tab[j][1]);
					maxi2=max(maxi2,tab[j][1]);
				}else{
					mini1=min(mini1,tab[j][1]);
					maxi1=max(maxi1,tab[j][1]);
					mini2=min(mini2,tab[j][0]);
					maxi2=max(maxi2,tab[j][0]);
				}
			}
			wynik=min(wynik,(maxi1-mini1)*(maxi2-mini2));
			
			mini1=mini2=INF;
			maxi1=maxi2=0;
			for(int j=0;j<n;++j){
				if(abs(t1[n+1]-tab[j][0])<abs(t1[n+1]-tab[j][1])){
					mini1=min(mini1,tab[j][0]);
					maxi1=max(maxi1,tab[j][0]);
					mini2=min(mini2,tab[j][1]);
					maxi2=max(maxi2,tab[j][1]);
				}else{
					mini1=min(mini1,tab[j][1]);
					maxi1=max(maxi1,tab[j][1]);
					mini2=min(mini2,tab[j][0]);
					maxi2=max(maxi2,tab[j][0]);
				}
			}
			wynik=min(wynik,(maxi1-mini1)*(maxi2-mini2));
			
			for(int i=0;i<2*n;++i){
				int tt=t1[i];
				temp.pb(t1[i]);
				++i;
				while(t1[i]==tt){
					++i;
				}
				i--;
			}
			
			mini1=mini2=INF;
			maxi1=maxi2=0;
			for(int j=0;j<n;++j){
				if(abs(temp[temp.size()/2]-tab[j][0])<abs(temp[temp.size()/2]-tab[j][1])){
					mini1=min(mini1,tab[j][0]);
					maxi1=max(maxi1,tab[j][0]);
					mini2=min(mini2,tab[j][1]);
					maxi2=max(maxi2,tab[j][1]);
				}else{
					mini1=min(mini1,tab[j][1]);
					maxi1=max(maxi1,tab[j][1]);
					mini2=min(mini2,tab[j][0]);
					maxi2=max(maxi2,tab[j][0]);
				}
			}
			wynik=min(wynik,(maxi1-mini1)*(maxi2-mini2));
			
			mini1=mini2=INF;
			maxi1=maxi2=0;
			for(int j=0;j<n;++j){
				if(abs(temp[max((lld)0,(lld)temp.size()/2-1)]-tab[j][0])<abs(temp[max((lld)0,(lld)temp.size()/2-1)]-tab[j][1])){
					mini1=min(mini1,tab[j][0]);
					maxi1=max(maxi1,tab[j][0]);
					mini2=min(mini2,tab[j][1]);
					maxi2=max(maxi2,tab[j][1]);
				}else{
					mini1=min(mini1,tab[j][1]);
					maxi1=max(maxi1,tab[j][1]);
					mini2=min(mini2,tab[j][0]);
					maxi2=max(maxi2,tab[j][0]);
				}
			}
			wynik=min(wynik,(maxi1-mini1)*(maxi2-mini2));
			
			mini1=mini2=INF;
			maxi1=maxi2=0;
			for(int j=0;j<n;++j){
				if(abs(temp[min(temp.size()-1,temp.size()/2+1)]-tab[j][0])<abs(temp[min(temp.size()-1,temp.size()/2+1)]-tab[j][1])){
					mini1=min(mini1,tab[j][0]);
					maxi1=max(maxi1,tab[j][0]);
					mini2=min(mini2,tab[j][1]);
					maxi2=max(maxi2,tab[j][1]);
				}else{
					mini1=min(mini1,tab[j][1]);
					maxi1=max(maxi1,tab[j][1]);
					mini2=min(mini2,tab[j][0]);
					maxi2=max(maxi2,tab[j][0]);
				}
			}
			wynik=min(wynik,(maxi1-mini1)*(maxi2-mini2));
	}
	return 0;
}
