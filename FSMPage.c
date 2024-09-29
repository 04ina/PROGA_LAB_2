#include "headers/FSMPage.h"

FSMPage
FSMPageInit(void)
{
    FSMPage fsmPage = (FSMPage) malloc(sizeof(FSMPageData));

    fsmPage->data = PageInit();

    return fsmPage;
}

void
FSMPageDrop(FSMPage fsmPage)
{
    PageDrop(fsmPage->data);
    free(fsmPage);
}

void
FSMPageRead(FSMPage fsmPage, unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    PageRead((Page) fsmPage->data, relOid, fork, pageNumber);
}

void
FSMPagePrintRawData(FSMPage fsmPage, FILE *output)
{
    for(int i = 0; i < RAW_PAGE_SIZE; i++)
    {
        fprintf(output, "%u ", 
                fsmPage->data->rawContent->data[i] & 0x000000FF);
    }
}