#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "assignment2.h"




//use get_delim
int add_user_password(const char *file_name,
                      const char *username, const char *password)
{
  FILE *file;
  file = fopen(file_name, "a+");
  if (!file)
    return -1;
  fseek(file, 0, SEEK_SET);
  char* buffer = NULL;
  size_t size;
  ssize_t read;
  while ((read = getline(&buffer, &size, file)) > 0)
  {
    buffer[read - 1] = 0;
    if (strcmp(username, buffer) == 0)
    {
      fclose(file);
      return 0;
    }
    getdelim(&buffer, &size, 0, file);
  }
  fprintf(file, "%s\n%s", username, password);
  fputc(0, file);
  fclose(file);
  return 1;
}

int check_user_password(const char* file_name,
                    const char* username, const char* password) {
                    //   FILE *file;
                    //   file = fopen(file_name, "r");
                    //   int length_pass = strlen(password);
                    //   int length_user = strlen(username);

                    //   char pos_user[length_user + 1];
                    //   char pos_password[length_pass + 1];
                    //   if (file) {
                    //   while (fgets(pos_user, length_user + 2, file)) {
                    //     if (!strcmp(username, pos_user)) {
                    //      fseek(file, length_user + 1, 0);
                    //      getdelim(pos_password, length_pass + 1, 0, file);
                    //      int val = strcmp(password, pos_password)? -3 : 1;
                    //      fclose(file);
                    //      return val;
                    //     }
                    //   return -2;
                    //   }
                    //   }
                      return -1;
}

/**
 * @brief takes two unsigned ints A and B,  A indicating the position of the fibonacci sequence the user 
 * wants the value for,  and B being the value to use when calculating the sequence.
 *  returns the value of the fibonacci sequence at A as an int.
 * @param n the position of the fibonacci sequence that we want the value of
 * @param p the integer to be used when calculating the sequence
 * @return int the value of the fibonacci sequence at A.
 */
int fib3_p(unsigned int n, unsigned int p) {
 int* fib_seq = (int*)malloc(((int)n + 1) * sizeof(int));
 fib_seq[0] = 0;
 fib_seq[1] = 1;
 fib_seq[2] = 2;
 for (int i = 3; i <= n; i++) {
   fib_seq[i] = (fib_seq[i - 1] + fib_seq[i - 2] + fib_seq[i - 3]) % p;
 }
 return fib_seq[n];
}


char* evolve(const char* state) {
  // implement me
  return NULL;
}  


char* last_state(const char* state) {
  // implement me
  return NULL;
}  
  