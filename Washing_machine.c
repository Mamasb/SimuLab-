#include <stdio.h>
#include <unistd.h> /* for sleep() */
#include <stdbool.h> /* for bool data type */

bool quit_requested = false;

/* Function to simulate a wash cycle with countdown timer */
void wash_clothes(const char *cycle_name, int wash_time)
{
    int i;
    printf("Starting %s cycle. Wash time: %d seconds.\n", cycle_name, wash_time);
    printf("Washing machine started. Setting timer for %d seconds...\n", wash_time);
    for (i = wash_time; i >= 0; i--)
    {
        printf("\rTime remaining: %d seconds   ", i);
        fflush(stdout);
        sleep(1); /* Wait for 1 second */

        /* Check if quit is requested */
        if (quit_requested)
        {
            printf("\nWashing cycle cancelled. Exiting program.\n");
            return;
        }
    }
    printf("\n%s cycle complete.\n", cycle_name);
}

int main()
{
    char clothes_type;
    char additional_feature;
    int wash_time;
    const char *cycle_name;

    while (true)
    {
        printf("\nSelect the type of clothes:\n");
        printf("1. Cotton\n");
        printf("2. Cotton large mix\n");
        printf("3. Easy care\n");
        printf("4. Sports wear\n");
        printf("5. Wool\n");
        printf("6. Quick 30\n");
        printf("7. Rinse and Spin\n");
        printf("8. Test for 10 seconds\n");
        printf("Q. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &clothes_type);

        if (clothes_type == 'Q' || clothes_type == 'q')
        {
            printf("Exiting program.\n");
            break;
        }

        switch (clothes_type)
        {
        case '1':
            wash_time = 40;
            cycle_name = "Cotton";
            break;
        case '2':
            wash_time = 60;
            cycle_name = "Cotton large mix";
            break;
        case '3':
            wash_time = 50;
            cycle_name = "Easy care";
            break;
        case '4':
            wash_time = 45;
            cycle_name = "Sports wear";
            break;
        case '5':
            wash_time = 30;
            cycle_name = "Wool";
            break;
        case '6':
            wash_clothes("Quick 30", 30);
            continue;
        case '7':
            wash_clothes("Rinse and Spin", 10);
            continue;
        case '8':
            wash_clothes("Test for 10 seconds", 10);
            continue;
        default:
            printf("Invalid clothes type.\n");
            continue;
        }

        wash_clothes(cycle_name, wash_time);

        /* Additional features */
        printf("Do you want to perform additional features? (Y/N): ");
        scanf(" %c", &additional_feature);

        if (additional_feature == 'Y' || additional_feature == 'y')
        {
            printf("Available features:\n");
            printf("1. Rinse and Spin\n");
            printf("2. Quick 30\n");
            printf("8. Test for 10 seconds\n");
            printf("Q. Quit\n");
            printf("Enter your choice: ");

            scanf(" %c", &additional_feature);

            switch (additional_feature)
            {
            case '1':
                wash_clothes("Rinse and Spin", 10);
                break;
            case '2':
                wash_clothes("Quick 30", 30);
                break;
            case '8':
                wash_clothes("Test for 10 seconds", 10);
                break;
            case 'Q':
            case 'q':
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
            }
        }
        else if (additional_feature == 'N' || additional_feature == 'n')
        {
            printf("No additional features selected.\n");
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
