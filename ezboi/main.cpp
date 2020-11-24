#include <bits/stdc++.h>

using namespace std;
long long int z;
//int n;
long long int n;
long long suma;
int main()
{



        suma=0;
    cin>>n;
    for(int j=n;j>0;j--){
        suma+=(n%j);
    }
    //suma+=((tab[i]+1)/2)*((tab[i]+1)/2-1)/2;
    cout<<suma;



    return 0;
}
