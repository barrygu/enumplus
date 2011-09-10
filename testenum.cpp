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
	EnumBase *pEnumHelper;

	pEnumHelper = ENUM_HELPER(Days);
	printf("Enum Days elements: %d\n", pEnumHelper->GetSize());
	for (i = 0; i < 7; i++)
	{
		name = pEnumHelper->NameAt(i);
		if (name)
			printf("\t%d) %-10s\n", i, name);
	}
	printf("    Enum Days' invalid value is %d\n", pEnumHelper->InvalidValue() );

	pEnumHelper = ENUM_HELPER(Numbers);
	printf("\nEnum Number elements: %d\n", pEnumHelper->GetSize());
	for (i = 0; i < 11; i++)
	{
		int pos = pEnumHelper->ValuePosition(static_cast<Numbers>(i));
		if (pos >= 0) {
			name = pEnumHelper->GetName(static_cast<Numbers>(i));
			printf("\t%-10s:\t%d\n", name, i);
		} else {
			printf("    %d is not a valid item of Enum Numbers\n", i);
		}
	}
	printf("    Enum Numbers' invalid value is %d\n", pEnumHelper->InvalidValue() );

	Fruits value;
	GET_ENUM_HELPER_PTR(Fruits, pFruits);
	printf("\nEnum Fruits elements: %d\n", pFruits->GetSize());
	for (i = 0; i < pFruits->GetSize(); i++)
	{
		value = pFruits->ValueAt(i);
		name = pFruits->NameAt(i);

		name = pFruits->GetName(value);
		if (name)
		{
			value = pFruits->GetValue(name);
			if (value != pFruits->InvalidValue())
				printf("\t%-10s:\t%d\n", name, value);
			else {
				printf("    %d is not a valid item of Enum Fruits\n", i);
			}
		}
	}
	printf("    Enum Fruits' invalid value is %d\n", pFruits->InvalidValue() );

	return 0;
}
