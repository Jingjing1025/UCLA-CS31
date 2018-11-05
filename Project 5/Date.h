//
//  Header.h
//  Project-5
//
//  Created by Jingjing on 2017/2/23.
//  Copyright © 2017 Jingjing. All rights reserved.
//

#ifndef Header_h
#define Header_h

class Date
{
public:
    Date(); //constructor for class Date
    Date (int month, int day);
    int getMonth ();
    int getDay ();
    
private:
    int mMonth;
    int mDay;
};

#endif /* Header_h */
