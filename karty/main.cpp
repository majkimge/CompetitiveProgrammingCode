#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MAX 100009
#define INF 1000000009
#define llu unsigned long long

char a[2],b[2];
int war[1000];

using namespace std;

int main()
{

    war[(int)'2']=2;
    war[(int)'3']=3;
    war[(int)'4']=4;
    war[(int)'5']=5;
    war[(int)'6']=6;
    war[(int)'7']=7;
    war[(int)'8']=8;
    war[(int)'9']=9;
    war[(int)'1']=10;
    war[(int)'J']=11;
    war[(int)'D']=12;
    war[(int)'K']=13;
    war[(int)'A']=14;
    scanf("%s",&a);
    scanf("%s",&b);
    if(war[a[0]]<war[b[0]]){
        printf("B");
    }else if(war[b[0]]<war[a[0]]){
        printf("A");
    }else{
        printf("R");
    }

    return 0;
}
