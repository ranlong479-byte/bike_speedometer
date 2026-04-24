#include "my_component.h"

struct my_component
{
    int width;
    int height;
    int border_width;
    lv_color_t bg_color;
    lv_obj_t *handle;
};

my_component_t *my_component_create(lv_obj_t *parent)
{
    my_component_t *cmp = lv_malloc_zeroed(sizeof(my_component_t));
    cmp->width = 200;
    cmp->height = 200;
    cmp->border_width = 5;
    cmp->bg_color = lv_color_hex(0x00ff11);
    
    lv_obj_t *child = lv_obj_create(parent);
    lv_obj_set_size(child, cmp->width, cmp->height);
    lv_obj_set_style_bg_color(child, cmp->bg_color, LV_PART_MAIN);

    cmp->handle = child;
    return cmp;
}

void my_component_set_size(my_component_t *cmp, int w, int h)
{
    cmp->width = w;
    cmp->height = h;

    lv_obj_set_size(cmp->handle, cmp->width, cmp->height);
}

uint32_t my_component_get_width(my_component_t *cmp)
{
    return cmp->border_width;
}