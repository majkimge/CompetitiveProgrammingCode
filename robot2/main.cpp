#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 300009
#define f first
#define s second
#define INF 1000000000

using namespace std;

int n,pio,co,x,y;
int tab[MAX];
int ilepoz[MAX];
int ilepion[MAX];
int iletpoz[MAX];
int iletpion[MAX];
int dpoz[MAX];
int dpion[MAX];
vector<int> pion;
vector<int> poz;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
        //ile[tab[i]]++;
    }
    int kt=0;
    while(kt<n&&tab[kt]==0){
        pio++;
        kt++;
    }
    for(int i=kt;i<n;++i){
        if(tab[i]){
            co=co^1;
        }else{
            int ile=0;
            while(i<n&&tab[i]==0){
                ile++;
                i++;
            }
            i--;
            if(co==1){
                poz.pb(ile);
            }else{
                pion.pb(ile);
            }
        }
    }
    int poczpoz=0;
    int poczpion=0;
    for(int i=0;i<poz.size();++i){
        ilepoz[poz[i]*2]++;
        poczpoz+=poz[i];
    }
    for(int i=0;i<pion.size();++i){
        ilepion[pion[i]*2]++;
        poczpion+=pion[i];
    }
    for(int i=0;i<=n;++i){
        iletpoz[i]=INF;
        iletpion[i]=INF;
    }
    //cout<<ilepion[4];
    iletpoz[0]=0;
    iletpion[0]=0;
    dpoz[0]=1;
    dpion[0]=1;
    for(int i=0;i<MAX;++i){
        if(ilepoz[i]>0){
            for(int j=0;j<MAX;++j){
                if(dpoz[j]){
                    iletpoz[j]=0;
                }else{
                    iletpoz[j]=INF;
                }
            }
            for(int z=i;z<MAX;z++){
                iletpoz[z]=min(iletpoz[z],iletpoz[z-i]+1);
            }
            for(int z=i;z<MAX;z++){
                if(iletpoz[z]<=ilepoz[i]){
                    dpoz[z]=1;
                }
            }
        }
    }
    for(int i=0;i<MAX;++i){
        if(ilepion[i]>0){
            for(int j=0;j<MAX;++j){
                if(dpion[j]){
                    iletpion[j]=0;
                }else{
                    iletpion[j]=INF;
                }
            }
            for(int z=i;z<MAX;z++){
                iletpion[z]=min(iletpion[z],iletpion[z-i]+1);
            }
            for(int z=i;z<MAX;z++){
                if(iletpion[z]<=ilepion[i]){
                    dpion[z]=1;
                }
            }
        }
    }
    scanf("%d",&x);
    scanf("%d",&y);
    if(dpoz[x+poczpoz]&&dpion[y+poczpion-pio]){
        printf("TAK");
    }else{
        printf("NIE");
    }
    return 0;
}
