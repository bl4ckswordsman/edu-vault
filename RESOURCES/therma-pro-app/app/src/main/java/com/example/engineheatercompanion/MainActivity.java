package com.example.engineheatercompanion;

import android.annotation.SuppressLint;
import android.app.TimePickerDialog;
import android.os.Bundle;
import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.snackbar.Snackbar;
import com.google.android.material.tabs.TabLayout;
import androidx.core.app.NotificationCompat;
import androidx.core.app.NotificationManagerCompat;
import androidx.viewpager.widget.ViewPager;
import androidx.appcompat.app.AppCompatActivity;
import android.view.View;
import android.webkit.WebChromeClient;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Button;
import android.widget.TimePicker;
import com.example.engineheatercompanion.ui.main.SectionsPagerAdapter;
import com.example.engineheatercompanion.databinding.ActivityMainBinding;


public class MainActivity extends AppCompatActivity {

    Button timeButton;
    int hour,minute;
    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        timeButton = findViewById(R.id.timeButton);

        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        SectionsPagerAdapter sectionsPagerAdapter = new SectionsPagerAdapter(this, getSupportFragmentManager());
        ViewPager viewPager = binding.viewPager;
        viewPager.setAdapter(sectionsPagerAdapter);
        TabLayout tabs = binding.tabs;
        tabs.setupWithViewPager(viewPager);
        FloatingActionButton fab = binding.fab;

        fab.setOnClickListener(new View.OnClickListener() {
            WebView webView;
            WebView webView2;

            public String fileName = "sundsvallweather.html";
            public String fileName2 = "sundsvallweather2.html";

            @SuppressLint("SetJavaScriptEnabled")
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Funktion inte implementerad", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();

                // init webView
                webView = (WebView) findViewById(R.id.simpleWebView);
                webView2 = (WebView) findViewById(R.id.simpleWebView2);
                // displaying content in WebView from html file that stored in assets folder
                webView.getSettings().setJavaScriptEnabled(true);
                webView.getSettings().setDomStorageEnabled(true);
                webView.setWebChromeClient(new WebChromeClient());
                webView.setWebViewClient(new WebViewClient());

                webView.loadUrl("file:///android_asset/" + fileName);

                webView2.getSettings().setJavaScriptEnabled(true);
                webView2.getSettings().setDomStorageEnabled(true);
                webView2.setWebChromeClient(new WebChromeClient());
                webView2.setWebViewClient(new WebViewClient());
                webView2.loadUrl("file:///android_asset/" + fileName2);
            }
        });
    }

    public void popTimePicker(View view) {
        TimePickerDialog.OnTimeSetListener onTimeSetListener = new TimePickerDialog.OnTimeSetListener() {
            @Override
            public void onTimeSet(TimePicker timePicker, int selectedHour, int selectedMinute) {
                //hour = selectedHour;
                //minute = selectedMinute;
                //timeButton.setText(String.format(Locale.getDefault(), "%02d:%02d",hour, minute));
            }
        };

        // int style = AlertDialog.THEME_HOLO_DARK;

        TimePickerDialog timePickerDialog = new TimePickerDialog(this, /*style,*/ onTimeSetListener, hour, minute, true);

        timePickerDialog.setTitle("Välj tid");
        timePickerDialog.show();
    }

    public void headsUpNotification(View view) {
        NotificationCompat.Builder builder = new NotificationCompat.Builder(this,Utils.CHANNEL_ID)
                .setSmallIcon(R.mipmap.ic_launcher)
                .setContentTitle(Utils.NOTI_TITLE)
                .setContentText(Utils.NOTI_DESC)
                .setPriority(NotificationCompat.PRIORITY_HIGH)
                .setAutoCancel(true);

        NotificationManagerCompat notificationManagerCompat = NotificationManagerCompat.from(this);
        notificationManagerCompat.notify(Utils.NOTI_ID,builder.build());

    }
}