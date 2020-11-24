#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 10000009
#define INF 1000000009

using namespace std;

int n;
bool sito[MAX*2];
int tab[109];
int wyny[209];
int sumy[209];
vector<int> pa;
vector<int> np;
int ilepa,ilenp,wynik;
int odw[209];
int zaj[209];
int kt=1;
vector<int> chce[MAX];

int skoj( int ii){
   // cout<<i;

        if(odw[ii]!=kt){
            int czy=0;
        odw[ii]=kt;
        for(int j=0;j<chce[ii].size();++j){//cout<<"W";
            if(zaj[chce[ii][j]]==-1){
                zaj[chce[ii][j]]=ii;
                ilepa++;
                wynik++;
                czy=1;

                return 1;
            }
        }
        if(!czy){
            for(int j=0;j<chce[ii].size();++j){
            if(skoj(zaj[chce[ii][j]])){
                zaj[chce[ii][j]]=ii;
                //ilepa++;
                //wynik++;
                czy=1;
                return 1;
            }
        }
        }
        }

        return 0;

}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    for(int i=2;i*i<MAX;++i){
        if(!sito[i]){
            //pier.pb(i);
            for(int j=i*i;j<MAX;j+=i){
                sito[j]=1;
            }
        }
    }
    sito[2]=1;
    for(int i=0;i<n;++i){
        if(tab[i]%2){
            np.pb(tab[i]);
        }else{
            pa.pb(tab[i]);
        }
        ++i;
        while(tab[i]==tab[i-1]+1){
            //wl++;
            ++i;
        }
        i--;
        if(tab[i]%2){
            pa.pb(tab[i]+1);
        }else{
            np.pb(tab[i]+1);
        }

    }
    /*for(int i=0;i<np.size();++i){
        cout<<np[i]<<" ";
    }
    //system("pause");
    */
    for(int i=0;i<202;++i){
        zaj[i]=-1;
    }
    for(int i=0;i<pa.size();++i){
        for(int j=0;j<np.size();++j){
            if(!sito[abs(pa[i]-np[j])]){
               // cout<<i<<" "<<j<<endl;
                chce[i].pb(j);
            }
        }
    }
    for(int i=0;i<pa.size();++i){
        kt++;
        skoj(i);

    }

    wynik+=(pa.size()-ilepa)/2*2+(np.size()-ilepa)/2*2;
    if((pa.size()-ilepa)%2){
        wynik+=3;
    }
    printf("%d",wynik);
    //cout<<"XD";
    return 0;
}
/*
10
1 2 3 5 6 7 8 9 10000 100000
*/
