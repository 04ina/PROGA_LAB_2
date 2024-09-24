/*------------------------------------------------------------------------- 
 *
 * VMPage.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef VMPAGE_H
#define VMPAGE_H

#include "Page.h"
#include "stdlib.h"

typedef struct VMPageData
{
    // static var:
    Page data;
} VMPageData;

typedef VMPageData *VMPage;

extern VMPage vm_page_init(void);

extern void vm_page_drop(VMPage vm_page);

extern VMPage vm_page_read(unsigned int rel_oid, ForkType fork, PageNumber page_number);

extern void vm_page_print_raw_data(VMPage vm_page, FILE *output);

#endif  /* VMPAGE_H*/