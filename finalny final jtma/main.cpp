#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second


using namespace std;

lld n;

lld il;
lld tab[300];
vector<int> ter;
lld odw[300];

int main()
{
    tab[1]=0;
    tab[0]=0;

    for(int i=2;i<=200;++i){
        for(int j=0;j<i;++j){
            ter.pb((tab[j]^(tab[i-j-1])));
            odw[(tab[j]^(tab[i-j-1]))]=1;
        }
        for(int j=0;j<=250;++j){
            if(!odw[j]){
                tab[i]=j;

                if(j>0)++il;
                break;
            }
        }
        for(int j=0;j<=250;++j){
            odw[j]=0;
        }
    }
    cout<<(29^163);
    return 0;
}
