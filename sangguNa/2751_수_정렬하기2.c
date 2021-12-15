#include <stdio.h>

int N;
int arr[1000000];
int sorted[1000000];

void merge(int *arr, int left, int mid, int right)
{
    /*
        i : 왼쪽 배열에 대한 인덱스
        j : 오른쪽 배열에 대한 인덱스
        k : 정렬될(sorted) 배열에 대한 인덱스
    */
    int i, j, k, l;

    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right)//분할 정렬된 리스트 합병
    {
        if (arr[i] <= arr[j])//오름차순
            sorted[k++] = arr[i++];
        else
            sorted[k++] = arr[j++];
    }

    if (i > mid)//오른쪽 배열의 남은 값들을 넣어줌
    {
        for (l = j; l <= right; l++)
            sorted[k++] = arr[l];
    }
    else//왼쪽 배열의 남은 값들을 넣어줌
        for (l = i; l <= mid; l++)
            sorted[k++] = arr[l];
    
    for (l = left; l <= right; l++)//정렬된 배열을 arr에 다시 넣어줌
        arr[l] = sorted[l];
}

void merge_sort(int *arr, int left, int right)
{
    int mid;

    if (left < right)
    {
        mid = (left + right) / 2;//배열의 중앙위치 저장 - 분할
        merge_sort(arr, left, mid);//앞쪽 배열 정렬 - 정복
        merge_sort(arr, mid + 1, right);//뒤쪽 배열 정렬 -정복
        merge(arr, left, mid, right);//정리된 2개 부분 배열 합병 - 결합
    }
}

int main(void)
{
    scanf("%d\n", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    merge_sort(arr, 0, N - 1);

    for (int i = 0; i < N; i++)
        printf("%d\n", arr[i]);
}