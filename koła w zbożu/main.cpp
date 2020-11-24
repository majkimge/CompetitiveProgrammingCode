#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 10007
#define MAX 809

using namespace std;

int n,a;
double wynik;



int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d%d",&a,&a,&a);
        wynik+=M_PI*(double)a*(double)a;
    }
    printf("%.6lf",wynik);
    return 0;
}
