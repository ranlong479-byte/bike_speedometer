#include "ui.h"

typedef enum
{
    RED = 0xff0000,
    GREEN = 0x00ff00,
    BLUE = 0x0000ff
} color_t;
static color_t color[] = {BLUE, RED, GREEN, BLUE, RED};
static uint8_t center_index = 2;
bool is_code_scroll = false;
/*obj对象*/
lv_obj_t *obj;
void scrollbar_cb(lv_event_t *e)
{
    if (is_code_scroll)
    {
        is_code_scroll = false;
        return;
    }
    lv_obj_t *target = lv_event_get_target(e);
    int32_t scroll_x = lv_obj_get_scroll_x(target);

    /*往左滚动*/
    if (scroll_x > 300)
    {
        if (center_index == 4)
        {
            center_index = 1;
        }
        center_index++;
    }
    /*向右滚动*/
    if (scroll_x < 300)
    {
        if (center_index == 0)
        {
            center_index = 3;
        }
        center_index--;
    }
    /*重铺背景颜色*/
    for (size_t i = 0; i < 3; i++)
    {
        lv_obj_t *child = lv_obj_get_child(target, i);
        lv_obj_set_style_bg_color(child, lv_color_hex(color[center_index + i - 1]), LV_PART_MAIN);
    }

    /*移动元素到原来的显示效果*/
    if (scroll_x > 300)
    {
        is_code_scroll = true;
        lv_obj_scroll_to_x(obj, scroll_x - 300, LV_ANIM_OFF);
    }
    if (scroll_x < 300)
    {
        is_code_scroll = true;
        lv_obj_scroll_to_x(obj, scroll_x + 300, LV_ANIM_OFF);
    }
}

void clear_default_style(lv_obj_t *o)
{
    /*去圆角*/
    lv_obj_set_style_radius(o, 0, LV_PART_MAIN);
    /*边框*/
    lv_obj_set_style_border_width(o, 0, LV_PART_MAIN);
    /*外边框*/
    lv_obj_set_style_pad_all(o, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_column(o, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_row(o, 0, LV_PART_MAIN);
}
void ui_init(void)
{
    //! 获取屏幕活动对像
    lv_obj_t *screen = lv_screen_active();
    /*创建元素对象*/
    obj = lv_obj_create(screen);
    clear_default_style(obj);
    /*设置元素样式*/
    lv_obj_set_size(obj, 300, 300);
    lv_obj_set_pos(obj, 100, 100);

    static int32_t col[] = {300, 300, 300, LV_GRID_TEMPLATE_LAST};
    static int32_t row[] = {300, LV_GRID_TEMPLATE_LAST};

    lv_obj_set_layout(obj, LV_LAYOUT_GRID);
    lv_obj_set_grid_dsc_array(obj, col, row);
    /*关闭滚动条*/
    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
    /*关闭惯性滚动*/
    lv_obj_remove_flag(obj, LV_OBJ_FLAG_SCROLL_MOMENTUM);
    for (size_t i = 0; i < 3; i++)
    {
        lv_obj_t *child = lv_obj_create(obj);
        clear_default_style(child);
        /*将child添加到cell中*/
        lv_obj_set_grid_cell(child, LV_GRID_ALIGN_STRETCH, i, 1, LV_GRID_ALIGN_STRETCH, 0, 1);

        lv_obj_set_style_bg_color(child, lv_color_hex(color[center_index + i - 1]), LV_PART_MAIN);
    }

    lv_obj_add_event_cb(obj, scrollbar_cb, LV_EVENT_SCROLL_END, NULL);
    /*移动到中心*/
    lv_obj_scroll_to_x(obj, 300, LV_ANIM_OFF);
}
