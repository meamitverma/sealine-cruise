#include <bits/stdc++.h>
#include <queue>
 
using namespace std;
class Ticket
{
private:
    string PNR;
    string name;
    string departure_city;
    string arrival_city;
    int departure_time; // cruise id addition is left.
    int arrival_time;
    string cabin; // may be economy class or business class or normal seating.
    int price;
    string seatNo;
 
    Passenger passenger;
 
    // for economy 3000, for seating 2000, for business 5000 per seat.
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
 
    void setPassenger(Passenger p) { passenger = p; }
 
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
 
    int getPrice() { return this->price; }
 
    void displayTicket()
    {
        cout << "********************************************" << endl;
        cout << "*          Passenger Ticket Details         *" << endl;
        cout << "********************************************" << endl;
        cout << "* Passenger name: " << setw(31) << left << passenger.getName() << " *" << endl;
        cout << "* PNR number: " << setw(37) << left << getPNR() << " *" << endl;
        cout << "* Seat number: " << setw(36) << left << getSeatNo() << " *" << endl;
        cout << "* From: " << setw(41) << left << getDeptCity() << " *" << endl;
        cout << "* To: " << setw(43) << left << getArrivalCity() << " *" << endl;
        cout << "* Departure Time: " << setw(31) << left << getDeptTime() << " *" << endl;
        cout << "* Arrival Time: " << setw(33) << left << getArrivalTime() << " *" << endl;
        cout << "* Cabin type: " << setw(37) << left << getCabin() << " *" << endl;
        cout << "* Total price: Rs." << setw(32) << left << getPrice() << " *" << endl;
        cout << "********************************************" << endl;
    }
 
    // book ticket
    bool bookTicket(string cruiseID, SeatType type, int seatno)
    {
        Cruise *cruise = &cruises[cruiseID];
        int seatcount;
        string cur_cabin = getCabin(type);
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
        setDeptCity(cruise->getDepartureCity());
        setArrivalCity(cruise->getArrivalCity());
        setArrvialTime(cruise->getArrivalTime());
        setDEptTime(cruise->getDepartureTime());
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
 
        // Extracting SeatType and seat number from seatNo
        SeatType type;
        int seatNumber;
        extractSeatInfo(seatNo, type, seatNumber);
 
        Cruise cruise = cruises[cruiseID];
 
        if (type == Economy)
        {
            cruise.cancelEconomySeat(seatNumber);
            cruise.setEconomySeatCount(cruise.getEconomySeatCount() + 1);
        }
        else if (type == Business)
        {
            cruise.cancelBusinessSeat(seatNumber);
            cruise.setBusinessSeatCount(cruise.getBusinessSeatCount() + 1);
        }
        else if (type == Seating)
        {
            cruise.cancelSeatingSeat(seatNumber);
            cruise.setSeatingSeatCount(cruise.getSeatingSeatCount() + 1);
        }
 
        // Reset ticket information
        PNR = "00000";
        // name = "N/A";
        departure_city = "N/A";
        arrival_city = "N/A";
        departure_time = 0000;
        arrival_time = 0000;
        cabin = "N/A";
        price = 00;
        seatNo = "00";
 
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