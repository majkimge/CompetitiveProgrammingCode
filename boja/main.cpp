#include <bits/stdc++.h>

using namespace std;
int z;
int n;
int tab[20];
int suma;

int main()
{
    scanf("%i",&n);
    for(int j=1;j<n;j++){
        suma+=n%j;
    }
    printf("%i",suma);
    return 0;
}
