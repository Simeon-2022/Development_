#define _CRT_SECURE_NO_WARNINGS
#define ARR_SIZE 51
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "Functions_14.h"


int main(void) {
	/*
	<<<<Local-part>>>>
	The local-part of the email address may be unquoted or may be enclosed in quotation marks.
	If unquoted, it may use any of these ASCII characters:
	* uppercase and lowercase Latin letters A to Z and a to z,
	* digits 0 to 9
	* printable characters !#$%&'*+-/=?^_`{|}~
	* dot ., provided that it is not the first or last character and provided also that it does not appear consecutively (e.g., John..Doe@example.com is not allowed).[5]

	<<<Domain>>>
	*uppercase and lowercase Latin letters A to Z and a to z;
	*digits 0 to 9, provided that top-level domain names are not all-numeric;
	*hyphen -, provided that it is not the first or last character.
	*special characters not allowed
	*/

	int approved = 0;

	char arr_2[] = ".com";
	int arr_size_2 = (int)my_strlen(arr_2);

	for (; approved != 1;)
	{
		int index_local = 0;
		int index_domain = 0;
		int end_index = 0;
		int begin_index = 0;

		char arr_1[ARR_SIZE] = { '\0' };

		printf("\n\nEnter a valid email address: ");
		get_string(arr_1);
		end_index = 0;

		int arr_size = (int)my_strlen(arr_1);

		int at_valuation = find_At_char(arr_1, &end_index);

		int part_local = validation_email_local(arr_1, begin_index, end_index, &index_local, at_valuation);
		print_warning(part_local, index_local, at_valuation);

		int part_domain = validation_email_domein(arr_1, end_index, arr_size, arr_2, arr_size_2, &index_local);
		print_warning(part_domain, index_local, at_valuation);

		if ((part_local == 1) && (part_domain == 1))
		{
			print_array_index(arr_1, arr_size);

			approved = 1;
		}

	}
	/*
	!!! TEST emails!!!
	===============================================================
Enter a valid email address: dsd*@sd-.s-.com

Warning: Last domain character must be an alphabetical letter!

Enter a valid email address: -dsd*@sd-.s-.com

Warning: First local character must be alpha-numeric!
Warning: Last domain character must be an alphabetical letter!

Enter a valid email address: -dsd*-@sd-.s-.com

Warning: First local character must be alpha-numeric!
Warning: Last domain character must be an alphabetical letter!

Enter a valid email address: dsd*-@sd-.s-.com

Warning: Last domain character must be an alphabetical letter!

Enter a valid email address: dsd*-@-sd-.s-.com

Warning: Hyphen at index [6] not allowed!

Enter a valid email address: \dsd*-@@sd-.s-.com

Warning: Only a single [@] character allowed!
Warning: Last domain character must be an alphabetical letter!

Enter a valid email address: \dsd*-@sd-.s-.com

Warning: First local character must be alpha-numeric!
Warning: Last domain character must be an alphabetical letter!

Enter a valid email address: ds\d*-@sd-.s-.com

Warning: Index[2] special character not allowed!
Warning: Last domain character must be an alphabetical letter!

Enter a valid email address: ds<d*-@sd-.s-.com

Warning: Index[2] special character not allowed!
Warning: Last domain character must be an alphabetical letter!

Enter a valid email address: ds\\d*-@sd-.s-.com

Warning: Index[2] special character not allowed!
Warning: Last domain character must be an alphabetical letter!

Enter a valid email address: ds\d*-@sd-.s-.com

Warning: Index[2] special character not allowed!
Warning: Last domain character must be an alphabetical letter!
*/


	return 0;

}



