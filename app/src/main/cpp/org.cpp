#include <jni.h>

// Write C++ code here.
//
// Do not forget to dynamically load the C++ library into your application.
//
// For instance,
//
// In MainActivity.java:
//    static {
//       System.loadLibrary("org");
//    }
//
// Or, in MainActivity.kt:
//    companion object {
//      init {
//         System.loadLibrary("org")
//      }
//    }
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1Mat__(JNIEnv *env, jclass clazz) {
    // TODO: implement n_Mat()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1Mat_III(JNIEnv *env, jclass clazz, jint rows, jint cols, jint type) {
    // TODO: implement n_Mat()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1Mat__III(JNIEnv *env, jclass clazz, jint rows, jint cols, jint type) {
    // TODO: implement n_Mat()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1Mat__I_3II(JNIEnv *env, jclass clazz, jint ndims, jintArray sizes,
                                       jint type) {
    // TODO: implement n_Mat()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1Mat__IIILjava_nio_ByteBuffer_2(JNIEnv *env, jclass clazz, jint rows,
                                                           jint cols, jint type, jobject data) {
    // TODO: implement n_Mat()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1Mat__IIILjava_nio_ByteBuffer_2J(JNIEnv *env, jclass clazz, jint rows,
                                                            jint cols, jint type, jobject data,
                                                            jlong step) {
    // TODO: implement n_Mat()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1Mat__DDI(JNIEnv *env, jclass clazz, jdouble size_width,
                                     jdouble size_height, jint type) {
    // TODO: implement n_Mat()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1Mat__IIIDDDD(JNIEnv *env, jclass clazz, jint rows, jint cols, jint type,
                                         jdouble s_val0, jdouble s_val1, jdouble s_val2,
                                         jdouble s_val3) {
    // TODO: implement n_Mat()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1Mat__DDIDDDD(JNIEnv *env, jclass clazz, jdouble size_width,
                                         jdouble size_height, jint type, jdouble s_val0,
                                         jdouble s_val1, jdouble s_val2, jdouble s_val3) {
    // TODO: implement n_Mat()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1Mat__I_3IIDDDD(JNIEnv *env, jclass clazz, jint ndims, jintArray sizes,
                                           jint type, jdouble s_val0, jdouble s_val1,
                                           jdouble s_val2, jdouble s_val3) {
    // TODO: implement n_Mat()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1Mat__JIIII(JNIEnv *env, jclass clazz, jlong m_native_obj,
                                       jint row_range_start, jint row_range_end,
                                       jint col_range_start, jint col_range_end) {
    // TODO: implement n_Mat()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1Mat__JII(JNIEnv *env, jclass clazz, jlong m_native_obj,
                                     jint row_range_start, jint row_range_end) {
    // TODO: implement n_Mat()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1Mat__J_3Lorg_opencv_core_Range_2(JNIEnv *env, jclass clazz,
                                                             jlong m_native_obj,
                                                             jobjectArray ranges) {
    // TODO: implement n_Mat()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1adjustROI__JIIII(JNIEnv *env, jclass clazz, jlong native_obj, jint dtop,
                                             jint dbottom, jint dleft, jint dright) {
    // TODO: implement n_adjustROI()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_core_Mat_n_1assignTo__JJI(JNIEnv *env, jclass clazz, jlong native_obj,
                                          jlong m_native_obj, jint type) {
    // TODO: implement n_assignTo()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_core_Mat_n_1assignTo__JJ(JNIEnv *env, jclass clazz, jlong native_obj,
                                         jlong m_native_obj) {
    // TODO: implement n_assignTo()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_n_1channels__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_channels()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_n_1checkVector__JIIZ(JNIEnv *env, jclass clazz, jlong native_obj,
                                              jint elem_channels, jint depth,
                                              jboolean require_continuous) {
    // TODO: implement n_checkVector()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_n_1checkVector__JII(JNIEnv *env, jclass clazz, jlong native_obj,
                                             jint elem_channels, jint depth) {
    // TODO: implement n_checkVector()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_n_1checkVector__JI(JNIEnv *env, jclass clazz, jlong native_obj,
                                            jint elem_channels) {
    // TODO: implement n_checkVector()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1clone__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_clone()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1col__JI(JNIEnv *env, jclass clazz, jlong native_obj, jint x) {
    // TODO: implement n_col()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1colRange__JII(JNIEnv *env, jclass clazz, jlong native_obj,
                                          jint startcol, jint endcol) {
    // TODO: implement n_colRange()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_n_1dims__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_dims()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_n_1cols__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_cols()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_core_Mat_n_1convertTo__JJIDD(JNIEnv *env, jclass clazz, jlong native_obj,
                                             jlong m_native_obj, jint rtype, jdouble alpha,
                                             jdouble beta) {
    // TODO: implement n_convertTo()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_core_Mat_n_1convertTo__JJID(JNIEnv *env, jclass clazz, jlong native_obj,
                                            jlong m_native_obj, jint rtype, jdouble alpha) {
    // TODO: implement n_convertTo()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_core_Mat_n_1convertTo__JJI(JNIEnv *env, jclass clazz, jlong native_obj,
                                           jlong m_native_obj, jint rtype) {
    // TODO: implement n_convertTo()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_core_Mat_n_1copyTo__JJ(JNIEnv *env, jclass clazz, jlong native_obj,
                                       jlong m_native_obj) {
    // TODO: implement n_copyTo()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_core_Mat_n_1copyTo__JJJ(JNIEnv *env, jclass clazz, jlong native_obj,
                                        jlong m_native_obj, jlong mask_native_obj) {
    // TODO: implement n_copyTo()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_core_Mat_n_1create__JIII(JNIEnv *env, jclass clazz, jlong native_obj, jint rows,
                                         jint cols, jint type) {
    // TODO: implement n_create()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_core_Mat_n_1create__JDDI(JNIEnv *env, jclass clazz, jlong native_obj,
                                         jdouble size_width, jdouble size_height, jint type) {
    // TODO: implement n_create()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_core_Mat_n_1create__JI_3II(JNIEnv *env, jclass clazz, jlong native_obj, jint ndims,
                                           jintArray sizes, jint type) {
    // TODO: implement n_create()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_core_Mat_n_1copySize__JJ(JNIEnv *env, jclass clazz, jlong native_obj,
                                         jlong m_native_obj) {
    // TODO: implement n_copySize()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1cross__JJ(JNIEnv *env, jclass clazz, jlong native_obj,
                                      jlong m_native_obj) {
    // TODO: implement n_cross()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1dataAddr__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_dataAddr()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_n_1depth__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_depth()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1diag__JI(JNIEnv *env, jclass clazz, jlong native_obj, jint d) {
    // TODO: implement n_diag()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1diag__J(JNIEnv *env, jclass clazz, jlong d_native_obj) {
    // TODO: implement n_diag()
}
extern "C"
JNIEXPORT jdouble JNICALL
Java_org_opencv_core_Mat_n_1dot__JJ(JNIEnv *env, jclass clazz, jlong native_obj,
                                    jlong m_native_obj) {
    // TODO: implement n_dot()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1elemSize__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_elemSize()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1elemSize1__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_elemSize1()
}
extern "C"
JNIEXPORT jboolean JNICALL
Java_org_opencv_core_Mat_n_1empty__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_empty()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1eye__III(JNIEnv *env, jclass clazz, jint rows, jint cols, jint type) {
    // TODO: implement n_eye()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1eye__DDI(JNIEnv *env, jclass clazz, jdouble size_width,
                                     jdouble size_height, jint type) {
    // TODO: implement n_eye()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1inv__JI(JNIEnv *env, jclass clazz, jlong native_obj, jint method) {
    // TODO: implement n_inv()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1inv__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_inv()
}
extern "C"
JNIEXPORT jboolean JNICALL
Java_org_opencv_core_Mat_n_1isContinuous__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_isContinuous()
}
extern "C"
JNIEXPORT jboolean JNICALL
Java_org_opencv_core_Mat_n_1isSubmatrix__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_isSubmatrix()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_core_Mat_locateROI_10__J_3D_3D(JNIEnv *env, jclass clazz, jlong native_obj,
                                               jdoubleArray whole_size_out, jdoubleArray ofs_out) {
    // TODO: implement locateROI_0()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1mul__JJD(JNIEnv *env, jclass clazz, jlong native_obj,
                                     jlong m_native_obj, jdouble scale) {
    // TODO: implement n_mul()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1mul__JJ(JNIEnv *env, jclass clazz, jlong native_obj,
                                    jlong m_native_obj) {
    // TODO: implement n_mul()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1ones__III(JNIEnv *env, jclass clazz, jint rows, jint cols, jint type) {
    // TODO: implement n_ones()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1ones__DDI(JNIEnv *env, jclass clazz, jdouble size_width,
                                      jdouble size_height, jint type) {
    // TODO: implement n_ones()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1ones__I_3II(JNIEnv *env, jclass clazz, jint ndims, jintArray sizes,
                                        jint type) {
    // TODO: implement n_ones()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_core_Mat_n_1push_1back__JJ(JNIEnv *env, jclass clazz, jlong native_obj,
                                           jlong m_native_obj) {
    // TODO: implement n_push_back()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_core_Mat_n_1release__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_release()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1reshape__JII(JNIEnv *env, jclass clazz, jlong native_obj, jint cn,
                                         jint rows) {
    // TODO: implement n_reshape()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1reshape__JI(JNIEnv *env, jclass clazz, jlong native_obj, jint cn) {
    // TODO: implement n_reshape()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1reshape_11__JII_3I(JNIEnv *env, jclass clazz, jlong native_obj, jint cn,
                                               jint newndims, jintArray newsz) {
    // TODO: implement n_reshape_1()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1row__JI(JNIEnv *env, jclass clazz, jlong native_obj, jint y) {
    // TODO: implement n_row()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1rowRange__JII(JNIEnv *env, jclass clazz, jlong native_obj,
                                          jint startrow, jint endrow) {
    // TODO: implement n_rowRange()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_n_1rows__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_rows()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1setTo__JDDDD(JNIEnv *env, jclass clazz, jlong native_obj,
                                         jdouble s_val0, jdouble s_val1, jdouble s_val2,
                                         jdouble s_val3) {
    // TODO: implement n_setTo()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1setTo__JDDDDJ(JNIEnv *env, jclass clazz, jlong native_obj,
                                          jdouble s_val0, jdouble s_val1, jdouble s_val2,
                                          jdouble s_val3, jlong mask_native_obj) {
    // TODO: implement n_setTo()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1setTo__JJJ(JNIEnv *env, jclass clazz, jlong native_obj,
                                       jlong value_native_obj, jlong mask_native_obj) {
    // TODO: implement n_setTo()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1setTo__JJ(JNIEnv *env, jclass clazz, jlong native_obj,
                                      jlong value_native_obj) {
    // TODO: implement n_setTo()
}
extern "C"
JNIEXPORT jdoubleArray JNICALL
Java_org_opencv_core_Mat_n_1size__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_size()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_n_1size_1i__JI(JNIEnv *env, jclass clazz, jlong native_obj, jint i) {
    // TODO: implement n_size_i()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1step1__JI(JNIEnv *env, jclass clazz, jlong native_obj, jint i) {
    // TODO: implement n_step1()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1step1__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_step1()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1submat_1rr__JIIII(JNIEnv *env, jclass clazz, jlong native_obj,
                                              jint row_range_start, jint row_range_end,
                                              jint col_range_start, jint col_range_end) {
    // TODO: implement n_submat_rr()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1submat_1ranges(JNIEnv *env, jclass clazz, jlong native_obj,
                                           jobjectArray ranges) {
    // TODO: implement n_submat_ranges()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1submat__JIIII(JNIEnv *env, jclass clazz, jlong native_obj, jint roi_x,
                                          jint roi_y, jint roi_width, jint roi_height) {
    // TODO: implement n_submat()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1t__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_t()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1total__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_total()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_n_1type__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_type()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1zeros__III(JNIEnv *env, jclass clazz, jint rows, jint cols, jint type) {
    // TODO: implement n_zeros()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1zeros__DDI(JNIEnv *env, jclass clazz, jdouble size_width,
                                       jdouble size_height, jint type) {
    // TODO: implement n_zeros()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_core_Mat_n_1zeros__I_3II(JNIEnv *env, jclass clazz, jint ndims, jintArray sizes,
                                         jint type) {
    // TODO: implement n_zeros()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_core_Mat_n_1delete__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement n_delete()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nPutD__JIII_3D(JNIEnv *env, jclass clazz, jlong self, jint row, jint col,
                                        jint count, jdoubleArray data) {
    // TODO: implement nPutD()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nPutDIdx__J_3II_3D(JNIEnv *env, jclass clazz, jlong self, jintArray idx,
                                            jint count, jdoubleArray data) {
    // TODO: implement nPutDIdx()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nPutF__JIII_3F(JNIEnv *env, jclass clazz, jlong self, jint row, jint col,
                                        jint count, jfloatArray data) {
    // TODO: implement nPutF()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nPutFIdx__J_3II_3F(JNIEnv *env, jclass clazz, jlong self, jintArray idx,
                                            jint count, jfloatArray data) {
    // TODO: implement nPutFIdx()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nPutI__JIII_3I(JNIEnv *env, jclass clazz, jlong self, jint row, jint col,
                                        jint count, jintArray data) {
    // TODO: implement nPutI()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nPutIIdx__J_3II_3I(JNIEnv *env, jclass clazz, jlong self, jintArray idx,
                                            jint count, jintArray data) {
    // TODO: implement nPutIIdx()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nPutS__JIII_3S(JNIEnv *env, jclass clazz, jlong self, jint row, jint col,
                                        jint count, jshortArray data) {
    // TODO: implement nPutS()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nPutSIdx__J_3II_3S(JNIEnv *env, jclass clazz, jlong self, jintArray idx,
                                            jint count, jshortArray data) {
    // TODO: implement nPutSIdx()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nPutB__JIII_3B(JNIEnv *env, jclass clazz, jlong self, jint row, jint col,
                                        jint count, jbyteArray data) {
    // TODO: implement nPutB()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nPutBIdx__J_3II_3B(JNIEnv *env, jclass clazz, jlong self, jintArray idx,
                                            jint count, jbyteArray data) {
    // TODO: implement nPutBIdx()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nPutBwOffset__JIIII_3B(JNIEnv *env, jclass clazz, jlong self, jint row,
                                                jint col, jint count, jint offset,
                                                jbyteArray data) {
    // TODO: implement nPutBwOffset()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nPutBwIdxOffset__J_3III_3B(JNIEnv *env, jclass clazz, jlong self,
                                                    jintArray idx, jint count, jint offset,
                                                    jbyteArray data) {
    // TODO: implement nPutBwIdxOffset()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nGetB__JIII_3B(JNIEnv *env, jclass clazz, jlong self, jint row, jint col,
                                        jint count, jbyteArray vals) {
    // TODO: implement nGetB()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nGetBIdx__J_3II_3B(JNIEnv *env, jclass clazz, jlong self, jintArray idx,
                                            jint count, jbyteArray vals) {
    // TODO: implement nGetBIdx()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nGetS__JIII_3S(JNIEnv *env, jclass clazz, jlong self, jint row, jint col,
                                        jint count, jshortArray vals) {
    // TODO: implement nGetS()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nGetSIdx__J_3II_3S(JNIEnv *env, jclass clazz, jlong self, jintArray idx,
                                            jint count, jshortArray vals) {
    // TODO: implement nGetSIdx()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nGetI__JIII_3I(JNIEnv *env, jclass clazz, jlong self, jint row, jint col,
                                        jint count, jintArray vals) {
    // TODO: implement nGetI()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nGetIIdx__J_3II_3I(JNIEnv *env, jclass clazz, jlong self, jintArray idx,
                                            jint count, jintArray vals) {
    // TODO: implement nGetIIdx()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nGetF__JIII_3F(JNIEnv *env, jclass clazz, jlong self, jint row, jint col,
                                        jint count, jfloatArray vals) {
    // TODO: implement nGetF()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nGetFIdx__J_3II_3F(JNIEnv *env, jclass clazz, jlong self, jintArray idx,
                                            jint count, jfloatArray vals) {
    // TODO: implement nGetFIdx()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nGetD__JIII_3D(JNIEnv *env, jclass clazz, jlong self, jint row, jint col,
                                        jint count, jdoubleArray vals) {
    // TODO: implement nGetD()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_core_Mat_nGetDIdx__J_3II_3D(JNIEnv *env, jclass clazz, jlong self, jintArray idx,
                                            jint count, jdoubleArray vals) {
    // TODO: implement nGetDIdx()
}
extern "C"
JNIEXPORT jdoubleArray JNICALL
Java_org_opencv_core_Mat_nGet__JII(JNIEnv *env, jclass clazz, jlong self, jint row, jint col) {
    // TODO: implement nGet()
}
extern "C"
JNIEXPORT jdoubleArray JNICALL
Java_org_opencv_core_Mat_nGetIdx__J_3I(JNIEnv *env, jclass clazz, jlong self, jintArray idx) {
    // TODO: implement nGetIdx()
}
extern "C"
JNIEXPORT jstring JNICALL
Java_org_opencv_core_Mat_nDump(JNIEnv *env, jclass clazz, jlong self) {
    // TODO: implement nDump()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_ml_KNearest_create_10__(JNIEnv *env, jclass clazz) {
    // TODO: implement create_0()
}
extern "C"
JNIEXPORT jlong JNICALL
Java_org_opencv_ml_KNearest_load_10(JNIEnv *env, jclass clazz, jstring filepath) {
    // TODO: implement load_0()
}
extern "C"
JNIEXPORT jboolean JNICALL
Java_org_opencv_ml_KNearest_getIsClassifier_10__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement getIsClassifier_0()
}
extern "C"
JNIEXPORT jfloat JNICALL
Java_org_opencv_ml_KNearest_findNearest_10__JJIJJJ(JNIEnv *env, jclass clazz, jlong native_obj,
                                                   jlong samples_native_obj, jint k,
                                                   jlong results_native_obj,
                                                   jlong neighbor_responses_native_obj,
                                                   jlong dist_native_obj) {
    // TODO: implement findNearest_0()
}
extern "C"
JNIEXPORT jfloat JNICALL
Java_org_opencv_ml_KNearest_findNearest_11__JJIJJ(JNIEnv *env, jclass clazz, jlong native_obj,
                                                  jlong samples_native_obj, jint k,
                                                  jlong results_native_obj,
                                                  jlong neighbor_responses_native_obj) {
    // TODO: implement findNearest_1()
}
extern "C"
JNIEXPORT jfloat JNICALL
Java_org_opencv_ml_KNearest_findNearest_12__JJIJ(JNIEnv *env, jclass clazz, jlong native_obj,
                                                 jlong samples_native_obj, jint k,
                                                 jlong results_native_obj) {
    // TODO: implement findNearest_2()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_ml_KNearest_getAlgorithmType_10__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement getAlgorithmType_0()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_ml_KNearest_getDefaultK_10__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement getDefaultK_0()
}
extern "C"
JNIEXPORT jint JNICALL
Java_org_opencv_ml_KNearest_getEmax_10__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement getEmax_0()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_ml_KNearest_setAlgorithmType_10__JI(JNIEnv *env, jclass clazz, jlong native_obj,
                                                    jint val) {
    // TODO: implement setAlgorithmType_0()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_ml_KNearest_setDefaultK_10__JI(JNIEnv *env, jclass clazz, jlong native_obj,
                                               jint val) {
    // TODO: implement setDefaultK_0()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_ml_KNearest_setEmax_10__JI(JNIEnv *env, jclass clazz, jlong native_obj, jint val) {
    // TODO: implement setEmax_0()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_ml_KNearest_setIsClassifier_10__JZ(JNIEnv *env, jclass clazz, jlong native_obj,
                                                   jboolean val) {
    // TODO: implement setIsClassifier_0()
}
extern "C"
JNIEXPORT void JNICALL
Java_org_opencv_ml_KNearest_delete__J(JNIEnv *env, jclass clazz, jlong native_obj) {
    // TODO: implement delete()
}