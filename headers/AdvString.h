/*------------------------------------------------------------------------- 
 *
 * AdvString.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef ADV_STRING_H 
#define ADV_STRING_H

#include <stdlib.h>

typedef struct String {
    size_t size;
    char *mem;
} String;

extern String string_init(size_t size);

extern void string_drop(String string);

#endif  /* ADV_STRING_H */