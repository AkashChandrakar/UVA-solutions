import java.io.*;
import java.util.*;

public class _673 {
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				System.in));
		int no_of_tests;
		no_of_tests = Integer.parseInt(reader.readLine());
		String line;
		for (int i = 0; i < no_of_tests; i++) {
			line = reader.readLine();
			List<Character> stack = new Stack<Character>();
			for (int j = 0; j < line.length(); j++) {
				check_paranthsization(line, stack, j);
			}
			if (stack.isEmpty()) {
				System.out.println("Yes");
			} else {
				System.out.println("No");
			}
		}
	}

	public static void check_paranthsization(String line,
			List<Character> stack, int j) {
		if (stack.isEmpty()) {
			stack.add(line.charAt(j));
		} else {
			Character c = line.charAt(j);
			switch (c) {
			case '(':
				if (stack.get(stack.size() - 1) == ')') {
					stack.remove(stack.size() - 1);
				} else {
					stack.add(c);
				}
				break;
			case ')':
				if (stack.get(stack.size() - 1) == '(') {
					stack.remove(stack.size() - 1);
				} else {
					stack.add(c);
				}
				break;
			case '[':
				if (stack.get(stack.size() - 1) == ']') {
					stack.remove(stack.size() - 1);
				} else {
					stack.add(c);
				}
				break;
			case ']':
				if (stack.get(stack.size() - 1) == '[') {
					stack.remove(stack.size() - 1);
				} else {
					stack.add(c);
				}
				break;
			}
		}
	}
}
