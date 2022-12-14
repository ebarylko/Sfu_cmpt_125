#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "assignment2.h"




/**
 * @brief searches the file for the username, and returns as follows:
 * - if edit is 1
 *   - file does not exist or username not found, returns 1 and adds username and password
 *   - returns 0 otherwise
 * - if edit is 0
 *   - if file does not exist , returns -1
 *   - if username is not in file, returns -2
 *   - if username is in the file and password does not match , returns -3
 *   - otherwise, returns 1
 * @param file_name name of file
 * @param username user to check for
 * @param password password to check for
 * @param edit edit mode
 * @return int values listed above in brief
 */
int add_or_check_user(const char *file_name, const char *username, const char *password, int edit) {

  FILE *file;
  if (edit)
  {
    file = fopen(file_name, "a+");
  }
  else
  {
    file = fopen(file_name, "r");
  }
  if (!file)
    return -1;
  fseek(file, 0, SEEK_SET);
  char *buffer = NULL;
  size_t size;
  ssize_t read;
  while ((read = getline(&buffer, &size, file)) > 0)
  {
    buffer[read - 1] = 0;
    if (strcmp(username, buffer) == 0)
    {
      if (edit)
      {
        fclose(file);
        free(buffer);
        return 0;
      }
      else
      {
        getdelim(&buffer, &size, 0, file);
        fclose(file);
        int match = strcmp(buffer, password) == 0 ? 1 : -3;
        free(buffer);
        return match;
      }
    }
    getdelim(&buffer, &size, 0, file);
  }
  if (edit)
  {
    fprintf(file, "%s\n%s", username, password);
    fputc(0, file);
    fclose(file);
    free(buffer);
    return 1;
  }
  else
  {
    fclose(file);
    free(buffer);
    return -2;
  }
}

int add_user_password(const char *file_name, const char *username, const char *password) {
  int val = add_or_check_user(file_name, username, password, 1);
  return val;
}

int check_user_password(const char* file_name, const char* username, const char* password) {
  int val = add_or_check_user(file_name, username, password, 0);
  return val;
}

/**
 * @brief takes two unsigned ints A and B,  A indicating the position of the fibonacci sequence the user
 * wants the value for,  and B being the value to use when calculating the sequence.
 *  returns the value of the fibonacci sequence at A as an int.
 * @param n the position of the fibonacci sequence that we want the value of
 * @param p the integer to be used when calculating the sequence
 * @return int the value of the fibonacci sequence at A.
 */
int fib3_p(unsigned int n, unsigned int p)
{
  int *fib_seq = (int *)malloc(((int)n + 1) * sizeof(int));
  fib_seq[0] = 0;
  fib_seq[1] = 1;
  fib_seq[2] = 2;
  for (int i = 3; i <= n; i++)
  {
    fib_seq[i] = (fib_seq[i - 1] + fib_seq[i - 2] + fib_seq[i - 3]) % p;
  }
  int final_val = fib_seq[n];
  free(fib_seq);
  return final_val;
}

/**
 * @brief takes a string representing the initial state of a group of pebbles in a
 * line, and returns the next state after applying the rules to each pebble in the
 * form of a string
 * @param state the initial state of the group of pebbles
 * @return char* the next state after applying the rules to every pebble in the initial
 * state
 */
char *evolve(const char *state)
{
  int length = strlen(state);
  char *new_state = (char *)malloc((length + 1) * sizeof(char));
  memset(new_state, '-', length);
  new_state[length] = 0;
  int *indices = (int *)malloc(length * sizeof(int));
  int pebbles = 0;
  // count all the pebbles in state and store their indices
  for (int i = 0; i < length; i++)
  {
    if (state[i] == '@')
    {
      indices[pebbles] = i;
      pebbles++;
    }
  }
  //
  if (pebbles > 1)
  {
    // stores new positions of pebbles after applying rules
    int *new_pos = (int *)malloc(pebbles * sizeof(int));
    // left-most neighbor can only move right, and right-most neighbor can only
    // move left
    new_pos[0] = indices[0] + 1;
    new_pos[1] = indices[pebbles - 1] - 1;
    int j = 2;
    // stores new positions of pebbles
    for (int i = 1; i < pebbles - 1; i++)
    {
      int left = indices[i] - indices[i - 1];
      int right = indices[i + 1] - indices[i];
      // if pebble is not the same distance from both neighbors
      if (left - right)
      {
        new_pos[j] = left > right ? indices[i] + 1 : indices[i] - 1;
        j++;
      }
    }
    // generating the next state of the game
    for (int pos = 0; pos < j; pos++)
    {
      // checking if another pebble is in the same location
      if (new_state[new_pos[pos]] == '@')
      {
        new_state[new_pos[pos]] = '-';
      }
      else
      {
        new_state[new_pos[pos]] = '@';
      }
    }
    free(new_pos);
    // sets position of sole pebble
  }
  else if (pebbles)
  {
    new_state[indices[0]] = '@';
  }
  free(indices);
  return new_state;
}

/**
 * @brief takes a string representing the initial state of a group of pebbles in
 * a line, and returns the final state according to the rules
 * @param state a string representing a group of pebbles
 * @return char* the final state of the group of pebbles according to the rules
 */
char *last_state(const char *state)
{

  char *previous = strdup(state);
  char *new_state = evolve(state);
  // while the final state has not been reached
  while (strcmp(previous, new_state) != 0)
  {
    free(previous);
    previous = new_state;
    new_state = evolve(new_state);
  }
  free(new_state);
  return previous;
}
