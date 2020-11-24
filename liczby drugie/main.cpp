#include <bits/stdc++.h>

#define lld long long
using namespace std;

//lld n;
char n[20];
int loga=0;
lld b,c;
bool czy=0,czy1=0;
bool wynik=0;
int main()
{
    scanf("%s",n);
    int a=strlen(n);



    for(int i=0;i<a;i++){
        b=0;
        c=0;
        czy=0;
        czy1=0;
        for(int j=i;j>=0;j--){
            b+=(n[j]-48)*pow(10,i-j);
            if(n[j]-48==0&&j==0)czy=1;

        }

        if(b<2) czy=1;
        for(int k=2;k<(int)(sqrt((double)b));k++){
            if(b%k==0){
                czy=1;

            }
        }
        if(!czy){

            for(int j=a-1;j>i;j--){
                c+=(n[j]-48)*pow(10,a-1-j);

                if(n[j]-48==0&&j==i+1)czy1=1;
            }

            if(c<2)czy1=1;
            for(int k=2;k<(int)(sqrt((double)c));k++){
                if(c%k==0||c<2) czy1=1;
            }
            if(!czy1){
                wynik=1;
            }
        }

    }
    if(wynik)printf("TAK");
    else printf("NIE");
    return 0;
}
