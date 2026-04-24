#include "ui.h"

void ui_init(void)
{
    // /*加载屏幕*/
    // lv_obj_t* scr1= lv_obj_create(NULL);

    // lv_obj_t* scr2= lv_obj_create(NULL);

    // lv_screen_load(scr2);
    //! 获取屏幕活动对像
    lv_obj_t *screen = lv_screen_active();
    /*创建元素对象*/
    lv_obj_t *obj = lv_obj_create(screen);

    /*设置元素样式*/
    /*对元素大小进行设置*/
    lv_obj_set_size(obj, 320, 480);
    // lv_obj_set_width(obj, 400);
    lv_obj_set_pos(obj, 100, 100);
    lv_obj_set_style_pad_all(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN);

    // /*创建滑块*/
    // lv_obj_t *slider_obj=lv_slider_create(screen);
    // lv_obj_set_pos(slider_obj, 0, 0);
    // lv_obj_set_size(slider_obj, 30, 1080);

    // lv_slider_set_range(slider_obj, 0, 1080);
    // lv_slider_set_value(slider_obj, 0, LV_ANIM_OFF);
    /*3秒后删除滑块*/
    // lv_obj_delete_delayed(slider_obj, 3000);

    // 获取slider_obj 的父元素
    //  lv_obj_get_parent(slider_obj);

    // // 使用样式表
    // static lv_style_t style_main;
    // /*初始化样式表*/
    // lv_style_init(&style_main);
    // /*设置样式大小*/
    // lv_style_set_width(&style_main, 100);

    // lv_obj_add_style(obj, &style_main, LV_PART_MAIN);

    /*大儿子的相关配置*/
    lv_obj_t *child1 = lv_obj_create(obj);
    lv_obj_set_pos(child1, 10,10);
    lv_obj_set_style_bg_color(child1, lv_color_hex(0xff0000), LV_PART_MAIN);
    lv_obj_set_style_border_width(child1, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(child1, 30, LV_PART_MAIN);
    /*二儿子的相关配置*/
    lv_obj_t *child2 = lv_obj_create(obj);
    lv_obj_set_style_bg_color(child2, lv_color_hex(0x00ff00), LV_PART_MAIN);
    lv_obj_set_x(child2, 10);
    lv_obj_set_style_radius(child2, 30, LV_PART_MAIN);
    lv_obj_set_style_border_width(child2, 0, LV_PART_MAIN);
     /*三儿子的相关配置*/
    lv_obj_t *child3 = lv_obj_create(obj);
    lv_obj_set_style_bg_color(child3, lv_color_hex(0x0000ff), LV_PART_MAIN);
    lv_obj_set_x(child3, 10);
    lv_obj_set_style_radius(child3, 30, LV_PART_MAIN);
    lv_obj_set_style_border_width(child3, 0, LV_PART_MAIN);

    lv_obj_align_to(child2, child1, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    lv_obj_align_to(child3, child2, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
}
