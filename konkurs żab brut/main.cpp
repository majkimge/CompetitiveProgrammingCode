#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 30009
#define MOD 1000000007
#define INF 1000000000000000

using namespace std;

int n,kt,wyn,k;
char s[109];
int tab[109];

int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    for(int i=0;i<n;++i){
        if(s[i]=='0'){
            tab[kt]=i;
            kt++;
        }
    }
    sort(tab,tab+kt);
    do{
        //cout<<tab[0]<<" "<<tab[1]<<" "<<tab[2];
        int p=0;
        for(int i=1;i<kt;++i){
            if(abs(tab[i]-tab[i-1])>k){
                p=1;
                break;
            }
        }
        if(!p&&abs(tab[kt-1]-tab[0])<=k)wyn++;
        wyn%=MOD;
    }while(next_permutation(tab+1,tab+kt));



    cout<<wyn;
    return 0;
}
