#include<iostream>

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
                return price;
            }

            void setSeatNo(int seatno){
                this->seatNo = seatno;
            }

            int getSeatNo(){
                return seatNo;
            }

            
};

