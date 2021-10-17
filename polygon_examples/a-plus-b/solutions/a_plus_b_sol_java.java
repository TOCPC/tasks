import java.io.*;
import java.util.*;
 
public class Main {
    private static FastInput in = new FastInput(System.in);
    private static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

    public static void main(String[] args) {
        long a = in.nextLong();
        long b = in.nextLong();
        out.println(a + b);
        out.flush();
    }
 
    static class FastInput {
        BufferedReader br;
        StringTokenizer tok;
    
        public FastInput(InputStream in) {
            br = new BufferedReader(new InputStreamReader(System.in));
            tok = new StringTokenizer("");
        }
    
        public String next() {
            while (!tok.hasMoreTokens()) {
                try {
                    tok = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                }
            }
            return tok.nextToken();
        }
    
        public int nextInt() {
            return Integer.parseInt(next());
        }
    
        public long nextLong() {
            return Long.parseLong(next());
        }
    
        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}
