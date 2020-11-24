#include <bits/stdc++.h>

#define lld long long
#define MAX 1000009
using namespace std;

lld n,m;
char s[MAX];
lld tab[MAX][2];
lld pref[MAX][28];
lld mod[28];
lld maxmod=0;
lld ost;
bool tesame=false;
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    cin>>m;
    cin>>s;
    for(int i=0;i<m;i++){
        cin>>tab[i][0];
        cin>>tab[i][1];
    }
    for(int i=0;i<n;i++){
        if(i==0){
            pref[i][(int)(s[i]-'a')]++;
        }else{
            for(int z=0;z<28;++z){
                if(z!=(int)(s[i]-'a')){
                    pref[i][z]=pref[i-1][z];
                }else{
                    pref[i][z]=pref[i-1][z]+1;
                }

            }

        }


    }
    for(int i=0;i<m;++i){
        tesame=false;
        maxmod=0;
        for(int j=0;j<28;++j){
            mod[j]=0;
        }
        for(int j=0;j<28;++j){
            mod[j]=pref[tab[i][1]-1][j]-pref[tab[i][0]-1][j];
            if(s[tab[i][0]-1]==j+97){
                mod[j]++;
            }
        }
        for(int k=0;k<28;++k){
            if(mod[k]>maxmod){
                ost=k;
                maxmod=mod[k];
                tesame=false;
            }else if(mod[k]==maxmod){
                tesame=true;
            }
        }
        if(tesame){
            cout<<"NIE MA"<<endl;
        }else{

            cout<<(char)(ost+97)<<endl;
        }
    }
    return 0;
}
