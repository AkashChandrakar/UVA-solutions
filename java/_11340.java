import java.io.*;
import java.util.*;

public class _11340 {

	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				System.in));
		StringTokenizer line;
		char[] newspaper;
		int test, no_of_keys, len_newspaper;
		String key;
		int value;
		double cost;
		test = Integer.parseInt(reader.readLine());
		for (int i = 0; i < test; i++) {
			HashMap<Character, Integer> hashtable = new HashMap<Character, Integer>();
			cost = 0.0;
			no_of_keys = Integer.parseInt(reader.readLine());
			for (int j = 0; j < no_of_keys; j++) {
				// build HashTable
				line = new StringTokenizer(reader.readLine());
				key = line.nextToken();
				value = Integer.parseInt(line.nextToken());
				hashtable.put(key.charAt(0), value);
			}
			// Read newspaper
			len_newspaper = Integer.parseInt(reader.readLine());
			for (int j = 0; j < len_newspaper; j++) {
				newspaper = reader.readLine().toCharArray();
				for (char c : newspaper) {
					if (hashtable.containsKey(c)) {
						cost += hashtable.get(c);
					}
				}
			}
			cost /= 100;
			System.out.printf("%.2f$" + System.lineSeparator(), cost);
		}

		reader.close();
	}
}
