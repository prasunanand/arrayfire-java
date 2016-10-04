#include "jni_helper.h"

BEGIN_EXTERN_C

#define LAPACK_FUNC(FUNC) AF_MANGLE(Lapack, FUNC)

#define LAPACK_OP_DEF(func)                                \
    JNIEXPORT jdouble JNICALL LAPACK_FUNC(func)            \
                    (JNIEnv *env, jclass clazz,jlong a){   \
        double real, imaginary;                            \
        (af_##func(&real, &imaginary, ARRAY(a)));          \
        return real;                                       \
    }

#define LAPACK_FAC_DEF(func)                               \
    JNIEXPORT jlong JNICALL LAPACK_FUNC(func)              \
                    (JNIEnv *env, jclass clazz, jlong a){  \
        af_array ret = 0;                                  \
        AF_TO_JAVA(af_##func(&ret, 0, ARRAY(a), true ));   \
        return JLONG(ret);                                 \
    }

LAPACK_OP_DEF(det)
LAPACK_FAC_DEF(cholesky)

END_EXTERN_C
