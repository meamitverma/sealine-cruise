#include <iostream>
using namespace std;

void drawCruiseBlueprint(int economySeats, int bussinessSeats, int seatingSeats, vector<bool> ec,vector<bool> bc,vector<bool> sc){

    for(int i=0;i<19;i++){
        for(int j=0;j<18-i;j++){
            cout<<" ";
        }
        cout<<"//";
        for(int j=0;j<i;j++){
            cout<<"  ";
        }
        cout<<"\\\\"<<endl;
    }

    // for(int i=1;i<=economySeats;i++){
    //     cout<<"|";
    //     for(int j=1;j<=economySeats;j++){
    //         char seatChar = (j%2==0)? 'o':'x';
    //         cout<<seatChar<<to_string(i)<<j;
    //         cout<<" ";
    //     }
    //     cout<<"|"<<endl;
    // }
    cout<<"|-------------------------------------|"<<endl;
    cout<<"|           Business Class            |"<<endl;
    cout<<"|-------------------------------------|"<<endl;
    //Draw bussiness class seats
    for(int i=0;i<bussinessSeats/3;i++){
        cout<<"| ";
        for(int j=1;j<4;j++){
            char seatChar = (bc[3*i+j-1])? 'x':'o';
            // cout<<seatChar<<3*i+j<<"B"<<"  ";
            cout <<"   "<<seatChar<< setw(3) << setfill('0') << 3*i+j <<"B"<<"    ";
        }
        cout<<"|"<<endl;
    }
    cout<<"|-------------------------------------|"<<endl;
    cout<<"|            Economy Class            |"<<endl;
    cout<<"|-------------------------------------|"<<endl;
    //Draw economy class seats
    for(int i=0;i<economySeats/5;i++){
        cout<<"| ";
        for(int j=1;j<6;j++){
            char seatChar = (ec[5*i+j-1])? 'x':'o';
            // cout<<seatChar<<5*i+j<<"E"<<" ";
            cout <<" "<<seatChar<< setw(3) << setfill('0') << 5*i+j <<"E"<<" ";
        }
        cout<<" |"<<endl;
    }
    cout<<"|-------------------------------------|"<<endl;
    cout<<"|            Seating Class            |"<<endl;
    cout<<"|-------------------------------------|"<<endl;
    //Draw seating class seats
    for(int i=0;i<seatingSeats/6;i++){
        cout<<"| ";
        for(int j=1;j<7;j++){
            char seatChar = (sc[6*i+j-1])? 'x':'o';
            // cout<<seatChar<<6*i+j<<"A"<<" ";
            cout <<seatChar<< setw(3) << setfill('0') << 6*i+j <<"A"<<" ";
        }
        cout<<"|"<<endl;
    }
    cout<<"\\\\";
    for(int i=0;i<35;i++){
        cout<<"_";
    }
    cout<<"//"<<endl;
}
