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
      free(buffer);
      return 0;
    }
    getdelim(&buffer, &size, 0, file);
  }
  fprintf(file, "%s\n%s", username, password);
  fputc(0, file);
  fclose(file);
  free(buffer);
  return 1;
}

int check_user_password(const char* file_name,
                    const char* username, const char* password) {
                      FILE *file;
                      file = fopen(file_name, "r");
                      if (!file) {
                        return -1;
                      }
  char* buffer = NULL;
  size_t size;
  ssize_t read;
  while ((read = getline(&buffer, &size, file)) > 0)
  {
    buffer[read - 1] = 0;
    if (strcmp(username, buffer) == 0)
    {
    getdelim(&buffer, &size, 0, file);
    fclose(file);
    int match = strcmp(buffer, password) == 0 ? 1 : -3;
    free(buffer);
    return match;
    }
    getdelim(&buffer, &size, 0, file);
  }
  fclose(file);
  free(buffer);
  return -2;
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
  