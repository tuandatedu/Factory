#include "travelService.h"
#include "travelServiceFactory.h"

string getTourType(int choice) {
    switch (choice) {
        case 1: return "DaLat";
        case 2: return "SapaHaGiang";
        case 3: return "HaLongTuanChau";
        case 4: return "DaNang";
        case 5: return "PhuQuoc";
        default: return ""; 
    }
}
int main() {
    int choice = -1;
    do {
        cout << "\n====== TOUR BOOKING SYSTEM =====\n";
        cout << "1. Da Lat\n";
        cout << "2. Sapa - Ha Giang\n";
        cout << "3. Ha Long - Tuan Chau\n";
        cout << "4. Da Nang\n";
        cout << "5. Phu Quoc\n";
        cout << "0. Exit\n";
        cout << "Choose a tour: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Thank you for using the tour booking system!\n";
            break;
        }

        string tourType = getTourType(choice);
        if (tourType == "") {
            cout << "Invalid choice! Please try again.\n";
            continue;
        }

        TourFactory factory(tourType);
        TravelService* tour = factory.createService();
        if (! tour) {
            cerr << "Error: creating tour. Please try again.\n";
            continue;
        }

        cout << "\n" << tour->getInfo() << "\n";

        // Booking
        char bookingChoice;
        cout << "Do you want to book this tour? (y/n): ";
        cin >> bookingChoice;

        if (bookingChoice == 'y' || bookingChoice == 'Y') {
            int groupSize;
            cout << "Enter number of people to book: ";
            cin >> groupSize;
            if (groupSize <= 0) {
                cout << "Invalid group size!\n";
            } else if (tour->book(groupSize)) {
                cout << "Booking successful for group of " << groupSize << ".\n";
                cout << "Current group size: " << tour->getInfo() << "\n"; 
            } else {
                cout << "Booking failed! Not enough slots remaining.\n";
            }
        } else {
            continue;
        }
        cout << "---------------------------------------------\n";
        delete tour;
    } while (choice != 0);
    return 0;
}