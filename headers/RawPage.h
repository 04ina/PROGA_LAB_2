/*------------------------------------------------------------------------- 
 *
 * RawPage.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef RAW_PAGE_H
#define RAW_PAGE_H

#include "RelFile.h"
#include "PageHeader.h"

#define RAW_PAGE_SIZE 8192

typedef struct RawPageData
{
    char *data;
} RawPageData;

typedef RawPageData *RawPage;

extern RawPage RawPageInit(void);

extern void RawPageDrop(RawPage rawPage);

extern void RawPageRead(RawPage rawPage, unsigned int relOid, ForkType fork, unsigned int pageNumber);

extern void RawPageParseHeader(RawPage rawPage, PageHeader pageHeader);

#endif  /* RAW_PAGE_H */