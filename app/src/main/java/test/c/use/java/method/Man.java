package test.c.use.java.method;

/**
 * Created by sunqi on 2018/10/8.
 *
 *
 * 测试结果：
 *
 修改前 ::::: Tom
 修改后 ::::: Tomandroid

 修改前 ::::: 18
 修改前 ::::: 19
 */

public class Man {

    static {
        System.loadLibrary("man-lib");
    }

    public String name = "Tom";//修改对象属性值

    public static int age = 18;//修改类属性值

    public native String accessField();//修改对象属性值 Tom -> Tomandroid

    public native String stringFromJNI();//修改类属性值18 -> 19

}
