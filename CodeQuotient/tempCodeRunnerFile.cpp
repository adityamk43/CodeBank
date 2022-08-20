int i = 1, j = 1;

    while (i < *size)
    {
        if (arr[i] != arr[i - 1])
            arr[j++] = arr[i];

        i++;
    }

    *size = j;