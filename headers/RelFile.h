/*------------------------------------------------------------------------- 
 *
 * RelFile.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef REL_FILE_H 
#define REL_FILE_H

#include <stdio.h>
#include <stdbool.h>

typedef int RelOid;

typedef enum ForkType {
    MAIN_FORK,
    FSM_FORK,
    VM_FORK,
    INIT_FORK,
} ForkType;

typedef struct RelFileData
{
    FILE    *file;

    RelOid  rel_oid;
    ForkType  fork;
} RelFileData;

typedef RelFileData *RelFile;

extern RelFile rel_file_init(void);

extern void rel_file_drop(RelFile rel_file);

extern bool rel_file_read_raw_page(RelFile rel_file, unsigned int page_number, char *raw_page);

extern RelFile rel_file_open_for_read(RelOid rel_oid, ForkType fork);

extern void rel_file_close(RelFile rel_file);

#endif  /* REL_FILE_H */