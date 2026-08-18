#include <stdio.h>
struct StudentDetails
{
    int StudentID;
    char name[50];
    float CSE103;
    float MAT101;
    float ENG7101;
    float CGPA;
};

float CGPA_calculator(float cse, float mat, float eng);

int main()
{
    FILE *input;
    FILE *output;

    struct StudentDetails std[100];
    int n = 0;

    input = fopen("./input.txt", "r");
    if (input == NULL)
        return 1;

    fscanf(input, "%d", &n);

    for (int i = 0; i < n; i++)
    {
        fscanf(input, "%d", &std[i].StudentID);
        fscanf(input, " %[^\n]", std[i].name);
        fscanf(input, "%f", &std[i].CSE103);
        fscanf(input, "%f", &std[i].MAT101);
        fscanf(input, "%f", &std[i].ENG7101);

        std[i].CGPA = CGPA_calculator(std[i].CSE103, std[i].MAT101, std[i].ENG7101);
    }

    fclose(input);

    output = fopen("./output.txt", "w");
    if (output == NULL)
        return 1;

    fprintf(output, "------------------------------------------------------------------------\n");
    fprintf(output, "%-8s %-15s %-10s %-10s %-10s %-8s\n", "ID", "Name", "CSE103", "MAT101", "ENG7101", "CGPA");
    fprintf(output, "------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        fprintf(output, "%-8d %-15s %-10.2f %-10.2f %-10.2f %-8.2f\n",std[i].StudentID, std[i].name, std[i].CSE103, std[i].MAT101, std[i].ENG7101, std[i].CGPA);
    }

    fprintf(output, "------------------------------------------------------------------------\n");

    fclose(output);

    return 0;
}

float CGPA_calculator(float cse, float mat, float eng)
{
    float total_credits = 4.5 + 3 + 3;
    float sum = (cse * 4.5) + (mat * 3) + (eng * 3);
    return sum / total_credits;
}
