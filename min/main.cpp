#include <bits/stdc++.h>

#define MAX 500001
#define lld long long
using namespace std;
int n;
int p;
lld wynik=0;
int tab[MAX];
priority_queue <int> kol;

int main()
{
    scanf("%i",&n);
    for(int i=0;i<n;i++){
        scanf("%i",&tab[i]);
        kol.push(-tab[i]);
    }
    p=-kol.top();
    printf("%i",p);
    return 0;
}
