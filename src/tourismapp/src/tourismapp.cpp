#include <iostream>

using namespace std;

void tourProgramManagement() {
    cout << "Tour and Package Program Management Menu\n";
    // Tur ve paket program yönetimi işlemleri burada gerçekleştirilebilir
}

void clientReservationAndPaymentTracking() {
    cout << "Client Reservation and Payment Tracking Menu\n";
    // Müşteri rezervasyon ve ödeme takibi işlemleri burada gerçekleştirilebilir
}

void guideAndTransportationPlanning() {
    cout << "Guide and Transportation Planning Menu\n";
    // Rehber ve ulaşım planlama işlemleri burada gerçekleştirilebilir
}

void reporting() {
    cout << "Reporting Menu\n";
    // Raporlama işlemleri burada gerçekleştirilebilir
}

void integrations() {
    cout << "Integrations Menu\n";
    // Entegrasyon işlemleri burada gerçekleştirilebilir
}

int main() {
    int choice;
    do {
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
            tourProgramManagement();
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
        }
    } while (choice != 0);

    return 0;
}