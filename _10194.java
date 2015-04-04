import java.io.*;
import java.util.*;

class _10194 {

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				System.in));
		int no_of_tests;
		no_of_tests = Integer.parseInt(reader.readLine());
		for (int i = 0; i < no_of_tests; i++) {
			String tournament_name = reader.readLine();
			int teams = Integer.parseInt(reader.readLine());
			team[] array = new team[teams];
			HashMap<String, Integer> map = new HashMap<String, Integer>();
			for (int j = 0; j < teams; j++) {
				// Insert Team
				String team_name = reader.readLine();
				map.put(team_name, j);
				array[j] = new team(team_name);
			}
			int matches = Integer.parseInt(reader.readLine());
			for (int j = 0; j < matches; j++) {
				// Simulate match Scores
				String s = reader.readLine();
				String[] tokens = s.split("#");
				String[] score = tokens[1].split("@");
				int indx1, indx2;
				indx1 = map.get(tokens[0]);
				indx2 = map.get(tokens[2]);
				array[indx1].games_played++;
				array[indx2].games_played++;
				array[indx1].goals_scored += Integer.parseInt(score[0]);
				array[indx2].goals_against += Integer.parseInt(score[0]);
				array[indx2].goals_scored += Integer.parseInt(score[1]);
				array[indx1].goals_against += Integer.parseInt(score[1]);
				if (score[0].compareTo(score[1]) == 0) {
					array[indx1].ties++;
					array[indx2].ties++;
					array[indx1].total_points_earned++;
					array[indx2].total_points_earned++;
				} else if (score[0].compareTo(score[1]) > 0) {
					array[indx1].wins++;
					array[indx1].total_points_earned += 3;
					array[indx2].losses++;
				} else {
					array[indx2].wins++;
					array[indx2].total_points_earned += 3;
					array[indx1].losses++;
				}
			}
			for (int j = 0; j < array.length; j++) {
				array[j].goal_difference = array[j].goals_scored
						- array[j].goals_against;
			}
			System.out.println(tournament_name);
			// Sort Team
			Arrays.sort(array);
			display(array);
		}
		reader.close();
	}

	public static void display(team[] array) {
		for (int j = 0; j < array.length; j++) {
			System.out.println((j + 1) + ") " + array[j].name + " "
					+ array[j].total_points_earned + "p, "
					+ array[j].games_played + "g (" + array[j].wins + "-"
					+ array[j].ties + "-" + array[j].losses + "), "
					+ array[j].goal_difference + "gd (" + array[j].goals_scored
					+ "-" + array[j].goals_against + ")");
		}
	}
}

class team implements Comparable<team> {
	String name;
	int total_points_earned;
	int games_played;
	int wins;
	int ties;
	int losses;
	int goal_difference;
	int goals_scored;
	int goals_against;

	public team(String name) {
		this.name = name;
		total_points_earned = 0;
		games_played = 0;
		wins = 0;
		ties = 0;
		losses = 0;
		goal_difference = 0;
		goals_scored = 0;
		goals_against = 0;
	}

	@Override
	public int compareTo(team opponent) {
		if (total_points_earned > opponent.total_points_earned) {
			return -1;
		} else if (total_points_earned == opponent.total_points_earned) {
			if (wins > opponent.wins) {
				return -1;
			} else if (wins == opponent.wins) {
				if (goal_difference > opponent.goal_difference) {
					return -1;
				} else if (goal_difference == opponent.goal_difference) {
					if (goals_scored > opponent.goals_scored) {
						return -1;
					} else if (goals_scored == opponent.goals_scored) {
						if (games_played > opponent.games_played) {
							return 1;
						} else if (games_played == opponent.games_played) {
							return name.compareTo(opponent.name);
						} else {
							return -1;
						}
					} else {
						return 1;
					}
				} else {
					return 1;
				}
			} else {
				return 1;
			}
		} else {
			return 1;
		}
	}
}