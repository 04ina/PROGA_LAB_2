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
    FILE        *file;

    RelOid      relOid;
    ForkType    fork;
} RelFileData;

typedef RelFileData *RelFile;

extern RelFile RelFileInit(RelOid relOid, ForkType fork);

extern void RelFileDrop(RelFile relFile);

extern bool RelFileReadRawPage(RelFile relFile, unsigned int pageNumber, char *rawPage);

extern void RelFileOpenForRead(RelFile relFile);

extern void RelFileClose(RelFile relFile);

#endif  /* REL_FILE_H */