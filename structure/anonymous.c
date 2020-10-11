#include <stdio.h>

// regular struct
// struct fooState {
//     struct barListener {
//         int id;
//         int to;
//         int from;
//     } bar;
// } foo = {1,2,3};

// int main(int argc, char *argv[]) {
//     printf("%d\n",foo.bar.id);
//     return 0;
// }

// anonymous struct
struct fooState {
    struct  {
        int id;
        int to;
        int from;
    } bar;
} foo = {1,2,3};

int main(int argc, char *argv[]) {
    printf("%d\n",foo.bar.id);
    return 0;
}