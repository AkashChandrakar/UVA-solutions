import java.io.*;
import java.util.Arrays;

public class _10258 {

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				System.in));
		int no_of_tests;
		no_of_tests = Integer.parseInt(reader.readLine());
		reader.readLine();
		String line;
		for (int i = 0; i < no_of_tests; i++) {
			line = "";
			contestant[] array = new contestant[101];
			for (int j = 0; j < 101; j++) {
				array[j] = new contestant(j);
			}
			while ((line = reader.readLine()) != null) {
				if (line.trim().equals("")) {
					break;
				}
				String[] token = line.split(" ");

				int idx = Integer.parseInt(token[0]);
				int problem_num = Integer.parseInt(token[1]);
				array[idx].valid = true;
				if (token[3].equals("I")) {
					// solution incorrect check if the problem already solved
					if (array[idx].incorrect[problem_num] != -1) {
						array[idx].incorrect[problem_num]++;
					}
				} else if (token[3].equals("C")) {
					// Solution is correct check if the problem already solved
					if (array[idx].incorrect[problem_num] != -1) {
						array[idx].problem_solved++;
						array[idx].penalty_time += Integer.parseInt(token[2])
								+ 20 * array[idx].incorrect[problem_num];
						array[idx].incorrect[problem_num] = -1;
					}
				}
			}
			Arrays.sort(array);
			for (contestant a : array) {
				if (a.valid == true) {
					System.out.println(a.label + " " + a.problem_solved + " "
							+ a.penalty_time);
				}
			}
			System.out.println();
		}
	}
}

class contestant implements Comparable<contestant> {
	boolean valid;
	int label;
	int problem_solved;
	int penalty_time;
	int[] incorrect;

	// incorrect[i]=-1 means problem solved correctly first time
	public contestant(int label) {
		valid = false;
		this.label = label;
		problem_solved = 0;
		penalty_time = 0;
		incorrect = new int[10];
	}

	@Override
	public int compareTo(contestant opponent) {
		if (problem_solved != opponent.problem_solved) {
			return opponent.problem_solved - problem_solved;
		}
		if (penalty_time != opponent.penalty_time) {
			return penalty_time - opponent.penalty_time;
		}
		return label - opponent.label;
	}
}
