package gamemaster.cmcm.com.ndklearndemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import java.util.Locale;

import test.c.use.java.method.Man;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("hello");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        String hello = HelloNdk.sayHello();
        Log.e("sunqi_log", hello);
        findViewById(R.id.sample_text).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                HelloNdk.printLog("view info" + view);
                hexCodec();
                testMan();
            }
        });
    }

    private void hexCodec() {
        String s = Codec.hexEncode(new byte[]{0x3c, 0x7c});
        Log.d("sunqi_log", "onCreate: s ==> " + s);
        byte[] bytes = Codec.hexDecode(s);

        for (byte aByte : bytes) {
            Log.d("sunqi_log", "onCreate: byte ==> " + String.format(Locale.CANADA, "%x",aByte ));
        }
    }

    private void testMan() {
        Man man = new Man();
        Log.e("sunqi_log",  " 修改前 ::::: " + man.name);

        String access = man.accessField();

        Log.e("sunqi_log",  " 修改后 ::::: " + man.name);


        Log.e("sunqi_log",  " 修改前 ::::: " + Man.age);

        String strFromJNI = man.stringFromJNI();


        Log.e("sunqi_log",  " 修改前 ::::: " + Man.age);
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
