//
//  dataFetch.hpp
//  MXBT
//
//  Created by Minxing Chen on 10/25/20.
//

#ifndef dataFetch_hpp
#define dataFetch_hpp

#include <stdio.h>
#include "marketDataProc.hpp"

class dataFetch {
public: dataFetch(char *symbol, long start_date, long end_date, char filename[MAX_LENGTH], char cookie[MAX_LENGTH], char crumbFilename[MAX_LENGTH] );
    MarketDataProc market;
};


#endif /* dataFetch_hpp */
