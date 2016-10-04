package com.arrayfire;

public class Blas extends Array {

    private native static long matmul(long a, long b);

    public static void matmul(Array c, Array a, Array b) throws Exception {
        long ref = matmul(a.ref,b.ref);
        c.set(ref);
    }
}
