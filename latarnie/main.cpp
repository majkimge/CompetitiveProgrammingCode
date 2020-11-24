#include <bits/stdc++.h>

#define MAX 500001
using namespace std;
struct maxim{
int maxin;
int inde;
};
int n;
int tab[MAX];
int maximum;
int maxInd;
int ile=0;

maxim maksym;
maxim getMax(int tab[],int a, int b, int n, int curr);
void latarnie(int tab[],int a,int b,int n, int curr);
int main()
{
    scanf("%i",&n);
    for(int i=0;i<n;i++){
        scanf("%i",&tab[i]);
    }
   latarnie(tab,0,n,n,0);
   printf("%i",ile);
    return 0;
}
maxim getMax(int tab[],int a, int b, int n, int curr){
    int maxi=0;
    int index;
    maxim maks;
    for(int i=a;i<b;i++){
        if(tab[i]>=maxi){
            maxi=tab[i];
            index=i;
        }

    }
    maks.maxin=maxi;
    maks.inde=index;
    //cout<< maks.maxin<<maks.inde<<endl;
    return maks;

}
void latarnie(int tab[],int a,int b,int n, int curr){

    maxim maxi;
    maxim maxi1;
    maxim maxi2;
    int constb=b;
    int consta=a;
    bool lgot=false;
    bool rgot=false;
    if(curr==0){
        a=0;
        b=n;
        maxi=getMax(tab,a,b,n,curr);
        ile++;
    }else{
        maxi=getMax(tab,a,b,n,curr);
        //cout<<"b";
        ile++;
    }
    int i=maxi.inde;
    int p=0;
    while(maxi.maxin-tab[i]>=maxi.inde-i){
        b=i;
        i--;
        p++;
        if(i<=a-1){
		lgot=true;
            break;

        }

    }
    if(p>1&&b>a&&!lgot){
        latarnie(tab,a,b,n,curr+1);//cout<<b<<endl;

    }else if(b>a&&!lgot&&p<=1&&maxi.maxin-tab[maxi.inde-1]==0){
    	latarnie(tab,a,b,n,curr+1);//cout<<"b";

	}
    i=maxi.inde;
    int k=0;
    while(maxi.maxin-tab[i]>=-maxi.inde+i){
        a=i;
        i++;
        k++;
        if(i>=constb){
			rgot=true;
            break;

        }

    }
    if(k>1&&constb>a&&!rgot){
        latarnie(tab,a+1,constb,n,curr+1);
        //cout<<"b";
    }else if(constb>a&&!rgot&&k<=1&&maxi.maxin-tab[maxi.inde+1]==0){
    	latarnie(tab,a,b,n,curr+1);//cout<<"b";
	}


}
