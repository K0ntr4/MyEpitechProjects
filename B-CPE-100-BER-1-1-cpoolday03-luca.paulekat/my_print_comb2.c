/*
** EPITECH PROJECT, 2021
** my_print_comb2
** File description:
** displays  all the different combinations of two two-digit numbers
*/

int my_print_comb2(void)
{
    int first = 0;
    int second = 0;
    int third = 0;
    int fourth = 1;

    get_result(first, second, third, fourth);
    return (0);
}

void get_result(int first, int second, int third, int fourth)
{
    while (first <= 9 && second <= 9 && third <= 9 && fourth <= 9) {
        print_result2(first + 48, second + 48, third + 48, fourth + 48);
        if (second >= 9 && third >= 9 && fourth >= 9) {
            first++;
            second = -1;
        }
        if (third >= 9 && fourth >= 9) {
            second++;
            third = first;
            fourth = second;
        }
        if (fourth >= 9) {
            third++;
            fourth = 0;
        } else {
            fourth++;
        }
    }
}

void print_result2(int f, int s, int t, int fth)
{
    char space = ' ';
    char comma = 44;
    write(1, &f, 1);
    write(1, &s, 1);
    write(1, &space, 1);
    write(1, &t, 1);
    write(1, &fth, 1);
    if (f == 57 && s == 56 && t == 57 && fth == 57){
    } else {
        write(1, &comma, 1);
        write(1, &space, 1);
    }
}
