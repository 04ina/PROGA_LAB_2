/*------------------------------------------------------------------------- 
 *
 * FSMPage.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef FSMPAGE_H
#define FSMPAGE_H

#include "Page.h"
#include "stdlib.h"

typedef struct FSMPageData
{
    // static var:
    Page data;
} FSMPageData;

typedef FSMPageData *FSMPage;

extern FSMPage fsm_page_init(void);

extern void fsm_page_drop(FSMPage fsm_page);

extern FSMPage fsm_page_read(unsigned int rel_oid, ForkType fork, PageNumber page_number);

extern void fsm_page_print_raw_data(FSMPage fsm_page, FILE *output);

#endif  /* FSMPAGE_H*/