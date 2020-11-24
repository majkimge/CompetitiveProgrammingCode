#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int z,n,m,a,b,c,ilej,wynik;
pair<int,pair<int,int> >tab[2009];
int wyny[4000009];

int main()
{
    scanf("%d",&z);
    for(int xd=0;xd<z;++xd){
        scanf("%d",&n);
        scanf("%d",&m);
        ilej=0;
        wynik=0;
        for(int i=0;i<4000;++i){
            wyny[i]=0;
        }
        for(int i=0;i<n;++i){
            scanf("%d",&a);
            scanf("%d",&b);
            scanf("%d",&c);
            tab[i]=mp(c,mp(a,b));
        }
        sort(tab,tab+n);
        for(int i=n-1;i>=0;--i){
            int ite=tab[i].s.f;
            int ile=tab[i].s.s;
            while(ile>0&&ite>0&&ilej<m){
                if(!wyny[ite]){
                    wyny[ite]=tab[i].f;
                    ite--;
                    ile--;
                    ilej++;
                    wynik+=tab[i].f;
                }else{
                    ite--;
                }
            }
        }
        printf("%d\n",wynik);

    }
    return 0;
}
