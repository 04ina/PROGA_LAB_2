/*------------------------------------------------------------------------- 
 *
 * AdvString.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef ADV_STRING_H 
#define ADV_STRING_H

#include <stdlib.h>

typedef struct StringData {
    size_t size;
    char *ptr;
} StringData;

typedef StringData *String;

extern String StringInit(size_t size);

extern void StringDrop(String string);

#endif  /* ADV_STRING_H */