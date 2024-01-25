#include <iostream>
using namespace std;

void drawCruiseBlueprint(int rows,int seatsPerRow){

    for(int i=0;i<2*seatsPerRow;i++){
        for(int j=0;j<2*seatsPerRow-i-1;j++){
            cout<<" ";
        }
        cout<<"//";
        for(int j=0;j<i;j++){
            cout<<"  ";
        }
        cout<<"\\\\"<<endl;
    }

    for(int i=1;i<=rows;i++){
        cout<<"|";
        for(int j=1;j<=seatsPerRow;j++){
            char seatChar = (j%2==0)? 'o':'x';
            cout<<seatChar<<to_string(i)<<j;
            cout<<" ";
        }
        cout<<"|"<<endl;
    }
    // cout<<"\\____//";
    cout<<"\\\\";
    for(int i=0;i<4*(seatsPerRow);i++){
        cout<<"_";
    }
    cout<<"//"<<endl;
}
