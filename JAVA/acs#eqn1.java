/*WAP to solve the eqn d=b^2-4ac */
import java.util.*;
public class equation
{
  public static void main(String args[])
  {
    Scanner sc = new Scanner (System.in);
    double a,b,c,d;
    System.out.println("Enter 3 numbers");
    a=sc.nextDouble();
    b=sc.nextDouble();
    c=sc.nextDouble();
    d=b*b-4*a*c;
    System.out.println("d = "+d);
  }
}
