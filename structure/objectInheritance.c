#include <stdio.h>
#include <stddef.h>

#define CustomTransfer(a) ( (_customObject*) ( ((char*)a) - \
offsetof(_customObject,obj_T) ) )

typedef struct parentObject {
    int count;
}parentObject ;

int ref(struct parentObject *obj) {
    return obj->count;
}

typedef struct _customObject {
    parentObject obj;
    parentObject obj_T;
    int extra;
}_customObject;

int sum(_customObject *obj) {
    return obj->extra+ ref(&obj->obj) + ref(&obj->obj_T);
}

void main() {
    _customObject custom = {10,11,12};

    printf("%d\n",ref(&custom.obj));
    printf("%d\n",ref((parentObject*)&custom));
    printf("%d\n",ref((parentObject*)(&custom.obj_T)));

    parentObject* parent_T = &custom.obj_T;
    printf("%d\n",sum(CustomTransfer(parent_T)));
}