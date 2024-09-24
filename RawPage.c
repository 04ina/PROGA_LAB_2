#include "headers/RawPage.h"

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

RawPage
raw_page_init(void)
{
    RawPage raw_page;
    
    raw_page = malloc(sizeof(RawPageData));

    raw_page->data = (void *) malloc(8192);

    return raw_page;
}

void
raw_page_drop(RawPage raw_page)
{
    free(raw_page->data);
    free(raw_page);
}

RawPage
raw_page_read(unsigned int rel_oid, ForkType fork, unsigned int page_number)
{
    RelFile rel_file;
    bool found;
    RawPage raw_page;

    raw_page = raw_page_init();

    rel_file = rel_file_open_for_read(rel_oid, fork); 

    found = rel_file_read_raw_page(rel_file, page_number, raw_page->data);
    if (!found)
    {
        assert(0);
    }

    rel_file_close(rel_file); 

    return raw_page;
}

PageHeader
raw_page_parse_header(RawPage raw_page)
{
    PageHeader page_header;

    page_header = page_header_init();

    memcpy(page_header, raw_page->data, sizeof(PageHeader));

    return page_header;
}

