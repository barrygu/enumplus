#if ( !defined(NUMBERS_H) || defined(GENERATE_ENUM_NAMES) )

#if (!defined(GENERATE_ENUM_NAMES))
	#define NUMBERS_H
#endif

#include "enumstr.h"

///////////////////////////////
// The enum declaration
///////////////////////////////
BEGIN_ENUM(Numbers)
    ENUM_ITEM_VALUE(one, 1)
    ENUM_ITEM(two)
    ENUM_ITEM(three)
    ENUM_ITEM_VALUE(five, 5)
    ENUM_ITEM(six)
    ENUM_ITEM_VALUE(eight, 8)
    ENUM_ITEM(nine)
    ENUM_ITEM_VALUE(ten, 10)
END_ENUM(Numbers)

#endif // (!defined(NUMBERS_H) || defined(GENERATE_ENUM_NAMES))
