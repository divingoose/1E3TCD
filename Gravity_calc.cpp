#include <iostream>
#include <iomanip> //unused in this version!! Use setprecision if desired.
#include <cmath>

using namespace std;

//****CALCULATES THE GRAVITATIONAL FORCE BETWEEN 2 BODIES****
//DEBUGGED AND WORKKING
//DOES NOT USE A CONSTANT FOR THE G VALUE AS REQUESTED IN PRACTICAL!!!

int calculate(double mass1, double mass2, double dist);

int main() {

//declare variables
	double mass1, mass2, dist;

//initial inputs
		cout << "Enter the mass in Kilos of body 1: \n";
		cin >> mass1;

//while loop (with -1 set as factor to quit)
		while (mass1 != -1) {

            cout << endl << "Enter the mass in Kilos of body 2: \n";
            cin >> mass2;
            cout << endl << "Enter the distance between bodies 1 and 2: \n";
            cin >> dist;

			calculate(mass1, mass2, dist); //runs function below as element of the loop

            cout << endl << "Enter the mass in Kilos of body 1 (or -1 to quit): \n";
            cin >> mass1;

		}


	return 0;
}

//calculation function
int calculate(double mass1, double mass2, double dist) {
	double G;
	double F;
	G = (6.674)*(pow ((10),(-11)));

	//sum
	F = (G*mass1*mass2) / (pow((dist),2));
    cout << F;

	return 0;
}

