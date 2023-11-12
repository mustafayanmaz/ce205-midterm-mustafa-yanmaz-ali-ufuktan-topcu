#include "../header/tourism.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stack>
#include <queue>
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
    void Itineraries() {
        // Tur adlarını ekrana yaz
        cout << "Available Tours:\n";
        for (size_t i = 0; i < tours.size(); ++i) {
            cout << i + 1 << "-" << tours[i].name << endl;
        }

        // Kullanıcıdan bir tur seçmesini iste
        int choice;
        cout << "Enter the number of the tour to view its itinerary: ";
        cin >> choice;

        // Seçilen turun index'ini bul
        int tourIndex = choice - 1;

        // Hatalı bir seçim yapıldıysa uyarı ver ve fonksiyondan çık
        if (tourIndex < 0 || tourIndex >= tours.size()) {
            cout << "Invalid choice. Itinerary view failed.\n";
            return;
        }

        // Kullanıcıdan güzergahı al
        string itinerary;
        cout << "Enter the itinerary for " << tours[tourIndex].name << ": ";
        cin.ignore();  // Boşluk karakterlerini temizle
        getline(cin, itinerary);

        // Güzergahı tourismitineraries.txt dosyasına kaydet
        ofstream outFile("tourismitineraries.txt", ios::app);
        if (outFile.is_open()) {
            outFile << choice << "-" << tours[tourIndex].name << endl;
            outFile << "Itinerary: " << itinerary << endl;
            outFile << "-------------------------\n";
            outFile.close();
            cout << "Itinerary for " << tours[tourIndex].name << " has been saved.\n";
        }

        else {
            cerr << "Failed to open the file for writing.\n";
        }
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
            cout << "Destination : " << tour.destination << endl;
            cout << "Tour Price : " << tour.price << endl;

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




void printPopularDestinations(stack<string>& destinationStack, queue<string>& destinationQueue) {
    cout << "Popular Destinations (Stack):\n";
    while (!destinationStack.empty()) {
        cout << destinationStack.top() << endl;
        destinationStack.pop();
    }

    cout << "\nPopular Destinations (Queue):\n";
    while (!destinationQueue.empty()) {
        cout << destinationQueue.front() << endl;
        destinationQueue.pop();
    }
}



void clientReservationAndPaymentTracking() {
    cout << "Client Reservation and Payment Tracking Menu\n";

}

void guideAndTransportationPlanning() {
    TourProgramManagement tourManager;  // TourProgramManagement sınıfından bir nesne oluşturuyoruz.

    int choice;
    do {
        cout << "Guide and Transportation Planning Menu\n";
        cout << "1-Itineraries\n";
        cout << "2-Vehicle Assignments\n";
        cout << "3-Guide Training Records\n";
        cout << "4-Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            tourManager.Itineraries();
            break;
        case 2:
            // Vehicle Assignments işlemleri eklenecek (istenildiğinde).
            cout << "This feature is not implemented yet.\n";
            break;
        case 3:
            // Guide Training Records işlemleri eklenecek (istenildiğinde).
            cout << "This feature is not implemented yet.\n";
            break;
        case 4:
            cout << "Returning to the main menu...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 4);
}
struct Node {
    string data;
    Node* next;
    Node* prev;
};

class DoubleLinkedList {
private:
    Node* head;

public:
    DoubleLinkedList() : head(nullptr) {}

    void addNode(const string& data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void printList() {
        Node* temp = head;
        int index = 1;
        while (temp) {
            cout << index << "-" << temp->data << endl;
            temp = temp->next;
            ++index;
        }
    }
};


void integrations() {
    cout << "Integrations Menu\n";

}