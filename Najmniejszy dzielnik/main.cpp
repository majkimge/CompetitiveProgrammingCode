#include <stdio.h>
#include <math.h>
using namespace std;
int n;


long long int suma=0;
int main()
{
    scanf("%i",&n);
    double pier=pow(n,0.5);

    bool tab[n-1];
    int dziel[n-1];
    for(int i=0;i<n-1;i++){
        tab[i]=true;
        dziel[i]=0;
    }
    for(int i=2;i<pier+2;i++){
        if(tab[i-2]==true){
            dziel[i-2]=i;

            for(int j=i*i;j<=n;j+=i){
                tab[j-2]=false;
                if(dziel[j-2]==0){
                    dziel[j-2]=i;
                }
            }
        }
    }
    for(int i=0;i<n-1;i++){
        if(dziel[i]==0){
            suma+=(i+2);
        }else{
            suma+=dziel[i];
        }
    }
    printf("%i",suma);
    return 0;
}
