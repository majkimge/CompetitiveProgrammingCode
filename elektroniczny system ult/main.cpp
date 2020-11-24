#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MAX 2000009
#define INF 1000000000
#define pii pair<int,int>

using namespace std;

int n,a,b,mini,wynik,ost=-MAX;
pii tab[MAX];
int limy[MAX];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&a,&b);
        limy[b]=a;
    }
    //sort(tab,tab+n);
    mini=INF;
    for(int i=0;i<MAX;++i){
        if(mini==i){
            //cout<<"A";
            ++wynik;
            ost=i;
            mini=INF;
        }
        if(limy[i]){
            //cout<<ost<<" "<<i<<endl;
            //cout<<limy[i];
            if(i-ost>=limy[i]){
                ost=i;
                wynik++;
                mini=INF;
            }else{
                mini=min(mini,ost+limy[i]);
            }
        }

    }
    printf("%d",wynik);
    return 0;
}
