#include <bits/stdc++.h>
#define MAX 100009
#define pb push_back

using namespace std;

int kraw[MAX];
int odl[MAX];
int ost[MAX];

int temp,n,m,co,a,b,gd,os,od,pier;

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    pier=316;
    for(int i=1;i<=n;++i){
        scanf("%d",&temp);
        if(temp+i<=n){
            kraw[i]=temp+i;
        }else{
            kraw[i]=n+1;
        }

    }
    for(int i=n;i>=1;--i){

        if(kraw[i]<=i/pier*pier+1){
            ost[i]=ost[kraw[i]];
            odl[i]=odl[kraw[i]]+1;
        }else{
            ost[i]=i;
            odl[i]=1;
        }

    }

    for(int i=n;i>=1;--i){

        if(kraw[i]<=(i/pier+1)*pier){
            ost[i]=ost[kraw[i]];
            odl[i]=odl[kraw[i]]+1;
        }else{
            ost[i]=i;
            odl[i]=1;
        }

    }
    for(int i=n;i>0;i--){
                if(kraw[i]<=(i/pier)*pier){
            ost[i]=ost[kraw[i]];
            odl[i]=odl[kraw[i]]+1;
        }else{
            ost[i]=i;
            odl[i]=1;
        }
        //cout<<ost[i]<<odl[i]<<endl;
    }

    for(int j=1;j<=m;++j){
        scanf("%lld",&co);
        if(co==0){
            scanf("%lld",&a);
            scanf("%lld",&b);
            kraw[a]=b+a;
            for(int i=(a/pier)*pier;i>max(0,(a/pier-1)*pier);i--){
                if(kraw[i]<=(i/pier)*pier){
            ost[i]=ost[kraw[i]];
            odl[i]=odl[kraw[i]]+1;
        }else{
            ost[i]=i;
            odl[i]=1;
        }
            }

        }else{
            scanf("%d",&a);
            temp=a;
            os=ost[a];
            od=odl[a];
            while(kraw[temp]!=n+1){
                od+=odl[kraw[temp]];
                os=ost[kraw[temp]];
                temp=kraw[temp];
            }
            printf("%d ",os);
            printf("%d\n",od);
        }
    }
    return 0;
}

