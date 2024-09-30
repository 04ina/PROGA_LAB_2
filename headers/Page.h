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
    /* Заголовок страницы */
    PageHeader header;

    /* Необработанная страницы */
    RawPage    rawContent;

    /* Номер страницы */
    PageNumber number;

    /* Слой страницы */
    ForkType fork;

    /* oid отношения, которому принадлежит страница */
    unsigned int relOid;
} PageData;

typedef PageData *Page;

extern Page PageInit(void);

extern void PageDrop(Page page);

extern void PageRead(Page page, unsigned int rel_oid, ForkType fork, PageNumber page_number);

#endif  /* PAGE_H */
