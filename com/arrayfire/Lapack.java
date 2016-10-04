package com.arrayfire;

public class Lapack extends Array {

    // Binary operations
    private native static double det(long a);
    private native static long cholesky(long a);


    public static double det(Array a) throws Exception {
        return det(a.ref);
    }

    public static void cholesky(Array c, Array a) throws Exception {
        long ref = cholesky(a.ref);
        c.set(ref);
    }
}