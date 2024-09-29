#include "headers/PageHandler.h"
#include "headers/VMPage.h"
#include "headers/FSMPage.h"

#include <stdlib.h>
#include <stdio.h>

PageHandler
PageHandlerInit(void)
{
    PageHandler pageHandler = (PageHandler) malloc(sizeof(PageHandlerData));

    pageHandler->output = NULL;
    pageHandler->input = NULL;
}

void
PageHandlerDrop(PageHandler pageHandler)
{
    free(pageHandler);
}

void
PageHandlerSetOutput(PageHandler pageHandler, FILE *output)
{
    pageHandler->output = output;
}

void
PageHandlerSetInput(PageHandler pageHandler, FILE *input)
{
    pageHandler->input = input;
}

bool
PageHandlerPrintRawFSMPage(PageHandler pageHandler, unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    FSMPage fsmPage;
    if (pageHandler->output == NULL)
    {
        fprintf(stdout, "The page_header output is not specified");
        return false;
    }

    FILE *output = pageHandler->output;
    
    fsmPage = FSMPageInit();

    FSMPageRead(fsmPage, relOid, fork, pageNumber);
    
    FSMPagePrintRawData(fsmPage, output);
    
    FSMPageDrop(fsmPage);

    return true;
}

bool
PageHandlerPrintRawVMPage(PageHandler pageHandler, unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    VMPage vmPage;

    if (pageHandler->output == NULL)
    {
        fprintf(stdout, "The page_header output is not specified");
        return false;
    }

    FILE *output = pageHandler->output;

    vmPage = VMPageInit();
    
    VMPageRead(vmPage, relOid, fork, pageNumber);
    
    VMPagePrintRawData(vmPage, output);
    
    VMPageDrop(vmPage);

    return true;
}