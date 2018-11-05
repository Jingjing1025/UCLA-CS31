//
//  main.cpp
//  Project 2
//
//  Created by Jingjing on 2017/1/17.
//  Copyright © 2017 Jingjing. All rights reserved.
//


#include <iostream>
#include <string>
using namespace std;

int main ()
{
    //decalre needed variables
    string CustomerName;
    double MilesToBeDriven;
    double MinutesToBeDriven;
    string RideType;
    
    //collect informaton of customer's name
    cout << "Customer Name:";
    getline(cin, CustomerName);
    
    if (CustomerName == "")
    {
        cout << "--- You must enter a customer name." << endl;
        return 1;
    }
    
    //collect informaton of driving miles
    cout << "Miles to be driven:";
    cin >> MilesToBeDriven;
    
    if (MilesToBeDriven <= 0)
    {
        cout << "--- The mileage must be positive." << endl;
        return 1;
    }
    
    //collect informaton of drving minutes
    cout << "Minutes to be driven:";
    cin >> MinutesToBeDriven;
    
    if (MinutesToBeDriven <= 0)
    {
        cout << "--- The time must be positive." << endl;
        return 1;
    }
    
    //collect informaton of ride type
    cout << "Ride Type:";
    cin.ignore (100000, '\n');
    getline (cin, RideType);
    
    if (RideType != "Br-UberX" && RideType != "Br-UberXL")
    {
        cout << "--- The ride type is not valid." << endl;
        return 1;
    }
    
    //magic formula for number of digits to be produced
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    //calculate fare under different situations
    double fare;
    
    if (RideType == "Br-UberX")
    {
        fare = 0.15*MinutesToBeDriven + 0.90*MilesToBeDriven + 1.65;
        if (fare < 5.15)           //for situation that the fare is below minimum fare
            cout << "--- The fare for " << CustomerName << " is $5.15" <<endl;
        else
            cout << "--- The fare for " << CustomerName << " is $" << fare <<endl;
    }
    
    else
    {
        fare = 0.30*MinutesToBeDriven +1.55*MilesToBeDriven + 1.65;
        if (fare < 7.65)         //for situation that the fare is below minimum fare
            cout << "--- The fare for " << CustomerName << " is $7.65" << endl;
        else cout << "--- The fare for " << CustomerName << " is $" << fare <<endl;
    }
    
        return 0;
    
}
