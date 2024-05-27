package com.android.example.camerexf2;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import org.opencv.android.BaseLoaderCallback;
import org.opencv.android.LoaderCallbackInterface;
import org.opencv.android.OpenCVLoader;
import org.opencv.android.Utils;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.MatOfPoint3f;
import org.opencv.core.Point3;
import org.opencv.imgproc.Imgproc;
import org.opencv.ml.KNearest;
import org.opencv.ml.Ml;
import org.opencv.utils.Converters;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

import static org.opencv.imgcodecs.Imgcodecs.imread;
import static org.opencv.imgproc.Imgproc.COLOR_BGR2RGB;
import static org.opencv.imgproc.Imgproc.cvtColor;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.Intent;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class LoadImageActivity2 extends AppCompatActivity {
    private static final String TAG = "LoadImageActivity2";
    public static String detectedGesture;
    private String imagePath;
    private static final String DATA_SET_FILE_NAME = "dataSet.txt";
    private Button loding_button;
    static {
        System.loadLibrary("opencv_java3");
    }



    private BaseLoaderCallback mLoaderCallback = new BaseLoaderCallback(this) {
        @Override
        public void onManagerConnected(int status) {
            switch (status) {
                case LoaderCallbackInterface.SUCCESS:
                    Log.i(TAG, "OpenCV 로드 성공1");

                    // OpenCV 초기화가 완료된 후에 처리할 작업 수행
                    boolean isInitialized = OpenCVLoader.initDebug();
                    performHandClassification();
                    break;
                default:
                    super.onManagerConnected(status);
                    break;
            }
        }
    };


    public static class ZipUtils {
        private static final String TAG = "ZipUtils";

        // dataSet.txt 파일을 압축 해제하고 내부 저장소에 저장하는 메서드
        public void extractAndSaveDataSet(Context context) {
            try {
                InputStream inputStream = context.getAssets().open("dataSet.zip");
                File outputFile = new File(context.getFilesDir(), "dataSet.txt");

                // 압축 해제된 파일을 저장할 FileOutputStream 생성
                FileOutputStream fileOutputStream = new FileOutputStream(outputFile);

                // ZipInputStream 생성하여 압축 파일 열기
                ZipInputStream zipInputStream = new ZipInputStream(inputStream);

                // 압축 파일에서 엔트리(파일) 하나씩 읽어오기
                ZipEntry zipEntry = zipInputStream.getNextEntry();

                // dataSet.txt 파일을 찾아서 압축 해제하여 저장
                while (zipEntry != null) {
                    String entryName = zipEntry.getName();
                    if (entryName.equals("dataSet.txt")) {
                        // 압축 해제된 파일로 데이터 복사
                        byte[] buffer = new byte[1024];
                        int length;
                        while ((length = zipInputStream.read(buffer)) > 0) {
                            fileOutputStream.write(buffer, 0, length);
                        }
                        break; // dataSet.txt 파일을 찾았으면 반복 종료
                    }

                    zipEntry = zipInputStream.getNextEntry();
                }

                // 리소스 정리
                zipInputStream.close();
                fileOutputStream.close();
                inputStream.close();

                Log.i(TAG, "데이터셋 경로: " + outputFile.getAbsolutePath());
                Log.i(TAG, "데이터셋 성공");

            } catch (IOException e) {
                Log.i(TAG, "데이터셋 실패");
                e.printStackTrace();
            }
        }
    }

    public static class MyHandTrackingClass {
        private static final String[] GESTURE_LABELS = {
                "ga", "na", "da", "ra", "ma", "ba", "sa", "a", "ja", "cha",
                "ka", "ta", "pa", "ha"
        };

        private KNearest knn;
        private List<List<Float>> angleData;
        private List<Float> labelData;
        private Context context;

        private float[][] getSubset(MatOfPoint3f joint) {
            int[][] indices = {{0, 1, 2, 3, 0, 5, 6, 7, 0, 9, 10, 11, 0, 13, 14, 15, 0, 17, 18, 19}};
            Point3[] jointArray = joint.toArray();
            float[][] subset = new float[indices[0].length][3];

            if (jointArray.length > 0) {
                for (int i = 0; i < subset.length; i++) {
                    int index = indices[0][i];
                    if (index < jointArray.length) {
                        Point3 point = jointArray[index];
                        subset[i][0] = (float) point.x;
                        subset[i][1] = (float) point.y;
                        subset[i][2] = (float) point.z;
                    }
                }
            }

            return subset;
        }





        public MyHandTrackingClass(AssetManager assetManager, Context context) {
            this.context = context;

            try {
                // Load angle and label data from "dataSet.txt"
                InputStream fileStream = assetManager.open(DATA_SET_FILE_NAME);
                int fileSize = fileStream.available();
                byte[] buffer = new byte[fileSize];
                int bytesRead = fileStream.read(buffer);
                Log.d(TAG, "Read " + bytesRead + " bytes from the file");
                fileStream.close();

                String dataSetContent = new String(buffer);
                String[] lines = dataSetContent.split("\n");

                angleData = new ArrayList<>();
                labelData = new ArrayList<>();

                for (String line : lines) {
                    String[] values = line.split(",");
                    if (values.length != 21) {
                        // 데이터셋 형식이 잘못되었을 경우 오류 처리
                        Log.i(TAG, "데이터 셋 형식 잘못됨");
                        return;
                    }

                    List<Float> angles = new ArrayList<>();

                    for (int i = 0; i < 20; i++) {
                        angles.add(Float.parseFloat(values[i]));
                    }

                    angleData.add(angles);
                    labelData.add(Float.parseFloat(values[20]));
                }

                // Convert angle and label data to Mat objects
                List<Float> flattenedAngleData = new ArrayList<>();
                for (List<Float> sublist : angleData) {
                    flattenedAngleData.addAll(sublist);
                }
                Mat angleMat = Converters.vector_float_to_Mat(flattenedAngleData);

                Mat labelMat = new Mat(labelData.size(), 1, CvType.CV_32FC1);
                for (int i = 0; i < labelData.size(); i++) {
                    labelMat.put(i, 0, labelData.get(i));
                }

                // Create and train the K-Nearest Neighbors classifier
                knn = KNearest.create();
                knn.train(angleMat, Ml.ROW_SAMPLE, labelMat);
            } catch (IOException e) {
                e.printStackTrace();
                Log.i(TAG, "데이터셋 처리중 IOException 발생");
            }
        }


        public String classifyHand(MatOfPoint3f hand) {
            float[][] subset = getSubset(hand);

            List<Float> angles = new ArrayList<>();
            for (float[] point : subset) {
                double x = point[0] - subset[0][0];
                double y = point[1] - subset[0][1];
                double z = point[2] - subset[0][2];
                double r = Math.sqrt(x * x + y * y + z * z);
                angles.add((float) r);
            }

            // Convert angles to Mat object
            Mat anglesMat = new Mat(1, angles.size(), CvType.CV_32FC1);
            float[] anglesArray = new float[angles.size()];
            for (int i = 0; i < angles.size(); i++) {
                anglesArray[i] = angles.get(i);
            }
            anglesMat.put(0, 0, anglesArray);

            // Create Mat objects for results
            Mat results = new Mat();
            Mat neighborResponses = new Mat();
            Mat dists = new Mat();

            // Convert data types
            anglesMat.convertTo(anglesMat, CvType.CV_32F);
            results.convertTo(results, CvType.CV_32F);

            // Perform classification
            if (knn != null) { // Check if knn object is not null
                knn.findNearest(anglesMat, 1, results, neighborResponses, dists);

                float resultLabel = (float) results.get(0, 0)[0];
                int labelIndex = Math.round(resultLabel);
                if (labelIndex >= 0 && labelIndex < GESTURE_LABELS.length) {
                    return GESTURE_LABELS[labelIndex];
                } else {
                    return "Unknown";
                }
            } else {
                return "KNearest object is null";
            }
        }

    }

    private MyHandTrackingClass handTrackingClass;

    @SuppressLint("SetTextI18n")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_load_image2);

        // Initialize OpenCV
        if (!OpenCVLoader.initDebug()) {
            Log.i(TAG, "OpenCV 로드안됨2");
            OpenCVLoader.initAsync(OpenCVLoader.OPENCV_VERSION, this, mLoaderCallback);
        } else {
            Log.i(TAG, "OpenCV 로드됨2");
            mLoaderCallback.onManagerConnected(LoaderCallbackInterface.SUCCESS);
        }

        // Set up the loading button click listener
        @SuppressLint({"MissingInflatedId", "LocalSuppress"}) Button loadingButton = findViewById(R.id.loding_button);
        loadingButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                performHandClassification();
            }
        });

        TextView resultTextView = findViewById(R.id.resultText2);
        resultTextView.setText("No gesture detected.");

        // Load the dataset and initialize the hand tracking class
        AssetManager assetManager = getAssets();
        ZipUtils zipUtils = new ZipUtils();
        zipUtils.extractAndSaveDataSet(this);
        handTrackingClass = new MyHandTrackingClass(assetManager, this);
    }

    private void performHandClassification() {
        // Process the image and perform hand classification
        Bitmap imageBitmap = BitmapFactory.decodeResource(getResources(), R.drawable.ga);
        processImage(imageBitmap);
    }


    @SuppressLint("SetTextI18n")
    private void processImage(Bitmap imageBitmap) {
        if (handTrackingClass == null) {
            // handTrackingClass가 초기화되지 않았을 경우 처리
            Log.i(TAG, "핸드트레킹 초기화안됨");
            return;
        }

        // Convert bitmap to Mat
        Mat imageMat = new Mat();
        Utils.bitmapToMat(imageBitmap, imageMat);

        // Preprocess image
        Imgproc.cvtColor(imageMat, imageMat, Imgproc.COLOR_BGR2GRAY);
        Imgproc.GaussianBlur(imageMat, imageMat, new org.opencv.core.Size(3, 3), 0);

        // Perform hand detection
        // ...

        // Perform hand tracking
        MatOfPoint3f hand = new MatOfPoint3f();
        // ...

        // Perform hand classification
        String gesture = handTrackingClass.classifyHand(hand);
        detectedGesture = gesture;

        Log.i(TAG, "손동작은: " + gesture);

        // Update UI with the detected gesture
        TextView resultTextView = findViewById(R.id.resultText2);
        resultTextView.setText("Detected Gesture: " + gesture);
    }



    @Override
    protected void onResume() {
        super.onResume();
        /*OpenCVLoader.initAsync(OpenCVLoader.OPENCV_VERSION_3_0_0, this, mLoaderCallback);*/
        // OpenCV 초기화
        if (!OpenCVLoader.initDebug()) {
            Log.i(TAG, "OpenCV initialization failed");
        } else {
            Log.i(TAG, "OpenCV initialization successful");
            mLoaderCallback.onManagerConnected(LoaderCallbackInterface.SUCCESS);
        }
    }


    @Override
    protected void onPause() {
        super.onPause();
        if (OpenCVLoader.initDebug()) {

        }
    }
}
