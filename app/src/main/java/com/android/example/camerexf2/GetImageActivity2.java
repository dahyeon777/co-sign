package com.android.example.camerexf2;

import androidx.appcompat.app.AppCompatActivity;

import androidx.core.app.ActivityCompat;
import androidx.core.content.FileProvider;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.provider.MediaStore;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import java.text.SimpleDateFormat;
import java.util.Date;
import android.Manifest;
import android.widget.TextView;
import android.os.Handler;


import com.bumptech.glide.Glide;
import java.io.File;
import java.io.IOException;

public class GetImageActivity2 extends AppCompatActivity implements View.OnClickListener {
    final int CAMERA = 100; // 카메라 선택시 인텐트로 보내는 값
    final int GALLERY = 101; // 갤러리 선택 시 인텐트로 보내는 값
    String imagePath = "";
    @SuppressLint("SimpleDateFormat")
    SimpleDateFormat imageDate = new SimpleDateFormat("yyyyMMdd_HHmmss");
    Intent intent;
    private Button button8;


    public ImageView imageView;
    Button btnCamera, btnGallery, btnMove;
    TextView explanation_text;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_get_image2);



        imageView = findViewById(R.id.iv_main);
        btnCamera = findViewById(R.id.btn_camera);
        btnGallery = findViewById(R.id.btn_gallery);
        btnMove = findViewById(R.id.btn_move);
        explanation_text = findViewById(R.id.explanation_text);


        btnCamera.setOnClickListener(this);
        btnGallery.setOnClickListener(this);
        btnMove.setOnClickListener(this);

        button8 = findViewById(R.id.button8);
        button8.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(GetImageActivity2.this, StudyImageActivity.class);
                startActivity(intent);
            }
        });



        //        권한 체크
        boolean hasCamPerm = false;
        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.M) {
            hasCamPerm = checkSelfPermission(Manifest.permission.CAMERA) == PackageManager.PERMISSION_GRANTED;
        }
        boolean hasWritePerm = false;
        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.M) {
            hasWritePerm = checkSelfPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE) == PackageManager.PERMISSION_GRANTED;
        }
        if (!hasCamPerm || !hasWritePerm)  // 권한 없을 시  권한설정 요청
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.CAMERA, Manifest.permission.WRITE_EXTERNAL_STORAGE}, 1);
    }

    @SuppressLint({"NonConstantResourceId", "QueryPermissionsNeeded"})
    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.btn_camera: // 카메라 선택 시
                intent = new Intent(android.provider.MediaStore.ACTION_IMAGE_CAPTURE);
                if (intent.resolveActivity(getPackageManager()) != null) {
                    File imageFile = null;
                    try {
                        imageFile = createImageFile();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    if (imageFile != null) {
                        Uri imageUri = FileProvider.getUriForFile(getApplicationContext(),
                                "com.android.example.camerexf.fileprovider",
                                imageFile);
                        intent.putExtra(MediaStore.EXTRA_OUTPUT, imageUri);
                        startActivityForResult(intent, CAMERA);

                    }
                }
                break;
            case R.id.btn_gallery: // 갤러리 선택 시
                intent = new Intent(Intent.ACTION_PICK);
                intent.setType(MediaStore.Images.Media.CONTENT_TYPE);
                intent.setType("image/*");
                startActivityForResult(intent, GALLERY);
                break;
            case R.id.btn_move: // 이동 선택 시
                if (imagePath.length() > 0) { // 이미지 경로가 있을 경우
                    // Handler를 사용하여 5초 대기 후에 실행되도록 설정
                    new Handler().postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            intent = new Intent(getApplicationContext(), SetImageActivity2.class);
                            intent.putExtra("path", imagePath);
                            startActivity(intent);
                        }
                    }, 1000); // 5초 대기

                    // 기존의 startActivity(intent); 부분은 주석 처리 또는 삭제합니다.
                }
                break;

        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (resultCode == Activity.RESULT_OK) { // 결과가 있을 경우
            if (requestCode == GALLERY) { // 갤러리 선택한 경우
//				1) data의 주소 사용하는 방법
                imagePath = data.getDataString(); // "content://media/external/images/media/7215"
//				2) 절대경로 사용하는 방법
                Cursor cursor = getContentResolver().query(data.getData(), null, null, null, null);
                if (cursor != null) {
                    cursor.moveToFirst();
                    int index = cursor.getColumnIndex(MediaStore.Images.ImageColumns.DATA);
                    imagePath = cursor.getString(index); // "/media/external/images/media/7215"
                    cursor.close();
                }
            }

            if (imagePath.length() > 0) {
                explanation_text.setVisibility(View.GONE);//설명 텍스트 없앰
                Glide.with(this)
                        .load(imagePath)
                        .into(imageView);
            }
        }
    }

    @SuppressLint("SimpleDateFormat")
    File createImageFile() throws IOException {
//        이미지 파일 생성
        String timeStamp = imageDate.format(new Date()); // 파일명 중복을 피하기 위한 "yyyyMMdd_HHmmss"꼴의 timeStamp
        String fileName = "IMAGE_" + timeStamp; // 이미지 파일 명
        File storageDir = getExternalFilesDir(Environment.DIRECTORY_PICTURES);
        File file = File.createTempFile(fileName, ".jpg", storageDir); // 이미지 파일 생성
        imagePath = file.getAbsolutePath(); // 파일 절대경로 저장하기
        return file;
    }
}