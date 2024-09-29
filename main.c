#include "headers/AdvString.h"
#include "headers/FSMPage.h"
#include "headers/Page.h"
#include "headers/PageHandler.h"
#include "headers/PageHeader.h"
#include "headers/RawPage.h"
#include "headers/RelFile.h"
#include "headers/VMPage.h"

void
main(void)
{
    RelFile relFile;
    RawPage rawPage;
    String str;
    Page page;
    VMPage vmPage;
    FSMPage fsmPage;
    PageHandler pageHandler;

    /*
     * AdvString example 
     */    
    str = StringInit(10);

    StringDrop(str);

    /*
     * RelFile and RawPage examples
     */
    relFile = RelFileInit(1247, FSM_FORK); 
    RelFileOpenForRead(relFile);

    rawPage = RawPageInit();
    RelFileReadRawPage(relFile, 0, rawPage->data);
    RawPageDrop(rawPage);

    RelFileClose(relFile);
    RelFileDrop(relFile);


    rawPage = RawPageInit();
    RawPageRead(rawPage , 1247, FSM_FORK, 0);
    RawPageDrop(rawPage);

    /*
     * Page and PageHeaders examples
     */
    page = PageInit();

    PageRead(page, 1247, FSM_FORK, 0);
    printf("%hd", page->header->pd_pagesize_version);

    PageDrop(page);

    /*
     * VMPage and FSMPage examples:
     */
    vmPage = VMPageInit();
    fsmPage = FSMPageInit();

    VMPageRead(vmPage, 1247, VM_FORK, 0);
    FSMPageRead(fsmPage, 1247, FSM_FORK, 0);

    VMPagePrintRawData(vmPage, stdout);
    printf("\n-------------\n");
    FSMPagePrintRawData(fsmPage, stdout);

    VMPageDrop(vmPage);
    FSMPageDrop(fsmPage);

    printf("\n");

    /*
     * Page handler example:
     */
    pageHandler = PageHandlerInit();

    PageHandlerSetOutput(pageHandler, stdout);
    PageHandlerSetInput(pageHandler, stdin);

    PageHandlerPrintRawFSMPage(pageHandler, 1247, FSM_FORK, 0);
    printf("\n-------------\n");
    PageHandlerPrintRawVMPage(pageHandler, 1247, FSM_FORK, 0);

    PageHandlerDrop(pageHandler);
}