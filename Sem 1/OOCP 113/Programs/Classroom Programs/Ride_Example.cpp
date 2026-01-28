// Ride Sharing Application (like Uber/Ola)
// Base class Ride with attributes: distance, cost per km.
// Constructors for ride details.
// Overload operators (+ to combine shared rides, < to compare fares).
// Template class RideLog<T> to handle ride details (int distance, float fare, string driverID).
// Inheritance for CarRide, BikeRide, AutoRide.

#include <iostream>
using namespace std;

// base class : ride class
class Ride
{
protected:
    int distance;
    float costperkm;

public:
    Ride(int d = 0, float cpk = 0.0) : distance(d), costperkm(cpk) {}

    virtual float calFare() const
    {
        return (distance * costperkm);
    }
    Ride operator+(const Ride &r)
    {
        int totalDistance = this->distance + r.distance;
        float avgKm = (this->costperkm + r.costperkm) / 2;
        return Ride(totalDistance, avgKm);
    }

    bool operator<(const Ride &r)
    {
        return this->calFare() < r.calFare();
    }

    virtual void displayDetails()
    {
        cout << "\t Ride Distance= " << distance << " km |\t Cost/Km=" << costperkm << "  | \t Total Fare:" << calFare() << endl;
    }
};

// car ride class
class CarRide : public Ride
{
public:
    CarRide(int d, float c) : Ride(d, c) {}
    void displayDetails()
    {
        cout << "  [Car Ride ] \t Ride Distance= " << distance << " km |\t Cost/Km=" << costperkm << "| \t Total Fare:" << calFare() << endl;
    }
};

// bike ride class
class BikeRide : public Ride
{
public:
    BikeRide(int d, float c) : Ride(d, c) {}
    void displayDetails()
    {
        cout << "  [Bike Ride ] \t Ride Distance= " << distance << " km |\t Cost/Km=" << costperkm << "| \t Total Fare:" << calFare() << endl;
    }
};
class AutoRide : public Ride
{
public:
    AutoRide(int d, float c) : Ride(d, c) {}
    void displayDetails()
    {
        cout << "  [Auto Ride ] \t Ride Distance= " << distance << " km |\t Cost/Km=" << costperkm << " | \t Total Fare:" << calFare() << endl;
    }
};

// template class
template <typename T>
class RideLog
{
    T logs[10];
    int count;

public:
    RideLog() { count = 0; }

    // add log
    void addLog(const T &Entry)
    {
        if (count < 10)
        {
            logs[count++] = Entry;
        }
        else
        {
            cout << "\n Log is full....";
        }
    }

    // show logs
    void showLogs(const string &lable)
    {
        cout << "\n Label: " << lable << endl;
        for (int i = 0; i < count; i++)
        {
            cout << logs[i] << endl;
        }
    }
};

// option template class for string
template <>
class RideLog<string>
{
    string logs[10];
    int count;

public:
    RideLog() { count = 0; }

    // add log
    void addLog(const string &Entry)
    {
        if (count < 10)
        {
            logs[count++] = Entry;
        }
        else
        {
            cout << "\n Driver Id  is full....";
        }
    }

    // show logs
    void showLogs(const string &lable)
    {
        cout << "\n Lable: " << lable << endl;
        for (int i = 0; i < count; i++)
        {
            cout << "DriverId: " << logs[i] << endl;
        }
    }
};

int main()
{
    Ride r1(5, 20.20);
    r1.displayDetails();
    CarRide c1(50, 30.20);
    c1.displayDetails();
    BikeRide b1(100, 25.25);
    b1.displayDetails();
    AutoRide a1(100, 5);
    a1.displayDetails();

    RideLog<int> r;
    r.addLog(100);
    r.showLogs("Distance");
    RideLog<string> s;
    s.addLog("1230 SD 283");
    s.showLogs("DirverId");
    RideLog<float> f;
    f.addLog(222.20);
    f.showLogs("Fare");
    return 0;
}