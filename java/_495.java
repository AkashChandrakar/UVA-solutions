import java.io.*;
import java.math.BigInteger;

public class _495 {
	public static void main(String[] args) throws IOException {
		BigInteger[] fib = new BigInteger[5001];
		for (int i = 0; i < fib.length; i++) {
			fib[i] = BigInteger.ZERO;
		}
		fib[1] = BigInteger.ONE;
		for (int i = 2; i < fib.length; i++) {
			fib[i] = fib[i - 1].add(fib[i - 2]);
		}
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				System.in));
		String line;
		int num;
		while ((line = reader.readLine()) != null) {
			num = Integer.parseInt(line);
			System.out.println("The Fibonacci number for " + num + " is "
					+ fib[num]);
		}
	}
}
