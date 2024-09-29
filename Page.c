#include "headers/Page.h"

#include <stdbool.h>
#include "stdlib.h"

#include "headers/RawPage.h"

Page
PageInit(void) 
{
    Page page = malloc(sizeof(PageData));

    return page;
}

void
PageDrop(Page page) 
{
    PageHeaderDrop(page->header);  
    RawPageDrop(page->rawContent);

    free(page);
}

void
PageRead(Page page, unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    RawPage rawPage;
    PageHeader pageHeader;

    bool found;

    rawPage = RawPageInit();
    RawPageRead(rawPage, relOid, fork, pageNumber);

    pageHeader = PageHeaderInit();
    RawPageParseHeader(rawPage, pageHeader);

    page->rawContent = rawPage;
    page->header = pageHeader;
    page->number = pageNumber;
    page->fork = fork;
    page->relOid = relOid;
}
