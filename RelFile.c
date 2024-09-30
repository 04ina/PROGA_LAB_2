#include "headers/RelFile.h"

#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "headers/AdvString.h"

#define MAX_REL_FILE_NAME_SIZE 100

#define RAW_PAGE_SIZE 8192

#define INVALID_REL_FILE (RelFile) 0

/*
 * Проверка RelFIle на валидность
 */
static bool
RelFileIsValid(RelFile relFile)
{
    if (relFile == INVALID_REL_FILE) 
        return 0;
    else    
        return 1;
}

RelFile
RelFileInit(RelOid relOid, ForkType fork)
{
    RelFile relFile;

    relFile = malloc(sizeof(RelFileData)); 

    relFile->fork = fork;
    relFile->relOid = relOid;

    return relFile; 
}

void
RelFileDrop(RelFile relFile)
{
    free(relFile);
}

/*
 * Парсинг имени RelFile файла и запись результата в fileName
 */
static void
RelFileGetParseName(RelOid relOid, ForkType fork, String fileName)
{
    sprintf(fileName->ptr, "%d", (int) relOid);

    switch (fork)
    {
        case MAIN_FORK:
            break;
        case FSM_FORK:
            strcat(fileName->ptr, "_fsm");
            break;
        case VM_FORK:
            strcat(fileName->ptr, "_vm");
            break;
        case INIT_FORK:
            strcat(fileName->ptr, "_init");
            break;
        default:
            assert(0);
    }
}

/*
 * Получение сырой страницы 
 */ 
bool
RelFileReadRawPage(RelFile relFile, unsigned int pageNumber, char *rawPage)
{
    FILE *file = relFile->file;
    int result;

    result = fseek(file, RAW_PAGE_SIZE * pageNumber, SEEK_SET);

    if (result != 0)
    {
        /* page not found */
        return false;
    }

    fread((char *) rawPage, RAW_PAGE_SIZE, 1, file);

    fseek(file, 0, SEEK_END);

    return true;
}

/*
 * Открытие RelFile для чтения
 */ 
void
RelFileOpenForRead(RelFile relFile) 
{
    char constFileName[MAX_REL_FILE_NAME_SIZE]; 

    String fileName = StringInit(MAX_REL_FILE_NAME_SIZE);

    RelFileGetParseName(relFile->relOid, relFile->fork, fileName);

    strcpy(constFileName, fileName->ptr);
    StringDrop(fileName);

    relFile->file = fopen(constFileName, "r");
}
/*
 * Закрытие открытого RelFile
 */ 
void
RelFileClose(RelFile relFile) 
{
    assert(RelFileIsValid(relFile));

    fclose(relFile->file);
}
