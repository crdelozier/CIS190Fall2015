#include <cstdio>
#include <cstring>

int main(void) {
    int arr [] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int i = 0;
    int arr2[10];

    char name[100];
    char name2[100];
    // std::string name;

    name = "Chris";
    name = {'C','h','r','i','s','\0'};

    strlen(name);
    strncpy(name2,name,100);

    int arr[10];

    for(i = 0; i < 10; i++) {
      arr2[i] = arr[i];
    }

    for (i = 0; i < 10; i++) {
        printf("%d\n", arr2[i]);
    }
    return 0;
}
