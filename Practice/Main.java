import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class Main{
    public static void main(String[] args){
        FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);

		int t = fs.nextInt();

		for (int tt = 1; tt <= t; tt++) {

		}
		out.close();
    }
    static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
}