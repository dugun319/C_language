#include <stdio.h>

typedef int element;
int cnt = 0;

void binarySearch(element a[], int begin, int end, element key)
{
    int middle;
    cnt++;
    if(begin == end) {
        if (key == a[begin])
        {
            printf("%3d 번째에서 검색 성공!\n", cnt);
            return;
        }
    }

    middle = (begin + end) / 2;
    if (key == a[middle])
    {
        printf("%3d 번째에서 검색 성공!\n", cnt);
    }
    else if(key<a[middle] && middle-1 >= begin) {
        binarySearch(a, begin, middle-1, key);
    }
    else if(key>a[middle] && middle+1 <= end) {
        binarySearch(a, middle+1, end, key);
    }
    else {
        printf("%3d 번째에서 검색 실패!\n", cnt);      
    }

}

int main() {
    element a[] = {1, 2, 8, 9, 11, 19, 29};
    element key;

    int size = sizeof(a) / sizeof(element);     //sizeof(a[0]);
    char more;

    printf("\n\n<<검색대상 자료>>\n");
    for(int i=0 ; i<size ; i++) {
        printf("%5d", a[i]);
        puts("");
    }
    do{
        cnt = 0;
        printf("\n검색할 키를 입력하세요: ");
        scanf("%d", &key);
        printf("\n%3d를 검색하라! ->>", key);
        binarySearch(a, 0, size-1, key);        //0부터 시작하여 size-1

        printf("\n\n검색을 계속하려면 y를 입력하세요 ->>");
        //getchar();
        scanf(" %c", &more);                    //\n 입력방지를 위하여 1칸 띄는 것 주의 or getchar();

    } while (more == 'y');

    getchar();

    return 0;
}