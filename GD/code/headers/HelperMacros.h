#ifndef __MACROS_H__
#define __MACROS_H__


/* Helpful Macros By Calloc for Reverse engineering gd with overall less headaches... */

/* Made for Handling both CCNodes and CCArrays */
#define NORMAL_ITERATE(IVAR, ARRAY, POBJECT , OBJTYPE, COMPARE) \
    for (unsigned int IVAR = 0; IVAR < ARRAY->##COMPARE(); IVAR++, POBJECT = reinterpret_cast<OBJTYPE*>(ARRAY->objectAtIndex(IVAR)))

#define NORMAL_ITERATE_WITH_CALL(IVAR, ARRAY, OBJTYPE, COMPARE, CALL) \
    for (unsigned int IVAR = 0; IVAR < ARRAY->##COMPARE(); IVAR++){ \
        reinterpret_cast<OBJTYPE*>(ARRAY->objectAtIndex(IVAR))->##CALL(); \
    }

#define NORMAL_ITERATE_WITH_CALL_AND_VALUE(IVAR, ARRAY, OBJTYPE, COMPARE, CALL, VALUE) \
    for (unsigned int IVAR = 0; IVAR < ARRAY->##COMPARE(); IVAR++){ \
        reinterpret_cast<OBJTYPE*>(ARRAY->objectAtIndex(IVAR))->##CALL(VALUE); \
    }

/* IVAR has already been declared In this scenario*/
#define NORMAL_ITERATE_WITH_CALL_AND_VALUE_NO_IT_DEF(IVAR, ARRAY, OBJTYPE, COMPARE, CALL, VALUE) \
    for (IVAR = 0; IVAR < ARRAY->##COMPARE(); IVAR++){ \
        reinterpret_cast<OBJTYPE*>(ARRAY->objectAtIndex(IVAR))->##CALL(VALUE); \
    }

#define NODE_ITERATE_WITH_CALL_VAL_NOITDEF(IVAR, PARENT, OBJTYPE, CALL, POBJECT) \
    for (IVAR = 0; IVAR < PARENT->getChildrenCount(); IVAR++){\
        reinterpret_cast<OBJTYPE*>(PARENT->getChildren()->objectAtIndex(IVAR))->##CALL(POBJECT);\
    }

#define NODE_ITERATE_WITH_CALL_VAL(IVAR, PARENT, OBJTYPE, CALL, POBJECT) \
    for (unsigned int IVAR = 0; IVAR < PARENT->getChildrenCount(); IVAR++){\
        reinterpret_cast<OBJTYPE*>(PARENT->getChildren()->objectAtIndex(IVAR))->##CALL(POBJECT);\
    }



#endif // __MACROS_H__