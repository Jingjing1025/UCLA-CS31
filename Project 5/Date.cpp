//
//  Date.cpp
//  Project-5
//
//  Created by Jingjing on 2017/2/23.
//  Copyright © 2017 Jingjing. All rights reserved.
//

#include "Date.h"

Date::Date(){
}

Date::Date (int month, int day)
{
    if ((month >= 1) && (month <= 12))
        mMonth = month;
    
    if ((day >= 1) && (day <= 31))
        mDay = day;
}

int Date::getMonth()
{
    return mMonth;
}

int Date::getDay()
{
    return mDay;
}
