#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lld long long
#define MAX 1009

using namespace std;

int n,wynik,maxik,gdz;
int ile[MAX*10];

int main()
{
    scanf("%d",&n);
    for(int j=0;j<n;++j){
        scanf("%d",&ile[j]);
        ile[j+n]=ile[j+2*n]=ile[j];
    }
    maxik=MAX;
    while(maxik>1){
        maxik=0;
        for(int j=0;j<n;++j){
            if(ile[j]>maxik){
                maxik=ile[j];
                gdz=j;
            }
        }
        int i=gdz;
        int temp=0;
        int temp1=0;

            int itl=i-1;
            while(ile[itl]>=maxik-1){
                itl--;
            }
            temp=i-itl;
            int itp=i+1;
            while(ile[itp]>=maxik-1){
                itp++;
            }
            temp1=itp-i;
            wynik+=min(temp,temp1);
            if(temp<temp1){
                ile[itl]++;
                if(itl-n>=0){
                    ile[itl-n]++;
                }
                ile[itl+n]++;
                ile[itl+2*n]++;
            }else{
                ile[itp]++;
                if(itp-n>=0){
                    ile[itp-n]++;
                }
                if(itp-2*n>=0){
                    ile[itp-2*n]++;
                }
                ile[itp+n]++;
                ile[itp+2*n]++;
            }
            ile[i]--;
            maxik=0;
            for(int j=0;j<n;++j){
            if(ile[j]>maxik){
                maxik=ile[j];
                gdz=j;
            }
        }
    }
    printf("%d",wynik);
    return 0;
}
