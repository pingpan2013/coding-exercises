/*
 * Amazon OA: Gray Check
 * Check if two bytes could be placed consectively in a gray code sequence
 *
 **/

public class GrayCheck{
    public static int grayCheck(byte b1, byte b2){
        byte ret = (byte)(b1 ^ b2);
        int cnt = 0;

        while(ret > 0){
            cnt ++;
            ret &= (ret - 1);
        }

        return (cnt == 1) ? 1 : -1;
    }

    public static void test(byte b1, byte b2){
        if(grayCheck(b1, b2) == 1)
            System.out.println("Yes they could");
        else
            System.out.println("No they could not");
    }
    
    
    public static void main(String[] args){
        byte b1 = 0x01;
        byte b2 = 0x02;

        test(b1, b2);  // no

        b1 = 0x03;
        test(b1, b2);  // yes
        
        b1 = 0x00;
        test(b1, b2); // yes
    }
};

