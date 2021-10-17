import java.io.*;
import java.util.*;
 
public class Main {
    private static FastInput in = new FastInput(System.in);
    private static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

    public static void main(String[] args) {
        int n = in.nextInt();
        List<Integer> vec = new ArrayList<Integer>();
        for(int i = 1; i <= n; i++) {
            vec.add(in.nextInt());
        }
        Collections.sort(vec);
        for(int x : vec) out.print(x + " ");
        out.println();
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
