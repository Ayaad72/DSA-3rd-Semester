//Example:1 Voter Eligibility Checker for GILGIT 

#include <iostream>
using namespace std;

int main() {
    char nationality;
    int age;
    int choice;

    cout << "Do you live in GILGIT? (y/n): ";
    cin >> nationality;

    if (nationality == 'y' || nationality == 'Y') {
        cout << "Choose a politician you support:" << endl;
        cout << "1. Hafeez Ur Rehman (PMLN)" << endl;
        cout << "2. Jamil Ahmed (PPP)" << endl;
        cout << "3. Fateh Ullah Khan (PTI)" << endl;
        cout << "Enter the number corresponding to your choice: ";
        cin >> choice;

        cout << "Enter your age: ";
        cin >> age;

        if (age >= 18) {
            cout << "You are eligible to vote." << endl;

            // Displaying chosen politician based on choice
            if (choice == 1) {
                cout << "You support Hafeez Ur Rehman (PMLN)." << endl;
            } else if (choice == 2) {
                cout << "You support Jamil Ahmed (PPP)." << endl;
            } else if (choice == 3) {
                cout << "You support Fateh Ullah Khan (PTI)." << endl;
            } else {
                cout << "Invalid choice for politician." << endl;
            }

        } else {
            cout << "You are not eligible to vote as you are under 18." << endl;
        }

    } else {
        cout << "You are not eligible to vote as you are not a citizen." << endl;
    }

    return 0;
}


//  ====================================================================================================================================

//Example 2: Temperature Alert System

#include <iostream>
using namespace std;

int main() {
    int temperature;
    int locationChoice;

    cout << "Select your location in Northern Areas of Pakistan:" << endl;
    cout << "1. Gilgit" << endl;
    cout << "2. Skardu" << endl;
    cout << "3. Hunza" << endl;
    cout << "Enter the number corresponding to your location: ";
    cin >> locationChoice;

    cout << "Enter the current temperature in Celsius: ";
    cin >> temperature;

    cout << endl; 

    if (locationChoice == 1) { // Gilgit
        cout << "Location: Gilgit" << endl;
        if (temperature >= 30) {
            if (temperature >= 40) {
                cout << "Warning for Gilgit: It's extremely hot. Stay hydrated and avoid going outside!" << endl;
            } else {
                cout << "It's hot in Gilgit. Wear light clothing and stay cool." << endl;
            }
        } else if (temperature >= 15) {
            if (temperature >= 20) {
                cout << "The weather in Gilgit is warm. A light jacket is enough." << endl;
            } else {
                cout << "It's a bit cool in Gilgit. Consider wearing a sweater." << endl;
            }
        } else {
            if (temperature >= 5) {
                cout << "It's cold in Gilgit. Wear a warm coat." << endl;
            } else {
                cout << "Warning for Gilgit: It's extremely cold. Stay indoors if possible!" << endl;
            }
        }
    } else if (locationChoice == 2) { // Skardu
        cout << "Location: Skardu" << endl;
        if (temperature >= 25) {
            if (temperature >= 35) {
                cout << "Warning for Skardu: It's very hot. Stay hydrated and avoid going outside!" << endl;
            } else {
                cout << "It's warm in Skardu. Dress lightly." << endl;
            }
        } else if (temperature >= 10) {
            if (temperature >= 15) {
                cout << "The weather in Skardu is moderate. A light jacket should be fine." << endl;
            } else {
                cout << "It's cool in Skardu. A sweater is recommended." << endl;
            }
        } else {
            if (temperature >= 0) {
                cout << "It's cold in Skardu. Wear a warm coat." << endl;
            } else {
                cout << "Warning for Skardu: It's extremely cold. Stay indoors if possible!" << endl;
            }
        }
    } else if (locationChoice == 3) { // Hunza
        cout << "Location: Hunza" << endl;
        if (temperature >= 20) {
            if (temperature >= 30) {
                cout << "Warning for Hunza: It's quite hot for this region. Stay hydrated!" << endl;
            } else {
                cout << "It's warm in Hunza. Light clothing is recommended." << endl;
            }
        } else if (temperature >= 10) {
            if (temperature >= 15) {
                cout << "The weather in Hunza is pleasant. A light sweater is enough." << endl;
            } else {
                cout << "It's cool in Hunza. Wear a sweater." << endl;
            }
        } else {
            if (temperature >= -5) {
                cout << "It's cold in Hunza. Dress warmly." << endl;
            } else {
                cout << "Warning for Hunza: Extremely cold conditions. Avoid going outside!" << endl;
            }
        }
    } else {
        cout << "Invalid location choice." << endl;
    }

    return 0;
}



//  ====================================================================================================================================

//Example 3: Student Grading System

#include <iostream>
using namespace std;

int main() {
    int marks;
    int attendance;

    cout << "Enter marks (out of 100): ";
    cin >> marks;
    cout << "Enter attendance percentage: ";
    cin >> attendance;

    if (marks >= 90) {
        if (attendance >= 90) {
            cout << "Grade: A" << endl;
        } else {
            cout << "Grade: B (due to low attendance)" << endl;
        }
    } else if (marks >= 75) {
        if (attendance >= 80) {
            cout << "Grade: B" << endl;
        } else {
            cout << "Grade: C (due to low attendance)" << endl;
        }
    } else if (marks >= 50) {
        if (attendance >= 75) {
            cout << "Grade: C" << endl;
        } else {
            cout << "Grade: D (due to low attendance)" << endl;
        }
    } else {
        cout << "Grade: F (fail)" << endl;
    }

    return 0;
}

//  ==================================================================================================================================== 

//Example 4: Bank loan eligibility checker

#include <iostream>
using namespace std;

int main() {
    double income;
    int creditScore;
    bool isEmployed;

    cout << "Enter monthly income: ";
    cin >> income;
    cout << "Enter credit score: ";
    cin >> creditScore;
    cout << "Are you currently employed? (1 for Yes, 0 for No): ";
    cin >> isEmployed;

    if (income >= 3000) {
        if (creditScore >= 700) {
            if (isEmployed) {
                cout << "Loan Approved!" << endl;
            } else {
                cout << "Loan Denied: Employment required." << endl;
            }
        } else {
            cout << "Loan Denied: Insufficient credit score." << endl;
        }
    } else {
        cout << "Loan Denied: Insufficient income." << endl;
    }

    return 0;
}




