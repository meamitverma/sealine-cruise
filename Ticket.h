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

    public:
            Ticket(){
                PNR = "00000";
                name= "N/A";
                departure_city = "N/A";
                arrival_city = "N/A";
                departure_time = "N/A";
                arrival_time = "N/A";
                cabin = "N/A";
            }

            //generate PNR number
            string getPNR(){
                return PNR;
            }
            
            void setName(){
                this->name=name;
            }
            string getName(){
                return name;
            }

            //departure city
            void setDeptCity(){
                this->departure_city=departure_city;
            }

            string getDeptCity(){
                return departure_city;
            }

            void setArrivalCity(){
                this->arrival_city = arrival_city;
            }
            string getArrivalCity(){
                return arrival_city;
            }

            void setArrvialTime(){
                this->arrival_time = arrival_time;
            }

            string getArrivalTime(){
                return arrival_time;
            }
            
            void setCabin(){
                this->cabin=cabin;
            }

            string getCabin(){
                return cabin;
            }
};

