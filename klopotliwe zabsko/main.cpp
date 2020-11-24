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

lld wart[MAX][MAX];
lld jak=1,wynik,x,y,s,h;
lld poz,pion;
int main()
{
    cin>>h;
    cin>>s;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>y;
        cin>>x;
        tab[i]=mp(x,y);
        wart[x][y]=1;
    }
    //cout<<wart[6][6];

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(tab[i].f>tab[j].f||i==j)continue;
            lld rx=tab[j].f-tab[i].f;
            lld ry=tab[j].s-tab[i].s;
            lld temp=0;
            lld tx=tab[i].f;
            lld ty=tab[i].s;
            lld ps=0;
            //if(i==7)cout<<tx<<" "<<ty<<endl;
            while(tx<=s&&ty>=1&&ty<=h){
                if(!wart[tx][ty]){

                    ps=1;
                    break;
                }
                tx+=rx;
                ty+=ry;
                temp++;
            }
            tx=tab[i].f-rx;
            ty=tab[i].s-ry;
            while(tx>=1&&ty>=1&&ty<=h){
                if(!wart[tx][ty]){

                    ps=1;
                    break;
                }
                tx-=rx;
                ty-=ry;
                temp++;
            }
            //if(temp==4)cout<<i<<" "<<j<<endl;
            if(!ps)wynik=max(wynik,temp);
        }

    }
    if(wynik<3){
        printf("0");
    }else{
        printf("%d",wynik);
    }
    return 0;
}
/*
6 7
17
1 1
6 2
1 5
4 7
1 2
1 4
1 6
1 7
2 1
2 3
2 6
4 2
4 4
4 5
5 4
5 5
6 6
*/
