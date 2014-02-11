/*Program to assist investors in their investment decisions by 
displaying a table of reutrn on investments at different rates*/

#include <iostream>
#include <iomanip>
#include <cmath>  //for power function
using namespace std;

int main () {
	
	double initial_investment, i, j, range_i, range_j, step_i, step_j, invest_return;
	cout << setprecision(2);
	
	cout << "Enter initial investment: ";
	cin >> initial_investment;
	
	cout << "\n Enter the rate range: ";
	cin >> range_j;
	
	cout << "\n Enter desired rate intervals: ";
	cin >> step_j;

	cout << "\n Enter the  year range: ";
	cin >> range_i;

	cout << "\n Enter the desired year intervals: ";
	cin >> step_i;

	//*********************************//
	
	//print table header//
	cout << "Rate ";
	for (i=1; i<=range_i; i=i+step_i)
		{	
			cout << setw(10) << i << "years";
		}
	cout << "\n";
	
	//print a line of --------------//
	for (i=1; i<=58; i++) cout << "-";
	cout << "\n";
		
		
	//the sumz!//
	for (j=1; j<=range_j; j=j+step_j)
		{
			cout << setw(10) << j << " | "; // This is the left hand column
			
			for (i=1; i<=range_i; i=i+step_i)
				{
					cout << setw(10) << (invest_return = pow( (initial_investment * (1+j/100)), i));
				}
			cout << "\n";
		}		
	
	
	
	
	return 0;
}	
