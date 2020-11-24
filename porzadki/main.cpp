#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ksiazki;
    cin >> ksiazki;
    int t[ksiazki + 1];
    bool wartosc[ksiazki + 1];
    int zmienna = 0;
    for(int i = 1; i <= ksiazki; i++)
        {
        cin >> t[i];
        if(t[i] == i){
            wartosc[i] = 1;
            zmienna++;
        }
        else
            wartosc[i] = 0;

        }
    int zamiany;
    cin >> zamiany;
    for(int u = 0; u < zamiany; u++)
    {

        int ruch1, ruch2, pomiedzy = 0;
        cin >> ruch1 >> ruch2;
        int a=wartosc[ruch1];
        int b=wartosc[ruch2];
        int temp=t[ruch2];
        t[ruch2]=t[ruch1];
        t[ruch1]=temp;
        if(t[ruch1]==ruch1&&a==0){
            zmienna++;
            wartosc[ruch1]=1;
        }else if(t[ruch1]!=ruch1&&a==1){
            zmienna--;
            wartosc[ruch1]=0;
        }
        if(t[ruch2]==ruch2&&b==0){
            zmienna++;
            wartosc[ruch2]=1;
        }else if(t[ruch2]!=ruch2&&b==1){
            zmienna--;
            wartosc[ruch2]=0;
        }
        if(zmienna == ksiazki)
            cout << "TAK"<<endl;
        else
            cout << "NIE"<<endl;
    }
}
