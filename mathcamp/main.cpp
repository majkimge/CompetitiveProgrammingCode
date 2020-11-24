#include <bits/stdc++.h>

using namespace std;

int a;
double wyn;


double rzut(int kt){
    int ter=0;
    for(int i=0;i<kt;++i){
        ter+=rand()%6+1;
    }
    if(ter%2==0){
        return rzut(kt+1);
    }else{
        return (double)ter;
    }
}

int main()
{
    cout<<(1|2016);
    return 0;
}
