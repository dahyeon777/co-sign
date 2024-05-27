package com.android.example.camerexf2;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import java.util.Random;

import com.bumptech.glide.Glide;

public class SetImageActivity2 extends AppCompatActivity {

    private Button button11;
    private Button button12;
    private Button button14;
    private Button button15;
    private Button button16;
    private TextView resultText;
    private TextView scoreText;
    private int gap;


    @SuppressLint({"MissingInflatedId", "SetTextI18n"})
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_set_image2);


        /*resultText = findViewById(R.id.resultText);
        scoreText=findViewById(R.id.scoreText);

        if (Math.random() < 0.1) {
            resultText.setText("통과입니다");
            int minScore = 60;
            int maxScore = 83;
            int randomScore = (int) (Math.random() * (maxScore - minScore + 1) + minScore);
            scoreText.setText(String.valueOf(randomScore));

        } else {
            resultText.setText("실패입니다");
            int minScore = 12;
            int maxScore = 39;
            int randomScore = (int) (Math.random() * (maxScore - minScore + 1) + minScore);
            scoreText.setText(String.valueOf(randomScore)+ "%");

        }*/

        // resultText 초기화

        // resultText 초기 값 설정
        /*while(true){
            if (gap<3){
                resultText.setText("통과입니다");
                int minScore = 60;
                int maxScore = 89;
                int randomScore = (int) (Math.random() * (maxScore - minScore + 1) + minScore);
                scoreText.setText(String.valueOf(randomScore));
                gap++;
                break;
            }
            if(gap==3){
                resultText.setText("실패입니다");
                int minScore = 32;
                int maxScore = 59;
                int randomScore = (int) (Math.random() * (maxScore - minScore + 1) + minScore);
                scoreText.setText(String.valueOf(randomScore)+ "%");
                gap++;
                break;
            }
            else{
                if (Math.random() < 0.7) {
                    resultText.setText("통과입니다");
                    int minScore = 60;
                    int maxScore = 83;
                    int randomScore = (int) (Math.random() * (maxScore - minScore + 1) + minScore);
                    scoreText.setText(String.valueOf(randomScore));
                    gap++;
                    break;
                } else {
                    resultText.setText("실패입니다");
                    int minScore = 32;
                    int maxScore = 59;
                    int randomScore = (int) (Math.random() * (maxScore - minScore + 1) + minScore);
                    scoreText.setText(String.valueOf(randomScore)+ "%");
                    gap++;
                    break;
                }

            }
        }
*/





        ImageView imageView = findViewById(R.id.iv_image);

        String imagePath = getIntent().getStringExtra("path");
        /*textView.setText(imagePath);*/
        Glide.with(this).load(imagePath).into(imageView);

        button11 = findViewById(R.id.button11);
        button11.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(SetImageActivity2.this, StudyImageActivity.class);
                startActivity(intent);
            }
        });

        button12 = findViewById(R.id.button12);
        button12.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(SetImageActivity2.this, GetImageActivity2.class);
                startActivity(intent);
            }
        });

        button14 = findViewById(R.id.button14);
        button14.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(SetImageActivity2.this, StudyImageActivity.class);
                startActivity(intent);
            }
        });

        ////////////////////Load로 넘어가는 버튼
        /*button15 = findViewById(R.id.button15);
        button15.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 확률에 따라 통과 또는 실패 문구 표시


                Intent intent = new Intent(SetImageActivity2.this, LoadImageActivity2.class);
                intent.putExtra("path", imagePath);
                startActivity(intent);
            }
        });*/



        button16 = findViewById(R.id.button16);
        button16.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                button16.setText("\u2605");
            }
        });
    }
}
