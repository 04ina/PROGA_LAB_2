/*------------------------------------------------------------------------- 
 *
 * PageHeader.h
 * 
 *------------------------------------------------------------------------- 
 */

#ifndef PAGE_HEADER_H
#define PAGE_HEADER_H

/*
 *  pd_lsn	PageXLogRecPtr	8 байт	LSN: Следующий байт после последнего байта записи xlog для последнего изменения на этой странице
 *  pd_checksum	uint16	2 байта	Контрольная сумма страницы
 *  pd_flags	uint16	2 байта	Биты признаков
 *  pd_lower	LocationIndex	2 байта	Смещение до начала свободного пространства
 *  pd_upper	LocationIndex	2 байта	Смещение до конца свободного пространства
 *  pd_special	LocationIndex	2 байта	Смещение до начала специального пространства
 *  pd_pagesize_version	uint16	2 байта	Информация о размере страницы и номере версии компоновки
 *  pd_prune_xid	TransactionId	4 байта	Самый старый неочищенный идентификатор XMAX на странице или ноль при отсутствии такового 
*/ 
typedef struct PageHeaderData 
{
    long long int pg_lsn;
    short pd_checksum;
    short pg_flags;
    short pd_lower;
    short pd_upper;
    short pd_special;
    short pd_pagesize_version;
    int pd_prune_xid;

} PageHeaderData;

typedef PageHeaderData *PageHeader;

extern PageHeader PageHeaderInit(void);

extern void PageHeaderDrop(PageHeader pageHeader);

#endif  /* PAGE_HEADER_H */ 