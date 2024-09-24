#include "headers/AdvString.h"

String
string_init(size_t size)
{
    String string; 

    string.size = size;

    string.mem = (char *) malloc(size);

    return string;
}

void
string_drop(String string)
{
    free(string.mem);
}