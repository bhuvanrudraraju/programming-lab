/*WAP to find the area of square by accepting side of square from user*/
import java.util.*;

public static void main(String args[])
{
  Scanner sc=new Scanner(System.in);
  float a,b;
  System.out.println("Enter side of square");
  a=sc.nextFloat();
  b=a*a;
  System.out.println("Area of square = "+b);
}
