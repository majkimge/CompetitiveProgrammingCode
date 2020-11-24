#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1009

using namespace std;

double v,s,h,komh,dod;
double dlug[MAX];
double wys[MAX];
double gest[MAX];
int n;

int main()
{
    scanf("%lf",&s);
    scanf("%lf",&h);
    scanf("%lf",&v);
    komh=v/s;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lf",&dlug[i]);
        scanf("%lf",&gest[i]);
        if(gest[i]>=(double)1){
            wys[i]=0;
            dod=dlug[i]*dlug[i]*dlug[i]/s;
        }else{
            wys[i]=dlug[i]-gest[i]*dlug[i]+komh;
            dod=dlug[i]*dlug[i]*dlug[i]*gest[i]/s;
        }
        komh+=dod;
        for(int j=0;j<=i;++j){
            wys[i]+=dod;
        }
    }
    for(int i=0;i<n;++i){
        if(wys[i]>h){
            komh+=(wys[i]-h)*dlug[i]*dlug[i]/s;
        }
    }
    printf("%.4lf",min(h,komh));
    return 0;
}
