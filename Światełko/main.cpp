#include <stdio.h>
#include <math.h>
using namespace std;
bool koniec=false;
int n;
int teraz=0;
int proby=0;
long double maximum=1.8E+300;
bool nigdy=false;
int main()
{
    scanf("%i",&n);
    long double pola[n-1][3];
    for(int i=0;i<(n-1);i++){
        for(int j=0;j<3;j++){
            if(j!=2){
                scanf("%i",&pola[i][j]);
            }else{
                pola[i][j]=1;
            }
        }
    }
    if(n==1){
        printf("0");
    }else{
    while(koniec!=true){
        if(teraz==n-1){
            koniec=true;
        }else{
            if(fmod(pola[teraz][2],2)==1){
                pola[teraz][2]++;
                teraz=pola[teraz][0]-1;

                proby++;
            }else{
                pola[teraz][2]++;
                teraz=pola[teraz][1]-1;
                proby++;
            }
        }
        for(int i=0;i<n-1;i++){
            /*if(i<n-1){
                if(pola[i][2]%2==0){
                    i=n;
                    //break;
                }
            }else{
                koniec=true;
                nigdy=true;
            }*/
            if(pola[i][2]>maximum-1){
                koniec=true;
                nigdy=true;
            }
        }


    }
    if(nigdy!=true){
        printf("%i",proby);
    }else{
        printf("nigdy");
    }

    }
    return 0;
}
