
/* framework */
#include "cdefs.h"
#include "debug.h"
#include "reentry_test.h"

static reentryType globalReentryTest _SECTION(.dma_buffer);

static void reentryMain(reentryType* item)
{
    if(item->isvalid){
        item->lastResult = item->function(item->priv);
        item->isvalid = 0;
        item->ispending = 0;
    }
}
/**
 * @description:
 * @param {void*} priv
 * @param {void*} function
 * @return {*}
 */
void  rentrySet(reentryType*item,void* priv,ReEntryTestType function)
{
    item->priv = priv;
    item->function = function;
    item->ispending = 1;
    item->lastResult = 0;
    item->isvalid = 1;
}
/**
 * @description:
 * @param {reentryType*} item
 * @return {*}
 */
char reentryTestPolling(reentryType* item)
{
    return item->ispending;
}
/**
 * @description:
 * @param {reentryType*} item
 * @return {*}
 */
int reentryTestGetResult(reentryType* item)
{
    return item->lastResult;
}
/**
 * @description:
 * @return {*}
 */
void reentryMainSerial(void)
{
    reentryMain(&globalReentryTest);
}
/**
 * @description:
 * @param {void*} priv
 * @param {void*} function
 * @return {*}
 */
void  rentrySetSerial(void* priv,ReEntryTestType function)
{
     rentrySet(&globalReentryTest,priv,function);
}
/**
 * @description:
 * @return {*}
 */
char reentryTestPollingSerial(void)
{
    return reentryTestPolling(&globalReentryTest);
}
/**
 * @description:
 * @return {*}
 */
int reentryTestGetResultSerial(void)
{
    return reentryTestGetResult(&globalReentryTest);
}