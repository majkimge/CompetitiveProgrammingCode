#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 5009

using namespace std;
typedef int16_t lld;

int n;
pair<lld,lld> tab[MAX];
//lld wart[MAX][MAX],x,y;

vector<lld> dziel[MAX];
lld wart[MAX][MAX];
vector<pair<lld,lld> > dody;
vector<pair<lld,lld> > uje;
pair<lld,lld> ter[MAX];
lld jak=1,wynik,x,y;
lld poz,pion;
int main()
{
    scanf("%d%d",&x,&y);
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&x,&y);
        tab[i]=mp(x,y);
    }
    for(int i=1;i<=5000;++i){
        for(int j=1;j*j<=i;++j){
            if(i%j==0){
                dziel[i].pb(j);
            }

        }
    }
    for(int i=0;i<n;++i){
        poz=0;
        pion=0;
        for(int j=0;j<n;++j){
            if(i!=j){
                if(tab[i].f-tab[j].f<0){
                    ter[j]=mp(-tab[i].f+tab[j].f,-tab[i].s+tab[j].s);
                }else{
                    ter[j]=mp(tab[i].f-tab[j].f,tab[i].s-tab[j].s);
                }
                if(ter[j].s>=0)wart[ter[j].f][ter[j].s]++;
            }

        }
        for(int j=0;j<n;++j){
            if(i!=j){
                if(ter[j].s>=0){
                    lld gcd=__gcd(ter[j].f,ter[j].s);
                    lld temp=0;
                    for(int z=0;z<dziel[gcd].size();++z){
                        temp+=(wart[ter[j].f/dziel[gcd][z]][ter[j].s/dziel[gcd][z]]);
                    }
                    wynik=max(wynik,temp);
                }
            }

        }
        for(int j=0;j<n;++j){
            if(i!=j){
                if(ter[j].s>=0)wart[ter[j].f][ter[j].s]=0;
            }

        }
        for(int j=0;j<n;++j){
            if(i!=j){
                if(ter[j].s<0)wart[ter[j].f][-ter[j].s]++;
            }

        }

        for(int j=0;j<n;++j){
            if(i!=j){
                if(ter[j].s<0){
                    lld gcd=__gcd(ter[j].f,(lld)-ter[j].s);
                    lld temp=0;
                    for(int z=0;z<dziel[gcd].size();++z){
                        temp+=(wart[ter[j].f/dziel[gcd][z]][-ter[j].s/dziel[gcd][z]]);
                    }
                    wynik=max(wynik,temp);
                }
            }

        }
    }
    if(wynik<3){
        printf("0");
    }else{
        printf("%d",wynik);
    }
    return 0;
}
