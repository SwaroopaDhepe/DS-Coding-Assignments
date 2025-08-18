/*Temperature Tracker:
Write a program for tracking daily temperatures of 3 cities for a week . The program calculates the average temperature for each day and for the week.*/

#include <iostream>
#include <iomanip>
using namespace std;

const int CITIES = 3;
const int DAYS = 7;
const float MIN_TEMP = -50.0;
const float MAX_TEMP = 60.0;

// Function to get validated temperature input
float getValidatedTemperature(int city, int day) {
    float temp;
    while (true) {
        cout << "Enter temperature for City " << city + 1 << ", Day " << day + 1 << ": ";
        cin >> temp;

        if(cin.fail()) {
            cin.clear(); // clear error flags
            cin.ignore(10000, '\n'); // discard input
            cout << "Invalid input. Please enter a numeric temperature value.\n";
        }
        else if (temp < MIN_TEMP || temp > MAX_TEMP) {
            cout << "Temperature must be between " << MIN_TEMP << " and " << MAX_TEMP << ". Try again.\n";
        }
        else {
            break; // valid input
        }
    }
    return temp;
}

void inputTemperatures(float temperature[CITIES][DAYS]) {
    cout << "\nInput temperature data for " << CITIES << " cities and " << DAYS << " days.\n";
    for (int c = 0; c < CITIES; c++) {
        for (int d = 0; d < DAYS; d++) {
            temperature[c][d] = getValidatedTemperature(c, d);
        }
    }
}

void displayTemperatures(const float temperature[CITIES][DAYS]) {
    cout << fixed << setprecision(2);
    cout << "\nTemperature Data & Weekly Averages:\n";
    cout << "Sr.No.\tCity\t";
    for (int d = 0; d < DAYS; d++) {
        cout << "D" << d + 1 << "\t\t";
    }
    cout << "Weekly Avg\n";

    for (int c = 0; c < CITIES; c++) {
        float total = 0;
        cout << c + 1 << "\tCity " << c + 1 << "\t";
        for (int d = 0; d < DAYS; d++) {
            cout << temperature[c][d] << "\t\t";
            total += temperature[c][d];
        }
        cout << total / DAYS << "\n";
    }
}

void displayDailyAverages(const float temperature[CITIES][DAYS]) {
    cout << fixed << setprecision(2);
    cout << "\nDaily Average Temperatures Across All Cities:\n";
    cout << "Day\tAverage\n";
    for (int d = 0; d < DAYS; d++) {
        float dayTotal = 0;
        for (int c = 0; c < CITIES; c++) {
            dayTotal += temperature[c][d];
        }
        cout << d + 1 << "\t" << dayTotal / CITIES << "\n";
    }
}

int main() {
    float temperature[CITIES][DAYS] = {0};
    int choice;

    do {
        cout << "\n=== Temperature Tracker Menu ===\n";
        cout << "1. Input Temperature Data\n";
        cout << "2. Display Temperature Data and Weekly Averages\n";
        cout << "3. Display Daily Average Temperatures\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inputTemperatures(temperature);
                break;
            case 2:
                displayTemperatures(temperature);
                break;
            case 3:
                displayDailyAverages(temperature);
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice, please select again.\n";
        }
    } while (choice != 4);

    return 0;
}
