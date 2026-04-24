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
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x80d6ff),LV_PART_MAIN);

    /*创建滑块*/
    lv_obj_t *slider_obj=lv_slider_create(screen);
    lv_obj_set_pos(slider_obj, 0, 0);
    lv_obj_set_size(slider_obj, 30, 1080);

    lv_slider_set_range(slider_obj, 0, 1080);
    lv_slider_set_value(slider_obj, 0, LV_ANIM_OFF);

    lv_obj_delete_delayed(slider_obj, 3000);
}
