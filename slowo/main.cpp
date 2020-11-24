#include <bits/stdc++.h>

#define lld long long
using namespace std;

string slowo;
bool czy=false;
int a;
int main()
{

    cin>>slowo;
    a=slowo.length();
    for(int i=0;i<a-2;++i){


        if((slowo[i]=='S')&&(slowo[i+1]=='K')&&(slowo[i+2]=='I')){
            czy=true;

        }
    }

    if(czy){
        printf("SPONTANICZNE");
    }else{
        printf("NUDNE");
    }

    return 0;
}
