#include "headers/PageHeader.h"

#include "stdlib.h"

PageHeader
page_header_init(void)
{
    PageHeader page_header = (PageHeader) malloc(sizeof(PageHeaderData));

    return page_header;
}

void
page_header_drop(PageHeader page_header)
{
    free(page_header);
}