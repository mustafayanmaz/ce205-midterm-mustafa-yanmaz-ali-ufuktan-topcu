#include "../header/tourism.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <sstream>
#include <algorithm> // for std::transform
using namespace std;

using namespace Coruh::Tourism;

class TourProgramManagement {
public:
    struct Tour {
        string name;
        string destination;
        string activity;
        double price;
        int numberOfPeople; // New field for the number of people
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
    int Itineraries() {
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
            return 0;
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
        return 2;
    }

    //*****************************************************************************
    int tripAssignments() {
        int choice;

        do {
            cout << "\nCustomer Assignments Menu:\n";
            cout << "1- Add Trip\n";
            cout << "2- Assign Trip to Tour\n";
            cout << "0- Return to Guide and Transportation Menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addTrip();
                break;

            case 2:
                assignToTrip();
                break;

            case 0:
                // Return to Guide and Transportation Menu
                cout << "Returning to CRAPT Menu.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
            }

        } while (choice != 0);
        return -2;
    }

    int addTrip() {
        string name;
        int price;

        cout << "Enter the Trip Name: ";
        cin.ignore();  // Ignore the newline character left in the buffer
        getline(cin, name);  // Read the entire line, including spaces





        cout << "Enter the Customer Price: ";
        cin >> price;



        ofstream outFile("trip.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Name: " << name << endl;
            outFile << "Price: " << price << endl;

            outFile << "-------------------------\n";
            outFile.close();
            cout << "Trip has been added.\n";
        }
        else {
            cerr << "Failed to open the file for writing.\n";
        }
        return -2;
    }

    int assignToTrip() {
        if (tours.empty()) {
            cout << "No tours available for assignment.\n";
            return 0;
        }

        // Display available tours
        cout << "Available Tours:\n";
        for (size_t i = 0; i < tours.size(); ++i) {
            cout << i + 1 << "-" << tours[i].name << endl;
        }

        // Get user's choice
        int tourChoice;
        cout << "Enter the number of the tour to assign a trip: ";
        cin >> tourChoice;

        // Validate tour choice
        if (tourChoice < 1 || tourChoice > static_cast<int>(tours.size())) {
            cout << "Invalid choice. Assignment failed.\n";
            return 0;
        }

        // Ignore the newline character left in the buffer
        cin.ignore();

        // Display available customers
        vector<string> trips = getAvailableTrips();
        cout << "Trips:\n";
        for (size_t i = 0; i < trips.size(); ++i) {
            cout << i + 1 << "-" << trips[i] << endl;
        }

        // Get user's choice for customer
        int tripChoice;
        cout << "Enter the number of the trip to assign to the tour: ";
        cin >> tripChoice;

        // Validate customer choice
        if (tripChoice < 1 || tripChoice > static_cast<int>(trips.size())) {
            cout << "Invalid choice. Assignment failed.\n";
            return 0;
        }

        // Create and save assignment record
        ofstream outFile("tourandtrip.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Tour: " << tours[tourChoice - 1].name << endl;
            outFile << "Trip: " << trips[tripChoice - 1] << endl;
            outFile << "-------------------------\n";
            outFile.close();
            cout << "Assignment has been made.\n";
        }
        else {
            cerr << "Failed to open the file for writing.\n";
        }
        return 0;
    }


    vector<string> getAvailableTrips() {
        vector<string> trips;
        ifstream file("trip.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                if (line.find("Name: ") == 0) {
                    trips.push_back(line.substr(7));
                }
            }
            file.close();
        }
        else {
            cerr << "Failed to open the file for reading.\n";
        }
        return trips;
    }
    //***********************************************************************+

    int customerAssignments() {
        int choice;

        do {
            cout << "\nCustomer Assignments Menu:\n";
            cout << "1- Add Customer\n";
            cout << "2- Assign Customer to Tour\n";
            cout << "0- Return to Guide and Transportation Menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addCustomer();
                break;

            case 2:
                assignToCustomer();
                break;

            case 0:
                // Return to Guide and Transportation Menu
                cout << "Returning to CRAPT Menu.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
            }

        } while (choice != 0);
        return 0;
    }

    
    int addCustomer() {
        string name, surname, sex;
        int year, id;

        cout << "Enter the Customer Name: ";
        cin.ignore();  // Ignore the newline character left in the buffer
        getline(cin, name);  // Read the entire line, including spaces

        cout << "Enter the Customer Surname: ";
        getline(cin, surname);

        cout << "Enter the Customer Gender: ";
        getline(cin, sex);

        cout << "Enter the Customer Age: ";
        cin >> year;

        cout << "Enter the Customer ID: ";
        cin >> id;

        ofstream outFile("customer.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Name: " << name << endl;
            outFile << "Surname: " << surname << endl;
            outFile << "Gender: " << sex << endl;
            outFile << "Age: " << year << endl;
            outFile << "ID: " << id << endl;
            outFile << "-------------------------\n";
            outFile.close();
            cout << "Customer has been added.\n";
        }
        else {
            cerr << "Failed to open the file for writing.\n";
        }
        return -2;
    }






    int assignToCustomer() {
        if (tours.empty()) {
            cout << "No tours available for assignment.\n";
            return 0;
        }

        // Display available tours
        cout << "Available Tours:\n";
        for (size_t i = 0; i < tours.size(); ++i) {
            cout << i + 1 << "-" << tours[i].name << endl;
        }

        // Get user's choice
        int tourChoice;
        cout << "Enter the number of the tour to assign a customer: ";
        cin >> tourChoice;

        // Validate tour choice
        if (tourChoice < 1 || tourChoice > static_cast<int>(tours.size())) {
            cout << "Invalid choice. Assignment failed.\n";
            return 0;
        }

        // Ignore the newline character left in the buffer
        cin.ignore();

        // Display available customers
        vector<string> customers = getAvailableCustomers();
        cout << "Customers:\n";
        for (size_t i = 0; i < customers.size(); ++i) {
            cout << i + 1 << "-" << customers[i] << endl;
        }

        // Get user's choice for customer
        int customerChoice;
        cout << "Enter the number of the customer to assign to the tour: ";
        cin >> customerChoice;

        // Validate customer choice
        if (customerChoice < 1 || customerChoice > static_cast<int>(customers.size())) {
            cout << "Invalid choice. Assignment failed.\n";
            return 0;
        }

        // Create and save assignment record
        ofstream outFile("tourandcustomer.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Tour: " << tours[tourChoice - 1].name << endl;
            outFile << "Customer:" << customers[customerChoice - 1] << endl;
            outFile << "-------------------------\n";
            outFile.close();
            cout << "Assignment has been made.\n";
        }
        else {
            cerr << "Failed to open the file for writing.\n";
        }
        return 0;
    }


    vector<string> getAvailableCustomers() {
        vector<string> customers;
        ifstream file("customer.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                if (line.find("Name: ") == 0) {
                    customers.push_back(line.substr(7));
                }
            }
            file.close();
        }
        else {
            cerr << "Failed to open the file for reading.\n";
        }
        return customers;
    }




    // Basit bir hash table benzeri veri yapısı
    using CustomerHashTable = unordered_map<string, string>;

    int insertToHashTable(CustomerHashTable& table, const string& key, const string& value) {
        // ID, Name, Surname, Gender, Age bilgilerini almak için stringstream kullanılır
        istringstream iss(value);
        string id, name, surname, gender, age;

        while (iss >> id >> name >> surname >> gender >> age) {
            // Hash tablosuna ekle
            table[key] = "ID: " + id + "\nName: " + name + "\nSurname: " + surname + "\nGender: " + gender + "\nAge: " + age;
        }
        return -2;
    }






    int displayHashTable(const CustomerHashTable& table) {
        for (const auto& entry : table) {
            cout << "Customer ID: " << entry.first << "\n" << entry.second << "\n-------------------------\n";
        }
        return -2;
    }

    int displayCustomers() {
        CustomerHashTable customerTable;
        cout << "Customer List:\n";

        ifstream file("customer.txt");
        if (file.is_open()) {
            string line;
            string currentCustomerID;

            while (getline(file, line)) {
                cout << " " << line << endl;  // Debug amaçlı, bu satırı ekleyin

                if (line.find("ID: ") == 0) {
                    currentCustomerID = line.substr(4);
                    // Debug amaçlı, bu satırı ekleyin
                }
                else {
                    insertToHashTable(customerTable, currentCustomerID, line);
                }
            }

            file.close();


            displayHashTable(customerTable);
        }
        else {
            cerr << "Failed to open the file for reading.\n";
        }
        return -2;
    }


    //***********************************************************
    int vehicleAssignments() {
        int choice;

        do {
            cout << "\nVehicle Assignments Menu:\n";
            cout << "1- Add Vehicle\n";
            cout << "2- Assign to Vehicle\n";
            cout << "0- Return to Guide and Transportation Menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addVehicle();
                break;

            case 2:
                assignToVehicle();
                break;

            case 0:
                // Return to Guide and Transportation Menu
                cout << "Returning to Guide and Transportation Menu.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
            }

        } while (choice != 0);
        return 0;
    }

    int addVehicle() {
        string brand, licensePlate;
        int year, kms;

        cout << "Enter the vehicle brand: ";
        cin >> brand;

        cout << "Enter the vehicle year: ";
        cin >> year;

        cout << "Enter the vehicle kilometers: ";
        cin >> kms;

        cin.ignore();  // Ignore the newline character left in the buffer

        cout << "Enter the vehicle license plate: ";
        getline(cin, licensePlate);  // Read the entire line, including spaces

        ofstream outFile("vehicle.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Brand: " << brand << endl;
            outFile << "Year: " << year << endl;
            outFile << "Kilometers: " << kms << endl;
            outFile << "License Plate: " << licensePlate << endl;
            outFile << "-------------------------\n";
            outFile.close();
            cout << "Vehicle has been added.\n";
        }
        else {
            cerr << "Failed to open the file for writing.\n";
        }
        return 0;
    }

    int assignToVehicle() {
        if (tours.empty()) {
            cout << "No tours available for assignment.\n";
            return 0;
        }

        // Display available tours
        cout << "Available Tours:\n";
        for (size_t i = 0; i < tours.size(); ++i) {
            cout << i + 1 << "-" << tours[i].name << endl;
        }

        // Get user's choice
        int tourChoice;
        cout << "Enter the number of the tour to assign a vehicle: ";
        cin >> tourChoice;

        // Validate tour choice
        if (tourChoice < 1 || tourChoice > static_cast<int>(tours.size())) {
            cout << "Invalid choice. Assignment failed.\n";
            return 0;
        }

        // Display available vehicles
        vector<string> vehicles = getAvailableVehicles();
        cout << "Available Vehicles:\n";
        for (size_t i = 0; i < vehicles.size(); ++i) {
            cout << i + 1 << "-" << vehicles[i] << endl;
        }

        // Get user's choice for vehicle
        int vehicleChoice;
        cout << "Enter the number of the vehicle to assign to the tour: ";
        cin >> vehicleChoice;

        // Validate vehicle choice
        if (vehicleChoice < 1 || vehicleChoice > static_cast<int>(vehicles.size())) {
            cout << "Invalid choice. Assignment failed.\n";
            return 0;
        }

        // Create and save assignment record
        ofstream outFile("tourandvehicle.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Tour: " << tours[tourChoice - 1].name << endl;
            outFile << "Vehicle: " << vehicles[vehicleChoice - 1] << endl;
            outFile << "-------------------------\n";
            outFile.close();
            cout << "Assignment has been made.\n";
        }
        else {
            cerr << "Failed to open the file for writing.\n";
        }
        return -2;
    }

    vector<string> getAvailableVehicles() {
        vector<string> vehicles;
        ifstream file("vehicle.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                if (line.find("Brand: ") == 0) {
                    vehicles.push_back(line.substr(7));
                }
            }
            file.close();
        }
        else {
            cerr << "Failed to open the file for reading.\n";
        }
        return vehicles;
    }





    //************************************************************************







    int guideRecords() {
        int choice;

        do {
            cout << "\nGuide Training Records Menu:\n";
            cout << "1- Add Guide\n";
            cout << "2- Assign Guide to Tour\n";
            cout << "0- Return to Guide and Transportation Menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addGuide();
                break;

            case 2:
                assignToGuide();
                break;

            case 0:
                // Return to Guide and Transportation Menu
                cout << "Returning to Guide and Transportation Menu.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
            }

        } while (choice != 0);
        return 0;
    }

    int addGuide() {
        string name, surname, sex;
        int old, experience;

        cout << "Enter the Guide Name: ";
        cin >> name;

        cout << "Enter the Guide Surname: ";
        cin >> surname;

        cout << "Enter the Gender: ";
        cin >> sex;
        cout << "Enter the Guides Old: ";
        cin >> old;
        cout << "Enter the Guides Experience (year): ";
        cin >> experience;

        ofstream outFile("guide.txt", ios::app);  // Open the file in append mode
        if (outFile.is_open()) {
            outFile << "Name: " << name << endl;
            outFile << "Surname: " << surname << endl;
            outFile << "Gender: " << sex << endl;
            outFile << "Old: " << old << endl;
            outFile << "Experience: " << experience << endl;
            outFile << "-------------------------\n";
            outFile.close();
            cout << "Guide has been added.\n";
            return 0;
        }
        else {
            cerr << "Failed to open the file for writing.\n";
        }
        return 0;
    }



    int assignToGuide() {
        if (tours.empty()) {
            cout << "No tours available for assignment.\n";
            return 0;
        }

        // Display available tours
        cout << "Available Tours:\n";
        for (size_t i = 0; i < tours.size(); ++i) {
            cout << i + 1 << "-" << tours[i].name << endl;
        }

        // Get user's choice
        int tourChoice;
        cout << "Enter the number of the tour to assign a guide: ";
        cin >> tourChoice;

        // Validate tour choice
        if (tourChoice < 1 || tourChoice > static_cast<int>(tours.size())) {
            cout << "Invalid choice. Assignment failed.\n";
            return 0;
        }

        // Display available guides
        vector<string> guides = getAvailableGuides();
        cout << "Available Guides:\n";
        for (size_t i = 0; i < guides.size(); ++i) {
            cout << i + 1 << "-" << guides[i] << endl;
        }

        // Get user's choice for guide
        int guideChoice;
        cout << "Enter the number of the guide to assign to the tour: ";
        cin >> guideChoice;

        // Validate guide choice
        if (guideChoice < 1 || guideChoice > static_cast<int>(guides.size())) {
            cout << "Invalid choice. Assignment failed.\n";
            return 0;
        }

        // Create and save assignment record
        ofstream outFile("tourandguide.txt", ios::app);
        if (outFile.is_open()) {
            outFile << "Tour: " << tours[tourChoice - 1].name << endl;
            // Retrieve guide details
            string guideDetails = getGuideDetails(guides[guideChoice - 1]);
            outFile << "Guide Details: " << guideDetails << endl;
            outFile << "-------------------------\n";
            outFile.close();
            cout << "Assignment has been made.\n";
            return 0;
        }
        else {
            cerr << "Failed to open the file for writing.\n";
        }
        return -2;
    }

    string getGuideDetails(const string& guideName) {
        ifstream file("guide.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                // Find lines starting with "Name: "
                size_t found = line.find("Name: " + guideName);
                if (found != string::npos) {
                    // Include relevant lines for guide details
                    string guideDetails;
                    for (int i = 0; i < 5; ++i) {
                        getline(file, line);
                        guideDetails += line + "\n";
                    }
                    file.close();
                    return guideDetails;
                }
            }
            file.close();
        }
        cerr << "Guide details not found for " << guideName << ".\n";
        return "";
    }


    vector<string> getAvailableGuides() {
        vector<string> guides;
        ifstream file("guide.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                // Find lines starting with "Name: "
                size_t found = line.find("Name: ");
                if (found != string::npos) {
                    // Extract the guide name (skip "Name: " prefix)
                    string guideName = line.substr(found + 6);
                    guides.push_back(guideName);
                }
            }
            file.close();
        }
        else {
            cerr << "Failed to open the file for reading.\n";
        }
        return guides;
    }


    //***********************************************************************



    int AddTour() {
        Tour newTour;

        cout << "Enter the tour name: ";
        cin >> newTour.name;

        cout << "Enter the tour destination: ";
        cin >> newTour.destination;

        cout << "Enter the tour activity: ";
        cin >> newTour.activity;

        cout << "Enter the tour price: ";
        cin >> newTour.price;

        cout << "Enter the number of people: ";
        cin >> newTour.numberOfPeople;

        tours.push_back(newTour);

        cout << "Added tour: " << newTour.name << endl;
        SaveToursToFile(tours, "tours.txt");
        return 0;
    }


    int SaveToursToFile(const vector<Tour>& tours, const string& fileName) {
        ofstream file(fileName);
        if (file.is_open()) {
            for (const Tour& tour : tours) {
                file << "Name: " << tour.name << endl;
                file << "Destination: " << tour.destination << endl;
                file << "Activity: " << tour.activity << endl;
                file << "Price: " << tour.price << endl;
                file << "Number of People: " << tour.numberOfPeople << endl; // Include number of people
                file << endl;
            }
            file.close();
            cout << "Tours have been saved to '" << fileName << "'." << endl;
        }
        else {
            cerr << "Failed to open the file for writing." << endl;
        }
        return -2;
    }


    int UpdateTour() {
        int index;
        string newName, newDestination, newActivity;
        double newPrice;

        if (tours.empty()) {
            cout << "No tours to update." << endl;
            return 0;
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
        return 0;
    }

    int DeleteTour() {
        if (tours.empty()) {
            cout << "No tours to delete." << endl;
            return 0;
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
        return -2;
    }

    int CategorizeByDestination() {
        cout << "Destinations:\n";
        for (const Tour& tour : tours) {
            cout << "-----------------------------------" << endl;
            cout << "THE DESTINATION :" << tour.destination << endl;
            cout << "Tour Name : " << tour.name << endl;
            cout << "Destination : " << tour.destination << endl;
            cout << "Tour Price : " << tour.price << endl;

        }
        return 0;


    }

    int CategorizeByActivity() {
        cout << "Activities:\n";
        for (const Tour& tour : tours) {
            cout << "-----------------------------------" << endl;
            cout << "THE ACTIVITY :" << tour.activity << endl;
            cout << "Tour Name : " << tour.name << endl;
            cout << "Activity : " << tour.destination << endl;
            cout << "Tour Price : " << tour.price << endl;

        }
        return 0;
    }
};






double convertCurrency(double amount, double exchangeRate) {
    return amount * exchangeRate;
}

int currencyConversionMenu() {
    // Exchange rates
    map<string, double> exchangeRates = {
        {"USD", 1.0},         // US Dollar
        {"EUR", 0.85},        // Euro
        {"CNY", 6.43},        // Chinese Yuan
        {"JPY", 114.41},      // Japanese Yen
        {"CHF", 0.92},        // Swiss Franc
        {"TRY", 28.67}         // Turkish Lira (example rate)
        // You can add more currency types as needed
    };

    cout << "Choose the source currency:\n";
    for (const auto& entry : exchangeRates) {
        cout << entry.first << endl;
    }

    string sourceCurrency;
    cout << "Enter the source currency code: ";
    cin >> sourceCurrency;

    // Convert currency code to uppercase
    for (auto& c : sourceCurrency) {
        c = toupper(c);
    }

    auto sourceIt = exchangeRates.find(sourceCurrency);
    if (sourceIt == exchangeRates.end()) {
        cout << "Invalid source currency code." << endl;
        return 0;
    }

    cout << "Enter the amount in " << sourceCurrency << ": ";
    double amount;
    cin >> amount;

    cout << "Choose the target currency:\n";
    for (const auto& entry : exchangeRates) {
        cout << entry.first << endl;
    }

    string targetCurrency;
    cout << "Enter the target currency code: ";
    cin >> targetCurrency;

    // Convert currency code to uppercase
    for (auto& c : targetCurrency) {
        c = toupper(c);
    }

    auto targetIt = exchangeRates.find(targetCurrency);
    if (targetIt == exchangeRates.end()) {
        cout << "Invalid target currency code." << endl;
        return 0;
    }

    double convertedAmount = convertCurrency(amount, targetIt->second / sourceIt->second);
    cout << amount << " " << sourceCurrency << " = " << convertedAmount << " " << targetCurrency << endl;

    return 0;
}


int printPopularDestinations(stack<string>& destinationStack, queue<string>& destinationQueue) {
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
    return -2;
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