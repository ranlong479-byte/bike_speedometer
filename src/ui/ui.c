#include "ui.h"


static void my_event_cb(lv_event_t * event)
{

    /*使用指针接受传进来的时间指针*/
    lv_obj_t* child=(lv_obj_t*)lv_event_get_user_data(event);

    lv_obj_set_style_bg_color(child, lv_color_hex(0x0000f), LV_PART_MAIN);
    lv_obj_set_size(child, 30, 50);
}
void ui_init(void)
{
    // /*加载屏幕*/
    // lv_obj_t* scr1= lv_obj_create(NULL);

    // lv_obj_t* scr2= lv_obj_create(NULL);

    // lv_screen_load(scr2);
    //! 获取屏幕活动对像
    lv_obj_t *screen = lv_screen_active();
    /*创建元素对象*/
    lv_obj_t * obj = lv_obj_create(screen);

    /*设置元素样式*/
    /*对元素大小进行设置*/
    lv_obj_set_size(obj, 320, 480);
    // lv_obj_set_width(obj, 400);
    lv_obj_set_pos(obj, 100, 100);
    lv_obj_set_style_pad_all(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_t * child=lv_obj_create(obj);
    lv_obj_set_size(child, 200, 300);
    lv_obj_set_style_bg_color(child, lv_color_hex(0xff1111),LV_PART_MAIN);


    lv_obj_add_event_cb(child, my_event_cb, LV_EVENT_CLICKED, child);
    // my_component_t * child1=my_component_create(obj);
    // my_component_set_size(child1, 200, 300);

}
