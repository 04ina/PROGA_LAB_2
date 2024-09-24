#include "headers/Page.h"

#include <stdbool.h>
#include "stdlib.h"

#include "headers/RawPage.h"

Page
page_init(void) 
{
    Page page = malloc(sizeof(Page));

    return page;
}

void
page_drop(Page page) 
{
    raw_page_drop(page->raw_content);
    page_header_drop(page->header);  

    free(page);
}

Page
page_read(unsigned int rel_oid, ForkType fork, PageNumber page_number)
{
    Page    page;

    RawPage raw_page;
    PageHeader page_header;

    bool found;

    page = page_init();

    raw_page = raw_page_read(rel_oid, fork, page_number);
    
    page_header = raw_page_parse_header(page->raw_content);

    page->raw_content = raw_page;
    page->header = page_header;
    page->number = page_number;
    page->fork = fork;
    page->rel_oid = rel_oid;

    return page;
}
