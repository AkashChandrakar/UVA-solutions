import java.util.*;

class _482 {
	static boolean debug = false;

	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		if (args.length > 0)
			debug = true;
		int testN = Integer.parseInt(reader.nextLine());
		for (int test = 0; test < testN; test++) {
			reader.nextLine();
			ArrayList<Integer> allIndex = new ArrayList<Integer>();
			StringTokenizer st = new StringTokenizer(reader.nextLine());
			while (st.hasMoreTokens()) {
				allIndex.add(Integer.parseInt(st.nextToken()) - 1);
			}
			int n = allIndex.size();
			ArrayList<String> all = new ArrayList<String>(n);
			for (int i = 0; i < n; i++) {
				all.add(null);
			}
			st = new StringTokenizer(reader.nextLine());
			for (int i = 0; i < n; i++) {
				all.set(allIndex.get(i), st.nextToken());
			}
			if (test != 0) {
				System.out.println("");
			}
			for (String s : all) {
				System.out.println(s);
			}
		}
		reader.close();
	}
}