#include "headers/VMPage.h"

VMPage
vm_page_init(void)
{
    VMPage vm_page = (VMPage) malloc(sizeof(VMPageData));

    vm_page->data = page_init();

    return vm_page;
}

void
vm_page_drop(VMPage vm_page)
{
    page_drop(vm_page->data);
    free(vm_page);
}

VMPage
vm_page_read(unsigned int rel_oid, ForkType fork, PageNumber page_number)
{
    VMPage vm_page;
    
    vm_page = (VMPage) page_read(rel_oid, fork, page_number);

    return vm_page;
}

void
vm_page_print_raw_data(VMPage vm_page, FILE *output)
{
    for(int i = 0; i < RAW_PAGE_SIZE; i++)
    {
        fprintf(output, "%x%x", 
                vm_page->data->raw_content->data[i] & (0xF0),   
                vm_page->data->raw_content->data[i] & (0x0F));
    }
}