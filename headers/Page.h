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
    RawPage    raw_content;

    PageNumber number;
    ForkType fork;
    unsigned int rel_oid;
} PageData;

typedef PageData *Page;

extern Page page_init(void);

extern void page_drop(Page page);

extern Page page_read(unsigned int rel_oid, ForkType fork, PageNumber page_number);

#endif  /* PAGE_H */