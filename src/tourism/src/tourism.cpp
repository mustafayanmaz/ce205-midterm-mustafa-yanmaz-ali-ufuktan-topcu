#include "../header/tourism.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

using namespace Coruh::Tourism;

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
    TourProgramManagement() {
        tours = LoadToursFromFile("tours.txt");
    }

    vector<Tour> LoadToursFromFile(const string& fileName) {
        vector<Tour> tours;
        ifstream file(fileName);
        if (file.is_open()) {
            Tour tour;
            string line;
            while (getline(file, line)) {
                if (line.find("Name: ") == 0) {
                    tour.name = line.substr(6);
                }
                else if (line.find("Destination: ") == 0) {
                    tour.destination = line.substr(13);
                }
                else if (line.find("Activity: ") == 0) {
                    tour.activity = line.substr(10);
                }
                else if (line.find("Price: ") == 0) {
                    tour.price = stod(line.substr(7));
                    tours.push_back(tour);
                }
            }
            file.close();
            cout << "Tours have been loaded from '" << fileName << "'." << endl;
        }
        else {
            cerr << "Failed to open the file for reading." << endl;
        }
        return tours;
    }
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
        string newName, newDestination, newActivity;
        double newPrice;

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
            cin >> newName;

            cout << "Enter the new destination: ";
            cin >> newDestination;

            cout << "Enter the new activity: ";
            cin >> newActivity;

            cout << "Enter the new price: ";
            cin >> newPrice;

            // Store old values for display purposes
            string oldName = tours[index].name;
            string oldDestination = tours[index].destination;
            string oldActivity = tours[index].activity;
            double oldPrice = tours[index].price;

            // Update the tour
            tours[index].name = newName;
            tours[index].destination = newDestination;
            tours[index].activity = newActivity;
            tours[index].price = newPrice;

            // Display the update
            cout << "Updated tour at index " << index << ": " << endl;
            cout << "Name: " << oldName << " -> " << newName << endl;
            cout << "Destination: " << oldDestination << " -> " << newDestination << endl;
            cout << "Activity: " << oldActivity << " -> " << newActivity << endl;
            cout << "Price: " << oldPrice << " -> " << newPrice << endl;  SaveToursToFile(tours, "tours.txt");
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
            cout << "-----------------------------------" << endl;
            cout << "THE DESTINATION :" << tour.destination << endl;
            cout << "Tour Name : " << tour.name << endl;
            cout << "Destination : "<<tour.destination << endl;
            cout <<"Tour Price : "<< tour.price << endl;
            
        }
        
       
    }

    void CategorizeByActivity() {
        cout << "Activities:\n";
        for (const Tour& tour : tours) {
            cout << "-----------------------------------" << endl;
            cout << "THE ACTIVITY :" << tour.activity << endl;
            cout << "Tour Name : " << tour.name << endl;
            cout << "Activity : " << tour.destination << endl;
            cout << "Tour Price : " << tour.price << endl;
            
        }
    }
};



void clientReservationAndPaymentTracking() {
    cout << "Client Reservation and Payment Tracking Menu\n";
    // Müþteri rezervasyon ve ödeme takibi iþlemleri burada gerçekleþtirilebilir
}

void guideAndTransportationPlanning() {
    cout << "Guide and Transportation Planning Menu\n";
    // Rehber ve ulaþým planlama iþlemleri burada gerçekleþtirilebilir
}

void reporting() {
    cout << "Reporting Menu\n";
    // Raporlama iþlemleri burada gerçekleþtirilebilir
}

void integrations() {
    cout << "Integrations Menu\n";
    // Entegrasyon iþlemleri burada gerçekleþtirilebilir
}