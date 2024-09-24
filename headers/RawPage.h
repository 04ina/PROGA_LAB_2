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
    void *data;
} RawPageData;

typedef RawPageData *RawPage;

extern RawPage raw_page_init(void);

extern void raw_page_drop(RawPage raw_page);

extern RawPage raw_page_read(unsigned int rel_oid, ForkType fork, unsigned int page_number);

extern PageHeader raw_page_parse_header(RawPage raw_page);

#endif  /* RAW_PAGE_H */