/*WAP to solve the eqn s=1/3 ab + 1/2 cd^2 */
import java.util.*;
public class equation
{
  public static void main (String args[])
  {
    Scanner sc = new Scanner (System.in);
    System.out.println("Enter 4 numbers: ");
    int a,b,c,d;
    double s;
    a=sc.nextInt();
    b=sc.nextInt();
    c=sc.nextInt();
    d=sc.nextInt();
    s=((1/3.0*a*b)+(1/2.0*c*d*d));
    System.out.println("S = "+s);
  }
}
