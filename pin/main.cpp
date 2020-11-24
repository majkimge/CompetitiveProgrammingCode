#include <bits/stdc++.h>
#define lld long long

using namespace std;

lld n,wynik;

int main()
{
    scanf("%lld",&n);
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            for(int j=2;j*j<=n/i-1;++j){
                if((n/i-1)%j==0&&(n/i-1)/j>2){
                    wynik++;
                    //cout<<i<<" "<<j<<endl;
                }
                if((n/i-1)%j==0&&j>2&&j*j!=n/i-1){
                    wynik++;
                    //cout<<i<<" "<<j<<endl;
                }
            }
            if(i*i!=n){
                for(int j=2;j*j<=i-1;++j){
                    if((i-1)%j==0&&(i-1)/j>2){
                        wynik++;
                        //cout<<i<<" "<<j<<endl;
                    }
                    if((i-1)%j==0&&j>2&&j*j!=i-1){
                        wynik++;
                        //cout<<i<<" "<<j<<endl;
                    }
                }
            }

        }
    }
    printf("%lld",wynik);
    return 0;
}
