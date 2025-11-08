#include <stdint.h>
#include <stdio.h>
#include <math.h>

// MCU GPIO defines (for LED toggle)
#define PERIPH_BASE        0x40000000U
#define AHB1PERIPH_OFFSET  0x00020000U
#define AHB1PERIPH_BASE    (PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOD_OFFSET       0x0C00U
#define GPIOD_BASE         (AHB1PERIPH_BASE + GPIOD_OFFSET)
#define GPIOD_ODR          (*(volatile uint32_t *)(GPIOD_BASE + 0x14U))

// Function prototypes
void toggleLED(void);
void delay(volatile uint32_t count);
void arraySum(void);
void leastAndGreatest(void);
void primeCheck(void);
void reverseString(void);

int main(void)
{
    printf("=== Week 1 C Exercises ===\n\n");

    // Exercise 1: LED toggle with delay
    toggleLED();
    printf("LED toggled 5 times (check on MCU)\n\n");

    // Exercise 2: Sum of array
    arraySum();
    printf("\n");

    // Exercise 3: Least and Greatest
    leastAndGreatest();
    printf("\n");

    // Exercise 4: Prime number check
    primeCheck();
    printf("\n");

    // Exercise 5: Reverse a string using sizeof
    reverseString();
    printf("\n");

    return 0;
}

// ---------- Exercise Implementations ----------

// Delay function: simple busy-wait
void delay(volatile uint32_t count)
{
    while(count--);
}

// LED toggle: blinks 5 times with delay
void toggleLED(void)
{
    for(int i = 0; i < 5; i++)
    {
        GPIOD_ODR ^= (1 << 13); // toggle LED
        delay(1000000);         // adjust count for visible blink
    }
}

void arraySum(void)
{
    int array[5] = {1, 2, 5, 6, 7};
    int sum = 0;
    for(int i = 0; i < 5; i++)
        sum += array[i];
    printf("Sum of array elements: %d\n", sum);
}

void leastAndGreatest(void)
{
    int array[5] = {1, 5, 33, 22, 76};
    int least = array[0];
    int greatest = array[0];
    for(int i = 0; i < 5; i++)
    {
        least = (array[i] < least) ? array[i] : least;
        greatest = (array[i] > greatest) ? array[i] : greatest;
    }
    printf("Least element: %d\n", least);
    printf("Greatest element: %d\n", greatest);
}

void primeCheck(void)
{
    int number = 763;
    int sqrt_num = (int)sqrt(number);
    int is_prime = 0;

    for(int i = 2; i <= sqrt_num; i++)
    {
        if(number % i == 0)
        {
            is_prime = 1;
            break;
        }
    }

    if(is_prime == 0)
        printf("%d is a prime number!\n", number);
    else
        printf("%d is not a prime number!\n", number);
}

void reverseString(void)
{
    char str[] = "HelloEmbeddedC";
    int length = sizeof(str) - 1; // exclude null terminator

    // Reverse in-place
    for(int i = 0; i < length/2; i++)
    {
        char temp = str[i];
        str[i] = str[length-1-i];
        str[length-1-i] = temp;
    }

    printf("Reversed string: %s\n", str);
}
