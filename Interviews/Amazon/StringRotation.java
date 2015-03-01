/*
 *    Amazon OA: StringRotation.java
 *    Description:  check if string s2 is a rotation of string s1
 *                     
 */

public class StringRotation{
    public static int isRotation(String s1, String s2){
        if(s1 == null || s2 == null || s1.length() == 0 || s2.length() == 0)
            return -1;

        if(s1.length() != s2.length())  return -1;

        String ss = s1 + s1;
        int ret = ss.indexOf(s2) != -1 ? 1 : -1;

        return ret;
    }

    public static void test(String s1, String s2){
        if(isRotation(s1, s2) == 1)
            System.out.println(s2 + " is a rotation of " + s1);
        else
            System.out.println(s2 + " is not a rotation of " + s1);
    }
    
    
    public static void main(String[] args){
        String s1 = "abcd";
        String s2 = "bcda";
        
        test(s1, s2);

        s2 = "";
        test(s1, s2);

        s1 = "";
        test(s1, s2);
    }
};

