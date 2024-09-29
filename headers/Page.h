/*------------------------------------------------------------------------- 
 *
 * Page.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef PAGE_H
#define PAGE_H

#include "RawPage.h"
#include "PageHeader.h"
#include "RelFile.h"

typedef unsigned int PageNumber;

typedef struct PageData 
{
    /* dynamic variables */

    /* static variables */
    PageHeader header;
    RawPage    rawContent;

    PageNumber number;
    ForkType fork;
    unsigned int relOid;
} PageData;

typedef PageData *Page;

extern Page PageInit(void);

extern void PageDrop(Page page);

extern void PageRead(Page page, unsigned int rel_oid, ForkType fork, PageNumber page_number);

#endif  /* PAGE_H */