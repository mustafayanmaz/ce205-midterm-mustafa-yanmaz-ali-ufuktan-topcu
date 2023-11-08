#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class TourProgramManagement {
private:
    struct Tour {
        string name;
        string destination;
        string activity;
        double price;
    };

    vector<Tour> tours;

public:
    void AddTour() {
        Tour newTour;

        cout << "Enter the tour name: ";
        cin >> newTour.name;

        cout << "Enter the tour destination: ";
        cin >> newTour.destination;

        cout << "Enter the tour activity: ";
        cin >> newTour.activity;

        cout << "Enter the tour price: ";
        cin >> newTour.price;

        tours.push_back(newTour);

        cout << "Added tour: " << newTour.name << endl;
        SaveToursToFile(tours, "tours.txt");
    }

    void SaveToursToFile(const vector<Tour>& tours, const string& fileName) {
        ofstream file(fileName);
        if (file.is_open()) {
            for (const Tour& tour : tours) {
                file << "Name: " << tour.name << endl;
                file << "Destination: " << tour.destination << endl;
                file << "Activity: " << tour.activity << endl;
                file << "Price: " << tour.price << endl;
                file << endl;
            }
            file.close();
            cout << "Tours have been saved to '" << fileName << "'." << endl;
        }
        else {
            cerr << "Failed to open the file for writing." << endl;
        }
    }

    void UpdateTour() {
        int index;
        string newTour;

        if (tours.empty()) {
            cout << "No tours to update." << endl;
            return;
        }

        cout << "Select a tour to update:" << endl;
        for (int i = 0; i < tours.size(); i++) {
            cout << i + 1 << ". " << tours[i].name << endl;
        }
        cout << "Enter the number of the tour to update: ";
        cin >> index;

        if (index >= 1 && index <= tours.size()) {
            index--; // Adjust the index to match vector indexing (0-based).

            cout << "Enter the new tour name: ";
            cin >> newTour;

            string oldTour = tours[index].name;
            tours[index].name = newTour;
            cout << "Updated tour at index " << index << ": " << oldTour << " -> " << newTour << endl;
            SaveToursToFile(tours, "tours.txt");
        }
        else {
            cout << "Invalid choice. Update failed." << endl;
        }
    }

    void DeleteTour() {
        if (tours.empty()) {
            cout << "No tours to delete." << endl;
            return;
        }

        cout << "Tours:\n";
        for (int i = 0; i < tours.size(); i++) {
            cout << i + 1 << ". " << tours[i].name << endl;
        }

        int index;
        cout << "Enter the number of the tour to delete: ";
        cin >> index;

        if (index >= 1 && index <= tours.size()) {
            index--; // Adjust the index to match vector indexing (0-based).

            cout << "Deleted tour at index " << index << ": " << tours[index].name << endl;
            tours.erase(tours.begin() + index);
            SaveToursToFile(tours, "tours.txt");
        }
        else {
            cout << "Invalid choice. Deletion failed." << endl;
        }
    }

    void CategorizeByDestination() {
        cout << "Destinations:\n";
        for (const Tour& tour : tours) {
            cout << tour.destination << endl;
        }
    }

    void CategorizeByActivity() {
        cout << "Activities:\n";
        for (const Tour& tour : tours) {
            cout << tour.activity << endl;
        }
    }
};

void tourProgramManagementMenu() {
    TourProgramManagement tourManager;
    int choice;
    do {
        cout << "Tour and Package Program Management\n";
        cout << "1. Add Tour\n";
        cout << "2. Update Tour\n";
        cout << "3. Delete Tour\n";
        cout << "4. Categorize by Destination\n";
        cout << "5. Categorize by Activity\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            tourManager.AddTour();
            break;
        case 2:
            tourManager.UpdateTour();
            break;
        case 3:
            tourManager.DeleteTour();
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
            break;
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
            break;
        }
    } while (choice != 0);

    return 0;
}