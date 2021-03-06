//Functions for Pratical 8 - 2014

#include <iostream>
using namespace std;

int month_length (int m, int y);
int year_length (int y);
bool leap_year (int year);
int daynumber (int day, int month, int year);
void dayMthYr (int numdays, int& day, int& month, int& year);
int day, month, year, numdays;

int main ()
{
    //Write code here to test dayMthYr by converting a date to daynumber
    cout << "Enter a date in the format dd mm yyyy: \n";
    cin >> day >> month >> year;
    cout << "The daynumber for the date entered is: " << dayMthYr(numdays, day, month, year);
    //and then using dyMthYr to convert it back, and checking if the
    // resulting day, month and year are what you started with; but be careful
    //not to let dayMthYr overwrite the values provided by the user.



    //Write code here to test the calc_date function


    return 0;
}


void dayMthYr (int numdays, int& day, int& month, int& year)
{
    //a dummy definition - should be replaced with your code to do the job.
    //if numdays were 1, this would do -
    day=1; month=1; year=1900;
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
