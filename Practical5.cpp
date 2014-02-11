/*Program to assist investors in their investment decisions by 
displaying a table of reutrn on investments at different rates*/

#include <iostream>
#include <iomanip>
#include <cmath>  //for power function
using namespace std;

int main () {
	
	double initial_investment, i, j, range_i, range_j, step_i, step_j, invest_return;
	cout << fixed << setprecision(2);

	cout << "Enter initial investment: ";
	cin >> initial_investment;
	
	cout << "\nEnter the maximum % the rate will reach: "; //range
	cin >> range_j;
	
	cout << "\nEnter desired interval for rate %: ";
	cin >> step_j;

	cout << "\nEnter the  number of years for this investment: "; //range
	cin >> range_i;

	cout << "\nEnter the desired interval for years: ";
	cin >> step_i;


	//*********************************//
	
	//print table header//
	cout << "Rate ";
	for (i=1; i<=range_i; i=i+step_i)
		{	
			cout << setw(10) << i << "years";
		}
	cout << "\n";
		
		
	//the sumz!//
	for (j=0; j<=range_j; j=j+step_j)
		if (j!=0){
			{
				cout << setw(10) << j << " | "; // This is the left hand column
			
				for (i=1; i<=range_i; i=i+step_i)
					{
					cout << setw(10) << (invest_return = pow( (initial_investment * (1+j/100)), i));
					}
				cout << "\n";
				}
			}
	
	
	
	
	return 0;
}	
