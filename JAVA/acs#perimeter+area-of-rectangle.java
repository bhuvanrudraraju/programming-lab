/*WAP to accept the length & breadth of a rectangle , find and display the area and perimeter */
import java.util.*;
public class print
{
public static void main(String args[])
{
  int a,b,c;
  float area;
  Scanner sc = new Scanner(System.in);
  System.out.println("Enter length of rectangle");
  a=sc.nextInt();
  System.out.println("Enter breadth of rectangle");
  b=sc.nextInt();
  c=2*(a+b);
  System.out.println("Perimeter = "+c);
  area=a*b;
  System.out.println("Area = "+area);
}
}
