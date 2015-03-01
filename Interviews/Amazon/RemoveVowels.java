/*
 * Amazon OA: RemoveVowels.java
 * Description: remove all the vowels of a given string
 *
 */

public class RemoveVowels{
    public static String removeVowels(String str){
        StringBuilder sb = new StringBuilder();
        String vowels = "aeiouAEIOU";

        for(int i = 0; i < str.length(); i++){
            if(vowels.indexOf(str.charAt(i)) == -1){
                sb.append(str.charAt(i));
            }
        }

        return sb.toString();
    }
    
    public static void test(String str){
        System.out.println("Original string: " + str);
        System.out.println("Now: " + removeVowels(str) + "\n");
    }

    public static void main(String args[]){
        test("I love you!");
    
        test("Hm my zk tst tst!");
    
    }
};
