template <typename T>
void merge(T* first, int low, int mid, int high){
    int i = low, j = mid + 1, k = low;
    T *temp = new T[high + 1];
    while (i <= mid && j <= high)
    {
        if (first[i] < first[j])
        {
            temp[k++] = first[i++];
        }
        else
        {
            temp[k++] = first[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = first[i++];
    }
    while (j <= high)
    {
        temp[k++] = first[j++];
    }

    for (int i = low; i <= high; i++)
    {
        first[i] = temp[i];
    }
    delete[] temp;
}

template <typename T>
void mergeSort(T* arr, int l, int h){
    int mid;
	if (l < h)
	{
		mid = (l + h) / 2;
		mergeSort(arr, l, mid);			//разцепваме на все по малки масиви , докато стигнем до 1-елементни масиви,
		mergeSort(arr, mid + 1, h);		// които са сортирани
		merge(arr, l, mid, h);
	}
}