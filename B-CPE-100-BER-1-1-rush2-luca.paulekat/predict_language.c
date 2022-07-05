/*
** EPITECH PROJECT, 2021
** RUSH2
** File description:
** desc
*/

#include "my.h"
#include "header.h"

float ENGLISH[26] = {
    8.167, 1.492, 2.782, 4.253,
    12.702, 2.228, 2.015, 6.094,
    6.966, 0.153, 0.772, 4.025,
    2.406, 6.749, 7.507, 1.929,
    0.095, 5.987, 6.327, 9.056,
    2.758, 0.978, 2.360, 0.150,
    1.974, 0.074 };

float GERMAN[26] = {
    6.516, 1.886, 2.732, 5.076,
    16.396, 1.656, 3.009, 4.577,
    6.550, 0.268, 1.417, 3.437,
    2.534, 9.776, 2.594, 0.670,
    0.018, 7.003, 7.270, 6.154,
    4.166, 0.846, 1.921, 0.034,
    0.039, 1.134 };

float FRENCH[26] = {
    7.636, 0.901, 3.260, 3.669,
    14.715, 1.066, 0.866, 0.737,
    7.529, 0.613, 0.074, 5.456,
    2.968, 7.095, 5.796, 2.521,
    1.362, 6.693, 7.948, 7.244,
    6.311, 1.838, 0.049, 0.427,
    0.128, 0.326 };

float SPANISH[26] = {
    11.525, 2.215, 4.019, 5.010,
    12.181, 0.692, 1.768, 0.703,
    6.247, 0.493, 0.011, 4.967,
    3.157, 6.712, 8.683, 2.510,
    0.877, 6.871, 7.977, 4.632,
    2.927, 1.138, 0.017, 0.215,
    1.008, 0.467 };

int lowest_from_array(float *arr, int len)
{
    int lowest = 0;

    for (int i = 0; i < len; i++) {
        if (i == 0)
            lowest = i;
        if (arr[i] < arr[lowest])
            lowest = i;
    }
    return lowest;
}

float calc_diff(letter *data_array, float *lang)
{
    float diff = 0;
    float temp_diff = 0;

    for (int i = 0; i < 26; i++) {
        temp_diff = (data_array[i].frequency - lang[i]);
        diff += temp_diff < 0 ? -temp_diff : temp_diff;
    }
    return diff;
}

int predict_lang(letter *data_array)
{
    float differences[4] = {
        calc_diff(data_array, GERMAN),
        calc_diff(data_array, ENGLISH),
        calc_diff(data_array, FRENCH),
        calc_diff(data_array, SPANISH) };
    char *langs[4] = {
        "German\0",
        "English\0",
        "French\0",
        "Spanish\0" };

    my_putstr("=> ");
    my_putstr(langs[lowest_from_array(differences, 4)]);
    return 0;
}
