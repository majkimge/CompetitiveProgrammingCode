#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define PIER 320
#define BRUT 63009

using namespace std;

lld n,kk=1,wynik,ilep;
pair<pair<lld,lld>,pair<lld,lld> >tree[320];
int tab[MAX];
pair<lld,lld> maxi[320][320];
lld odw[MAX];
lld dl[320];
lld pmax[320];

void akt(lld gdzie){
    for(int j=0;j<dl[gdzie];++j){
        if(!odw[gdzie*PIER+j]){
            maxi[gdzie][j].f+=tree[gdzie].s.f;
            maxi[gdzie][j].f+=tree[gdzie].s.s*tab[gdzie*PIER+j];
        }
    }
    tree[gdzie].s=mp(0,0);
}

void ust(lld gdzie,lld dok,lld maxik1){
    tree[gdzie].f=mp(0,0);
    pmax[gdzie]=0;
    for(int j=0;j<dok;++j){
        if(!odw[gdzie*PIER+j]){
            maxi[gdzie][j].f+=tab[gdzie*PIER+dok];
            tree[gdzie].f=max(tree[gdzie].f,maxi[gdzie][j]);
            pmax[gdzie]=max((lld)tab[gdzie*PIER+j],pmax[gdzie]);
        }
    }
    for(int j=dok+1;j<dl[gdzie];++j){
        if(!odw[gdzie*PIER+j]){
            maxi[gdzie][j].f+=tab[gdzie*PIER+j];
            tree[gdzie].f=max(tree[gdzie].f,maxi[gdzie][j]);
            pmax[gdzie]=max((lld)tab[gdzie*PIER+j],pmax[gdzie]);
        }
    }
    maxi[gdzie][dok].f=0;
}

void ust1(lld gdzie,lld maxik1){
    for(int i=0;i<gdzie;++i){
        tree[i].s.f+=maxik1;
        tree[i].f.f+=maxik1;
    }
    for(int i=gdzie+1;i<ilep;++i){
        tree[i].s.s++;
        tree[i].f.f+=pmax[i];
    }
}

int main()
{
    scanf("%lld",&n);
    if(n>63005){
        for(int i=0;i<n;++i){
            scanf("%lld",&tab[i]);
        }
        ilep=(n-1)/PIER+1;
        //cout<<ilep;
        int ost=n%PIER;
        if(n%PIER==0){
            ost=PIER;
        }
        for(int i=0;i<ilep;++i){
            if(i!=ilep-1){
                dl[i]=PIER;
                for(int j=0;j<PIER;++j){
                    maxi[i][j]=mp(tab[i*PIER+j],j);

                    tree[i].f=max(tree[i].f,maxi[i][j]);
                    pmax[i]=tree[i].f.f;
                }
            }else{
                dl[i]=ost;
                for(int j=0;j<ost;++j){
                    maxi[i][j]=mp(tab[i*PIER+j],j);
                    tree[i].f=max(tree[i].f,maxi[i][j]);
                    pmax[i]=tree[i].f.f;
                }
            }

        }
        for(int i=1;i<=n;++i){
            pair<lld,lld> maxik=mp(0,0);
            int gd=0;
            for(int j=0;j<ilep;++j){
                if(maxik<=tree[j].f){
                    maxik=max(maxik,tree[j].f);
                    gd=j;
                }

            }
            akt(gd);
            //cout<<"Y"<<gd<<endl;
            //cout<<"D"<<tree[0].f.f<<" "<<tree[1].f.f<<endl;
            //cout<<"Z"<<pmax[0];
            //for(int x=0;x<2;++x){
                //cout<<"X"<<maxi[1][x].f<<" ";
            //}
            odw[gd*PIER+maxik.s]=1;
            wynik+=maxi[gd][maxik.s].f;
            printf("%lld ",wynik);
            ust(gd,maxik.s,maxik.f);

            ust1(gd,tab[gd*PIER+maxik.s]);
        }
    }else{
        for(int i=0;i<n;++i){
            scanf("%lld",&tab[i]);
        }
        ilep=(n-1)/BRUT+1;
        //cout<<ilep;
        int ost=n%BRUT;
        if(n%BRUT==0){
            ost=BRUT;
        }
        for(int i=0;i<ilep;++i){
            if(i!=ilep-1){
                dl[i]=BRUT;
                for(int j=0;j<BRUT;++j){
                    maxi[i][j]=mp(tab[i*BRUT+j],j);

                    tree[i].f=max(tree[i].f,maxi[i][j]);
                    pmax[i]=tree[i].f.f;
                }
            }else{
                dl[i]=ost;
                for(int j=0;j<ost;++j){
                    maxi[i][j]=mp(tab[i*BRUT+j],j);
                    tree[i].f=max(tree[i].f,maxi[i][j]);
                    pmax[i]=tree[i].f.f;
                }
            }

        }
        for(int i=1;i<=n;++i){
            pair<lld,lld> maxik=mp(0,0);
            int gd=0;
            for(int j=0;j<ilep;++j){
                if(maxik<=tree[j].f){
                    maxik=max(maxik,tree[j].f);
                    gd=j;
                }

            }
            akt(gd);
            //cout<<"Y"<<gd<<endl;
            //cout<<"D"<<tree[0].f.f<<" "<<tree[1].f.f<<endl;
            //cout<<"Z"<<pmax[0];
            //for(int x=0;x<2;++x){
                //cout<<"X"<<maxi[1][x].f<<" ";
            //}
            odw[gd*BRUT+maxik.s]=1;
            wynik+=maxi[gd][maxik.s].f;
            printf("%lld ",wynik);
            ust(gd,maxik.s,maxik.f);

            ust1(gd,tab[gd*BRUT+maxik.s]);
        }

    }

    return 0;
}
/*
6
2 1 3 7 5 8
*/
