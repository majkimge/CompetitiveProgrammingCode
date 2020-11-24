#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 100009
#define MOD 1000000007
#define PIER 311

using namespace std;

int wyny[MAX];
int n,m,a,d,l,pom[MAX][2],ilek[330][330];
pair<int,pair<int,int> >zapy[MAX];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        //scanf("%d%d%d",&a,&l,&d);
        a=1;
        l=20;
        d=i%100+1;
        zapy[i]=mp(d,mp(a,l));
    }
    sort(zapy,zapy+m);
    for(int xd=0;xd<m;++xd){
        a=zapy[xd].s.f;
        l=zapy[xd].s.s;
        d=zapy[xd].f;
        if(d>PIER){

            for(int j=0;j<l;++j){

                wyny[a+d*j]++;
            }
        }else{
            pom[a][0]++;
            pom[a+d*(l-1)][1]--;
            while(xd<m-1&&d==zapy[xd+1].f){
                ++xd;
                a=zapy[xd].s.f;
                l=zapy[xd].s.s;
                d=zapy[xd].f;
                pom[a][0]++;
                pom[a+d*(l-1)][1]--;
            }
            for(int j=1;j<=n;++j){
                ilek[j%d][d]+=pom[j][0];
                //if(i<=3)cout<<i<<" "<<j<<" "<<ilek[j%i]<<endl;
                wyny[j]+=ilek[j%d][d];
                ilek[j%d][d]+=pom[j][1];
            }
            for(int j=1;j<=n;++j)pom[j][0]=pom[j][1]=0;
        }
    }


    for(int i=1;i<=n;++i){
        //printf("%d ",wyny[i]);
    }
    return 0;
}
