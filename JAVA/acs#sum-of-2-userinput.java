/*WAP to find the sum of 2 values by accepting the values form the user*/
import java.util.*;

public static void main(String args[])
{
  Scanner sc=new Scanner(System.in);
  int a,b,c;
  System.out.println("Enter 2 values");
  a=sc.nextInt();
  b=sc.nextInt();
  c=a+b;
  System.out.println("Sum = "+c);
}
