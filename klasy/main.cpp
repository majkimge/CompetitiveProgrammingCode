#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 1000009
#define INF 1000000000000000
#define MOD 1000000009

using namespace std;

int poczy[5009],xx1,xx2,yy1,yy2,n;
pair<int,int> pozy[5009];
int wyny[MAX];
int kier;
int skr;
char sl[20];
int rog;

int podaj(int x,int y){
    int gl=0;
    int wyn=0;
    gl=min(min(n-y,y-1),min(n-x,x-1));
    //cout<<gl<<endl;
    /*if(rog==2){
        y=n-y+1;
    }
    if(rog==3){
        y=n-y+1;
        x=n-x+1;
    }
    if(rog==4){
        x=n-x+1;
    }*/
    if(skr==1){
        if(kier==1||kier==2){
        if(x==pozy[gl].f){
            if(kier==1){
                wyn=y-pozy[gl].s;
            }else{
                wyn=pozy[gl].s-y;
            }
        }else if(x==n-pozy[gl].f+1){
            wyn=(n-gl*2)*2-2;
            if(kier==1){
                wyn+=pozy[gl].s+(n-gl*2)-1-y;
            }else{
                wyn+=-abs(pozy[gl].s-y)+(n-gl*2)-1;
            }
        }else if(y==pozy[gl].s){
            wyn=(n-gl*2)*4-5;
            wyn-=(abs(x-pozy[gl].f)-1);
        }else{
            wyn=(n-gl*2)+(abs(x-pozy[gl].f))-1;
        }
    }else{
        if(y==pozy[gl].s){
            if(kier==3){
                wyn=x-pozy[gl].f;
            }else{
                wyn=pozy[gl].f-x;
            }
        }else if(y==n-pozy[gl].s+1){
            wyn=(n-gl*2)*2-2;
            if(kier==3){
                wyn+=pozy[gl].f+(n-gl*2)-1-x;
            }else{
                wyn+=-abs(pozy[gl].f-x)+(n-gl*2)-1;
            }
        }else if(x==pozy[gl].f){
            wyn=(n-gl*2)*4-5;
            wyn-=abs(y-pozy[gl].s)-1;
        }else{
            wyn=(n-gl*2)+abs(y-pozy[gl].s)-1;
        }
    }

    }else{
        if(kier==1||kier==2){
        if(x==pozy[gl].f){
            if(kier==1){
                wyn=y-pozy[gl].s;
            }else{
                wyn=pozy[gl].s-y;
            }
        }else if(x==1+n-pozy[gl].f){
            wyn=(n-gl*2)*2-2;
            if(kier==1){
                wyn+=pozy[gl].s+(n-gl*2)-1-y;
            }else{
                wyn+=y-pozy[gl].s+(n-gl*2)-1;
            }
        }else if(y==pozy[gl].s){
            wyn=(n-gl*2)*4-5;
            wyn-=abs(pozy[gl].f-x)-1;
        }else{
            wyn=(n-gl*2)+abs(pozy[gl].f-x)-1;
        }
    }else{
        if(y==pozy[gl].s){
            if(kier==3){
                wyn=x-pozy[gl].f;
            }else{
                wyn=pozy[gl].f-x;
            }
        }else if(y==1+n-pozy[gl].s){
            wyn=(n-gl*2)*2-2;
            if(kier==3){
                wyn+=pozy[gl].f-x+(n-gl*2)-1;
            }else{
                wyn+=-pozy[gl].f+x+(n-gl*2)-1;
            }
        }else if(x==pozy[gl].f){
            wyn=(n-gl*2)*4-5;
            wyn-=abs(y-pozy[gl].s)-1;
        }else{
            wyn=(n-gl*2)+abs(y-pozy[gl].s)-1;
        }
    }

    }

    wyn+=poczy[gl];
    return wyn;
}

int main()
{
    scanf("%d",&n);
    scanf("%s",sl);
    //cout<<sl[0];
    if(sl[0]=='P'){
        if(sl[3]=='N'){
            kier=1;
        }else{
            kier=2;
        }
    }else if(sl[0]=='W'){
        kier=3;
        //cout<<"DDDD";
    }else{
        kier=4;

    }
    scanf("%s",sl);
    if(sl[0]=='P'){
        skr=1;
    }else{
        skr=2;
    }
    //kier=1;
    poczy[0]=1;
    for(int i=1;i<(n+1)/2;++i){
        poczy[i]=poczy[i-1]+(n-(i-1)*2)*4-4;
    }
    if(skr==1){
        pozy[0]=mp(1,1);
    }else{
        pozy[0]=mp(n,1);
    }

    if((skr==1&&kier==1)||(skr==2&&kier==3)){
        pozy[0]=mp(1,1);
    }else if((skr==2&&kier==2)||(skr==1&&kier==3)){
        pozy[0]=mp(1,n);
    }else if((skr==1&&kier==2)||(skr==2&&kier==4)){
        pozy[0]=mp(n,n);
    }else{
        pozy[0]=mp(n,1);
    }
    for(int i=1;i<(n+1)/2;++i){
        if(pozy[0].f==n){
            pozy[i].f=pozy[i-1].f-1;
            rog=1;
        }else{
            pozy[i].f=pozy[i-1].f+1;
            rog=2;
        }
        if(pozy[0].s==n){
            pozy[i].s=pozy[i-1].s-1;
            rog=3;
        }else{
            pozy[i].s=pozy[i-1].s+1;
            rog=4;
        }
    }
    //cout<<kier;
    scanf("%d%d%d%d",&xx1,&xx2,&yy1,&yy2);
    for(int i=yy2;i>=yy1;--i){
        for(int j=xx1;j<=xx2;++j){
            printf("%d ",podaj(j,i));
        }
        printf("\n");
    }
    return 0;
}
/*
6 ZOLNOC L
1 6 1 6
*/
