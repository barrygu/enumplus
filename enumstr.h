#undef ENUM_ITEM
#undef ENUM_ITEM_VALUE
#undef BEGIN_ENUM
#undef END_ENUM
#undef NUMBER_OF
#undef INVALID_ENUM_ITEM

#ifndef _ENUM_HELPER_CLASS_
#define _ENUM_HELPER_CLASS_
#include <string.h>

typedef const char * PCS;

template <typename T>
struct E_Map {
    T value;
    PCS name;
};

template <typename T>
class EnumHelper
{
private:
    typedef struct E_Map<T> ETMAP;
    static struct E_Map<T> m_arrMapped[];
    ETMAP *m_pMapped;
    int m_nSize;
	static EnumHelper<T> * m_pThis;

    bool Equal(PCS s1, PCS s2)
    { return (strcmp (s1, s2) == 0); }

    bool Equal(T v1, T v2)
    { return (v1 == v2); }

public:
    EnumHelper()
    {
        m_pThis = this;
        m_pMapped = &m_arrMapped[0];
        m_nSize = ((int)(sizeof ( m_arrMapped ) / sizeof ( m_arrMapped[0] )) - 1);
    }

    static EnumHelper<T> *GetSelf(void) { return m_pThis; }
	ETMAP *At (int index)
	{
		return (index >= 0 && index < m_nSize) ? m_pMapped + index : 0;
	}

    int GetSize(void) { return m_nSize; }
    int ValuePosition ( T value );
    T InvalidValue (void)
	{
		return ((m_pMapped + m_nSize)->value);
	}

    T ValueAt ( int index )
	{
		ETMAP *pMapped = At(index);
		return pMapped ? pMapped->value : InvalidValue();
	}

    T GetValue ( PCS name );
    const char* GetName ( T value )
	{
		int pos = ValuePosition(value);
		return pos >= 0 ? (m_pMapped + pos)->name : 0;
	}

    const char* NameAt ( int index )
	{
		ETMAP *pMapped = At(index);
		return pMapped ? pMapped->name : 0;
	}
};

template <typename T> EnumHelper<T> * EnumHelper<T>::m_pThis = 0;

template <typename T>
int EnumHelper<T>::ValuePosition (T value)
{
    int i;
    ETMAP *pMapped = m_pMapped;
    for ( i = 0; i < m_nSize ; i++ )
    {
        if ( Equal(pMapped->value, value) )
            return i;
        pMapped++;
    }
    return -1;
}

template <typename T>
T EnumHelper<T>::GetValue ( PCS name )
{
    int i;
    ETMAP *pMapped = m_pMapped;
    for ( i = 0; i < m_nSize ; i++ )
    {
        if ( Equal(pMapped->name, name) )
            return pMapped->value;
		pMapped++;
    }
    return InvalidValue();
}

#endif // _ENUM_HELPER_CLASS_

#ifndef GENERATE_ENUM_NAMES

    #define ENUM_ITEM( element )              element ,
    #define ENUM_ITEM_VALUE( element, value ) element = value ,

    #define BEGIN_ENUM( ENUM_NAME )           typedef enum etag##ENUM_NAME {
    #define END_ENUM( ENUM_NAME )             invalid##ENUM_NAME##EnumValue } ENUM_NAME;
	#define GET_ENUM_HELPER( ENUM_NAME )      (EnumHelper<ENUM_NAME>::GetSelf())

#else

	#define ENUM_ITEM( element )               { element, #element } ,
	#define ENUM_ITEM_VALUE( element, value )  ENUM_ITEM( element )

	#define BEGIN_ENUM( ENUM_NAME )            template<> EnumHelper<ENUM_NAME>::ETMAP EnumHelper<ENUM_NAME>::m_arrMapped [] = {
	#define END_ENUM( ENUM_NAME )              {invalid##ENUM_NAME##EnumValue, (0)} }; \
         static EnumHelper<ENUM_NAME> g_clsEnumHelper_##ENUM_NAME;

#endif // defined GENERATE_ENUM_NAMES



