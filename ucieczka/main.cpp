#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;

int n;
int odp;
bool xpline=false;
bool xlline=false;
bool yuline=false;
bool ydline=false;
bool I=false;
bool II=false;
bool III=false;
bool IV=false;
int xplineDist=0;
int xllineDist=0;
int yulineDist=0;
int ydlineDist=0;
int IDist=0;
int IIDist=0;
int IIIDist=0;
int IVDist=0;

int main()
{
    scanf("%i",&n);
    int wspol[n][2];
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            scanf("%i",&wspol[i][j]);
        }
    }
    for(int i=0;i<n;i++){

            if(wspol[i][0]==0&&wspol[i][1]>0){
                xpline=true;
                xlline=true;
                yuline=true;
                I=true;
                II=true;
                if((wspol[i][1]<yulineDist)||yulineDist==0){
                    yulineDist=wspol[i][1];
                }

            }else if(wspol[i][0]==0&&wspol[i][1]<0){
                xpline=true;
                xlline=true;
                ydline=true;
                III=true;
                IV=true;
                if((ydlineDist!=0&&-wspol[i][1]<(ydlineDist))||ydlineDist==0){
                    ydlineDist=-wspol[i][1];
                }

            }else if(wspol[i][1]==0&&wspol[i][0]<0){
                yuline=true;
                xlline=true;
                ydline=true;
                III=true;
                II=true;
                if((xllineDist!=0&&-wspol[i][0]<xllineDist)||xllineDist==0){
                    xllineDist=-wspol[i][0];
                }

            }else if(wspol[i][1]==0&&wspol[i][0]>0){
                yuline=true;
                xpline=true;
                ydline=true;
                I=true;
                IV=true;
                if((xllineDist!=0&&wspol[i][0]<xplineDist)||xplineDist==0){
                    xplineDist=wspol[i][0];
                }

            }else if(wspol[i][1]>0&&wspol[i][0]>0){
                yuline=true;
                xpline=true;
                I=true;
                if(wspol[i][0]>wspol[i][1]){
                    if((IDist!=0&&wspol[i][0]<IDist)||IDist==0){
                    IDist=wspol[i][0];
                }
                }else{
                    if((IDist!=0&&wspol[i][1]<IDist)||IDist==0){
                    IDist=wspol[i][1];
                }
                }

            }else if(wspol[i][1]>0&&wspol[i][0]<0){
                yuline=true;
                xlline=true;
                II=true;
                if(-wspol[i][0]>wspol[i][1]){
                    if((IDist!=0&&-wspol[i][0]<IDist)||IDist==0){
                    IIDist=-wspol[i][0];
                }
                }else{
                    if((IDist!=0&&wspol[i][1]<IDist)||IDist==0){
                    IIDist=wspol[i][1];
                }
                }

            }else if(wspol[i][1]<0&&wspol[i][0]<0){
                ydline=true;
                xlline=true;
                III=true;
                if(-wspol[i][0]>-wspol[i][1]){
                    if((IDist!=0&&-wspol[i][0]<IDist)||IDist==0){
                    IIIDist=-wspol[i][0];
                }
                }else{
                    if((IDist!=0&&-wspol[i][1]<IDist)||IDist==0){
                    IIIDist=-wspol[i][1];
                }
                }

            }else if(wspol[i][1]<0&&wspol[i][0]>0){
                ydline=true;
                xpline=true;
                IV=true;
                if(wspol[i][0]>-wspol[i][1]){
                    if((IDist!=0&&-wspol[i][0]<IDist)||IDist==0){
                    IVDist=-wspol[i][0];
                }
                }else{
                    if((IDist!=0&&-wspol[i][1]<IDist)||IDist==0){
                    IVDist=-wspol[i][1];
                }
                }

            }


    }
    if(ydline&&yuline&&xpline&&xlline&&I&&II&&III&&IV){
        int temp[8];
        temp[0]=ydlineDist;
        temp[1]=yulineDist;
        temp[2]=xplineDist;
        temp[3]=xllineDist;
        temp[4]=IDist;
        temp[5]=IIDist;
        temp[6]=IIIDist;
        temp[7]=IVDist;
        int najm=0;
        int ktory;
        for(int i=0;i<8;i++){
            //cout<<(temp[i]);
            if((najm==0||temp[i]<najm)&&temp[i]!=0){

                najm=temp[i];
            //cout<<najm;
                ktory=i;
                cout<<ktory;
            }
        }

        if(ktory>=0&&ktory<4){
            int najm1=0;
            int ktory1;
            for(int i=0;i<8;i++){
                if(i==0){
                if((i!=ktory&&i!=6&&i!=7&&(najm1==0||temp[i]<najm1))&&temp[i]!=0){
                    najm1=temp[i];

                    ktory1=i;
                    cout<<ktory1;
                }
            }else if(i==1){
                if((i!=ktory&&i!=4&&i!=5&&(najm1==0||temp[i]<najm1))&&temp[i]!=0){
                    najm1=temp[i];

                    ktory1=i;
                    cout<<ktory1;
                }
            }else if(i==2){
                if((i!=ktory&&i!=4&&i!=7&&(najm1==0||temp[i]<najm1))&&temp[i]!=0){
                    najm1=temp[i];

                    ktory1=i;
                    cout<<ktory1;
                }
            }else if(i==3){
                if((i!=ktory&&i!=6&&i!=5&&(najm1==0||temp[i]<najm1))&&temp[i]!=0){
                    najm1=temp[i];

                    ktory1=i;
                    cout<<ktory1;
                }
            }
            }
            if(ktory<2){
                    cout<<"boja";
                if((ktory+1)==ktory1||(ktory-1)==ktory1){
                    odp=(temp[ktory1]-temp[ktory])/2+temp[ktory];
                    printf("%i",odp);
                }else if(ktory==0&&(ktory1==2||ktory1==3||ktory1==3)){
                         int najm2;
                         if((i!=ktory&&i!=ktory1&&(najm1==0||temp[i]<najm1))&&temp[i]!=0){
                    najm1=temp[i];
                         }
                        }
            }else if(ktory<4){
                //cout<<temp[ktory];
                if((ktory-1)==ktory1||(ktory+1)==ktory1){
                    odp=(temp[ktory1]-temp[ktory])/2+temp[ktory];
                    printf("%i",odp);
                }
            }
        }
            }else{
                printf("Nigdy");
            }
    return 0;
}
