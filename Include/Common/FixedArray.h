#pragma once

#include "Common/Keywords.h"
#include "Common/BasicDataTypes.h"
#include  "Common/NameManglingGuard.h"

Common_NameManglingGuard_Begin

#define Common_Define_Fixed_Array(Name, ElementType, Capacity)                                                   \
                                                                                                                 \
    typedef struct Name                                                                                          \
    {                                                                                                            \
        SizeType size;                                                                                           \
        ElementType data[Capacity];                                                                              \
    } Name;                                                                                                      \
                                                                                                                 \
    static inline void Name##_Init(Name* array)                                                                  \
    {                                                                                                            \
        dynamic_assert(array != NULL);                                                                           \
        array->size = 0;                                                                                         \
    }                                                                                                            \
                                                                                                                 \
    static inline SizeType Name##_GetSize(const Name* array)                                                     \
    {                                                                                                            \
        dynamic_assert(array != NULL);                                                                           \
        return array->size;                                                                                      \
    }                                                                                                            \
                                                                                                                 \
    static inline SizeType Name##_GetCapacity(const Name* array)                                                 \
    {                                                                                                            \
        unused(array);                                                                                           \
        dynamic_assert(array != NULL);                                                                           \
        return (Capacity);                                                                                       \
    }                                                                                                            \
                                                                                                                 \
    static inline Bool Name##_CheckIsEmpty(const Name* array)                                                    \
    {                                                                                                            \
        dynamic_assert(array != NULL);                                                                           \
        return Name##_GetSize(array) == 0;                                                                       \
    }                                                                                                            \
                                                                                                                 \
    static inline Bool Name##_CheckIsFull(const Name* array)                                                     \
    {                                                                                                            \
        dynamic_assert(array != NULL);                                                                           \
        return Name##_GetSize(array) == Name##_GetCapacity(array);                                               \
    }                                                                                                            \
                                                                                                                 \
    static inline ElementType* Name##_GetByReferenceAtIndex(Name* array, const SizeType index)                   \
    {                                                                                                            \
        dynamic_assert(array != NULL);                                                                           \
        dynamic_assert(index < Name##_GetSize(array));                                                           \
        dynamic_assert(index < Name##_GetCapacity(array));                                                       \
        return &array->data[index];                                                                              \
    }                                                                                                            \
                                                                                                                 \
    static inline const ElementType* Name##_GetByConstReferenceAtIndex(const Name* array, const SizeType index)  \
    {                                                                                                            \
        dynamic_assert(array != NULL);                                                                           \
        dynamic_assert(index < Name##_GetSize(array));                                                           \
        dynamic_assert(index < Name##_GetCapacity(array));                                                       \
        return &array->data[index];                                                                              \
    }                                                                                                            \
                                                                                                                 \
    static inline ElementType Name##_GetByValueAtIndex(const Name* array, const SizeType index)                  \
    {                                                                                                            \
        dynamic_assert(array != NULL);                                                                           \
        dynamic_assert(index < Name##_GetSize(array));                                                           \
        dynamic_assert(index < Name##_GetCapacity(array));                                                       \
        return array->data[index];                                                                               \
    }                                                                                                            \
                                                                                                                 \
    static inline void Name##_SetAtIndex(Name* array, const SizeType index, const ElementType value)             \
    {                                                                                                            \
        dynamic_assert(array != NULL);                                                                           \
        dynamic_assert(index < Name##_GetSize(array));                                                           \
        dynamic_assert(index < Name##_GetCapacity(array));                                                       \
        array->data[index] = value;                                                                              \
    }                                                                                                            \
                                                                                                                 \
    static inline void Name##_InsertAtIndex(Name* array, const SizeType index, const ElementType value)          \
    {                                                                                                            \
        dynamic_assert(array != NULL);                                                                           \
        dynamic_assert(Name##_CheckIsFull(array) == false);                                                      \
        dynamic_assert(index <= Name##_GetSize(array));                                                          \
        dynamic_assert(index < Name##_GetCapacity(array));                                                       \
                                                                                                                 \
        for (SizeType i = Name##_GetSize(array); i > index; --i)                                                 \
        {                                                                                                        \
            array->data[i] = array->data[i - 1];                                                                 \
        }                                                                                                        \
                                                                                                                 \
        array->data[index] = value;                                                                              \
        array->size = array->size + 1;                                                                           \
    }                                                                                                            \
                                                                                                                 \
    static inline void Name##_Push(Name* array, const ElementType value)                                         \
    {                                                                                                            \
        dynamic_assert(array != NULL);                                                                           \
        dynamic_assert(Name##_CheckIsFull(array) == false);                                                      \
        Name##_InsertAtIndex(array, Name##_GetSize(array), value);                                               \
    }                                                                                                            \
                                                                                                                 \
    static inline void Name##_RemoveFromIndex(Name* array, const SizeType index)                                 \
    {                                                                                                            \
        dynamic_assert(array != NULL);                                                                           \
        dynamic_assert(Name##_CheckIsEmpty(array) == false);                                                     \
        dynamic_assert(index < Name##_GetSize(array));                                                           \
        dynamic_assert(index < Name##_GetCapacity(array));                                                       \
                                                                                                                 \
        for (SizeType i = index; i < Name##_GetSize(array) - 1; ++i)                                             \
        {                                                                                                        \
            array->data[i] = array->data[i + 1];                                                                 \
        }                                                                                                        \
                                                                                                                 \
        array->size = array->size - 1;                                                                           \
    }                                                                                                            \
                                                                                                                 \
    static inline void Name##_PopByReference(Name* array, ElementType* poppedValue)                              \
    {                                                                                                            \
        dynamic_assert(array != NULL);                                                                           \
        dynamic_assert(Name##_CheckIsEmpty(array) == false);                                                     \
        const SizeType toBePoppedIndex = Name##_GetSize(array) - 1;                                              \
        *poppedValue = Name##_GetByValueAtIndex(array, toBePoppedIndex);                                         \
        Name##_RemoveFromIndex(array, toBePoppedIndex);                                                          \
    }                                                                                                            \
                                                                                                                 \
    static inline ElementType Name##_PopByValue(Name* array)                                                     \
    {                                                                                                            \
        dynamic_assert(array != NULL);                                                                           \
        dynamic_assert(Name##_CheckIsEmpty(array) == false);                                                     \
        ElementType poppedValue = 0;                                                                             \
        Name##_PopByReference(array, &poppedValue);                                                              \
        return poppedValue;                                                                                      \
    }                                                                                                            \
                                                                                                                 \
    static inline void Name##_Clear(Name* array)                                                                 \
    {                                                                                                            \
        dynamic_assert(array != NULL);                                                                           \
        array->size = 0;                                                                                         \
    }

Common_NameManglingGuard_End
