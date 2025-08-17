int binary_search_recursion(int* array, int end, int begin, int search_value){
    if (begin > end) { //failed to find
        return -1;
    }

    int middle = begin + (end - begin) / 2;

    if (array[middle] == search_value){
        return middle;
    } else if (array[middle] > search_value) {
        return binary_search_recursion(array, middle - 1, begin, search_value);
    } else {
        return binary_search_recursion(array, end, middle + 1, search_value);
    }
}

//ret: index position of search_value if found, -1 otherwise
int binary_search(int* array, int size, int search_value){
    return binary_search_recursion(array, size, 0, search_value);
}