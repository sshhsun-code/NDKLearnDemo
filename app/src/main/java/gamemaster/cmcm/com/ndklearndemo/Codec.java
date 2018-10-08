package gamemaster.cmcm.com.ndklearndemo;

/**
 *  参考：https://www.jianshu.com/p/215133d64358
 *  HEX的编码和解码
 * Created by sunqi on 2018/10/8.
 */

public class Codec {
    static {
        //一定不要忘记调用!!!!
        System.loadLibrary("codec");
    }
    public static native String hexEncode(byte[] data);
    public static native byte[] hexDecode(String data);
}
