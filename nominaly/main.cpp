#include<bits/stdc++.h>

using namespace std;

int n;
int tab[209];
int czy[200009];
int v=0;

int main(){

	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&tab[i]);
		//czy[tab[i]]=1;
	}
	czy[0]=1;
		for(int j=0;j<n;++j){
		for(int i=100000;i>=tab[j];--i){
			if(czy[max(0,i-tab[j])]){
				czy[i]=1;
			}
		}
	}
	for(int i=1;i<n*1001;++i){
		if(czy[i]==0){
			printf("%d",i);
			break;
		}
	}

}
