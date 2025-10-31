// (Airline Reservations System) A small airline has just purchased a computer
// for its new au- tomated reservations system. You’ve been asked to program the
// new system. You are to write a pro- gram to assign seats on each flight of
// the airline’s only plane (capacity: 10 seats). Your program should display
// the following menu of alternatives—Please type 1 for "First Class" and Please
// type 2 for "Economy". If the person types 1, your program should assign a
// seat in the first class section (seats 1–5). If the person types 2, your
// program should assign a seat in the economy section (seats 6–10). Your
// program should print a boarding pass indicating the person’s seat number and
// whether it’s in the first class or economy section of the plane. Use a
// one-dimensional array to represent the seating chart of the plane. Initialize
// all the ele- ments of the array to false to indicate that all seats are
// empty. As each seat is assigned, set the cor- responding elements of the
// array to true to indicate that the seat is no longer available. Your program
// should, of course, never assign a seat that has already been assigned. When
// the first class section is full, your program should ask the person if it’s
// acceptable to be placed in the economy section (and vice versa). If yes, then
// make the appropriate seat assignment. If no, then print the message "Next
// flight leaves in 3 hours."

#include <iostream>

using namespace std;

int findAvailability(int option, const bool seats[]) {
    int filled = 0;
    for (int i = (5 * (option - 1)); i < 5 * option; i++) {
        if (seats[i] == true) {
            filled += 1;
        } else {
            return i;
        }
    }
    if (filled == 5) {
        return -1;
    }

    return -1;
}

int bookTicket(int option, bool seats[]) {
    int seatNumber = findAvailability(option, seats);

    if (seatNumber != -1) {
        seats[seatNumber] = true;
    }

    return seatNumber;
}

void printConfirmationMessage(int seat, string preference) {
    cout << "Your seat number " << seat << " in " << preference
         << " class is confirmed" << endl;
}

char getSecondPreferenceConfirmation(string firstPreference,
                                     string secondPreference) {
    char confirmation;

    cout << " All seats in " << firstPreference
         << " are filled. Would you like to book " << secondPreference
         << "(y/N) " << endl;
    cin >> confirmation;
    return confirmation;
}
void handleBooking(int option, bool seats[], string firstPreference,
                   string secondPreference) {
    char confirmSecondPreference = 'n';
    int ticket = bookTicket(option, seats);
    if (ticket != -1) {
        printConfirmationMessage(ticket + 1, firstPreference);
    } else {
        confirmSecondPreference =
            getSecondPreferenceConfirmation(firstPreference, secondPreference);
        if (confirmSecondPreference == 'y') {
            ticket = bookTicket(3 - option, seats);
            if (ticket != -1) {
                printConfirmationMessage(ticket + 1, secondPreference);
            } else {
                cout << secondPreference << " class is fully booked. Sorry!"
                     << endl;
            }
        } else {
            cout << "Next flight leaves in 3 hours" << endl;
        }
    }
}

int main() {
    const int seatingCapacity = 10;
    bool seats[seatingCapacity] = {false, false, false, false, false,
                                   true,  true,  true,  true,  true};
    int option;

    cout << "Airline Reservation System" << endl << endl;
    cout << "1. First Class" << endl;
    cout << "2. Second Class" << endl;
    cout << "Select your option: ";
    cin >> option;

    switch (option) {
    case 1:
        handleBooking(option, seats, "First", "Economy");

        break;
    case 2:
        handleBooking(option, seats, "Economy", "First");
        break;
    default:
        cout << "Invalid Option. Please select either 1 or 2" << endl;
        break;
    }

    cout << "\nSeats Details " << endl;
    for (int i = 0; i < seatingCapacity; i++) {
        cout << seats[i] << "   ";
    }
    return 0;
}
