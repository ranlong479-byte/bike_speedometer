
#include "sm_common.h"

void clear_default_style(lv_obj_t *obj)
{
    /*设置内边距*/
    lv_obj_set_style_pad_all(obj, 0, LV_PART_MAIN);
    /*清除行和列的内边距*/
    lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN);

    /*设置圆角*/
    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN);

    /*设置边框*/
    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN);
}
