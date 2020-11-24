#include <bits/stdc++.h>
#define MAX 100009
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define pii pair<int,int>

using namespace std;

int t,n,q,x,y;
pii wynik;
int maxi;
char c[1];
pair<pii,char> pepx[MAX];
pair<pii,char> pepy[MAX];
int prefyx[MAX];
int prefyy[MAX];
int prefyx1[MAX];
int prefyy1[MAX];
int wpr[MAX];
int wle[MAX];
int wdol[MAX];
int wgor[MAX];

int main()
{
    scanf("%d",&t);
    for(int xd=1;xd<=t;++xd){
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;++i){
            scanf("%d%d",&x,&y);
            scanf("%s",c);
            if(c[0]=='N'){
                wgor[y]++;
            }else if(c[0]=='S'){
                wdol[y]++;
            }else if(c[0]=='E'){
                wpr[x]++;
            }else{
                wle[x]++;
            }

            //pepx[i]=mp(mp(x,y),c[0]);
            //pepy[i]=mp(mp(y,x),c[0]);

        }

        for(int i=1;i<=q;++i){

            prefyx[i]=prefyx[max(i-1,0)]+wpr[max(0,i-1)];
        }
        for(int i=q-1;i>=0;--i){
            prefyx1[i]+=prefyx1[i+1]+wle[i+1];
        }
        for(int i=1;i<=q;++i){
            prefyy[i]=prefyy[max(i-1,0)]+wgor[max(0,i-1)];
        }
        for(int i=q-1;i>=0;--i){
            prefyy1[i]+=prefyy1[i+1]+wdol[i+1];
        }
        //cout<<prefyy[5];
        int maxx=0;
        int maxy=0;
        int gdzx=0;
        int gdzy=0;
        for(int i=0;i<=q;++i){
            if(prefyx[i]+prefyx1[i]>maxx){
                maxx=prefyx[i]+prefyx1[i];
                gdzx=i;
            }
            if(prefyy[i]+prefyy1[i]>maxy){
                maxy=prefyy[i]+prefyy1[i];
                //cout<<i;
                gdzy=i;
            }
        }
        printf("Case #%d: %d %d\n",xd,gdzx,gdzy);
        for(int i=0;i<MAX;++i){
            prefyx1[i]=prefyx[i]=prefyy[i]=prefyy1[i]=wdol[i]=wgor[i]=wle[i]=wpr[i]=0;
        }
    }
    return 0;
}
