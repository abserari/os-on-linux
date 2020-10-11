#include <stdio.h>

typedef struct parentObject {
    int count;
}parentObject ;

int ref(struct parentObject *obj) {
    return obj->count;
}

typedef struct _customObject {
    parentObject obj;
    int extra;
}_customObject;

void main() {
    _customObject custom = {10,10};

    printf("%d\n",ref(&custom.obj));
    printf("%d\n",ref((parentObject*)&custom));
}