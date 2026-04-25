#include "ui.h"

static void keypad_cd(lv_event_t *event)
{
    /*target 具体的按键*/
    lv_obj_t *target_btn = (lv_obj_t *)lv_event_get_target(event);

    /*背景板*/
    lv_obj_t *current_panel = (lv_obj_t *)lv_event_get_current_target(event);

    /*输出结果*/
    lv_obj_t *out_label = (lv_obj_t *)lv_event_get_user_data(event);

    /*如果手指点在了背景板的空白版，target和current_target就是一个人*/
    if(target_btn==current_panel)
    {
        return;
    }
    lv_obj_t *btn_label= lv_obj_get_child(target_btn, 0);
    if(btn_label!=NULL)
    {
        const char *txt = lv_label_get_text(btn_label);
        lv_label_set_text_fmt(out_label, "%s", txt);
    }
}
void ui_init(void)
{
    /*放置顶部，专用展示按了什么*/
    lv_obj_t *screen = lv_screen_active();

    lv_obj_t *out_label = lv_label_create(screen);
    lv_label_set_text(out_label, "waiting...");
    lv_obj_align(out_label, LV_ALIGN_TOP_MID, 0, 20);

    lv_obj_set_style_bg_color(out_label, lv_color_hex(0x0022ff), LV_PART_MAIN);

    /*创建大背景版*/
    lv_obj_t *panel = lv_obj_create(screen);
    lv_obj_set_size(panel, 240, 240);
    lv_obj_align(panel, LV_ALIGN_CENTER, 0, 20);

    /*开启灵活布局，让按键自动排布*/
    lv_obj_set_flex_flow(panel, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(panel, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    /*注册回调*/
    lv_obj_add_event_cb(panel, keypad_cd, LV_EVENT_CLICKED, out_label);

    for (int i = 1; i <= 6; i++)
    {
        lv_obj_t *btn =lv_button_create(panel);
        lv_obj_set_size(btn, 60, 60);

        /*允许时间冒泡到父元素*/
        lv_obj_add_flag(btn, LV_OBJ_FLAG_EVENT_BUBBLE);
        /*给每个按键添加数字标签*/
        lv_obj_t *label = lv_label_create(btn);

        lv_label_set_text_fmt(label, "%d", i);
        lv_obj_center(label);
    }
}
