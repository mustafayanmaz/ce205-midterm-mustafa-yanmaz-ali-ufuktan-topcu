#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../../tourism/src/tourism.cpp"
using namespace std;

void printArt() {
    cout << "    ######   #####   ##   ##   #####      ##     ######   ######            #####    ###### " << endl;
    cout << "      ##    ##   ##  ##   ##  ##   ##     ##    ##       ## ## ##          ##   ##  ##   " << endl;
    cout << "      ##    ##   ##  ##   ##  ## ###      ##     #####   ## ## ##          ## ####  ## ### " << endl;
    cout << "      ##    ##   ##  ##   ##  ##   ##     ##         ##  ## ## ##          ##   ##  ## " << endl;
    cout << "      ##     #####    #####   ##   ##     ##    ######   ## ## ##          ##   ##  ## " << endl;
    cout << endl;
}
int main() {
    int choice;
    do {
        printArt();
        cout << "Tourism and Travel Agency Automation\n";
        cout << "1. Tour and Package Program Management\n";
        cout << "2. Client Reservation and Payment Tracking\n";
        cout << "3. Guide and Transportation Planning\n";
        cout << "4. Reporting\n";
        cout << "5. Integrations\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            tourProgramManagementMenu();
            break;
        case 2:
            clientReservationAndPaymentTracking();
            break;
        case 3:
            guideAndTransportationPlanning();
            break;
        case 4:
            reporting();
            break;
        case 5:
            integrations();
            break;
        case 0:
            cout << "Exiting program. Goodbye!";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}