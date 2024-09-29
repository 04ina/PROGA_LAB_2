#include "headers/AdvString.h"

String
StringInit(size_t size)
{
    String string; 

    string = (String) malloc(sizeof(StringData));

    string->size = size;

    string->ptr = (char *) malloc(size);

    return string;
}

void
StringDrop(String string)
{
    free(string->ptr);
    free(string);
}