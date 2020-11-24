#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 10000009
#define INF 1000000009

using namespace std;

int n;
int sito[MAX];
int tab[109];
vector<int> pier;
vector<int> blok;
int wyny[209];
int sumy[209];

void ustaw(int od, int co){
    if(!sito[co]&&co!=1&&co!=2){
        wyny[od]=1;
    }else if(co%2==0){
        wyny[od]=2;
    }else{
        wyny[od]=3;
    }
}

int daj(int co){
    if(!sito[co]&&co!=1){
        return 1;
    }else if(co%2==0){
        return 2;
    }else{
        return 3;
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    for(int i=2;i*i<MAX;++i){
        if(!sito[i]){
            //pier.pb(i);
            for(int j=i*i;j<MAX;j+=i){
                sito[j]=1;
            }
        }
    }
    for(int i=2;i<MAX-8;++i){
        if(!sito[i]){
            pier.pb(i);
        }
    }
    //cout<<pier.size();
    blok.pb(0);
    blok.pb(0);
    for(int i=0;i<n;++i){
        int wl=1;
        ++i;
        while(tab[i]==tab[i-1]+1){
            wl++;
            ++i;
        }
        blok.pb(wl);
        if(i!=n)blok.pb(tab[i]-tab[i-1]-1);

        i--;

    }
    ustaw(2,blok[2]);
    //cout<<wyny[0];
    //sumy[0]=blok[0];
    /*
	cout<<sito[89999];
    for(int i=3;i<=blok.size();++i){
        sumy[i]=sumy[i-1]+blok[i-1];
    }
    for(int i=0;i<blok.size();++i){
    	cout<<blok[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<blok.size();++i){
    	cout<<sumy[i]<<" ";
	}
	*/
    for(int i=4;i<blok.size();i+=2){
        int wyn=wyny[i-2]+daj(blok[i]);

        int dod=0;
        for(int j=i-4;j>=0;j-=2){
            wyn=min(wyn,wyny[j]+daj(blok[j+3])+dod+daj(sumy[i+1]-sumy[j+2]));
            dod+=daj(blok[j+3]);
        }
        wyny[i]=wyn;
    }
    printf("%d",wyny[blok.size()-1]);
    return 0;
}
/*
10
1 2 3 5 6 7 8 9 10000 100000
*/
