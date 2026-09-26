/* WAP to find the greatest of 2 numbers using ternary operator */
import java.util.*;
public class equation
{
  public static void main(String args[])
  {
    Scanner sc=new Scanner(System.in);
    int a,b,c;
    System.out.println("Enter 2 numbers");
    a=sc.nextInt();
    b=sc.nextInt();
    c=(a>b)?a:b;
    System.out.println("Greatest Number: "+c);
  }
}
