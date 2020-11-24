#include <bits/stdc++.h>
#define ld double

using namespace std;

int t,n,p,w,h;
long double maxi,mini,ile,last,maxim,minim,wyn,ilem;

int main()
{
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        scanf("%d",&n);
        scanf("%d",&p);
        wyn=0;
        ilem=0;
        for(int j=0;j<n;++j){
            scanf("%d",&w);
            scanf("%d",&h);
        }
        ile=(ld)(p-2*n*w-2*n*h);
        mini=min(w,h);
        maxi=sqrt((ld)w*w+h*h);
        minim=mini*n;
        maxim=maxi*n;
        int temp=n;
        int last=n;
        while(minim*2*temp>ile-0.0001){
            ilem++;
            last=temp;
            temp--;
        }
        if((n-ilem)*maxi*2>ile||ile<=0.0001){
            printf("Case #%d: %lf\n",i+1,(ld)p);
        }else{
            cout<<setprecision(7)<<"Case #"<<i+1<<": "<<(ld)(n-ilem)*maxi*2+2*n*w+2*n*h<<"\n";
            //printf("Case #%d: %lf\n",i+1,(ld)(n-ilem)*maxi*2+2*n*w+2*n*h);
        }

    }
    return 0;
}
