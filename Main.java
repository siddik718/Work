import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            int n = sc.nextInt();
            long k = sc.nextLong();
            long[] a = new long[n];
            for(int i = 0; i < n; i++){
                a[i] = sc.nextLong();
            }
            long l = 1,r = (long)3e8,ans = -1;
            while(l<=r){
                long mid = (l+r)/2;
                Boolean ok = true;int i;
                for(i = 0;i<n;i++){
                    if(Math.abs(a[i]-mid) > k){
                        ok = false;
                        break;
                    }
                }
                if(ok == true){
                    ans = mid;
                    l = mid+1;
                }
                else{
                    if(a[i] < mid)r = mid-1;
                    else l = mid+1;
                }
            }
            System.out.println(ans);
        }
        sc.close();
    }
}