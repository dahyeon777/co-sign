package com.android.example.camerexf2;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.net.http.SslError;
import android.os.Build;
import android.os.Bundle;
import android.security.KeyChain;
import android.security.KeyChainAliasCallback;
import android.view.View;
import android.webkit.SslErrorHandler;
import android.webkit.WebChromeClient;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Button;
import android.widget.Toast;

import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.security.KeyStore;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;

import javax.net.ssl.SSLContext;
import javax.net.ssl.TrustManagerFactory;

public class StudyImageActivity extends AppCompatActivity {


    private Button button4;
    private WebView webView;



    @SuppressLint("SetJavaScriptEnabled")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_study_image);

        button4 = findViewById(R.id.button4);
        button4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(StudyImageActivity.this, GetImageActivity2.class);
                startActivity(intent);
            }
        });


        KeyChain.choosePrivateKeyAlias(this, new KeyChainAliasCallback() {
            @Override
            public void alias(String alias) {
                // 인증서 등록이 완료되면 호출됨
            }
        }, new String[] { "https://sldict.korean.go.kr/multimedia/multimedia_files/convert/20220802/1005695/MOV000359820_700X466.webm" }, null, null, -1, null);

        // WebView 위젯 초기화
        webView = findViewById(R.id.webView);

        // SSL 인증서 로드
        addSslCertificate();

        // WebView 설정
        WebSettings webSettings = webView.getSettings();
        webSettings.setJavaScriptEnabled(true);  // 자바스크립트 사용 가능하도록 설정


        webView.setWebViewClient(new WebViewClient() {
            @SuppressLint("WebViewClientOnReceivedSslError")
            @Override
            public void onReceivedSslError(WebView view, SslErrorHandler handler, SslError error) {
                handler.proceed();
            }
        });  // WebViewClient 설정
        webView.setWebChromeClient(new WebChromeClient() {
            @Override
            public void onProgressChanged(WebView view, int newProgress) {
                if (newProgress == 100) {
                    // 로딩 완료 시 실행할 코드
                }
            }
        });
        String videoUrl = "https://sldict.korean.go.kr/multimedia/multimedia_files/convert/20220802/1005695/MOV000359820_700X466.webm";
        try {
            webView.loadUrl(videoUrl);  // WebView에 URL 로드
        } catch (Exception e) {
            Toast.makeText(this, "Error loading webpage", Toast.LENGTH_SHORT).show();
            e.printStackTrace();
        }
    }




    // Back 버튼 클릭 시 웹뷰에서 이전 페이지로 이동
    @Override
    public void onBackPressed() {
        if (webView.canGoBack()) {
            webView.goBack();
        } else {
            super.onBackPressed();
        }
    }

    @SuppressLint("SetJavaScriptEnabled")
    private void addSslCertificate() {
        try {
            // 인증서를 메모리에 로드
            CertificateFactory cf = CertificateFactory.getInstance("X.509");
            InputStream caInput = getResources().openRawResource(R.raw.korean2);
            X509Certificate caCert = (X509Certificate) cf.generateCertificate(caInput);
            caInput.close();

            // KeyStore 생성
            KeyStore keyStore = KeyStore.getInstance(KeyStore.getDefaultType());
            keyStore.load(null, null);
            keyStore.setCertificateEntry("caCert", caCert);

            // TrustManager 생성
            TrustManagerFactory tmf = TrustManagerFactory.getInstance(TrustManagerFactory.getDefaultAlgorithm());
            tmf.init(keyStore);

            // SSLContext 생성
            SSLContext sslContext = SSLContext.getInstance("TLS");
            sslContext.init(null, tmf.getTrustManagers(), null);

            // WebView에 SSLContext 추가
            webView.setWebViewClient(new WebViewClient() {
                @SuppressLint("WebViewClientOnReceivedSslError")
                @Override
                public void onReceivedSslError(WebView view, SslErrorHandler handler, SslError error) {
                    handler.proceed();
                }
            });
            webView.setLayerType(View.LAYER_TYPE_HARDWARE, null);
            webView.getSettings().setCacheMode(WebSettings.LOAD_NO_CACHE);
            webView.getSettings().setJavaScriptEnabled(true);
            webView.setWebChromeClient(new WebChromeClient() {
                @Override
                public void onProgressChanged(WebView view, int newProgress) {
                    if (newProgress == 100) {
                        // 로딩 완료 시 실행할 코드
                    }
                }
            });
            webView.loadUrl("https://sldict.korean.go.kr/front/sign/signContentsView.do?origin_no=9344&top_category=CTE&category=&searchKeyword=%E3%84%B1&searchCondition=&search_gubun=&museum_type=00&current_pos_index=0");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}