#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 10009
#define INF 1000000009

using namespace std;

pair<int,int> tabl[MAX];
pair<int,int> tabp[MAX];
pair<int,int> rep[30][MAX];
lld wyn=1;
int mini[30][MAX];
int l,p,k,t,temp;
int ile[30];
char lewy[MAX];
char prawy[MAX];
int odw[30][MAX],shame;

pair<int,int> Find(pair<int,int> x){
    if(rep[x.f][x.s]!=x){
        rep[x.f][x.s]=Find(rep[x.f][x.s]);
    }
    return rep[x.f][x.s];
}

void Onion(pair<int,int> x, pair<int,int> y){

    pair<int,int> x1;
    pair<int,int> y1;
    if(x.f<0){
        if(y.f<0&&y.f!=x.f){
            shame=1;
        }
        if(y.f>=0){
            y1=Find(y);
            if(mini[y1.f][y1.s]<0&&mini[y1.f][y1.s]!=x.f) shame=1;
            mini[y1.f][y1.s]=x.f;
        }
    }else if(y.f<0){
        x1=Find(x);
        if(mini[x1.f][x1.s]<0&&mini[x1.f][x1.s]!=y.f) shame=1;
            mini[x1.f][x1.s]=y.f;

    }else{
        x1=Find(x);
        y1=Find(y);
        if(x1!=y1){

            mini[y1.f][y1.s]=min(mini[y1.f][y1.s],mini[x1.f][x1.s]);
            rep[x1.f][x1.s]=rep[y1.f][y1.s];
        }
    }


}


int main()
{
    scanf("%d",&t);
    for(int xd=0;xd<t;++xd){
        shame=0;
        scanf("%d",&k);
        for(int i=0;i<k;++i){
            scanf("%d",&temp);
            ile[i]=temp;
            for(int j=0;j<MAX;++j){
                rep[i][j]=mp(i,j);
                mini[i][j]=2;
                lewy[j]=0;
                prawy[j]=0;
                tabl[j]=mp(0,0);
                tabp[j]=mp(0,0);
                odw[i][j]=0;
            }
        }

        scanf("%d",&l);
        scanf("%s",lewy);
        scanf("%d",&p);
        scanf("%s",prawy);
        int kt=0;
        for(int i=0;i<l;++i){
            if(lewy[i]=='1'||lewy[i]=='0'){
                tabl[kt]=mp(-(lewy[i]-'0'+1),0);
                kt++;
            }else{
                for(int j=0;j<ile[lewy[i]-'a'];++j){
                    tabl[kt]=mp(lewy[i]-'a',j);
                    kt++;
                }
            }
        }
        int kt1=kt;
        kt=0;
        for(int i=0;i<p;++i){
            if(prawy[i]=='1'||prawy[i]=='0'){
                tabp[kt]=mp(-(prawy[i]-'0'+1),0);
                kt++;
            }else{
                for(int j=0;j<ile[prawy[i]-'a'];++j){
                    tabp[kt]=mp(prawy[i]-'a',j);
                    kt++;
                }
            }
        }

        wyn=1;
        shame=0;
        if(kt1!=kt){
            shame=1;
        }
        for(int i=0;i<kt;++i){
            Onion(tabl[i],tabp[i]);
        }
        for(int i=0;i<k;++i){
            for(int j=0;j<ile[i];++j){
                if(!odw[rep[i][j].f][rep[i][j].s]){
                    if(mini[rep[i][j].f][rep[i][j].s]>0) wyn*=mini[rep[i][j].f][rep[i][j].s];
                    if(wyn>1000000000000) cout<<"XD";
                    odw[rep[i][j].f][rep[i][j].s]=1;
                }
            }
        }
        if(shame){
            printf("0\n");
        }else{
            printf("%lld\n",wyn);
        }

    }
    return 0;
}
