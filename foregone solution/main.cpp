#include <bits/stdc++.h>
#define lld long long

using namespace std;

char s[1009];
char s1[1009];
char s2[1009];
int n,p1,p2,t;

int main()
{
    scanf("%d",&t);
    for(int xd=0;xd<t;++xd){
        scanf("%s",s);
        n=0;
        p2=0;
    while(s[n])++n;
    for(int i=n-1;i>=0;--i){
        if(s[i]=='4'){
            s1[i]='3';
            s2[i]='1';
        }else{
            s1[i]=s[i];
            s2[i]='0';
        }
    }
    while(s2[p2]=='0'){
        p2++;
    }
    printf("Case #%d: ",xd+1);
    for(int i=0;i<n;++i)printf("%c",s1[i]);

        printf(" ");
    for(int i=p2;i<n;++i)printf("%c",s2[i]);
    for(int i=0;i<n;++i)s[i]=s1[i]=s2[i]=0;
        printf("\n");
    }




    return 0;
}
