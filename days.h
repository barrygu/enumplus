// File name: "Days.h"
#if ( !defined(DAYS_H) || defined(GENERATE_ENUM_NAMES) )

#if (!defined(GENERATE_ENUM_NAMES))
	#define DAYS_H
#endif

#include "enumstr.h"

///////////////////////////////
// The enum declaration
///////////////////////////////
BEGIN_ENUM(Days)
    ENUM_ITEM(sunday)
    ENUM_ITEM(monday)
    ENUM_ITEM(tuesday)
    ENUM_ITEM(wednesday)
    ENUM_ITEM(thursday)
    ENUM_ITEM(friday)
    ENUM_ITEM(saturday)
END_ENUM(Days)

#endif // (!defined(DAYS_H) || defined(GENERATE_ENUM_NAMES))
