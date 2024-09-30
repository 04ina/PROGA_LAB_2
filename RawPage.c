#include "headers/RawPage.h"

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

RawPage
RawPageInit(void)
{
    RawPage rawPage;
    
    rawPage = malloc(sizeof(RawPageData));

    rawPage->data = (char *) malloc(RAW_PAGE_SIZE);

    return rawPage;
}

void
RawPageDrop(RawPage rawPage)
{
    free(rawPage->data);
    free(rawPage);
}

/*
 * Получение сырой страницы.
 */
void
RawPageRead(RawPage rawPage, unsigned int relOid, ForkType fork, unsigned int pageNumber)
{
    RelFile relFile;
    bool found;

    relFile = RelFileInit(relOid, fork);
    RelFileOpenForRead(relFile); 
    
    found = RelFileReadRawPage(relFile, pageNumber, rawPage->data);
    if (!found)
    {
        assert(0);
    }

    RelFileClose(relFile); 
    RelFileDrop(relFile);
}

/*
 * парсинг заголовка страницы
 */ 
void
RawPageParseHeader(RawPage rawPage, PageHeader pageHeader)
{
    memcpy(pageHeader, rawPage->data, sizeof(PageHeaderData));
}
