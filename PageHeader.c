#include "headers/PageHeader.h"

#include "stdlib.h"

PageHeader
PageHeaderInit(void)
{
    PageHeader pageHeader = (PageHeader) malloc(sizeof(PageHeaderData));

    return pageHeader;
}

void
PageHeaderDrop(PageHeader page_header)
{
    free(page_header);
}