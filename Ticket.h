#include<bits/stdc++.h>

using namespace std;

class Ticket{
    private: 
            string PNR;
            string name;
            string departure_city;
            string arrival_city;
            string departure_time;  //cruise id addition is left.
            string arrival_time;
            string cabin; //may be economy class or business class or normal seating.
            int price;
            int seatNo;
            //for economy 3000, for seatign 2000, for business 5000 per seat.
            //add price for each seat type

    public:
            Ticket(){
                PNR = "00000";
                name= "N/A";
                departure_city = "N/A";
                arrival_city = "N/A";
                departure_time = "N/A";
                arrival_time = "N/A";
                cabin = "N/A";
                price = 00;
                seatNo = 0;
            }

            //generate PNR number
            string getPNR(){
                return PNR;
            }
            
            string getName(){
                return name;
            }

            //departure city
            void setDeptCity(string deptCity){
                this->departure_city=deptCity;
            }

            string getDeptCity(){
                return departure_city;
            }

            void setArrivalCity(string arrivalCity){
                this->arrival_city = arrivalCity;
            }
            string getArrivalCity(){
                return arrival_city;
            }

            void setDEptTime(int time){
                this->departure_time=time;
            }

            string getDeptTime(){
                return departure_time;
            }

            void setArrvialTime(string arrivalTime){
                this->arrival_time = arrivalTime;
            }

            string getArrivalTime(){
                return arrival_time;
            }
            
            void setCabin(string cabin){
                this->cabin=cabin;
            }

            string getCabin(){
                return cabin;
            }

            void setPrice(int pp){ //if someone updraged the booking then you can also set the price for each type of booking class
                this->price=pp;
            }
            int getprice(){
                if(cabin==Business){
                    price = 5000;
                } else if(cabin==Economy){
                    price = 3000;
                } else if(cabin=Seating){
                    price = 2000;
                }
                return price;
            }

            void setSeatNo(int seatno){
                this->seatNo = seatno;
            }

            int getSeatNo(){
                return seatNo;
            }

            void displayTicket(){
                cout<<"Passenger name: "<<getName()<<endl;
                cout<<"PNR number: "<<getPNR()<<endl;
                cout<<"Seat number: "<<getSeatNo();
                cout<<"From: "<<getDeptCity()<<endl;
                cout<<"To: "<<getArrivalCity()<<endl;
                cout<<"Departure Time: "<<getDeptTime()<<endl;
                cout<<"Arrival Time: "<<getArrivalTime()<<endl;
                cout<<"Cabin type: "<<getCabin()<<endl;
                cout<<"Total price: "<<getprice()<<endl;
            }
            
};

