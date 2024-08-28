#ifndef _REENTRY_TEST_H_
#define _REENTRY_TEST_H_

#include<stdint.h>
/* framework */

typedef int (*ReEntryTestType)(void* );

typedef struct reentryTypeTag
{
    void* priv;
    ReEntryTestType function;
    int lastResult;
    char ispending;
    char isvalid;
}reentryType;

void reentryMainSerial(void);
char reentryTestPollingSerial(void);
int  reentryTestGetResultSerial(void);
void rentrySetSerial(void* priv,ReEntryTestType function);
char reentryTestPolling(reentryType* item);
int  reentryTestGetResult(reentryType* item);
void rentrySet(reentryType* item,void* priv,ReEntryTestType function);


/*
user demo:
// 定义自己的重入回调 -- 必须的
typedef int (*Spi_ReEntryTestType)(void* );
// 定义自己的重入回参数类型 -- 可选的
typedef struct {

}xxx_t;
// 实现自己的回调接口
int xxx_test((void* parms)
{
    xxx_t *param = (xxx_t *)priv;
    Spi_Function(param->1,param->2,......);
    return 0;
}
*/

#endif