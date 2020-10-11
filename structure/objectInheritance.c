#include <stdio.h>
#include <stddef.h>

typedef struct list_head {
    int count;
}list_head ;

int ref(struct list_head *obj) {
    return obj->count;
}


#define CustomTransfer_T(a) ( (_customObject*) ( ((char*)a) - \
offsetof(_customObject,obj_T) ) )

typedef struct _customObject {
    list_head obj;
    list_head obj_T;
    int extra;
}_customObject;

int sum(_customObject *obj) {
    return obj->extra+ ref(&obj->obj) + ref(&obj->obj_T);
}

void main() {
    _customObject custom = {10,11,12};

    printf("%d\n",ref(&custom.obj));
    printf("%d\n",ref((list_head*)&custom));
    printf("%d\n",ref((list_head*)(&custom.obj_T)));

    list_head* parent_T = &custom.obj_T;
    printf("%d\n",sum(CustomTransfer_T(parent_T)));
}