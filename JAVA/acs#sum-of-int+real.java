/*WAP to find the sum of 1 integer value and 1 real value by accepting values from user*/
import java.util.*;

public static void main(String args[])
{
  Scanner sc=new Scanner(System.in);
  int a;
  float b,c;
  System.out.println("Enter 2 values");
  a=sc.nextInt();
  b=sc.nextFloat();
  c=a+b;
  System.out.println("Sum = "+c);
}
