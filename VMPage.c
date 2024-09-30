#include "headers/VMPage.h"

VMPage
VMPageInit(void)
{
    VMPage vmPage = (VMPage) malloc(sizeof(VMPageData));

    vmPage->data = PageInit();

    return vmPage;
}

void
VMPageDrop(VMPage vmPage)
{
    PageDrop(vmPage->data);
    free(vmPage);
}

/*
 * Чтение VM страницы
 */
void
VMPageRead(VMPage vmPage, unsigned int relOid, ForkType fork, PageNumber pageNumber)
{
    PageRead((Page) vmPage->data, relOid, fork, pageNumber);
}

/*
 * вывод в output данных VM старницы в необработанном виде 
 */
void
VMPagePrintRawData(VMPage vmPage, FILE *output)
{
    for(int i = 0; i < RAW_PAGE_SIZE; i++)
    {
        fprintf(output, "%x%x", 
                vmPage->data->rawContent->data[i] & (0xF0),   
                vmPage->data->rawContent->data[i] & (0x0F));
    }
}
