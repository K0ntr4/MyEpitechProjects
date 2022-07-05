/*
** EPITECH PROJECT, 2021
** language_probability
** File description:
** gives the probabilities of every language
*/

void my_put_float(float nb, int dec);

void lang_probs(float *dif)
{
    float total = dif[0] + dif[1] + dif[2] + dif[3];
    char *langs[4] = {"German\0", "English\0", "French\0", "Spanish\0"};

    for (int i = 0; i < 4; i++) {
        my_putstr(langs[i]);
        my_putstr(" => ");
        my_put_float((dif[i] / total) * 100, 2);
        my_putchar('%');
        my_putchar('\n');
    }
}
