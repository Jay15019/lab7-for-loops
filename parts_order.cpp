/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Jadiel Ortiz Rodriguez]
 * Lab: 7 - Loops II
 * Description: [What this specific program does]
 * Due Date: [30/septiembre/2026]
 */
#include <iostream>                                      // Provides cin, cout, and endl
#include <iomanip>                                       // Provides fixed and setprecision
using namespace std;                                     // Allows standard-library names without the std:: prefix

int main() {                                             // Starts the program
    int requestCount;                                    // Stores the known number of part requests
    int partChoice;                                      // Stores one menu selection
    int quantity;                                        // Stores the requested quantity for one part
    int validLineCount = 0;                              // Counts requests that have a valid part and quantity
    double unitPrice;                                    // Stores the price selected by the switch
    double lineCost;                                     // Stores the cost of one valid request
    double orderTotal = 0.0;                             // Accumulates all valid line costs
    bool isValidPartChoice;                              // Tracks whether the switch selected a real part

    cout << "Enter number of part requests from 1 to 5: "; // Prompts for the iteration count
    cin >> requestCount;                                 // Reads the first request-count candidate

    while (requestCount < 1 || requestCount > 5) {
        cout << "Invalid request count. Try again: ";
        cin >> requestCount;
    }

    for (int request = 1; request <= requestCount; request++) {
        // TODO: Reset isValidPartChoice to true.
        isValidPartChoice = true;

        cout << "Menu Options:" << endl;
        cout << "1. Cable set - $3.25" << endl;
        cout << "2. Part Fuse pack - $4.50" << endl;
        cout << "3. Connector kit - $1.75" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> partChoice;

        while (partChoice < 1 || partChoice > 3) {
            cout << "Invalid choice. Please enter a number between 1 and 3: ";
            cin >> partChoice;
        }

        switch (partChoice) {
            case 1:
                unitPrice = 3.25;
                cout << "You selected Cable set." << endl;
                break;
            case 2:
                unitPrice = 4.50;
                cout << "You selected Part Fuse pack." << endl;
                break;
            case 3:
                unitPrice = 1.75;
                cout << "You selected Connector kit." << endl;
                break;
            default:
                isValidPartChoice = false;
                cout << "Invalid part selection." << endl;
        }

        if (isValidPartChoice) {
            cout << "Enter quantity for the selected part: ";
            cin >> quantity;
            if (quantity >= 1 && quantity <= 5) {
                lineCost = unitPrice * quantity;
                orderTotal += lineCost;
                validLineCount++;
            } else {
                cout << "Invalid quantity. Request skipped." << endl;
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << "Valid line items: " << validLineCount << endl;
    cout << "Total order amount: $" << orderTotal << endl;

    return 0;                                            // Ends the program successfully
}                                                         // Ends the main function
/*
 * Test analysis:
 * 1. [orderTotal starts at 0.0 because it accumulates the total cost of valid line items, and initially no items have been added.]
 * 2. [An invalid part choice asks for another menu selection because the program validates the user's input and prompts for a valid choice if the initial input is outside the acceptable range.]
 * 3. [isValidPartChoice is reset during every for iteration to ensure that each part selection is evaluated independently.]
 * 4. [An invalid quantity doesn't change validLineCount because the program only increments validLineCount when a valid quantity is entered, ensuring that only legitimate line items are counted.]
 */