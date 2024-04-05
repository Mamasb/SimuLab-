#include <stdio.h>
#include <unistd.h> /* for sleep() */
#include <stdbool.h> /* for bool data type */
#include <time.h> /* for time functions */

bool quit_requested = false;

/* Function to simulate cooking food in a microwave */
void cook_food(const char *food_type, int cook_time)
{
    int i;
    clock_t start_time, end_time;
    double cpu_time_used;

    printf("Cooking %s. Cooking time: %d seconds.\n", food_type, cook_time);
    printf("Microwave started. Setting timer for %d seconds...\n", cook_time);

    start_time = clock();
    for (i = cook_time; i >= 0; i--)
    {
        printf("\rTime remaining: %d seconds   ", i);
        fflush(stdout);
        sleep(1); 
        
        if (quit_requested)
        {
            printf("\nMicrowave stopped. Food not cooked.\n");
            return;
        }
    }
    end_time = clock();

    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\n%s cooked successfully in %.2f seconds.\n", food_type, cpu_time_used);
}

int main()
{
    char food_type;
    int cook_time;
    const char *food_name;

    while (true)
    {
        printf("\nSelect the type of food to cook:\n");
        printf("1. Popcorn\n");
        printf("2. Pizza\n");
        printf("3. Soup\n");
        printf("4. Hot Dog\n");
        printf("5. Beverage\n");
        printf("Q. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &food_type);

        if (food_type == 'Q' || food_type == 'q')
        {
            printf("Exiting microwave.\n");
            break;
        }

        switch (food_type)
        {
        case '1':
            cook_time = 120;
            food_name = "Popcorn";
            break;
        case '2':
            cook_time = 180;
            food_name = "Pizza";
            break;
        case '3':
            cook_time = 90;
            food_name = "Soup";
            break;
        case '4':
            cook_time = 60;
            food_name = "Hot Dog";
            break;
        case '5':
            cook_time = 30;
            food_name = "Beverage";
            break;
        default:
            printf("Invalid food type.\n");
            continue;
        }

        quit_requested = false;

        cook_food(food_name, cook_time);

        if (quit_requested)
        {
            break;
        }
    }

    return 0;
}
