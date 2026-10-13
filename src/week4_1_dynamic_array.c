
/*
 * week4_1_dynamic_array.c
 * Description:
 *   Dynamically allocates an integer array using malloc,
 *   calculates the sum and average, then frees memory.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  int* arr = NULL;
  long long sum = 0;
  double average;

  // Read and validate the number of elements.
  printf("Enter number of elements: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid size.\n");
    return 1;
  }

  // Check that the allocation size will not overflow.
  if ((size_t)n > SIZE_MAX / sizeof(int)) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  // Allocate memory for n integers.
  arr = malloc((size_t)n * sizeof(int));

  // Check whether memory allocation succeeded.
  if (arr == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  // Read n integers from the user.
  printf("Enter %d integers: ", n);

  for (int i = 0; i < n; i++) {
    if (scanf("%d", &arr[i]) != 1) {
      printf("Invalid input.\n");
      free(arr);
      return 1;
    }
  }

  // Calculate the sum of all integers.
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }

  // Calculate the average using floating-point division.
  average = (double)sum / n;

  // Display results in the required format.
  printf("Sum = %lld\n", sum);
  printf("Average = %.2f\n", average);

  // Free the dynamically allocated memory.
  free(arr);

  return 0;
}
