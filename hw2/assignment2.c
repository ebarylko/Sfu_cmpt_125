#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "assignment2.h"




/**
 * @brief Takes
 * 
 * @param file_name 
 * @param username 
 * @param password 
 * @return int 
 */
// check password + user is repeated, while es lo mismo, la uniqua cosa que cambia
// son los valores que devuelvo
//make general function called add_or_check_user, takes filename, username, and password

int add_or_check_user(const char *file_name,
                      const char *username, const char *password, int edit) {

  FILE *file;
  if (edit) {
  file = fopen(file_name, "a+");
  } else {
  file = fopen(file_name, "r");
  }
  if (!file)
    return -1;
  fseek(file, 0, SEEK_SET);
  char* buffer = NULL;
  size_t size;
  ssize_t read;
  while ((read = getline(&buffer, &size, file)) > 0) {
    buffer[read - 1] = 0;
    if (strcmp(username, buffer) == 0) {
      if (edit) {
      fclose(file);
      free(buffer);
      return 0;
      } else {
      getdelim(&buffer, &size, 0, file);
      fclose(file);
      int match = strcmp(buffer, password) == 0 ? 1 : -3;
      free(buffer);
      return match;
      }
    }
    getdelim(&buffer, &size, 0, file);
  }
  if (edit) {
    fprintf(file, "%s\n%s", username, password);
    fputc(0, file);
    fclose(file);
    free(buffer);
    return 1;
  } else {
  fclose(file);
  free(buffer);
  return -2;
  } 
  }

int add_user_password(const char *file_name,
                      const char *username, const char *password) {
  int val = add_or_check_user(file_name, username, password, 1);
  return val;
}

int check_user_password(const char* file_name,
                    const char* username, const char* password) {
  int val = add_or_check_user(file_name, username, password, 0);
  return val;
}



// int add_user_password(const char *file_name,
//                       const char *username, const char *password)
// {
//   FILE *file;
//   file = fopen(file_name, "a+");
//   if (!file)
//     return -1;
//   fseek(file, 0, SEEK_SET);
//   char* buffer = NULL;
//   size_t size;
//   ssize_t read;
//   while ((read = getline(&buffer, &size, file)) > 0)
//   {
//     buffer[read - 1] = 0;
//     if (strcmp(username, buffer) == 0) {
//       fclose(file);
//       free(buffer);
//       return 0;
//     }
//     getdelim(&buffer, &size, 0, file);
//   }
//   fprintf(file, "%s\n%s", username, password);
//   fputc(0, file);
//   fclose(file);
//   free(buffer);
//   return 1;
// }

// int check_user_password(const char* file_name,
//                     const char* username, const char* password) {
//   FILE *file;
//   file = fopen(file_name, "r");
//   if (!file)
//   {
//     return -1;
//   }
//   char *buffer = NULL;
//   size_t size;
//   ssize_t read;
//   while ((read = getline(&buffer, &size, file)) > 0)
//   {
//     buffer[read - 1] = 0;
//     if (strcmp(username, buffer) == 0)
//     {
//       getdelim(&buffer, &size, 0, file);
//       fclose(file);
//       int match = strcmp(buffer, password) == 0 ? 1 : -3;
//       free(buffer);
//       return match;
//     }
//     getdelim(&buffer, &size, 0, file);
//   }
//   fclose(file);
//   free(buffer);
//   return -2;
// }

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
 int final_val = fib_seq[n];
 free(fib_seq);
 return final_val;
}


char* evolve(const char* state) {
int length = strlen(state);
char* new_state = (char*)malloc((length + 1) * sizeof(char));
memset(new_state, '-', length);
new_state[length] = 0;
int* indices = (int*)malloc(length * sizeof(int));
int pebbles = 0;
int j = 0;
for (int i = 0; i < length; i++) {
  if (state[i] == '@') {
    indices[pebbles] = i;
    pebbles++;
  }
}

if (pebbles > 1) {
  int * new_pos = (int*)malloc(pebbles * sizeof(int));
  new_pos[0] = indices[0] + 1;
  new_pos[1] = indices[pebbles -1] -1;
  j= 2;
  for (int i = 1; i < pebbles - 1; i++) {
    int left = indices[i] - indices[i - 1];
    int right = indices[i + 1] - indices[i];
    if (left - right)  {
      new_pos[j] = left > right? indices[i] + 1 : indices[i] - 1;
      j++;
    }
  }
  for (int pos = 0; pos < j; pos++) {
    if (new_state[new_pos[pos]] ==  '@') {
      new_state[new_pos[pos]] = '-';
    } else {
    new_state[new_pos[pos]] =  '@';
    }
}
  free(new_pos);
  } else if (pebbles) {
    new_state[indices[0]] = '@';
  }
free(indices);
return new_state;
}  

char* last_state(const char* state) {
  
  char* previous = strdup(state);
  char* new_state = evolve(state);
  while (strcmp(previous, new_state) != 0) {
    free(previous);
    previous = new_state;
    new_state = evolve(new_state);
  }
  free(new_state);
  return previous;
}  
  