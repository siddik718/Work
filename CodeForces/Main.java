import java.util.*;
import java.io.*;
public class Main{
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next(){
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        double nextDouble(){
            return Double.parseDouble(next());
        }
        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    public static void main(String[] args){
        FastReader input = new FastReader();
        int n = input.nextInt();
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = input.nextInt();
        }
        int[] b = new int[n];
        for(int i = 0; i < n; i++){
            b[i] = input.nextInt();
        }
        int ans1 = 0;
        int ans2 = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == b[i]){
                ans1++;
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if((i != j) && (a[i] == b[j])){
                    ans2++;
                }
            }
        }
        System.out.println(ans1 + "\n" + ans2);
    }
}