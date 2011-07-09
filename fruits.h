#if ( !defined(FRUITS_H) || defined(GENERATE_ENUM_NAMES) )

#if (!defined(GENERATE_ENUM_NAMES))
	#define FRUITS_H
#endif

#include "enumstr.h"

///////////////////////////////
// The enum declaration
///////////////////////////////
BEGIN_ENUM(Fruits)
    ENUM_ITEM_VALUE(apple, -2)
    ENUM_ITEM(orange)
    ENUM_ITEM(pear)
    ENUM_ITEM(cherry)
    ENUM_ITEM_VALUE(lemon, 10)
    ENUM_ITEM(grape)
    ENUM_ITEM(banana)
    ENUM_ITEM(melon)
END_ENUM(Fruits)

#endif // (!defined(FRIUTS_H) || defined(GENERATE_ENUM_NAMES))
