
#include <iostream>
#include <string>
using namespace std;

int month_length (int m, int y);
int year_length (int y);
bool leap_year (int year);
int daynumber (int day, int month, int year);
void dayMthYr (int numdays, int& day, int& month, int& year);
int calc_date (int numdays, string op, int change, string type);



int main ()
{
    //Write code here to test dayMthYr by converting a date to daynumber

	int numdays, day, month, year, change;
	string op, type;
	
	cout << "Enter a daynumber and operation in the form: daynum +/- x days/weeks/years: ";
	cin >> numdays >> op >> change >> type;
		
	
	dayMthYr(numdays, day, month, year);
	cout << "The original date was " << day << "/" << month << "/" << year << endl;
	
	numdays = calc_date(numdays, op, change, type);
	dayMthYr(numdays, day, month, year);
	
	cout << "The new date is " << day << "/" << month << "/" << year << endl;
	

    //Write code here to test the calc_date function


    return 0;
}

int calc_date (int numdays, string op, int change, string type)
{
	if  (type == "year" || type == "y" || type == "years" )
		{ 
			int day, month, year;
			dayMthYr(numdays, day, month, year);
			
			if( op == "-")
				year = year - change;
		
			if( op == "+")
				year = year + change;	
			
			numdays = daynumber(day, month, year);
					
		}
			
	else 
	{
	
	int x;
	
	
	if (type == "week" || type == "w" || type == "weeks" )
		x = 7;
		
	
	if ( type == "day" || type == "days" || type == "d" )
		x=1;
		
	if( op == "-")
		numdays = numdays - change*x;
		
	if( op == "+")
		numdays = numdays + change*x;
		
	}	
		
	return numdays;
}


void dayMthYr (int numdays, int& day, int& month, int& year)
{
    //a dummy definition - should be replaced with your code to do the job.
    //if numdays were 1, this would do -
    day=1; month=1; year=1900;
    
    while(numdays > year_length(year))
    {
    	numdays = numdays - year_length(year);
    	year++;
    }
    
    while(numdays > month_length(month, year))
    {
    	numdays = numdays - month_length(month, year);
    	month++;
  	}
  	
  	day = numdays;  	
}


//converts a date to a daynumber
int daynumber (int day, int month, int year)
{
    int y, m, daynumber;
    //accumelate days in all years before the given one
    daynumber = 0;
    for (y = 1900; y < year; y++)
    {
        daynumber = daynumber + year_length (y);
    }

    //in the given year, accumelate days in all months before the given month
    for (m = 1; m < month; m++)
    {
        daynumber = daynumber + month_length(m, year);
    }

    //accumelate all the days in the given month, including the given day
    daynumber = daynumber + day;

    return daynumber;
}


//gives back the number of days in the given month of the given year
int month_length (int m, int y)
{
    if (m==2) 
        if (leap_year(y))
	      return 29;
        else
		return 28;
      
    else if (m==9 || m==4 || m==6 || m==11)  //i.e. September, April, June, or November
        return 30;
    
    else
        return 31;
}


int year_length (int y)
{
    if (leap_year (y)) 
        return 366;

    else
        return 365;
}
    

bool leap_year (int year)
{
    //returns true if year is a leap year
    
    if (year % 4 == 0) //all others are definitely not leap
        if (year < 1583)
            return true;
   
        else //after 1583
            if ((year % 100 == 0) && (year % 400 != 0))   //e.g. 1900
                return false;
            else //e.g. 1904 or 2000
                return true;

    else //not divisible by 4
         return false;
} 
