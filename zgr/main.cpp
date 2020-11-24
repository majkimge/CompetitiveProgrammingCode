#include <bits/stdc++.h>
#define lld unsigned int
#define MAX 100009
#define MOD 1000000007
#define mp make_pair
#define f first
#define s second
#define pb push_back

using namespace std;

int n;
int tab[MAX];
int ilew[MAX*100];
int wyn;
vector<int> temp;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&tab[i]);
    }
    for(int i=0;i<n;++i){
        for(int j=2;j*j<tab[i];++j){
            if(tab[i]%j==0&&(tab[i]/j)%j!=0){
                temp.pb(j);
                temp.pb(tab[i]);
            }else{
                    temp.clear();
                    break;
                }
            if(tab[i]%j==0){
                //temp.pb(tab[i]);
            }

        }
        for(int j=0;j<temp.size();++j){
            ilew[temp[j]]++;
        }
        temp.clear();
    }
    wyn=n*(n-1)/2;
    for(int i=0;i<MAX*100;++i){
        if(ilew[i]!=0){
            if(ilew[i]%2==0){
                wyn++;
            }else{
                wyn--;
            }
        }
    }
    printf("%d",wyn);
    return 0;
}
