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
void reporting() {
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
            return;
        default:
            cout << "Invalid selection!\n";
        }
    }
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