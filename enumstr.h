#undef ENUM_ITEM
#undef ENUM_ITEM_VALUE
#undef BEGIN_ENUM
#undef END_ENUM
#undef NUMBER_OF
#undef INVALID_ENUM_ITEM

#ifndef _ENUM_HELPER_CLASS_
#define _ENUM_HELPER_CLASS_
#include <string.h>

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr) ((int)(sizeof (arr) / sizeof (arr[0])))
#endif // ARRAY_SIZE

typedef const char * PCS;
typedef struct {
    int value;
    PCS name;
} ETMAP;

class EnumBase
{
protected:
	int m_nSize;
    ETMAP *m_pMapped;

    bool Equal(PCS s1, PCS s2)
    { return (strcmp (s1, s2) == 0); }

    bool Equal(int v1, int v2)
    { return (v1 == v2); }

public:

	EnumBase() : m_nSize(0), m_pMapped(0) {}
	virtual ~EnumBase() {}

	int GetSize() { return m_nSize; }
    int ValuePosition ( int value );

    int InvalidValue (void)
	{
		return ((m_pMapped + m_nSize)->value);
	}

    int ValueAt ( int index )
	{
		ETMAP *pMapped = At(index);
		return pMapped ? pMapped->value : InvalidValue();
	}

	ETMAP *At (int index)
	{
		return (index >= 0 && index < m_nSize) ? m_pMapped + index : 0;
	}

    const char* NameAt ( int index )
	{
		ETMAP *pMapped = At(index);
		return pMapped ? pMapped->name : 0;
	}

    int GetValue ( PCS name );

	const char* GetName ( int value )
	{
		int pos = ValuePosition(value);
		return pos >= 0 ? (m_pMapped + pos)->name : 0;
	}

};

template <typename T>
class EnumHelper : public EnumBase
{
private:
	static EnumHelper<T> * m_pThis;
    static ETMAP m_arrMapped[];

    bool Equal(T v1, T v2)
    { return EnumBase::Equal((int)v1, (int)v2); }

public:
    EnumHelper()
	{
        m_pThis = this;
        m_pMapped = &m_arrMapped[0];
        m_nSize = ARRAY_SIZE(m_arrMapped) - 1;
    }

    static EnumHelper<T> *GetSelf(void) { return m_pThis; }

    int ValuePosition ( T value ) { 
		return EnumBase::ValuePosition((int)value);
   	}

    T InvalidValue (void) {
		return static_cast<T>(EnumBase::InvalidValue());
	}

    T ValueAt ( int index ) {
		return static_cast<T>(EnumBase::ValueAt(index));
	}

    T GetValue ( PCS name ) {
		return static_cast<T>(EnumBase::GetValue(name));
	}

    const char* GetName ( T value ) {
		return EnumBase::GetName( (int)value );
	}

};

template <typename T> EnumHelper<T> * EnumHelper<T>::m_pThis = 0;

int EnumBase::ValuePosition (int value)
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

int EnumBase::GetValue ( PCS name )
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
	#define ENUM_HELPER( ENUM_NAME )          (EnumHelper<ENUM_NAME>::GetSelf())

#else

	#define ENUM_ITEM( element )               { element, #element } ,
	#define ENUM_ITEM_VALUE( element, value )  ENUM_ITEM( element )

	#define BEGIN_ENUM( ENUM_NAME )            template<> ETMAP EnumHelper<ENUM_NAME>::m_arrMapped [] = {
	#define END_ENUM( ENUM_NAME )              {invalid##ENUM_NAME##EnumValue, (0)} }; \
         static EnumHelper<ENUM_NAME> g_clsEnumHelper_##ENUM_NAME;

#endif // defined GENERATE_ENUM_NAMES



