#pragma once

#include "lvgl.h"

/*透明指针，外部可访问指针成员，并对其修改*/
// typedef struct
// {
//     int width;
//     int height;
// } my_component_t;

// my_component_t component;

/* 不透明指针，不向外暴漏成员，只暴露指针，无法从外部对成员进行修改*/

typedef struct my_component my_component_t;

my_component_t *my_component_create(lv_obj_t *parent);

void my_component_set_size(my_component_t *cmp, int w, int h);

uint32_t my_component_get_width(my_component_t *cmp);
