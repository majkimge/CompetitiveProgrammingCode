#include <bits/stdc++.h>

using namespace std;

struct litera{
char lit;
int ile;
};
struct tree{
    bool jest;
    tree* wsk[25];
    litera literki[25];
};

litera ileLiter[25];
int n, k;
int tab[200000][2];
char word[200000];
tree head;
int suma=0;
int zmiana(litera litereczki[],tree tre){
    int p=25;
    tree head=tre;
    tree *trev;
    tree newTree;
    for(int i=0;i<25;i++){
        if(litereczki[i].ile>0){
            litereczki[i].ile--;
            trev=head.wsk[i];
            newTree=*trev;
            zmiana(litereczki,newTree);
        }else{
            i--;
        }

    }
    if(p==0){
        suma++;
    }
    return 0;

}
int main()
{
    scanf("%i",&n);
    scanf("%i",&k);
    scanf("%s",word);
    for(int i=0;i<k;i++){
        for(int j=0;j<2;j++){
            scanf("%i",&tab[i][j]);

        }
    }
    for(int z=0;z<k;z++){
         for(int j=0;j<25;j++){
            ileLiter[j].ile=0;
         }
    for(int i=tab[z][0];i<tab[z][1];i++){
        if(word[i]>='a'&&word[i]<='z'){
            ileLiter[word[i]-'a'].ile++;
        }
    }
    zmiana(ileLiter,head);
    printf("%i\n",suma);
    }

    /*for(int i=0;i<25;i++){
        cout<<i;
        cout<<ileLiter[i].ile<<endl;
    }*/



    return 0;
}
