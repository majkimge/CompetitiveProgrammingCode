#include <bits/stdc++.h>

#define lld long long
#define MAX 100009
#define MLN 1000009
using namespace std;

lld wys,szer,wys1,szer1;
lld suma=0,sumal=0,sumap=0,sumag=0,sumad=0;
bool g=0,d=0,p=0,l=0,d1=0,g1=0;
lld glen=0,plen=0,dlen=0,llen=0,gg=0,dd=0;
lld maxl=-1;
lld maxp=-1;
lld maxd=-1;
lld maxg=-1;
lld maxl1=-1;
lld maxp1=-1;
lld maxd2=-1;
char tab[60][60];
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>wys;
    cin>>szer;
    cin>>wys1;
    cin>>szer1;

    for(int i=0;i<wys1;++i){
        for(int j=0;j<szer1;++j){
            cin>>tab[i][j];
        }
    }
    bool f=false;
    for(int i=wys1-1;i>=0;--i){
        f=false;
        for(int j=szer1-1;j>=0;--j){
            if(tab[i][j]=='#'&&!d){
                //sumad+=(szer1-1)-j+((wys1-1)-i)*szer-maxl*((wys1-1)-i);
                //maxp=j;
                maxd2=i;
                break;
            }

        }
    }
    for(int i=0;i<wys1;++i){
        f=false;
        for(int j=0;j<szer1;++j){
            if(tab[i][j]=='#'&&!g){
                sumag+=j+i*szer;
                maxl=j;
                maxg=i;
                g=true;
                f=true;
                gg++;
            }
            else if(tab[i][j]=='#'&&g&&!f){
                if(j>maxl){
                    sumag+=maxl;
                }else{
                    sumag+=j;
                    maxl=j;
                }
                gg++;
                f=true;
            }
        }
    }
    sumal+=maxl*wys-maxl*wys1+maxl*(wys1-maxd2-1);
     for(int i=wys1-1;i>=0;--i){
        f=false;
        for(int j=szer1-1;j>=0;--j){
            if(tab[i][j]=='#'&&!d){
                sumad+=(szer1-1)-j+((wys1-1)-i)*szer-maxl*((wys1-1)-i);
                maxp=j;
                maxd=i;
                d=true;
                f=true;
                dd++;
            }
            else if(tab[i][j]=='#'&&d&&!f){
                if(j<maxp){
                    sumad+=((szer1-1)-maxp);
                }else{
                    sumad+=(szer1-1)-j;
                    maxp=j;
                }
                dd++;
                f=true;
            }
        }
    }
    bool boi=false;
    for(int i=maxd;i>=0;--i){
        f=false;
        if(boi){
            break;
        }
        for(int j=maxl;j<szer1;++j){
            if(tab[i][maxl]=='#'){
                    boi=true;
                break;
            }
            if(tab[i][j]=='#'&&!d1){
                suma+=j;
                maxl1=j;
                //maxd=i;
                d1=true;
                f=true;
            }
            else if(tab[i][j]=='#'&&d1&&!f){
                if(j>maxl1){
                    suma+=(maxl1);
                }else{
                    suma+=j;
                    maxl1=j;
                }
                f=true;
            }
        }
    }
    boi=false;
    for(int i=maxg;i<wys1;++i){
        f=false;
        if(boi){
            break;
        }
        for(int j=maxp;j>=0;--j){
            if(tab[i][maxp]=='#'){
                    boi=true;
                break;
            }
            if(tab[i][j]=='#'&&!g1){
                suma+=maxp-j;
                maxp1=j;
                //maxd=i;
                g1=true;
                f=true;
            }
            else if(tab[i][j]=='#'&&g1&&!f){
                if(j<maxp1){
                    suma+=maxp-maxp1;
                }else{
                    suma+=maxp-j;
                    maxp1=j;
                }
                f=true;
            }
        }
    }
    sumap+=((szer1-1)-maxp)*wys-((szer1-1)-maxp)*wys1+((szer1-1)-maxp)*(maxg)-((szer1-1)-maxp)*maxg;
    //cout<<sumag<<sumap<<sumad<<sumal;
    suma+=sumag+sumap+sumad+sumal;
    cout<<suma;
    return 0;
}
