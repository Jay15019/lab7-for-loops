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
    int deviceCount;                                     // Stores the known number of devices in the batch
    int passingDeviceCount = 0;                          // Counts devices with a passing quality score
    double qualityScore;                                 // Stores one device score per iteration
    double totalScore = 0.0;                             // Accumulates all quality scores

    cout << "Enter number of devices from 1 to 10: ";  // Prompts for the batch size
    cin >> deviceCount;                                  // Reads the first batch-size candidate

    while (deviceCount < 1 || deviceCount > 10) {        // Repeats while the batch size is outside the allowed range
        cout << "Invalid device count. Try again: ";    // Explains why another batch size is required
        cin >> deviceCount;                              // Reads a replacement batch size
    }                                                     // Ends after a valid batch size is entered

    for (int device = 1; device <= deviceCount; device++) {
        cout << "Enter quality score for device " << device << ": ";
        cin >> qualityScore;
        totalScore += qualityScore;

        if (qualityScore >= 70.0) {
            passingDeviceCount++;
            cout << "Device passes inspection." << endl;
        } else {
            cout << "Device fails inspection." << endl;
        }
    }

    double averageScore = totalScore / deviceCount;
    cout << fixed << setprecision(2);
    cout << "Total quality score: " << totalScore << endl;
    cout << "Average quality score: " << averageScore << endl;
    cout << "Passing devices: " << passingDeviceCount << endl;

    return 0;                                            // Ends the program successfully
}                                                         // Ends the main function
/*
 * Analysis:
 * 1. [totalScore starts at 0.0 because it is a double and we want to accumulate the sum of quality scores.]
 * 2. [passingDeviceCount changes for 70 but not for 69 because the condition checks for a score of 70 or higher.]
 * 3. [averageScore is calculated after the for loop because we need the total sum and the number of devices to compute the average.]
 */