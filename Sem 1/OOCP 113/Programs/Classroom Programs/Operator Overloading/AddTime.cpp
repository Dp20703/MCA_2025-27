#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Time
{
public :
	int Hours;
	int Minutes;
	int Seconds;
	void ShowTime()
	{
		cout << "Time is "<< Hours << " Hours : "<< Minutes << " Minutes : and " << Seconds <<  " Seconds \n";
	}
	Time(int TempHours=0, int TempMinutes=0, int TempSeconds=0)
	{
		Hours = TempHours;
		Minutes = TempMinutes;
		Seconds = TempSeconds;
	}
	Time operator +(Time Time2)
	{
		int TempHours, TempMinutes, TempSeconds;

		TempHours = Hours + Time2.Hours;
		TempMinutes = Minutes + Time2.Minutes;
		TempSeconds = Seconds + Time2.Seconds;

		TempMinutes += TempSeconds/60;
		TempSeconds %= 60;
		TempHours +=TempMinutes/60;
		TempMinutes %= 60;

		return Time(TempHours, TempMinutes, TempSeconds);
	}
};
	
	void main()
	{
		
		Time Time1 (12,15,15);
		cout << "The First Value \n";
		Time1.ShowTime ();

		Time Time2 (10,30,30);
		cout << "The Second Value \n";
		Time2.ShowTime ();	

		Time Time3;
		Time3= Time1 + Time2;
		cout << "And the Result is \n";
		Time3.ShowTime ();
		
		Time Time4 = Time1 + Time2 + Time3;
		Time4.ShowTime();
	}


