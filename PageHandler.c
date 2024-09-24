#include "headers/PageHandler.h"
#include "headers/VMPage.h"
#include "headers/FSMPage.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct PageHandlerData
{
    //static vars:
    FILE *output;
    FILE *input;

} PageHandlerData;

typedef PageHandlerData *PageHandler;

PageHandler
page_handler_init(void)
{
    PageHandler page_handler = (PageHandler) malloc(sizeof(PageHandlerData));

    page_handler->output = NULL;
    page_handler->input = NULL;
}

void
page_handler_drop(PageHandler page_handler)
{
    free(page_handler);

}

void
page_handler_set_output(PageHandler page_handler, FILE *output)
{
    page_handler->output = output;
}

void
page_handler_set_input(PageHandler page_handler, FILE *input)
{
    page_handler->input = input;
}

bool
page_handler_print_raw_fsm_page(PageHandler page_handler, unsigned int rel_oid, ForkType fork, PageNumber page_number)
{
    FSMPage fsm_page;
    if (page_handler->output == NULL)
    {
        fprintf(stdout, "The page_header output is not specified");
        return false;
    }

    FILE *output = page_handler->output;

    fsm_page = fsm_page_read(rel_oid, fork, page_number);

    fsm_page_print_raw_data(fsm_page, output);

    fsm_page_drop(fsm_page);

    return true;
}

bool
page_handler_print_raw_vm_page(PageHandler page_handler, unsigned int rel_oid, ForkType fork, PageNumber page_number)
{
    VMPage vm_page;
    if (page_handler->output == NULL)
    {
        fprintf(stdout, "The page_header output is not specified");
        return false;
    }

    FILE *output = page_handler->output;

    vm_page = vm_page_read(rel_oid, fork, page_number);

    vm_page_print_raw_data(vm_page, output);

    vm_page_drop(vm_page);

    return true;
}