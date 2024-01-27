#include <bits/stdc++.h>
using namespace std;

class Ticket
{
private:
    string PNR;
    // string name;
    string departure_city;
    string arrival_city;
    int departure_time; // cruise id addition is left.
    int arrival_time;
    string cabin; // may be economy class or business class or normal seating.
    int price;
    string seatNo;

    Passenger passenger;
    // for economy 3000, for seatign 2000, for business 5000 per seat.
    // add price for each seat type

public:
    Ticket()
    {
        PNR = "00000";
        // name = "N/A";
        departure_city = "N/A";
        arrival_city = "N/A";
        departure_time = 0000;
        arrival_time = 0000;
        cabin = "N/A";
        price = 00;
        seatNo = "00";
    }

    // generate PNR number
    string getPNR()
    {
        return PNR;
    }

    void setPassenger(Passenger p) { passenger = p;}

    // departure city
    void setDeptCity(string deptCity)
    {
        this->departure_city = deptCity;
    }

    string getDeptCity()
    {
        return departure_city;
    }

    void setArrivalCity(string arrivalCity)
    {
        this->arrival_city = arrivalCity;
    }
    string getArrivalCity()
    {
        return arrival_city;
    }

    void setDEptTime(int time)
    {
        this->departure_time = time;
    }

    int getDeptTime()
    {
        return departure_time;
    }

    void setArrvialTime(int arrivalTime)
    {
        this->arrival_time = arrivalTime;
    }

    int getArrivalTime()
    {
        return arrival_time;
    }

    void setCabin(string cabin)
    {
        this->cabin = cabin;
    }

    string getCabin()
    {
        return cabin;
    }

    void setPrice(int pp)
    { // if someone updraged the booking then you can also set the price for each type of booking class
        this->price = pp;
    }

    void setSeatNo(string seatno)
    {
        this->seatNo = seatno;
    }

    string getSeatNo()
    {
        return seatNo;
    }

    int getPrice() { return this->price;}

    void displayTicket()
    {
        cout << "Passenger name: " << passenger.getName() << endl;
        cout << "PNR number: " << getPNR() << endl;
        cout << "Seat number: " << getSeatNo() << endl;
        cout << "From: " << getDeptCity() << endl;
        cout << "To: " << getArrivalCity() << endl;
        cout << "Departure Time: " << getDeptTime() << endl;
        cout << "Arrival Time: " << getArrivalTime() << endl;
        cout << "Cabin type: " << getCabin() << endl;
        cout << "Total price: Rs." << getPrice() << endl;
    }


    // book ticket 
    bool bookTicket(string cruiseID, SeatType type, int seatno) {
        Cruise cruise = cruises[cruiseID];
        int seatcount;
        string cur_cabin = getCabin(type);
        if (type == Economy) {
            seatcount = cruise.getEconomySeatCount();
            cruise.setEconomySeatCount(seatcount - 1);
            bool status = cruise.bookEconomySeat(seatno);
            if (!status) return false;
            this->price = cruise.getEconomyPrice();
        }
        else if (type == Business) {
            seatcount = cruise.getBusinessSeatCount();
            cruise.setBusinessSeatCount(seatcount - 1);
            bool status = cruise.bookBusinessSeat(seatno);
            if (!status) return false;
            this->price = cruise.getBusinessPrice();
        }
        else if (type == Seating) {
            seatcount = cruise.getSeatingSeatCount();
            cruise.setSeatingSeatCount(seatcount - 1);
            bool status = cruise.bookSeatingSeat(seatno);
            if (!status) return false;
            this->price = cruise.getSeatingPrice();
        }

        // if successful
        PNR = generatePNR();
        setDeptCity(cruise.getDepartureCity());
        setArrivalCity(cruise.getArrivalCity());
        setArrvialTime(cruise.getArrivalTime());
        setDEptTime(cruise.getDepartureTime());
        setCabin(cur_cabin);
        setSeatNo(cur_cabin[0] + to_string(seatno));
        return true;
    }

    string getCabin(SeatType type) {
        if (type == Economy) return "Economy";
        else if (type == Business) return "Business";
        else if (type == Seating) return "Seating";
        return "NULL";
    }
    string generatePNR() {
        return "SLNK" + to_string(rand() % 1000);
    }
};
