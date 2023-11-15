#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "../../tourism/src/tourism.cpp"
using namespace std;


void printArt() {
    cout << "--------------------------------------------------------------------------------------------- " << endl;
    cout << " |   ######   #####   ##   ##   #####      ##     ######   ######            #####    ######  |" << endl;
    cout << " |     ##    ##   ##  ##   ##  ##   ##     ##    ##       ## ## ##          ##   ##  ##       |" << endl;
    cout << " |     ##    ##   ##  ##   ##  ## ###      ##     #####   ## ## ##          ## ####  ## ###   |" << endl;
    cout << " |     ##    ##   ##  ##   ##  ##   ##     ##         ##  ## ## ##          ##   ##  ##       |" << endl;
    cout << " |     ##     #####    #####   ##   ##     ##    ######   ## ## ##          ##   ##  ##       |" << endl;
    cout << "--------------------------------------------------------------------------------------------- " << endl;
    cout << endl;

}
int tourProgramManagementMenu() {
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
    return 0;
}
int reporting() {
    DoubleLinkedList popularDestinationsList;
    DoubleLinkedList seasonalTrendsList;
    DoubleLinkedList clientFeedbackList;

    while (true) {
        cout << "Reporting Menu\n";
        cout << "1. Popular Destinations\n";
        cout << "2. Seasonal Trends\n";
        cout << "3. Client Feedback\n";
        cout << "0. Back to Main Menu\n";

        int choice;
        cout << "Please Select: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Popular Destinations
            popularDestinationsList.addNode("Mugla");
            popularDestinationsList.addNode("Mersin");
            popularDestinationsList.addNode("Nevsehir");
            popularDestinationsList.addNode("Antalya");
            popularDestinationsList.addNode("Kayseri");
            popularDestinationsList.addNode("Trabzon");

            popularDestinationsList.printList();
            break;
        case 2:
            // Seasonal Trends
            seasonalTrendsList.addNode("Ski");
            seasonalTrendsList.addNode("Baloon");
            seasonalTrendsList.addNode("SnowBoard");
            seasonalTrendsList.addNode("IceSkate");
            seasonalTrendsList.addNode("Doing the homework given by professor Ugur");

            seasonalTrendsList.printList();
            break;
        case 3:
            // Client Feedback       
            clientFeedbackList.addNode("Excellent service! The staff was very friendly and accommodating.");
            clientFeedbackList.addNode(" We had an amazing time on the tour. The itinerary was well-planned.");
            clientFeedbackList.addNode("The tour package offered great value for the money.");
            clientFeedbackList.addNode("The transportation arrangements were convenient and comfortable.");
            clientFeedbackList.addNode("Knowledgeable guides made the trip informative and enjoyable.");
            clientFeedbackList.addNode("The variety of activities provided a well-rounded experience");
            clientFeedbackList.printList();
            break;
        case 0:
            // Ana Menüye Dön
            return 0;
        default:
            cout << "Invalid selection!\n";
        }
        
    }
}
int vehicleAssignmentsMenu(TourProgramManagement& tourManager) {
    int vehicleChoice;

    do {
        cout << "\nVehicle Assignments Menu:\n";
        cout << "1- Add Vehicle\n";
        cout << "2- Assign to Vehicle\n";
        cout << "0- Return to Guide and Transportation Menu\n";
        cout << "Enter your choice: ";
        cin >> vehicleChoice;

        switch (vehicleChoice) {
        case 1:
            // Add Vehicle
            tourManager.addVehicle();
            break;
        case 2:
            // Assign to Vehicle
            tourManager.assignToVehicle();
            break;
        case 0:
            // Return to Guide and Transportation Menu
            cout << "Returning to Guide and Transportation Menu.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    } while (vehicleChoice != 0);
    return -2;
}
int guideAssignmentsMenu(TourProgramManagement& tourManager) {
    int guideChoice;

    do {
        cout << "\nGuide and Trasnportation Records Menu:\n";
        cout << "1- Add Guide\n";
        cout << "2- Assign Guide to Tour\n";
        cout << "0- Return to Guide and Transportation Menu\n";
        cout << "Enter your choice: ";
        cin >> guideChoice;

        switch (guideChoice) {
        case 1:
            // Add Vehicle
            tourManager.addGuide();
            break;
        case 2:
            // Assign to Vehicle
            tourManager.assignToGuide();
            break;
        case 0:
            // Return to Guide and Transportation Menu
            cout << "Returning to Guide and Transportation Menu.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    } while (guideChoice != 0);
    return -2;
}



int guideAndTransportationPlanning() {
    TourProgramManagement tourManager;  // TourProgramManagement sınıfından bir nesne oluşturuyoruz.

    int choice;
    do {
        cout << "Guide and Transportation Planning Menu\n";
        cout << "1-Itineraries\n";
        cout << "2-Vehicle Assignments\n";
        cout << "3-Guide Training Records\n";
        cout << "0-Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Returning to the main menu...\n";
            break;
        case 1:
            tourManager.Itineraries();
            break;
        case 2:
            // Vehicle Assignments işlemleri eklenecek (istenildiğinde).
            vehicleAssignmentsMenu(tourManager);
            break;
        case 3:
            // Guide Training Records işlemleri eklenecek (istenildiğinde).
            guideAssignmentsMenu(tourManager);
            break;
       
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 0);
    return 0;
}






//**************************************************************************************************



int customerAssignmentsMenu(TourProgramManagement& tourManager) {
    int customerChoice;

    do {
        cout << "\nCustomer Assignments Menu:\n";
        cout << "1- Add Customer\n";
        cout << "2- Assign Customer to Tour\n";
        cout << "0- Return to Client Reservation and Payment Tracking Menu\n";
        cout << "Enter your choice: ";
        cin >> customerChoice;

        switch (customerChoice) {
        case 1:
            // Add Vehicle
            tourManager.addCustomer(); //********************
            break;
        case 2:
            // Assign to Vehicle
            tourManager.assignToCustomer();
            break;
        case 0:
            // Return to Guide and Transportation Menu
            cout << "Returning to Guide and Transportation Menu.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    } while (customerChoice != 0);
    return 0;
}


int tripAssignmentsMenu(TourProgramManagement& tourManager) {
    int tripChoice;

    do {
        cout << "\nCustomer Assignments Menu:\n";
        cout << "1- Add Trip\n";
        cout << "2- Assign Trip to Tour\n";
        cout << "0- Return to Client Reservation and Payment Tracking Menu\n";
        cout << "Enter your choice: ";
        cin >> tripChoice;

        switch (tripChoice) {
        case 1:
            // Add Vehicle
            tourManager.addTrip(); //********************
            break;
        case 2:
            // Assign to Vehicle
            tourManager.assignToTrip();
            break;
        case 0:
            // Return to Guide and Transportation Menu
            cout << "Returning to Guide and Transportation Menu.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    } while (tripChoice != 0);
    return 0;
}
int clientReservationAndPaymentTracking() {
    TourProgramManagement tourManager;  // TourProgramManagement sınıfından bir nesne oluşturuyoruz.

    int choice;
    do {
        cout << "Client Reservation And Payment Tracking Menu\n";
        cout << "1-Booking Confirmations\n";
        cout << "2-Trip Customization \n";
        
        cout << "0-Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Returning to the main menu...\n";
            break;
        case 1:
            customerAssignmentsMenu(tourManager);
            
            break;
        case 2:
            // Vehicle Assignments işlemleri eklenecek (istenildiğinde).
            tripAssignmentsMenu(tourManager);
            break;
       
        
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 0);
    return -2;
}

//*************************************************************************************

int integrations() {
    cout << "Integrations Menu\n";
    int choice;
    do {
        cout << "1- Currency Conversion\n";
        cout << "0- Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            currencyConversionMenu();
            break;
        case 0:
            cout << "Returning to the Main Menu.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    } while (choice != 0);
    return -2;
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