#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define INF 100000000009
#define MOD 1000696969
#define llu unsigned long long
#define lld long long


using namespace std;

int n,f,kk=1,co=1;
int tab[MAX];
int KMR[20][MAX];
pair<pair<int,int>,int> temp[MAX];

bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    if(a.f.f<b.f.f){

    } return 1;
}

int main()
{
    scanf("%d%d",&n,&f);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
        KMR[0][i]=tab[i];
    }
    if(n>1){
        while(kk<n){
        for(int i=0;i<n;++i){
            temp[i]=mp(mp(KMR[co-1][i],KMR[co-1][(i+kk)%n]),i);
            //cout<<KMR[co-1][i]<<" ";
        }
        //cout<<endl;
        sort(temp,temp+n);
        int kt=0;
        for(int i=0;i<n;++i){
            pair<int,int> tempor=temp[i].f;
            KMR[co][temp[i].s]=kt;
            ++i;
            while(temp[i].f==tempor){
                KMR[co][temp[i].s]=kt;
                ++i;
            }
            i--;
            kt++;
        }
        kk<<=1;
        co++;
    }

    for(int i=0;i<n;++i){
        if(KMR[co-1][i]==0){
            printf("%d",i+1);
            break;
        }
    }
    }else{
        printf("1");
    }

    return 0;
}
