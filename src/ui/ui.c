#include "ui.h"
#include "sm_common.h"

//! 定义主题的对象
sm_sub_t *speed_meter_sub = NULL;
static char *running_states[] = {"running", "stopped"};
lv_obj_t *scr = NULL;
void speed_meter_screen_init(void)
{
    scr = lv_screen_active();
    clear_default_style(scr);
}

void speed_meter_navbar_init(void)
{
    lv_obj_t *navbar = lv_obj_create(scr);
    clear_default_style(navbar);

    /*设置导航栏的布局为弹性flex*/
    lv_obj_set_layout(navbar, LV_LAYOUT_FLEX);
    /*设置导航栏的方向为水平*/
    lv_obj_set_flex_flow(navbar, LV_FLEX_FLOW_ROW);
    /*设置导航栏的对齐方式为居中*/
    lv_obj_set_flex_align(navbar, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_left(navbar, 8, LV_PART_MAIN);
    lv_obj_set_style_pad_right(navbar, 8, LV_PART_MAIN);
    /*设置大小*/
    lv_obj_set_size(navbar, lv_pct(100), lv_pct(10));
    /*设置背景颜色*/
    lv_obj_set_style_bg_color(navbar, lv_color_hex(0xd1d3d4), 0);

    /*创建显示的3个内容 label*/
    lv_obj_t *gps_label = lv_label_create(navbar);
    lv_obj_t* running_states_label = lv_label_create(navbar);
    lv_obj_t* batterty_level_label = lv_label_create(navbar);

    /*绑定对应主题*/
    lv_label_bind_text(gps_label, &speed_meter_sub->gps, LV_SYMBOL_GPS " %d");
    lv_label_bind_text(running_states_label, &speed_meter_sub->running_state, "%s");
    lv_label_bind_text(batterty_level_label, &speed_meter_sub->battery_level, " %s");
}

void speed_meter_sub_init(void)
{
    /*为主题的结构体分配内存空间*/
    speed_meter_sub = lv_malloc_zeroed(sizeof(sm_sub_t));
    /*gps主题的初始化*/
    lv_subject_init_int(&speed_meter_sub->gps, 0);
    /*运动状态的初始化 */
    lv_subject_init_pointer(&speed_meter_sub->running_state, running_states[0]);

    /*电池电量的初始化*/
    lv_subject_init_pointer(&speed_meter_sub->battery_level, LV_SYMBOL_BATTERY_3);
}

void sm_ui_init(void)
{
    /*屏幕初始化*/
    speed_meter_screen_init();

    /*初始化所有的主题*/
    speed_meter_sub_init();

    /*顶部导航栏的初始化*/
    speed_meter_navbar_init();
}
