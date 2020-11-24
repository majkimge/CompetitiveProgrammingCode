#include <bits/stdc++.h>
#define lld long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009

using namespace std;

int z,n,a,m,pr1,pr2,dl;
int tab1[MAX];
int tab2[MAX];
int sum1[MAX];
int sum2[MAX];
int pref1[MAX];
int pref2[MAX];
int czypref1[MAX];
int czypref2[MAX];

int main()
{
    scanf("%d",&z);
    for(int xx=1;xx<=z;++xx){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i){
            scanf("%d",&a);
            tab1[i]=(a&1);
        }
        for(int i=1;i<=m;++i){
            scanf("%d",&a);
            tab2[i]=(a&1);
        }
        //sum1[0]=tab1[0];
        //sum2[0]=tab2[0];
        for(int i=1;i<=n;++i){
            sum1[i]=((sum1[i-1]+tab1[i])&1);
        }
        for(int i=1;i<=m;++i){
            sum2[i]=((sum2[i-1]+tab2[i])&1);
        }
        pref1[0]=0;
        pref1[1]=0;
        int pr=0;
        //cout<<n;
        for(int i=2;i<=n;++i){
            //cout<<tab1[i];
            //system("pause");
            while(pr!=0&&tab1[i]!=tab1[pr+1]) pr=pref1[pr];
            if(tab1[i]==tab1[pr+1]){
                pref1[i]=pr+1;
                pr++;
            }else{
                pr=0;
                pref1[i]=0;
            }
        }
        pref2[0]=0;
        pref2[1]=0;
        pr=0;
        for(int i=2;i<=m;++i){
            while(pr!=0&&tab2[i]!=tab2[pr+1]) pr=pref2[pr];
            if(tab2[i]==tab2[pr+1]){
                pref2[i]=pr+1;
                pr++;
            }else{
                pr=0;
                pref2[i]=0;
            }
        }
        pr=pref1[n];
        while(pr!=0){
                //cout<<"X"<<pr;
            czypref1[pr]=xx;
            pr=pref1[pr];
        }
        pr=pref2[m];
        while(pr!=0){
            czypref2[pr]=xx;
            pr=pref2[pr];
        }
        pr1=1;
        pr2=1;
        if(n>m){
            pr1=n-m+1;
        }else{
            pr2=m-n+1;
        }
        //dl=min(n,m);
        //cout<<pr2;
        //cout<<((sum2[m]-sum2[pr2-1]+2)&1);
        int jest=0;
        while(pr1<=n){
            if(((sum1[n]-sum1[pr1-1]+2)&1)==((sum2[m]-sum2[pr2-1]+2)&1)||(czypref1[pr1-1]!=xx&&pr1!=1)||(czypref2[pr2-1]!=xx&&pr2!=1)){
                printf("%d\n",n-pr1+1);
                jest=1;
                break;
            }
            pr1++;
            pr2++;
        }
        if(!jest){
            printf("0\n");
        }

    }
    return 0;
}
/*
2
6 4
0 1 2 3 4 5
3 1 3 6
9 9
0 0 0 0 1 0 0 0 0
0 0 1 0 0 0 1 0 0
*/
