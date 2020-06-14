// package JAVA.algorithmOfXiaoHui.RemoveKDigits;

// /**
//  * 删除整数的k个数字，或得删除后的最小值
//  * @param strNum 原整数用字符串表示
//  * @param nK 删除的数量
//  * @return 删除后的最小值
//  */

// class String
// {
//     public  String removeKDigits(String strNum, int nK)
// {
//     int newLength = strNum.length() - k;

//     char[] stack = new char[strNum.length()];

//     int top = 0;

//     for (int i = 0; i < strNum.length(); ++i)
//     {
//         char c = strNum.charAt(i);

//         while(top > 0 && stack[top-1] > c && k > 0)
//         {
//             top -= 1;
//             k -= 1;
//         }
//         stack[top++] = c;
//     }

//     int offset = 0;
//     while(offset < newLength && stack[offset] == '0')
//     {
//         ++offset;
//     }
       
//     return offset == newLength ? "0": new String(stack, offset, newLength - offset);

// }


// public static void main(String[] args)
// {
//     System.out.println(removeKDigits("1270936", 3));
// }
// }
 