#include <iostream>

using namespace std;

int tab [10];
int szukaj;
int s;
int n;


void binSearch(int tab[],int n,int szuk){
int l=0;
bool jest=false;
    int p=n-1;
    int s=(p-l)/2;
    while(l!=p){

        if(tab[s]<szukaj){

            l=s+1;
            s=l+(p-l)/2;
        }else if(tab[s]>szukaj){
            p=s-1;
            s=p-(p-l)/2;
        }
        if(tab[s]==szukaj){
            cout<<s+1;
            jest=true;
            l=p;
        }
    }
    if(!jest){
        cout<<"NIE MA";
    }
}
int main()
{
    cin>>n;
    int tab [n];
    for (int i=0;i<n;i++){
        cin>>tab[i];
    }
    cin>>szukaj;
    binSearch(tab,n,szukaj);

    return 0;
}
