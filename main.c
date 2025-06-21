#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// This program converts a number in string format to its English word representation
// It handles numbers up to 999 decillion and prints them in a human-readable format

int main (int argc, char *argv[]) {
	// Check if the correct number of arguments is provided
	if (argc != 2) {
		return 1; // Return an error code
	}

	// Print the first argument passed to the program
	// printf("Argument: %s\n", argv[1]);
		
	char *str = argv[1];
	int len = strlen(str);
	int i;
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9') {
			write(1, "Error\n", 6); // Print error message if input is invalid
			return 1; // Return an error code
		}
		int j = len - i - 1;
		/* printf("i: %d, j: %d, str[i]: %c\n", i, j, str[i]); */
		if ((i > 0 && str[i] != '0')
			&& !(j % 3 == 1 && str[i] == '1')
			&& !(len == 2 && str[0] == '1'))
			write(1, " ", 1);
		switch (str[i])
		{
			case '1':
			if (j % 3 == 1 && str[i + 1] == '0') write(1, "ten", 4);
			else if (j % 3 == 0 && str[i - 1] == '1') write(1, "eleven", 6);
			else if (j % 3 != 1) write(1, "one", 3);
			break;

			case '2':
			if (j % 3 == 1) write(1, "twenty", 6);
			else if (j % 3 == 0 && str[i - 1] == '1') write(1, "twelve", 6);
			else write(1, "two", 3);
			break;

			case '3':
			if (j % 3 == 1) write(1, "thirty", 6);
			else if (j % 3 == 0 && str[i - 1] == '1') write(1, "thirteen", 8);
			else write(1, "three", 5);
			break;

			case '4':
			if (j % 3 == 1) write(1, "forty", 5);
			else if (j % 3 == 0 && str[i - 1] == '1') write(1, "fourteen", 8);
			else write(1, "four", 4);
			break;

			case '5':
			if (j % 3 == 1) write(1, "fifty", 5);
			else if (j % 3 == 0 && str[i - 1] == '1') write(1, "fifteen", 7);
			else write(1, "five", 4);
			break;

			case '6':
			if (j % 3 == 1) write(1, "sixty", 5);
			else if (j % 3 == 0 && str[i - 1] == '1') write(1, "sixteen", 7);
			else write(1, "six", 3);
			break;

			case '7':
			if (j % 3 == 1) write(1, "seventy", 7);
			else if (j % 3 == 0 && str[i - 1] == '1') write(1, "seventeen", 9);
			else write(1, "seven", 5);
			break;

			case '8':
			if (j % 3 == 1) write(1, "eighty", 6);
			else if (j % 3 == 0 && str[i - 1] == '1') write(1, "eighteen", 8);
			else write(1, "eight", 5);
			break;

			case '9':
			if (j % 3 == 1) write(1, "ninety", 6);
			else if (j % 3 == 0 && str[i - 1] == '1') write(1, "nineteen", 8);
			else write(1, "nine", 4);
			break;
		}
		if (j % 3 == 2 && str[i] != '0') write(1, " hundred", 8);
		if (j % 3 == 0 && (str[i] != '0'
			|| str[i - 1] != '0' || str[i - 2] != '0'))
		{
			write(1, " ", 1);
			switch (j / 3)
			{
				case 1: write(1, "thousand", 8); break;
				case 2: write(1, "million", 7); break;
				case 3: write(1, "billion", 7); break;
				case 4: write(1, "trillion", 8); break;
				case 5: write(1, "quadrillion", 11); break;
				case 6: write(1, "quintillion", 11); break;
				case 7: write(1, "sextillion", 10); break;
				case 8: write(1, "septillion", 10); break;
				case 9: write(1, "octillion", 9); break;
				case 10: write(1, "nonillion", 9); break;
				case 11: write(1, "decillion", 9); break;
			}
		}
		/* if (!(j % 3 == 1 && str[i] == '1'))
			write(1, " ", 1); */
	}
	/* write(1, "-", 1); */
	write(1, "\n", 1);
	return 0; // Return success
}
