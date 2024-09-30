/*------------------------------------------------------------------------- 
 *
 * FSMPage.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef FSMPAGE_H
#define FSMPAGE_H

#include "Page.h"
#include "stdlib.h"

typedef struct FSMPageData
{
    Page data;
} FSMPageData;

typedef FSMPageData *FSMPage;

extern FSMPage FSMPageInit(void);

extern void FSMPageDrop(FSMPage fsmPage);

extern void FSMPageRead(FSMPage fsmPage, unsigned int relOid, ForkType fork, PageNumber pageNumber);

extern void FSMPagePrintRawData(FSMPage fsmPage, FILE *output);

#endif  /* FSMPAGE_H*/
