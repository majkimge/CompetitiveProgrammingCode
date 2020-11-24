#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 30009
#define MOD 1000000009

using namespace std;

int n;
lld tab[MAX];
lld dod,czy,mini,dod1;
char s[MAX];
int sum,pocz=0;

int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;++i){
        if(s[i]==')'){
            sum++;
            czy--;
        }else{
            czy++;
        }
        mini=min(mini,czy);
    }
    if(n%2||sum>n/2||mini!=0){
        //cout<<czy;
        printf("0");
    }else{
        tab[1]=1;
        for(int i=0;i<n;++i){
            if(s[i]==')'){
                for(int j=pocz;j<n+4;++j){
                    tab[j]=tab[j+1];
                    tab[j+1]=0;
                }
                //pocz++;
            }else{
                for(int j=pocz;j<n+4;++j){
                    dod=tab[j];
                    //cout<<tab[j]<<" ";
                    tab[j]=tab[j+1];
                    tab[j]+=dod1;
                    tab[j]%=MOD;
                    dod1=dod;
                    //swap(dod,dod1);
                }
                //cout<<endl;
            }
        }


        printf("%lld",tab[1]);
    }
    return 0;
}
