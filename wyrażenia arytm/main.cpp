#include <bits/stdc++.h>
#define lld long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define piii pair<int,pair<int,int> >
#define pii pair<int,int>
#define MAX 100009
#pragma GCC optimalize ("ofast")

using namespace std;

lld p,m,n,wynik;
char wyr[MAX];




int main()
{
    scanf("%s",wyr);
    while(wyr[n])++n;
    scanf("%lld%lld",&p,&m);
    srand(time(0)+n);
    cout<<rand()%m;
    return 0;
}
