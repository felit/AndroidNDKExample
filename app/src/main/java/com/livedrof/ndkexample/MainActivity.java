package com.livedrof.ndkexample;

import static android.view.KeyEvent.KEYCODE_0;
import static android.view.KeyEvent.KEYCODE_F;
import static android.view.KeyEvent.KEYCODE_HOME;
import static android.view.KeyEvent.KEYCODE_R;
import static android.view.KeyEvent.KEYCODE_SLEEP;

import androidx.appcompat.app.AppCompatActivity;

import android.hardware.input.InputManager;
import android.os.Bundle;
import android.os.SystemClock;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.widget.TextView;

import com.livedrof.ndkexample.databinding.ActivityMainBinding;
import com.livedrof.ndkexample.dto.SystemInfoDTO;

import java.util.Date;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'ndkexample' library on application startup.
    static {
        System.loadLibrary("ndkexample");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(ss());
        binding.inputManagerButton.setOnClickListener(new View.OnClickListener() {
                                                          @Override
                                                          public void onClick(View v) {
                                                              InputManager inputManager = InputManager.getInstance();
                                                              System.out.println(inputManager);
                                                              Log.i("input:", inputManager.toString());
                                                              MainActivity.this.pressKey(inputManager,KEYCODE_0);
                                                              MainActivity.this.pressKey(inputManager,KEYCODE_F);
                                                              MainActivity.this.pressKey(inputManager,KEYCODE_R);
                                                              MainActivity.this.pressKey(inputManager,KEYCODE_SLEEP);

                                                          }
                                                      }
        );
    }

    private void pressKey(InputManager inputManager,int keyCode) {
        long now = SystemClock.uptimeMillis();
        KeyEvent down = new KeyEvent(now, now, KeyEvent.ACTION_DOWN,keyCode, 0);
        Log.i("down:", down.toString());
        inputManager.injectInputEvent(down, InputManager.INJECT_INPUT_EVENT_MODE_ASYNC);

        now = SystemClock.uptimeMillis();
        KeyEvent up = new KeyEvent(now, now, KeyEvent.ACTION_UP,keyCode, 0);
        Log.i("up:", up.toString());
        inputManager.injectInputEvent(up, InputManager.INJECT_INPUT_EVENT_MODE_ASYNC);
    }

    /*  *
     * A native method that is implemented by the 'ndkexample' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native String string2FromJNI();

    public native String dtoFromJNI(byte byteVal,
                                    char charVal,
                                    int intVal,
                                    long lVal,
                                    boolean bVal,
                                    float fVal,
                                    double dVal,
                                    Date date,
                                    SystemInfoDTO dto
    );

    public String ss() {
        return this.dtoFromJNI((byte) 1, 'c', 12, 23L, true, 1.0f, 2.33D, new Date(), new SystemInfoDTO());
    }
}