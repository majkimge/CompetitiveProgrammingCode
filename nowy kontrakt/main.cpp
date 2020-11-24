#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 300009
#define MOD 1000000007
#define INF 1000000000000000

using namespace std;

lld n,wyn,temp,tdl;
lld tab[MAX];
lld dl[MAX];
lld ost[MAX];
lld dychy[100];
lld czyzer[MAX];
pair<lld,lld> ktzer;
void dodaj(lld dli){
    int sk=0;
    for(int i=tdl-1;i>=dli;--i){
        if(czyzer[i]<ktzer.f&&i>=ktzer.s){
            ost[i]=0;
            czyzer[i]=ktzer.f;
        }
        if(ost[i]!=9){
            ost[i]++;
            sk=1;
            break;
        }
        ost[i]=0;
    }
    if(!sk){
		//cout<<"A";
        tdl++;
        wyn++;
        //ost[0]=1;
    }
}

lld por(int odi){
    lld ret=0;
    for(int i=odi-1;i>=0;--i){
        ret+=ost[i]*dychy[odi-1-i];
    }
    return ret;
}

void ustpier(lld na, lld od){
    for(int i=od-1;i>=0;--i){
        ost[i]=na%10;
        na=na/10;
    }
}

int main()
{
    dychy[0]=1;
    for(int i=1;i<=12;++i){
        dychy[i]=dychy[i-1]*10;
    }
    scanf("%lld",&n);

    for(int i=0;i<n;++i){
        scanf("%lld",&tab[i]);
        lld temp=tab[i];
        while(temp>0){
            dl[i]++;
            temp=temp/10;
        }
    }
    tdl=dl[0];
    ustpier(tab[0],dl[0]);
    for(int i=1;i<n;++i){
		//cout<<wyn<<endl;
        if(dl[i]>tdl){
            ustpier(tab[i],dl[i]);
            tdl=dl[i];
        }else{
            //cout<<tab[i]<<" "<<por(dl[i])<<" ";
            wyn+=tdl-dl[i];
            if(tab[i]>por(dl[i])){
                ustpier(tab[i],dl[i]);
                ktzer=mp(ktzer.f+1,dl[i]);
                for(int j=dl[i];j<dl[i]+10;++j){
					ost[j]=0;
					czyzer[j]=ktzer.f;
				}
            }else if(tab[i]<por(dl[i])){

                ustpier(tab[i],dl[i]);
                ktzer=mp(ktzer.f+1,dl[i]);
                for(int j=dl[i];j<dl[i]+10;++j){
					ost[j]=0;
					czyzer[j]=ktzer.f;
				}
                tdl++;
                wyn++;
                //cout<<"A";
            }else{
                if(dl[i]==tdl){
                    tdl++;
                    wyn++;
                }else{
                    dodaj(dl[i]);
                }
            }
        }
    }
    printf("%lld",wyn);
    return 0;
}

/*

*/
