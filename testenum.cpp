#include <stdio.h>
#include "days.h"
#include "numbers.h"
#include "fruits.h"

/// The strings associated with the enums are gererated here
/////////////////////////////////////////////////////////////////////
#define GENERATE_ENUM_NAMES  // Start string generation

#include <strings.h>

#include "numbers.h"             
#include "days.h"             
#include "fruits.h"             

#undef GENERATE_ENUM_NAMES

int main(int argc, char* argv[], char* envp[])
{
	int i;
	const char *name;

	printf("Enum Days elements:\n");
	for (i = 0; i < 7; i++)
	{
		name = EnumHelper<Days>::GetSelf()->NameAt(i);
		if (name)
			printf("\t%d) %-10s\n", i, name);
	}

	printf("\nEnum Number elements:\n");
	EnumHelper<Numbers> *pEnumObj = EnumHelper<Numbers>::GetSelf();
	for (i = 0; i < 11; i++)
	{
		int pos = pEnumObj->ValuePosition(static_cast<Numbers>(i));
		if (pos >= 0) {
			name = pEnumObj->GetName(static_cast<Numbers>(i));
			printf("\t%-10s:\t%d\n", name, i);
		} else {
			printf("    %d is not a valid item of Enum Numbers\n", i);
		}
	}
	printf("Enum numbers' invalid value is %d", pEnumObj->InvalidValue() );

	EnumHelper<Fruits> *pEnumObj1 = EnumHelper<Fruits>::GetSelf();
	printf("\nEnum Fruits elements: %d\n", pEnumObj1->GetSize());
	Fruits value;
	for (i = 0; i < pEnumObj1->GetSize(); i++)
	{
		value = pEnumObj1->ValueAt(i);
		name = pEnumObj1->NameAt(i);
//		printf("\t%d) %-10s:\t%d\n", i, name, value);

		name = pEnumObj1->GetName(value);
		if (name)
		{
			value = pEnumObj1->GetValue(name);
			if (value != pEnumObj1->InvalidValue())
				printf("\t%-10s:\t%d\n", name, value);
			else {
				printf("    %d is not a valid item of Enum Fruits\n", i);
			}
		}
	}

	return 0;
}
