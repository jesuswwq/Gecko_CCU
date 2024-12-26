#ifndef COMPILER_H
#define COMPILER_H
#ifdef __cplusplus
extern "C" {
#endif
#ifndef STATIC
#define STATIC  static
#endif
#ifndef NULL_PTR
#define NULL_PTR ((void *)0)
#endif
#define INLINE              __inline
#define LOCAL_INLINE            static __inline
#define INTERRUPT_FUNC
#define FUNC(rettype, memclass) rettype
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *
#define P2P2VAR(ptrtype, memclass, ptrclass) ptrtype **
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype * const
#define P2FUNC(rettype, ptrclass, fctname) rettype (*fctname)
#define CONST(consttype, memclass) const consttype
#define VAR(vartype, memclass) vartype
#define CONSTP2FUNC(rettype, ptrclass, fctname) rettype (* const fctname)
#define FUNC_P2CONST(rettype, ptrclass, memclass) const ptrclass rettype * memclass
#define FUNC_P2VAR(rettype, ptrclass, memclass) ptrclass rettype * memclass

#define AUTOSAR_OS_NOT_USED
#ifdef __cplusplus
}
#endif /* #ifndef COMPILER_H */
#endif
