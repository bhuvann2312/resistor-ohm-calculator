#include <stdio.h>
#include <math.h>

void printColors() {
    printf("\nColor Codes:\n");
    printf("0: Black  1: Brown  2: Red    3: Orange  4: Yellow\n");
    printf("5: Green  6: Blue   7: Violet 8: Grey    9: White\n");
}

void resistorColorCode() {
    int b1, b2, mult;
    printColors();
    printf("\nEnter 1st band digit (0-9): ");
    scanf("%d", &b1);
    printf("Enter 2nd band digit (0-9): ");
    scanf("%d", &b2);
    printf("Enter multiplier band (0-9): ");
    scanf("%d", &mult);

    if (b1 < 0 || b1 > 9 || b2 < 0 || b2 > 9 || mult < 0 || mult > 9) {
        printf("Invalid color band input.\n");
        return;
    }

    double resistance = (b1 * 10 + b2) * pow(10, mult);
    if (resistance >= 1000000)
        printf("Resistance: %.2f M-Ohm\n", resistance / 1000000.0);
    else if (resistance >= 1000)
        printf("Resistance: %.2f k-Ohm\n", resistance / 1000.0);
    else
        printf("Resistance: %.2f Ohm\n", resistance);
}

void ohmsLaw() {
    int choice;
    double v, i, r;
    printf("\n1. Find Voltage (V = I * R)\n2. Find Current (I = V / R)\n3. Find Resistance (R = V / I)\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter Current (A) and Resistance (Ohm): ");
        scanf("%lf %lf", &i, &r);
        printf("Voltage = %.2f V\n", i * r);
    } else if (choice == 2) {
        printf("Enter Voltage (V) and Resistance (Ohm): ");
        scanf("%lf %lf", &v, &r);
        if (r != 0) printf("Current = %.4f A\n", v / r);
        else printf("Resistance cannot be zero.\n");
    } else if (choice == 3) {
        printf("Enter Voltage (V) and Current (A): ");
        scanf("%lf %lf", &v, &i);
        if (i != 0) printf("Resistance = %.2f Ohm\n", v / i);
        else printf("Current cannot be zero.\n");
    }
}

void seriesParallel() {
    double r1, r2;
    printf("\nEnter R1 and R2 (in Ohms): ");
    scanf("%lf %lf", &r1, &r2);
    printf("Series Resistance: %.2f Ohm\n", r1 + r2);
    if (r1 + r2 != 0)
        printf("Parallel Resistance: %.2f Ohm\n", (r1 * r2) / (r1 + r2));
}

int main() {
    int option;
    while (1) {
        printf("\n--- Basic Electronics Calculator ---\n");
        printf("1. 4-Band Resistor Color Code\n");
        printf("2. Ohm's Law Calculator\n");
        printf("3. Series & Parallel Resistance\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        if (scanf("%d", &option) != 1 || option == 4) break;

        switch (option) {
            case 1: resistorColorCode(); break;
            case 2: ohmsLaw(); break;
            case 3: seriesParallel(); break;
            default: printf("Invalid option.\n");
        }
    }
    return 0;
}
