#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void enterNumber(int arr[]);
void bubbleSort(int arr[]);
void largestElement(int arr[]);
void primeNumber(int arr[]);

int main() {
    int choice;
    char continueProgram = 'Y';
    int arr[10];
    do {
        printf("\n\nData Structures and Algorithms\n       Final Project");
        printf("\n\n         Main Menu");
        printf("\n----------------------------------");
        printf("\n[1] Bubble Sort\n[2] Largest Element in the Array\n[3] Prime Number Identifier\n[4] Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        (choice >= 1 && choice <= 3) && printf("\n\nData Structures and Algorithms\n       Final Project");
        switch (choice) {
            case 1:
                printf("\n\n        Bubble Sort");
                printf("\n----------------------------------");
                printf("\nThis mini program will sort a set of 10 numbers using the Bubble Sort algorithm.\n");
                enterNumber(arr);
                bubbleSort(arr);
                break;
            case 2:
                printf("\n\n Largest Element in the Array");
                printf("\n----------------------------------");
                printf("\nThis mini program will find the largest element in a set of 10 numbers.\n");
                enterNumber(arr);
                largestElement(arr);
                break;
            case 3:
                printf("\n\n   Prime Number Identifier");
                printf("\n----------------------------------");
                printf("\nThis mini program will find all prime numbers in a set of 10 numbers.\n");
                enterNumber(arr);
                primeNumber(arr);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }          

        do {
            printf("\nDo you want to perform another operation? (Y/N): ");
            if (scanf(" %c", &continueProgram) != 1 || getchar() != '\n') {
                while (getchar() != '\n'); 
                printf("Invalid input. Please enter 'Y' or 'N'.\n");
            }
        } while (strchr("yYnN", continueProgram) == NULL);

    } while (continueProgram == 'y' || continueProgram == 'Y');
   
}

void enterNumber(int arr[]) {
    printf("\nEnter a set of 10 values: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[]) {
    bool isSorted = false;
    int pass = 0;
    while (!isSorted) {
        isSorted = true;
        for (int i = 0; i < 9 - pass; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                isSorted = false;   
            }
        }
        pass++; 
        printf("Pass %d: ", pass);
        for (int k = 0; k < 10; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

void largestElement(int arr[]) {
    int max = arr[0];
    for (int i = 1; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("The largest element in the array is: %d\n", max);
}

void primeNumber(int arr[]) {
    printf("Prime numbers in the array are: ");
    for (int i = 0; i < 10; i++) {
        int isPrime = arr[i] > 1;
        for (int j = 2; j * j <= arr[i] && isPrime; j++) {
            if (arr[i] % j == 0) isPrime = 0;
        }
        if (isPrime) printf("%d ", arr[i]);
    }
    printf("\n");
}

