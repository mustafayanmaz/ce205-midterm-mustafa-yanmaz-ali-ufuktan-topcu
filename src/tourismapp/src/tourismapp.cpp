#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class TourProgramManagement {
private:
    vector<string> destinations;
    vector<string> activities;

public:
    void AddDestination(const string& destination) {
        destinations.push_back(destination);
        cout << "Added destination: " << destination << endl;
        SaveDestinationsToFile(destinations, "destinations.txt"); // Verileri kaydet
    }
    void SaveDestinationsToFile(const vector<string>& destinations, const string& fileName) {
        ofstream file(fileName);
        if (file.is_open()) {
            for (const string& destination : destinations) {
                file << destination << endl;
            }
            file.close();
            cout << "Destinations have been saved to '" << fileName << "'." << endl;
        }
        else {
            cerr << "Failed to open the file for writing." << endl;
        }
    }


    void TourProgramManagement::UpdateDestination(int index, const string& newDestination) {
        if (index >= 0 && index < destinations.size()) {
            string oldDestination = destinations[index];
            destinations[index] = newDestination;
            cout << "Updated destination at index " << index << ": " << oldDestination << " -> " << newDestination << endl;
            SaveDestinationsToFile(destinations, "destinations.txt"); // Verileri kaydet
        }
        else {
            cout << "Invalid index. Update failed." << endl;
        }
    }


    void DeleteDestination(int index) {
        if (index >= 0 && index < destinations.size()) {
            cout << "Deleted destination at index " << index << ": " << destinations[index] << endl;
            destinations.erase(destinations.begin() + index);
        }
        else {
            cout << "Invalid index. Deletion failed." << endl;
        }
    }

    void CategorizeByDestination() {
        cout << "Destinations:\n";
        for (const string& destination : destinations) {
            cout << destination << endl;
        }
    }

    void CategorizeByActivity() {
        cout << "Activities:\n";
        for (const string& activity : activities) {
            cout << activity << endl;
        }
    }
};

void tourProgramManagementMenu() {
    TourProgramManagement tourManager;
    int choice;
    do {
        cout << "Tour and Package Program Management\n";
        cout << "1. Add Destination\n";
        cout << "2. Update Destination\n";
        cout << "3. Delete Destination\n";
        cout << "4. Categorize by Destination\n";
        cout << "5. Categorize by Activity\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            string newDestination;
            cout << "Enter the destination to add: ";
            cin >> newDestination;
            tourManager.AddDestination(newDestination);
        }
        break;
        case 2:
        {
            int index;
            string newDestination;
            cout << "Enter the index of the destination to update: ";
            cin >> index;
            cout << "Enter the new destination: ";
            cin >> newDestination;
            tourManager.UpdateDestination(index, newDestination);
        }
        break;
        case 3:
        {
            int index;
            cout << "Enter the index of the destination to delete: ";
            cin >> index;
            tourManager.DeleteDestination(index);
        }
        break;
        case 4:
            tourManager.CategorizeByDestination();
            break;
        case 5:
            tourManager.CategorizeByActivity();
            break;
        case 0:
            cout << "Returning to Main Menu...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
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
        }
    } while (choice != 0);

    return 0;
}