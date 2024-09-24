#include "headers/RelFile.h"

#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "headers/AdvString.h"

#define MAX_REL_FILE_NAME_SIZE 100

#define RAW_PAGE_SIZE 8192

#define INVALID_REL_FILE (RelFile) 0

static bool
rel_file_is_valid(RelFile rel_file)
{
    if (rel_file == INVALID_REL_FILE) 
        return 0;
    else    
        return 1;
}

RelFile
rel_file_init(void)
{
    RelFile rel_file;

    rel_file = malloc(sizeof(RelFileData)); 

    return rel_file; 
}

void
rel_file_drop(RelFile rel_file)
{
    free(rel_file);
}

static void
rel_file_get_parse_name(RelOid rel_oid, ForkType fork, String file_name)
{
    int name_size = 0;

    sprintf(file_name.mem,"%d", (int) rel_oid);

    file_name.mem[sizeof(file_name.mem)] = '_';

    switch (fork)
    {
        case MAIN_FORK:
            break;
        case FSM_FORK:
            strcat(file_name.mem, "_fsm");
            break;
        case VM_FORK:
            strcat(file_name.mem, "_vm");
            break;
        case INIT_FORK:
            strcat(file_name.mem, "_init");
            break;
        default:
            assert(0);
    }
}

bool
rel_file_read_raw_page(RelFile rel_file, unsigned int page_number, char *raw_page)
{
    FILE *file = rel_file->file;
    int result;

    result = fseek(file, RAW_PAGE_SIZE * page_number, SEEK_SET);

    if (result != 0)
    {
        /* page not found */
        return false;
    }

    fread((char *) raw_page, RAW_PAGE_SIZE, 1, file);

    fseek(file, 0, SEEK_END);

    return true;
}

RelFile
rel_file_open_for_read(RelOid rel_oid, ForkType fork) 
{
    RelFile rel_file;

    rel_file = rel_file_init();

    String file_name = string_init(MAX_REL_FILE_NAME_SIZE);

    rel_file_get_parse_name(rel_oid, fork, file_name);

    rel_file->file = fopen(file_name.mem, "r");

    string_drop(file_name);

    rel_file->fork = fork;
    rel_file->rel_oid = rel_oid;

    return rel_file;
}

void
rel_file_close(RelFile rel_file) 
{
    assert(rel_file_is_valid(rel_file));

    fclose(rel_file->file);

    rel_file_drop(rel_file);
}