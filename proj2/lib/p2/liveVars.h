#ifndef __LIVEVARS_H__
#define __LIVEVARS_H__

#include "flags.h"
#ifdef PRINTANALRESULTS
    static const bool PRINT_ANAL_RESULTS = true;
#else
    static const bool PRINT_ANAL_RESULTS = false;
#endif
#ifdef PRINTREMOVING
    static const bool PRINT_REMOVING = true;
#else
    static const bool PRINT_REMOVING = false;
#endif


#endif
