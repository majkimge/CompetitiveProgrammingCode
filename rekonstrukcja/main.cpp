#include <bits/stdc++.h>
#define MAX 1030
#define f first
#define s second
#define mp make_pair
#define pb push_back

using namespace std;

int n;
pair<int,int> tab[MAX];
int odl[MAX][MAX];
vector<int> wier;
int czy[MAX][MAX];
int poile[MAX];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;++i){cout<<"G";
        for(int j=i+1;j<=n;++j){
            scanf("%d",&odl[i][j]);
            if(i==1){
                tab[j]=mp(odl[i][j],j);
            }

            odl[j][i]=odl[i][j];
        }
        if(i==1){
            sort(&tab[i+1],&tab[n+1]);
        }

    }
    wier.pb(1);
    for(int i=2;i<=n;++i){

            int ten=tab[i].s;
        for(int j=0;j<wier.size();++j){
            int czy1=1;
            for(int z=0;z<wier.size();++z){
                if(z!=j&&wier[j]!=ten&&wier[z]!=ten){
                    if(odl[wier[j]][ten]+odl[wier[j]][wier[z]]!=odl[wier[z]][ten]){
                        czy1=0;
                        break;
                    }
                }
            }
            if(czy1){
                czy[wier[j]][ten]=1;
                czy[ten][wier[j]]=1;
                poile[ten]++;
                poile[wier[j]]++;
                wier.pb(ten);
                break;
            }
        }
    }
    for(int i=1;i<=n;++i){
        printf("%d ",poile[i]);
        for(int j=1;j<=n;++j){
            if(czy[i][j]==1){
                printf("%d ",j);
            }
        }
        printf("\n");
    }
    return 0;
}
