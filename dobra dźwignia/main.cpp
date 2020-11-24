#include <bits/stdc++.h>
#define MAX 200001
using namespace std;

int n, k;
long long tab[MAX][2];
char word[MAX];
long long literki[MAX][26];
long long all;
long long bad;
int main()
{
    scanf("%lld",&n);
    scanf("%lld",&k);
    scanf("%s",word);
    for(int i=0;i<k;i++){
        for(int j=0;j<2;j++){
            scanf("%lld",&tab[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        if(i!=0){
            for(int z=0;z<26;z++){
                literki[i][z]=literki[i-1][z];
            }
            literki[i][word[i]-'a']++;
        }else{
            literki[i][word[i]-'a']++;
        }


    }
    for(int i=0;i<k;i++){
            bad=0;
            all=0;
        for(int j=0;j<26;j++){
            if(tab[i][0]>1){
                bad+=(literki[tab[i][1]-1][j]-literki[tab[i][0]-2][j])*(literki[tab[i][1]-1][j]-literki[tab[i][0]-2][j]-1)/2;
            }else{
                if((word[tab[i][0]-1]-'a')==j){
                    bad+=(literki[tab[i][1]-1][j]-literki[tab[i][0]-1][j]+1)*(literki[tab[i][1]-1][j]-literki[tab[i][0]-1][j])/2;
                }else{
                    bad+=(literki[tab[i][1]-1][j]-literki[tab[i][0]-1][j]-1)*(literki[tab[i][1]-1][j]-literki[tab[i][0]-1][j])/2;
                }
            }
        }
        all=((tab[i][1]-1)-(tab[i][0]-1))*((tab[i][1]-1)-(tab[i][0]-1)+1)/2-bad+1;
        printf("%lld\n",all);
    }

    return 0;
}
