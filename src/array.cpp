#include "jni_helper.h"

BEGIN_EXTERN_C

#define ARRAY_FUNC(FUNC) AF_MANGLE(Array, FUNC)

JNIEXPORT void JNICALL ARRAY_FUNC(destroyArray)(JNIEnv *env, jclass clazz, jlong ref)
{
    AF_TO_JAVA(af_release_array(ARRAY(ref)));
}

JNIEXPORT jintArray JNICALL ARRAY_FUNC(getDims)(JNIEnv *env, jclass clazz, jlong ref)
{
    jintArray result = env->NewIntArray(MaxDimSupported);
    if (result == NULL) {
        return NULL;
    }

    dim_t dims[4];
    AF_TO_JAVA(af_get_dims(dims + 0,
                           dims + 1,
                           dims + 2,
                           dims + 3,
                           ARRAY(ref)));

    jint* dimsf  = env->GetIntArrayElements(result, 0);

    for(int k=0; k<MaxDimSupported; ++k) {
        dimsf[k] = dims[k];
    }
    env->ReleaseIntArrayElements(result, dimsf, 0);

    return result;
}

JNIEXPORT jint JNICALL ARRAY_FUNC(getType)(JNIEnv *env, jclass clazz, jlong ref)
{
    af_dtype ty = f32;
    AF_TO_JAVA(af_get_type(&ty, ARRAY(ref)));
    return ty;
}

END_EXTERN_C
