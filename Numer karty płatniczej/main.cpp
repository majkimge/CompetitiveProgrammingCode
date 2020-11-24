#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int c;
char numer[17];
int suma=0;
int main()
{
    scanf("%i",&n);

    for(int i=0;i<n;i++){
        scanf("%16s",numer);

        suma=0;
        for(int i=0;i<16;i++){
            c=numer[i]-48;
            //printf("%i",c);
            if((i+1)%2==1){
                if(c*2>9){
                    suma+=1+((c*2)%10);
                }else{
                    suma+=c*2;
                }

            }else{
                suma+=c;
            }
            //printf("%i\n",suma);
        }
        if(suma%10==0){
            printf("OK\n");

        }else{
            if(suma%10>c){
                printf("%i\n",10-(suma%10)+c);
            }else{
                printf("%i\n",c-suma%10);
            }
        }

    }
    return 0;
}
