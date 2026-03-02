#include <stdio.h>

// required conversion functions

float celsius_to_fahrenheit(float c) {
    return (9.0/5.0) * c + 32;
}

float fahrenheit_to_celsius(float f) {
    return (5.0/9.0) * (f - 32);
}

float celsius_to_kelvin(float c) {
    return c + 273.15;
}

float kelvin_to_celsius(float k) {
    return k - 273.15;
}

// categorize based on Celsius
void categorize_temperature(float c) {

    if (c < 0) {
        printf("Category: Freezing\n");
        printf("Weather Advisory: Wear heavy winter clothing.\n");
    }
    else if (c <= 10) {
        printf("Category: Cold\n");
        printf("Weather Advisory: Wear a jacket.\n");
    }
    else if (c <= 25) {
        printf("Category: Comfortable\n");
        printf("Weather Advisory: Enjoy the weather.\n");
    }
    else if (c <= 35) {
        printf("Category: Hot\n");
        printf("Weather Advisory: Stay hydrated.\n");
    }
    else {
        printf("Category: Extreme Heat\n");
        printf("Weather Advisory: Stay indoors if possible.\n");
    }
}

int main() {

    float value, converted, celsius;
    char original, target;
    char again;

    while (1) {

        printf("\nEnter the temperature value: ");
        if (scanf("%f", &value) != 1) {
            printf("Invalid number. Try again.\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Enter the original scale (C, F, K): ");
        scanf(" %c", &original);

        printf("Enter the target scale (C, F, K): ");
        scanf(" %c", &target);

        // validation
        if (original == 'K' && value < 0) {
            printf("Error: Kelvin cannot be negative.\n");
            continue;
        }

        if ((original != 'C' && original != 'F' && original != 'K') ||
            (target != 'C' && target != 'F' && target != 'K')) {
            printf("Error: Invalid scale entered.\n");
            continue;
        }

        if (original == target) {
            printf("Error: Cannot convert to the same scale.\n");
            continue;
        }

        // convert to Celsius
        if (original == 'C')
            celsius = value;
        else if (original == 'F')
            celsius = fahrenheit_to_celsius(value);
        else
            celsius = kelvin_to_celsius(value);

        // convert to target
        if (target == 'C')
            converted = celsius;
        else if (target == 'F')
            converted = celsius_to_fahrenheit(celsius);
        else
            converted = celsius_to_kelvin(celsius);

        printf("Converted temperature: %.2f %c\n", converted, target);
        categorize_temperature(celsius);

        // ask user if they want to continue
        printf("\nDo you want to convert another temperature? (Y/N): ");
        scanf(" %c", &again);

        if (again == 'N' || again == 'n') {
            printf("Program ended.\n");
            break;
        }
    }

    return 0;
}
