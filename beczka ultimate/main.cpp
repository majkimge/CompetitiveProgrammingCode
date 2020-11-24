#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1009

using namespace std;

double v,s,h,komh,dodw;
double dlug[MAX];
double gest[MAX];
int czyj[MAX];
int n;


int check(double wys){
    double obj=0;
    for(int i=0;i<n;++i){
        obj+=dlug[i]*dlug[i]*max(wys-(h-dlug[i]),min(wys,dlug[i]*min(1.0000000,gest[i])));
    }
    if((obj+v)/s>wys) return 1;
    return 0;
}

double bin(double l, double p){
    double ss=(l+p)/2.00;
    double wyn=0.0;
    for(int i=0;i<400;++i){
        ss=(l+p)/2.00;
        if(check(ss)){
            l=ss;
        }else{
            p=ss;
        }
    }
    return ss;
}

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
    }
    printf("%.14lf",min(h,bin(0.00,h)));
    return 0;
}
