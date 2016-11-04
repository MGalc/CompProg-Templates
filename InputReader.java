package Libs;

import java.io.*;
import java.util.*;

public class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream), 32768);
        tokenizer = null;
    }

    public boolean hasMore() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                String s = reader.readLine();
                if (s == null)
                    return false;
                tokenizer = new StringTokenizer(s);
            } catch (IOException e) {
                return false;
            }
        }
        return true;
    }

    public String nextLine() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken("\n");
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() { return Long.parseLong((next())); }
}
