import java.util.Scanner;
public class hello {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long t=sc.nextLong();
        for (int R=0;R<t;R++){
           long n=sc.nextLong();
           System.out.printf("%d %d\n",-n+1,n);
       }
    }
}
