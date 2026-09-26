/*WAP to accept 2 numbers and display the greatest number */
import java.util.*;
public class equation
{
  public static void main (String args[])
  {
    Scanner sc = new Scanner (System.in);
    System.out.println("Enter 2 numbers: ");
    int a,b,c;
    a=sc.nextInt();
    b=sc.nextInt();
    if(a>b)
    c=a;
    else
    c=b;
    System.out.println("Greatest number = "+c);
  }
}
