#include<bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define MAX 100009
#define f first
#define s second
#define INF 1000000000

using namespace std;

int n;
int tab[MAX];
int wyn=INF;

int main()
{
    scanf("%d",&n);
    for(int i=2;i*i<n;++i){
        if(n%i!=0){
            printf("%d",i-1);
            break;
        }
    }
    if(n==3)
    return 0;
}
