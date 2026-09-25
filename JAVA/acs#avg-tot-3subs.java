/*WAP to accept 3 marks of a student find and display the sum and average marks of the student*/
import java.util.*;
public static void main(String args[])
{
  Scanner sc = new Scanner(System.in);
  System.out.println("Enter marks of 3 subjects:");
  int a,b,c,d;
  float avg;
  a=sc.nextInt();
  b=sc.nextInt();
  c=sc.nextInt();
  d=a+b+c;
  avg=d/3;
  System.out.println("Total marks = "+d);
  System.out.println("Average = "+avg);
}
