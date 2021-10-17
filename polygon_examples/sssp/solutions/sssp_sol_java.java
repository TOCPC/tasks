import java.io.*;
import java.util.*;
 
public class Main {
    private static FastInput in = new FastInput(System.in);
    private static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

    static class Item implements Comparable<Item> {
        long a, b;
        
        Item(long a, long b) {
            this.a = a;
            this.b = b;
        }

        long first() {
            return this.a;
        }

        long second() {
            return this.b;
        }

        public int compareTo(Item rhs) {
            return new Long(this.a).compareTo(new Long(rhs.a));
        }
    }

    public static void main(String[] args) {
        int n = in.nextInt();
        int m = in.nextInt();
        List<List<Item>> g = new ArrayList<List<Item>>();
        List<Long> dp = new ArrayList<Long>();

        for(int i = 0; i <= n; i++) {
            g.add(new ArrayList<Item>());
            dp.add((long)1e18);
        }

        for(int i = 1, a, b, c; i <= m; i++) {
            a = in.nextInt();
            b = in.nextInt();
            c = in.nextInt();
            g.get(a).add(new Item(b, c));
            g.get(b).add(new Item(a, c));
        }

        PriorityQueue<Item> Q = new PriorityQueue<Item>();
        dp.set(1, (long)0);
        Q.add(new Item(0, 1));
        while(!Q.isEmpty()) {
            Item u = Q.poll();
            if(u.first() != dp.get((int)u.second()))
                continue;
            for(Item v : g.get((int)u.second())) if(u.first() + v.second() < dp.get((int)v.first())) {
                dp.set((int)v.first(), u.first() + v.second());
                Q.add(new Item(dp.get((int)v.first()), v.first()));
            }
        }

        for(int i = 1; i <= n; i++) out.print(dp.get(i) + " ");
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
