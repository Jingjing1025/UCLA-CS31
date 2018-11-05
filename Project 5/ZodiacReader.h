//
//  ZodiacReader.h
//  Project-5
//
//  Created by Jingjing on 2017/2/23.
//  Copyright © 2017 Jingjing. All rights reserved.
//

#ifndef ZodiacReader_h
#define ZodiacReader_h

#include "Date.h"
#include <string>


class ZodiacReader
{
public:
    enum Sign {ARIES, TAURUS, GEMINI, CANCER, LEO, VIRGO, LIBRA, SCORPIO, SAGITTARIUS, CAPRICORN, AQUARIUS, PISCES};
    
    ZodiacReader (Date date);
    ZodiacReader::Sign checkSign( );
    bool onCusp( );
    ZodiacReader::Sign cuspSign( );
    std::string stringifySign( ZodiacReader::Sign sign);
    
private:
    Date mDate ;
    
};

#endif /* ZodiacReader_h */
