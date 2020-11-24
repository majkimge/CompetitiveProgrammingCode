#include <iostream>

using namespace std;

int n;
int w;
int tab[70][100];
int tab1[70][100];
int wagi[70];
int waga,cena;
int main()
{
    cin>>n;
    cin>>w;
    for(int i=1;i<=n;i++){
        cin>>waga;
        cin>>cena;
        wagi[i]=waga;
        for(int j=1;j<=w;j++){
            if(j>=waga){
                if(tab[i-1][j]<tab[i][j-waga]+cena){
                    tab[i][j]=tab[i][j-waga]+cena;
                    tab1[i][j]=i;
                }else{
                    tab[i][j]=tab[i-1][j];
                    tab1[i][j]=tab1[i-1][j];
                }
            }else{
                tab[i][j]=tab[i-1][j];
                tab1[i][j]=tab1[i-1][j];
            }
        }
    }
    int a=w;
    while(a>0){
        cout<<tab1[n][a]<<" ";
        a-=wagi[tab1[n][a]];
    }
    return 0;
}
