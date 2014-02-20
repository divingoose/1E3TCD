#include <iostream>
#include <iomanip>

using namespace std;

//Lists all primes to user entered n value
//NOT WORKING!!! RETURNS 9 AND MULTIPLES OF 5 ETC.

int main()
{
    int num, i, count, n;
    cout << "Enter max no of range: \n" << endl;
    cin >> n;

    for (num = 1; num <= n; num++) {
        count = 0;

        for (i = 2; i <= num; i++){

            if(num%i == 0)
                count++;
                break;
        }

        if (count ==0) {
        cout << num << setw(3);
        }

    }


    return 0;
}
