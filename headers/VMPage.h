/*------------------------------------------------------------------------- 
 *
 * VMPage.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef VMPAGE_H
#define VMPAGE_H

#include "Page.h"
#include "stdlib.h"

typedef struct VMPageData
{
    // static var:
    Page data;
} VMPageData;

typedef VMPageData *VMPage;

extern VMPage VMPageInit(void);

extern void VMPageDrop(VMPage vmPage);

extern void VMPageRead(VMPage vmPage, unsigned int relOid, ForkType fork, PageNumber pageNumber);

extern void VMPagePrintRawData(VMPage vmPage, FILE *output);

#endif  /* VMPAGE_H*/