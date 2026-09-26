/*WAP to find the product of 3 integer values by accepting values from user*/
import java.util.*;

public static void main(String args[])
{
  Scanner sc=new Scanner(System.in);
  int a,b,c,d;
  System.out.println("Enter 3 values");
  a=sc.nextInt();
  b=sc.nextInt();
  c=sc.nextInt();
  d=c*a*b;
  System.out.println("Product = "+d);
}
