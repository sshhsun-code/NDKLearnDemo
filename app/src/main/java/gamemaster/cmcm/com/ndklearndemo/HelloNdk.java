package gamemaster.cmcm.com.ndklearndemo;

/**
 * Created by sunqi on 2018/10/8.
 */

public class HelloNdk {

    static {
        System.loadLibrary("hello");
    }

    public static native String sayHello();

    public static native String sayok();

    public static native void printLog(String log);
}
