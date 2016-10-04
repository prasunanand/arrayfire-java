#include "jni_helper.h"

BEGIN_EXTERN_C

#define BLAS_FUNC(FUNC) AF_MANGLE(Blas, FUNC)

#define BLAS_OP_DEF(func)                                       \
    JNIEXPORT jlong JNICALL BLAS_FUNC(func)(JNIEnv *env,        \
                                             jclass clazz,      \
                                             jlong a, jlong b)  \
    {                                                           \
        af_array ret = 0;                                       \
        AF_TO_JAVA(af_##func(&ret, ARRAY(a), ARRAY(b),          \
                            AF_MAT_NONE , AF_MAT_NONE ));       \
        return JLONG(ret);                                      \
    }

BLAS_OP_DEF(matmul)

END_EXTERN_C
