/* dirdetails - extract directory name and last part of a path name */

/* 
 * dirdetails -- extract directory name and last part from a path name
 *
 * Author Name    : Jigar Gosalia
 * Course Name    : CSC 502 : Principles of OS & Distributed Systems 
 * Professor Name : Dr. Yurong Xu 
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define EOS '\0'

int main(int argc, char **argv);

int main(argc, argv)
int argc;
char *argv[];
{
  char *resultant_path;
  char *input_path;

  char *resultant_string;	/* pointer to argv[1] */
  char *temporary;			/* used to move in argv[1] */
  int suffix_length;		/* suffix length */
  int suffix_start;			/* suffix start */

  if ((argc < 2) || (argc > 3)) {
	fprintf(stderr, "Usage: basename string [suffix] \n");
	exit(1);
  }

  for (temporary = argv[1]; *temporary == '/'; temporary++);

  if (*temporary == EOS) {
	printf("/\n");
	exit(0);
  }

  resultant_string = argv[1];

  temporary = strrchr(resultant_string, '/');

  if (temporary != NULL) {
	while ((*(temporary + 1) == EOS) && (*temporary == '/')) *temporary-- = EOS;
	if (*temporary != '/') temporary = strrchr(resultant_string, '/');
	if (temporary != NULL && *temporary == '/') resultant_string = temporary + 1;
  }

  if (argc > 2) {
	suffix_length = strlen(argv[2]);
	suffix_start = strlen(resultant_string) - suffix_length;
	if (suffix_start > 0)
		if (strcmp(resultant_string + suffix_start, argv[2]) == EOS)
			*(resultant_string + suffix_start) = EOS;
  }

  printf("\n\n");
  printf("==================================================\n");
  printf("    input    : %s\n", argv[1]);
  printf("    basename : %s\n", resultant_string);

  input_path = argv[1];
  resultant_path = input_path + strlen(input_path);
  while (resultant_path > input_path && resultant_path[-1] == '/') resultant_path--;
  while (resultant_path > input_path && resultant_path[-1] != '/') resultant_path--;
  while (resultant_path > input_path && resultant_path[-1] == '/') resultant_path--;
  if (resultant_path == input_path) {
	printf("    dirname  : %s\n", (input_path[0] == '/' ? "/\n" : ".\n"));
  } else {
	printf("    dirname  : %.*s\n", (int) (resultant_path - input_path), input_path);
  }
  printf("==================================================\n");
  printf("\n\n");
  return(0);
}

