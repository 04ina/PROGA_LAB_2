/*------------------------------------------------------------------------- 
 *
 * PageHandler.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef PAGE_HANDLER_H
#define PAGE_HANDLER_H

#include "RelFile.h"
#include "RawPage.h"
#include "VMPage.h"
#include "FSMPage.h"

typedef struct PageHandlerData
{
    //static vars:
    FILE *output;
    FILE *input;

} PageHandlerData;

typedef PageHandlerData *PageHandler;

extern PageHandler PageHandlerInit(void);

extern void PageHandlerDrop(PageHandler pageHandler);

extern void PageHandlerSetOutput(PageHandler pageHandler, FILE *output);

extern void PageHandlerSetInput(PageHandler pageHandler, FILE *input);

extern bool PageHandlerPrintRawFSMPage(PageHandler pageHandler, unsigned int relOid, ForkType fork, PageNumber pageNumber);

extern bool PageHandlerPrintRawVMPage(PageHandler pageHandler, unsigned int relOid, ForkType fork, PageNumber pageNumber);

#endif  /* PAGE_HANDLER_H */