#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
#define MAX 1000009

using namespace std;

int n,wyn,czy,wynik,itl,itp,maxi,mini,ile[30],bwyn;
char tab[MAX];
vector<int> v[30];

int brut(){
    for(int i=1;i<=n;++i){
        for(int j=0;j<=n-i;++j){
            maxi=0;
            mini=MAX;
            for(int z=0;z<30;++z){
                ile[z]=0;
            }
            for(int z=j;z<j+i;++z){
                ile[tab[z]-'a']++;
            }
            for(int z=0;z<30;++z){
                maxi=max(maxi,ile[z]);
                if(ile[z])mini=min(mini,ile[z]);
            }
            bwyn=max(bwyn,maxi-mini);
        }
    }
}

int main()
{
    scanf("%d",&n);
    scanf("%s",tab);
    //srand(time(NULL)+n);
    /*for(int i=0;i<n;++i){
        tab[i]=rand()%4+'a';
    }*/
    for(int i=0;i<n;++i){
        v[tab[i]-'a'].pb(i);
    }
    //brut();
    //cout<<bwyn<<" ";
    for(int i=0;i<='z'-'a';++i){
        for(int j=0;j<='z'-'a';++j){
            if(i==j||v[i].empty()||v[j].empty())continue;
            czy=0;
            itl=0;
            itp=0;
            wyn=0;
            int twyn=0;
            int tczy=0;
            while(itl<v[i].size()||itp<v[j].size()){
                while(itl<v[i].size()&&(itp>v[j].size()-1||v[i][itl]<v[j][itp])){
                    if(wyn<0){
                        wyn=0;
                        czy=0;
                    }
                    if(tczy)twyn++;
                    wyn++;
                    itl++;
                }//cout<<i<<" "<<j<<endl;
                if(czy){
                    wynik=max(wynik,wyn);
                    twyn=max(twyn,wyn);
                    //wynik=max(twyn,wynik);
                }
                if(tczy)wynik=max(twyn,wynik);
                while(itp<v[j].size()&&(itl>v[i].size()-1||v[j][itp]<v[i][itl])){
                    czy=1;
                    tczy=1;
                    twyn--;
                    wyn--;
                    itp++;
                    wynik=max(wynik,wyn);
                    if(czy){
                        wynik=max(wynik,wyn);
                        twyn=max(twyn,wyn);
                        //wynik=max(twyn,wynik);
                    }
                    if(tczy)wynik=max(twyn,wynik);
                }
            }
            //cout<<wynik;
        }
    }
    printf("%d",wynik);
    /*if(bwyn!=wynik){
        cout<<endl;
        for(int i=0;i<n;++i){
            cout<<tab[i];
        }
    }*/
    return 0;
}

/*
20
khpqhdaveohjwxcaynqw
*/
