#include "headers/FSMPage.h"

FSMPage
fsm_page_init(void)
{
    FSMPage fsm_page = (FSMPage) malloc(sizeof(FSMPageData));

    fsm_page->data = page_init();

    return fsm_page;
}

void
fsm_page_drop(FSMPage fsm_page)
{
    page_drop(fsm_page->data);
    free(fsm_page);
}

FSMPage
fsm_page_read(unsigned int rel_oid, ForkType fork, PageNumber page_number)
{
    FSMPage fsm_page;
    
    fsm_page = (FSMPage) page_read(rel_oid, fork, page_number);

    return fsm_page;
}

void
fsm_page_print_raw_data(FSMPage fsm_page, FILE *output)
{
    for(int i = 0; i < RAW_PAGE_SIZE; i++)
    {
        fprintf(output, "%x%x", 
                fsm_page->data->raw_content->data[i] & (0xF0),   
                fsm_page->data->raw_content->data[i] & (0x0F));
    }
}