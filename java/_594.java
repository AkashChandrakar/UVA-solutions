import java.util.Scanner;

public class _594 {
	public static void main(String[] args) {
		int converted, endian = 0;
		Scanner reader = new Scanner(System.in);
		while (reader.hasNext()) {
			endian = reader.nextInt();
			converted = convert(endian);
			System.out.println(endian + " converts to " + converted);
		}
		reader.close();
	}

	public static int convert(int endian) {
		int converted = 0;
		int first, second, third, fourth, t1;
		// Extract bytes
		first = (endian >> (32 - 8) & 0XFF);
		second = ((endian >> (32 - 16)) & 0XFF);
		third = (endian >> (32 - 24) & 0XFF);
		fourth = (endian & 0XFF);
		// Swap Bytes
		t1 = first;
		first = fourth;
		fourth = t1;
		t1 = second;
		second = third;
		third = t1;
		// Piece Bytes Together
		converted = converted | first;
		converted = converted << 8;
		converted = converted | second;
		converted = converted << 8;
		converted = converted | third;
		converted = converted << 8;
		converted = converted | fourth;
		return converted;
	}
}
