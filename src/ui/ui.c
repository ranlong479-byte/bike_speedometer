#include"ui.h"

void ui_init(void)
{
    //!获取屏幕活动对像
    lv_obj_t * screen=lv_screen_active();
    /*创建元素对象*/
    lv_obj_t *obj=lv_obj_create(screen);

    /*设置元素样式*/
    lv_obj_set_size(obj, 320, 480);
    lv_obj_set_pos(obj, 100, 100);
    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(obj, 0,LV_PART_MAIN);
    lv_obj_set_style_pad_all(obj, 0,LV_PART_MAIN);
    // lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff),LV_PART_MAIN);

    /*设置obj为弹性布局*/
    lv_obj_set_layout(obj, LV_LAYOUT_FLEX);

    /*水平流动*/
    lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_ROW);
    /*对齐方式*/
    lv_obj_set_flex_align(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    for (size_t i = 0; i < 5;i++)
    {
        lv_obj_t* child =lv_obj_create(obj);
        lv_obj_set_size(child, i * 10 + 10, i * 10 + 10);
        lv_obj_set_scrollbar_mode(child, LV_SCROLLBAR_MODE_OFF);
        lv_obj_set_style_bg_color(child, lv_color_hex(0x0022ff), LV_PART_MAIN);
    }
}
