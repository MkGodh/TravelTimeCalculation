#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <vector>


using namespace std;
int main() {
    string depTime;
    string arrTime;

    cout << "Please, enter departure time: "; cin >> depTime;
    cout << "Please, enter arrival time: "; cin >> arrTime;

    while (depTime.size() != 5 || arrTime.size() != 5 ||
        !isdigit(depTime[0]) || !isdigit(depTime[1]) || !isdigit(depTime[3]) || !isdigit(depTime[4]) ||
        !isdigit(arrTime[0]) || !isdigit(arrTime[1]) || !isdigit(arrTime[3]) || !isdigit(arrTime[4])
        || depTime[2] != ':' || arrTime[2] != ':') {
        cout << "Wrong values! Repeat your input: " << "\n";
        cin >> depTime;
        cin >> arrTime;
    }

    string depHours = depTime.substr(0, 2);
    string arrHours = arrTime.substr(0, 2);
    string depMinutes = depTime.substr(3, 2);
    string arrMinutes = arrTime.substr(3, 2);

    int dHours = stoi(depHours);
    int aHours = stoi(arrHours);
    int dMinutes = stoi(depMinutes);
    int aMinutes = stoi(arrMinutes);

    int tHours = 0;
    int tMinutes = 0;


    if (dHours < aHours && dMinutes < aMinutes) {
        tHours = aHours - dHours;
        tMinutes = aMinutes - dMinutes;
    }
    else if (aHours < dHours) {
        tHours = (24 - dHours) + aHours;
        tMinutes = aMinutes - dMinutes;
    }
    else if (dHours == aHours) {
        tHours = 24 - 1; 
        tMinutes = aMinutes - dMinutes;
    }
    else {
        tHours = aHours - dHours;
        if (dMinutes > aMinutes) {
            tHours--; 
            tMinutes = 60 - (dMinutes - aMinutes);
        }
        else {
            tMinutes = aMinutes - dMinutes;
        }
    }
    if (tMinutes < 0) {
        tMinutes *= -1;
    }


    cout << "Trip was: " << tHours << " h. " << tMinutes << " min.";
}
