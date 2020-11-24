#include <stdio.h>
#include <iostream>
using namespace std;



int getPath(int tab[][3], int n, int m, bool zeroMus);
int main()
{
    int n;
    int m;
    scanf("%i",&n);
    scanf("%i",&m);
    int paths[m][3];

    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            scanf("%i",&paths[i][j]);
        }
    }
    if(getPath(paths,n,m,false)>=0){
        printf("%i",getPath(paths,n,m,false));
    }else{
        printf("NIE");
    }
    return 0;
}
int getPath(int tab[][3],int n, int m, bool zeroMus){
    //printf("%i\n",zeroMus);
    int t[1000];
    int ileRoz=0;



    for(int i=0;i<1000;i++){
        t[i]=-1;
    }
    for(int i=0;i<m;i++){

//if(uzyte[i]==0){
        if(tab[i][1]>tab[i][0]){
        if(tab[i][1]==n&&((tab[i][2]==0&&zeroMus==false)||tab[i][2]!=0)){
//cout<<tab[i][1]<<tab[i][2]<<"/n";
        //cout<<zeroMus<<"/n";


            if(tab[i][0]==1){

                    //przebyte[przebytes][0]=tab[i][0];
                    //przebyte[przebytes][1]=tab[i][1];
                    //przebytes++;

                t[i]+=tab[i][2]+1;
                ileRoz++;

            }else{
            if((tab[i][2]==0||zeroMus==true)&&getPath(tab,tab[i][0],m,true)>-1){

                   // przebyte[przebytes][0]=tab[i][0];
                   // przebyte[przebytes][1]=tab[i][1];
                    //przebytes++;

            t[i]+=tab[i][2]+getPath(tab,tab[i][0],m,true)+1;
            ileRoz++;
            }else if((tab[i][2]!=0&&zeroMus!=true)&&getPath(tab,tab[i][0],m,false)>-1){
                //przebyte[przebytes][0]=tab[i][0];
                    //przebyte[przebytes][1]=tab[i][1];
                    //przebytes++;

            t[i]+=tab[i][2]+getPath(tab,tab[i][0],m,false)+1;
            ileRoz++;
            }
            }

        }
        }else if(tab[i][1]<tab[i][0]){
        if(tab[i][0]==n&&((tab[i][2]==0&&zeroMus==false)||tab[i][2]!=0)){




            if(tab[i][1]==1){
                if((tab[i][2]==0&&zeroMus==false)||tab[i][2]!=0){
                    //przebyte[przebytes][0]=tab[i][0];
                    //przebyte[przebytes][1]=tab[i][1];
                    //przebytes++;

                t[i]+=tab[i][2]+1;
                ileRoz++;
                }
            }else{
            if((tab[i][2]==0||zeroMus==true)&&getPath(tab,tab[i][1],m,true)>-1){

                   // przebyte[przebytes][0]=tab[i][0];
                   // przebyte[przebytes][1]=tab[i][1];
                    //przebytes++;


            t[i]+=tab[i][2]+getPath(tab,tab[i][1],m,true)+1;
            ileRoz++;
            }else if((tab[i][2]!=0&&zeroMus!=true)&&getPath(tab,tab[i][1],m,false)>-1){
                //przebyte[przebytes][0]=tab[i][0];
                    //przebyte[przebytes][1]=tab[i][1];
                    //przebytes++;


            t[i]+=tab[i][2]+getPath(tab,tab[i][1],m,false)+1;
            ileRoz++;
            }
            }

        //ileRoz++;
        }
        }
    }
    int najm;

    for(int i=0;i<m;i++){
        if(t[i]!=-1){
            najm=t[i];
            break;
        }
    }

    for(int i=0;i<m;i++){
        if(t[i]!=-1&&t[i]<najm){
            najm=t[i];
        }
    }

    if(ileRoz>0){
        return najm;
    }else{
        return -1;
    }

}
