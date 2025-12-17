#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
};

int main() {
    struct Patient p;
    FILE *fp;
    int choice;
    int found;
    int id;

    do {
        printf("\n===== Hospital Management System =====\n");
        printf("1. Add Patient Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Patient by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            fp = fopen("hospital.dat", "ab");
            if (fp == NULL) {
                printf("Error opening file!\n");
                exit(1);
            }
            printf("Enter Patient ID: ");
            scanf("%d", &p.id);
            printf("Enter Patient Name: ");
            scanf(" %s", p.name);
            printf("Enter Age: ");
            scanf("%d", &p.age);
            printf("Enter Disease: ");
            scanf(" %s", p.disease);

            fwrite(&p, sizeof(p), 1, fp);
            fclose(fp);
            printf("Record added successfully!\n");
        }

        else if (choice == 2) {
            fp = fopen("hospital.dat", "rb");
            if (fp == NULL) {
                printf("No records found!\n");
            } else {
                printf("\n--- Patient Records ---\n");
                while (fread(&p, sizeof(p), 1, fp)) {
                    printf("ID: %d\nName: %s\nAge: %d\nDisease: %s\n\n",
                           p.id, p.name, p.age, p.disease);
                }
                fclose(fp);
            }
        }

        else if (choice == 3) {
            fp = fopen("hospital.dat", "rb");
            if (fp == NULL) {
                printf("No records found!\n");
            } else {
                printf("Enter Patient ID to search: ");
                scanf("%d", &id);
                found = 0;
                while (fread(&p, sizeof(p), 1, fp)) {
                    if (p.id == id) {
                        printf("\n--- Patient Found ---\n");
                        printf("ID: %d\nName: %s\nAge: %d\nDisease: %s\n",
                               p.id, p.name, p.age, p.disease);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Patient with ID %d not found!\n", id);
                }
                fclose(fp);
            }
        }

        else if (choice == 4) {
            printf("Exiting program...\n");
        }

        else {
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
