/*
** EPITECH PROJECT, 2021
** my_sort_int_array
** File description:
** sorts an integer array in ascending order
*/

void my_sort_int_array(int *array , int size)
{
    int i = 0;
    int content = 0;
    int counter = 0;

    while (i < size){
        if (array[i] > array[i + 1]){
            content = array[i];
            array[i] = array[i + 1];
            array[i + 1] = content;
            i++;
            counter++;
        } else {
            i++;
        }
    }
    if (counter != 0){
        counter = 0;
        my_sort_int_array(array, size);
    }
}
