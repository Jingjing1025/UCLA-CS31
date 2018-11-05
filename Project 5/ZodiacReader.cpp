//
//  ZodiacReader.cpp
//  Project-5
//
//  Created by Jingjing on 2017/2/23.
//  Copyright © 2017 Jingjing. All rights reserved.
//

#include <stdio.h>
#include "ZodiacReader.h"
#include "Date.h"

ZodiacReader::ZodiacReader (Date date)
{
    mDate = date;
}

ZodiacReader::Sign ZodiacReader::checkSign( )
{
    ZodiacReader::Sign sign = (ZodiacReader::SCORPIO);
    switch (mDate.getMonth())
    {
        case 1:
            if (mDate.getDay()<20)
                sign = ZodiacReader::CAPRICORN;
            if (mDate.getDay()>19)
                sign = ZodiacReader::AQUARIUS;
            break;
            
        case 2:
            if (mDate.getDay()<19)
                sign = ZodiacReader::AQUARIUS;
            if (mDate.getDay()>18)
                sign = ZodiacReader::PISCES;
            break;
            
        case 3:
            if (mDate.getDay()<21)
                sign = ZodiacReader::PISCES;
            if (mDate.getDay()>20)
                sign = ZodiacReader::ARIES;
            break;
            
        case 4:
            if (mDate.getDay()<20)
                sign = ZodiacReader::ARIES;
            if (mDate.getDay()>19)
                sign = ZodiacReader::TAURUS;
            break;
            
        case 5:
            if (mDate.getDay()<21)
                sign = ZodiacReader::TAURUS;
            if (mDate.getDay()>20)
                sign = ZodiacReader::GEMINI;
            break;
            
        case 6:
            if (mDate.getDay()<21)
                sign = ZodiacReader::GEMINI;
            if (mDate.getDay()>20)
                sign = ZodiacReader::CANCER;
            break;
            
        case 7:
            if (mDate.getDay()<23)
                sign = ZodiacReader::CANCER;
            if (mDate.getDay()>22)
                sign = ZodiacReader::LEO;
            break;
            
        case 8:
            if (mDate.getDay()<23)
                sign = ZodiacReader::LEO;
            if (mDate.getDay()>22)
                sign = ZodiacReader::VIRGO;
            break;
            
        case 9:
            if (mDate.getDay()<23)
                sign = ZodiacReader::VIRGO;
            if (mDate.getDay()>22)
                sign = ZodiacReader::LIBRA;
            break;
            
        case 10:
            if (mDate.getDay()<23)
                sign = ZodiacReader::LIBRA;
            if (mDate.getDay()>22)
                sign = ZodiacReader::SCORPIO;
            break;
            
        case 11:
            if (mDate.getDay()<22)
                sign = ZodiacReader::SCORPIO;
            if (mDate.getDay()>21)
                sign = ZodiacReader::SAGITTARIUS;
            break;
            
        case 12:
            if (mDate.getDay()<22)
                sign = ZodiacReader::SAGITTARIUS;
            if (mDate.getDay()>21)
                sign = ZodiacReader::CAPRICORN;
            break;
    }
    return (sign);
    
}

bool ZodiacReader::onCusp( )
{
    bool result = false;
    switch (mDate.getMonth())
    {
        case 1:
            if (mDate.getDay () < 22 && mDate.getDay() > 17)
                result = true;
            break;
            
        case 2:
            if (mDate.getDay () < 21 && mDate.getDay() > 16)
                result = true;
            break;
            
        case 3:
            if (mDate.getDay () < 23 && mDate.getDay() > 18)
                result = true;
            break;
            
        case 4:
            if (mDate.getDay () < 22 && mDate.getDay() > 17)
                result = true;
            break;
            
        case 5:
            if (mDate.getDay () < 23 && mDate.getDay() > 18)
                result = true;
            break;
            
        case 6:
            if (mDate.getDay () < 23 && mDate.getDay() > 18)
                result = true;
            break;
            
        case 7:
            if (mDate.getDay () < 25 && mDate.getDay() > 20)
                result = true;
            break;
            
        case 8:
            if (mDate.getDay () < 25 && mDate.getDay() > 20)
                result = true;
            break;
            
        case 9:
            if (mDate.getDay () < 25 && mDate.getDay() > 20)
                result = true;
            break;
            
        case 10:
            if (mDate.getDay () < 25 && mDate.getDay() > 20)
                result = true;
            break;
            
        case 11:
            if (mDate.getDay () < 24 && mDate.getDay() > 19)
                result = true;
            break;
            
        case 12:
            if (mDate.getDay () < 24 && mDate.getDay() > 19)
                result = true;
            break;
    }
    
    return (result);
}


ZodiacReader::Sign ZodiacReader::cuspSign( )
{
    ZodiacReader::Sign sign = ZodiacReader::ARIES;
    switch (mDate.getMonth())
    {
        case 1:
            if (ZodiacReader::onCusp())
            {
                if (mDate.getDay() == 18 || mDate.getDay() == 19)
                    sign = ZodiacReader::AQUARIUS;
                else
                    sign = ZodiacReader::CAPRICORN;
            }
            break;
            
        case 2:
            if (ZodiacReader::onCusp())
            {
                if (mDate.getDay() == 18 || mDate.getDay() == 17)
                    sign = ZodiacReader::PISCES;
                else
                    sign = ZodiacReader::AQUARIUS;
            }
            break;
            
        case 3:
            if (ZodiacReader::onCusp())
            {
                if (mDate.getDay() == 20 || mDate.getDay() == 19)
                    sign = ZodiacReader::ARIES;
                else
                    sign = ZodiacReader::PISCES;
            }
            break;
            
        case 4:
            if (ZodiacReader::onCusp())
            {
                if (mDate.getDay() == 19 || mDate.getDay() == 18)
                    sign = ZodiacReader::TAURUS;
                else
                    sign = ZodiacReader::ARIES;
            }
            break;
            
        case 5:
            if (ZodiacReader::onCusp())
            {
                if (mDate.getDay() == 20 || mDate.getDay() == 19)
                    sign = ZodiacReader::GEMINI;
                else
                    sign = ZodiacReader::TAURUS;
            }
            break;
            
        case 6:
            if (ZodiacReader::onCusp())
            {
                if (mDate.getDay() == 20 || mDate.getDay() == 19)
                    sign = ZodiacReader::CANCER;
                else
                    sign = ZodiacReader::GEMINI;
            }
            break;
            
        case 7:
            if (ZodiacReader::onCusp())
            {
                if (mDate.getDay() == 22 || mDate.getDay() == 21)
                    sign = ZodiacReader::LEO;
                else
                    sign = ZodiacReader::CANCER;
            }
            break;
            
        case 8:
            if (ZodiacReader::onCusp())
            {
                if (mDate.getDay() == 22 || mDate.getDay() == 21)
                    sign = ZodiacReader::VIRGO;
                else
                    sign = ZodiacReader::LEO;
            }
            break;
            
        case 9:
            if (ZodiacReader::onCusp())
            {
                if (mDate.getDay() == 22 || mDate.getDay() == 21)
                    sign = ZodiacReader::LIBRA;
                else
                    sign = ZodiacReader::VIRGO;
            }
            break;
            
        case 10:
            if (ZodiacReader::onCusp())
            {
                if (mDate.getDay() == 22 || mDate.getDay() == 21)
                    sign = ZodiacReader::SCORPIO;
                else
                    sign = ZodiacReader::LIBRA;
            }
            break;
            
        case 11:
            if (ZodiacReader::onCusp())
            {
                if (mDate.getDay() == 21 || mDate.getDay() == 20)
                    sign = ZodiacReader::SAGITTARIUS;
                else
                    sign = ZodiacReader::SCORPIO;
            }
            break;
            
        case 12:
            if (ZodiacReader::onCusp())
            {
                if (mDate.getDay() == 21 || mDate.getDay() == 20)
                    sign = ZodiacReader::CAPRICORN;
                else
                    sign = ZodiacReader::SAGITTARIUS;
            }
            break;
    }
    
    return (sign);
}

std::string ZodiacReader::stringifySign( ZodiacReader::Sign sign )
{
    std::string string;
    switch (sign)
    {
        case 0:
            string = "Aries";
            break;
            
        case 1:
            string = "Taurus";
            break;
            
        case 2:
            string = "Gemini";
            break;
            
        case 3:
            string = "Cancer";
            break;
            
        case 4:
            string = "Leo";
            break;
            
        case 5:
            string = "Virgo";
            break;
            
        case 6:
            string = "Libra";
            break;
            
        case 7:
            string = "Scorpio";
            break;
            
        case 8:
            string = "Sagittarius";
            break;
            
        case 9:
            string = "Capricorn";
            break;
            
        case 10:
            string = "Aquarius";
            break;
            
        case 11:
            string = "Pisces";
            break;
    }
    
    return (string);
}
