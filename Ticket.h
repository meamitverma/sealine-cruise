#include <bits/stdc++.h>
 
using namespace std;
class Ticket
{
private:
    string PNR;
    // string name;
    // string departure_city;
    // string arrival_city;
    // int departure_time; // cruise id addition is left.
    // int arrival_time;
    string cabin; // may be economy class or business class or normal seating.
    int price;
    string seatNo;
    int seatno_int;
    SeatType type;

    Cruise cruise;
    Passenger passenger;
 
    // for economy 3000, for seating 2000, for business 5000 per seat.
    // add price for each seat type
 
public:
    Ticket()
    {
        PNR = "00000";
        // name = "N/A";
        cabin = "N/A";
        price = 00;
        seatNo = "00";
        seatno_int = -1;
    }
 
    // generate PNR number
    string getPNR()
    {
        return PNR;
    }
 
    void setPassenger(Passenger p) { passenger = p; }
    void setCruise(Cruise c) { cruise = c;}
    void setSeatnoInt(int seat) { seatno_int = seat;}

    int getSeatnoInt() { return seatno_int;}
 
    // departure city
    // void setDeptCity(string deptCity)
    // {
    //     this->departure_city = deptCity;
    // }
 
    // string getDeptCity()
    // {
    //     return departure_city;
    // }
 
    // void setArrivalCity(string arrivalCity)
    // {
    //     this->arrival_city = arrivalCity;
    // }
    // string getArrivalCity()
    // {
    //     return arrival_city;
    // }
 
    // void setDEptTime(int time)
    // {
    //     this->departure_time = time;
    // }
 
    // int getDeptTime()
    // {
    //     return departure_time;
    // }
 
    // void setArrvialTime(int arrivalTime)
    // {
    //     this->arrival_time = arrivalTime;
    // }
 
    // int getArrivalTime()
    // {
    //     return arrival_time;
    // }
 
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
 
    int getPrice() { return this->price; }


    void displayTicket()
    {
        cout << "********************************************" << endl;
        cout << "*          Passenger Ticket Details         *" << endl;
        cout << "********************************************" << endl;
        cout << setw(31)<< left<<setfill(' ') <<"* Passenger name: " << setw(15) << left << passenger.getName() << " *" << endl;
        cout << setw(31) << left << "* PNR number: " << setw(15) << left << getPNR() << " *" << endl;
        cout << setw(31) << left << "* Seat number: " << setw(15) << left << getSeatNo() << " *" << endl;
        cout << setw(31) << left << "* From: " << setw(15) << left << cruise.getDepartureCity() << " *" << endl;
        cout << setw(31) << left << "* To: " << setw(15) << left << cruise.getArrivalCity() << " *" << endl;
        cout << setw(31) << left << "* Departure Time: " << setw(15) << left << cruise.getDepartureTime() << " *" << endl;
        cout << setw(31) << left << "* Arrival Time: " << setw(15) << left << cruise.getArrivalTime() << " *" << endl;
        cout << setw(31) << left << "* Cabin type: " << setw(15) << left << getCabin() << " *" << endl;
        cout << setw(31) << left << "* Total price (in Rs): " << setw(15) << left << getPrice() << " *" << endl;
        cout << "********************************************" << endl;
    }
 
    // book ticket
    bool bookTicket(string cruiseID, SeatType type, int seatno)
    {
        Cruise *cruise = &cruises[cruiseID];
        int seatcount;
        string cur_cabin = getCabin(type);
        this->type = type;
        if (type == Economy)
        {
            seatcount = cruise->getEconomySeatCount();
            cruise->setEconomySeatCount(seatcount - 1);
            bool status = cruise->bookEconomySeat(seatno);
            if (!status)
                return false;
            this->price = cruise->getEconomyPrice();
        }
        else if (type == Business)
        {
            seatcount = cruise->getBusinessSeatCount();
            cruise->setBusinessSeatCount(seatcount - 1);
            bool status = cruise->bookBusinessSeat(seatno);
            if (!status)
                return false;
            this->price = cruise->getBusinessPrice();
        }
        else if (type == Seating)
        {
            seatcount = cruise->getSeatingSeatCount();
            cruise->setSeatingSeatCount(seatcount - 1);
            bool status = cruise->bookSeatingSeat(seatno);
            if (!status)
                return false;
            this->price = cruise->getSeatingPrice();
        }
 
        // if successful
        PNR = generatePNR();
        setCruise(*cruise);
        setSeatnoInt(seatno);
        setCabin(cur_cabin);
        setSeatNo(cur_cabin[0] + to_string(seatno));
        return true;
    }
 
    // ticket cancellation
    void cancelTicket(string cruiseID)
    {
        if (seatNo == "00")
        {
            cout << "Ticket is not booked yet." << endl;
            return;
        }
 
        Cruise *cruise = &cruises[cruiseID];
 
        if (type == Economy)
        {
            cruise->cancelEconomySeat(seatno_int);
            cruise->setEconomySeatCount(cruise->getEconomySeatCount() + 1);
        }
        else if (type == Business)
        {
            cruise->cancelBusinessSeat(seatno_int);
            cruise->setBusinessSeatCount(cruise->getBusinessSeatCount() + 1);
        }
        else if (type == Seating)
        {
            cruise->cancelSeatingSeat(seatno_int);
            cruise->setSeatingSeatCount(cruise->getSeatingSeatCount() + 1);
        }
 
        // Reset ticket information
        PNR = "00000";
        // name = "N/A";
        cabin = "N/A";
        price = 00;
        seatNo = "00";
        seatno_int = -1;
        
        cout << "Ticket canceled successfully." << endl;
    }
 
    void extractSeatInfo(string seatNo, SeatType type, int &seatNumber)
    {
        char cabinCode = seatNo[0];
        if (cabinCode == 'E')
        {
            type = Economy;
        }
        else if (cabinCode == 'B')
        {
            type = Business;
        }
        else if (cabinCode == 'A')
        {
            type = Seating;
        }
 
        seatNumber = stoi(seatNo.substr(1));
    }
 
    string getCabin(SeatType type)
    {
        if (type == Economy)
            return "Economy";
        else if (type == Business)
            return "Business";
        else if (type == Seating)
            return "Seating";
        return "NULL";
    }
    string generatePNR()
    {
        return "SLNK" + to_string(rand() % 1000);
    }

    string getCruiseID() {
        return cruise.getID();
    }
 
    // wailist creation
    void BsWaitlist(string cruiseID, Ticket ticket)
    {
        Cruise cruise = cruises[cruiseID];
        queue<Ticket> waitlist1;
 
        if (cruise.getBusinessSeatCount() == 0)
        {
            waitlist1.push(ticket);
            cout << "Seats unavailable. Passenger added to Business class Waitlist." << endl;
        }
        else if (cruise.getBusinessSeatCount() > 0)
        {
            waitlist1.pop();
            cout << "Your booking is confirmed" << endl;
        }
    }
 
    void EcWaitlist(string cruiseID, Ticket ticket)
    {
        Cruise cruise = cruises[cruiseID];
        queue<Ticket> waitlist2;
        if (cruise.getEconomySeatCount() == 0)
        {
            waitlist2.push(ticket);
            cout << "Seats unavailable. Passenger added to Economy class Waitlist." << endl;
        }
        else if (cruise.getEconomySeatCount() > 0)
        {
            waitlist2.pop();
            cout << "Booking confirmed" << endl;
        }
    }
 
    void geWailist(string cruiseID, Ticket ticket)
    {
        Cruise cruise = cruises[cruiseID];
        queue<Ticket> waitlist3;
        if (cruise.getSeatingSeatCount() == 0)
        {
            waitlist3.push(ticket);
            cout << "Seats unavailable. Passenger added to General class Waitlist." << endl;
        }
        else if (cruise.getSeatingSeatCount() > 0)
        {
            waitlist3.pop();
            cout << "Booking Confirmed." << endl;
        }
    }
};