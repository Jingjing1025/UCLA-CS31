//
//  main.cpp
//  Project 3
//
//  Created by Jingjing on 2017/1/26.
//  Copyright © 2017 Jingjing. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>
#include <cctype>
#include <cassert>

bool isWellFormedAirportString(string commands)
{
    string a;
    string b;
    
    //Convert all characters to lowercase
    for (size_t k = 0; k < commands.size (); k++)
    {
        a += tolower (commands [k]);
    }
    
    //A loop to test the command string
    while (isalpha (a [0]))
    {
        //Find the total length of one group of the string
        int i = 0;
        int sum = 0;
        
        b = a.substr(0,2);  //Clip the first two characters of the string to compare airline code
        if ( b == "ua" || b == "aa"|| b == "va"|| b == "dl"|| b == "sw"|| b == "al")
        {
            a = a. substr (2, a.size()-2); //The string now starts with flight number
            while (isdigit (a [i]))
            {
                sum += a [i];
                i++;
                if (!isdigit(a [i]))
                    break;
            }
        
            if (i >= 1 && i <= 3)  //Flight number can only have 1-3 digits
            {
               if (sum <= '0' * i)   //Flight number cannot be 0
                   break;
               if (a [i] == '+' || a [i] == '-')
                  {
                      a = a.substr (i+1, a.size()-i-1);   //The string now starts with arrival time
                      i = 0;
                      while (isdigit (a [i]))  //find the number of digit of arrival time
                      {
                          i++;
                          if (!isdigit(a [i]))
                              break;
                      }
                      if (i >= 1 && i <= 3)  //The arrival time can only have 1-3 digits
                      {
                          a = a.substr (i, a.size()-i);  //Cut the tested group off the string
                          if (a == "")
                              return true;
                          else continue;
                      }  break;
                  }  break;
                
            }  break;
            
    }  break;
    }
    return false;
}

//To test the function
/*
int main()
{
    string d;
    cout.setf( ios::boolalpha ); // prints bool values as "true" or "false"
    for(;;)
    {
        cout << "Enter commands: ";
        getline(cin, d);
    if (d == "quit") break;
        cout << "isWellFormedAirportString returns ";
        cout << isWellFormedAirportString(d) << endl;
    }
}
*/


double ontimeArrivalPercentage(string commands, string airlinecode)
{
    string AP;
    string AC;
    string d;
    double total = 0;
    double ontime = 0;
    double OntimeArrivalPercentage;
    
    //Convert all characters to lowercase
    for (size_t k = 0; k < commands.size (); k++)
    {
        AP += tolower (commands [k]);
    }
    
    //Convert all characters to lowercase
    for (size_t k = 0; k < airlinecode.size (); k++)
    {
        AC += tolower (airlinecode [k]);
    }
    
    //Set for cases that the inputs are not valid
    if (isWellFormedAirportString(commands) == false)   //Call the previous function
        OntimeArrivalPercentage = -1;
    
    else if (AC !="aa" && AC!="ua" && AC!="dl" && AC!="sw" && AC!="va" && AC!="al")
        OntimeArrivalPercentage = -1;
    
    else
    {
        while (isalpha(AC[0]))   //A loop to check each group of the string
        {
            int flightnumber = 0;
            int minute = 0;

        d = AP.substr (0,2);   //Clip the first two characters to check for airline code
        if (d == AC)        //If the airline code maches, check for the arrival time
        {
            total +=1;
            AP = AP.substr (2, AP.size()-2);
            for (size_t n = 0; n < AP.size(); n++)
            {
                if (isdigit (AP[n]))
                    flightnumber +=1;
                else
                    break;
            }
            
            AP = AP.substr (flightnumber, AP.size()-flightnumber);   //Now AP starts with arrival time
            
            if (AP [0] == '-')
            {
                AP = AP.substr (1,AP.size()-1);
                for (size_t p = 0; p < AP.size(); p++)   //Find the number of digits for arrival time
                {
                    if (isdigit (AP[p]))
                        minute +=1;
                    else
                        break;
                }
                    ontime +=1;
            }
            
            if (AP [0] == '+')
            {
                AP = AP.substr (1,AP.size()-1);
                for (size_t p = 0; p < AP.size(); p++)   //Find the number of digits for arrival time
            {
                if (isdigit (AP[p]))
                    minute +=1;
                else
                    break;
            }
            
            switch (minute)   //Three cases of minute digit numbers (1, 2, and 3)
            {
                case 1: ontime +=1; break;
                case 2:
                    if(AP[0] == '0')
                        ontime +=1;
                    else if(AP[0] == '1' && (AP[1] =='0'||AP[1] =='1'||AP[1] =='2'||AP[1] =='3'||AP[1] =='4'))
                        ontime +=1;
                    break;
                case 3:
                    if (AP[0] == '0' && AP[1] == '0')
                        ontime +=1;
                    else if (AP[0] == '0' && AP[1] == '1' && (AP[2] =='0'||AP[2] =='1'||AP[2] =='2'||AP[2] =='3'||AP[2] =='4'))
                        ontime +=1;
                    break;
            }

            }
                        
            AP = AP.substr(minute, AP.size()-minute);      //Clip off the tested group from the string
            if (AP == "")      //Leave the loop after the whole string is checked
                break;
        }
        else   //If the airline code does not match, only find the length of the group and clip it off from string
        {
            AP = AP.substr (2, AP.size()-2);
            for (size_t n = 0; n < AP.size(); n++)
            {
                if (isdigit (AP[n]))
                    flightnumber +=1;
                else
                    break;
            }
            AP = AP.substr (flightnumber+1, AP.size()-flightnumber-1);
            
            for (size_t p = 0; p < AP.size(); p++)
            {
                if (isdigit (AP[p]))
                    minute +=1;
                else
                    break;
            }
       
             AP = AP.substr(minute, AP.size()-minute);
            if (AP == "")
                break;
        }
            
    
        }
        
        if (total == 0)         //If there is no matches, set the result be 0
            OntimeArrivalPercentage = 0;
        else
        OntimeArrivalPercentage = ontime / total;      //Calculate the ontime arrival percentage
    }
    return OntimeArrivalPercentage;
}

//To test the function
/*
int main ()
{
    string commands;
    string airlinecode;
    
    cout << "commands:" << endl;
    cin >> commands;
    
    cout << "airline code:" << endl;
    cin >> airlinecode;
    
    cout << ontimeArrivalPercentage(commands, airlinecode) << endl;
    
    return 0;
}
*/
