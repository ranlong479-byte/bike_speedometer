#include "ui.h"


static void btn_event_cb(lv_event_t* e)
{
    lv_obj_t* obj=lv_event_get_target(e);

    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN);
}
void ui_init(void)
{
    //! 获取屏幕活动对像
    lv_obj_t *screen = lv_screen_active();
    /*创建元素对象*/
    lv_obj_t *obj = lv_obj_create(screen);

    /*设置元素样式*/
    lv_obj_set_size(obj, 320, 480);
    lv_obj_set_pos(obj, 100, 100);
    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(obj, 0, LV_PART_MAIN);
    // lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN);

    /*设置为网格布局*/
    lv_obj_set_layout(obj, LV_LAYOUT_GRID);

    /*设置为3行3列*/
    static int32_t column_dsc[] = {100, 100, 100, LV_GRID_TEMPLATE_LAST}; /* 2 columns with 100- and 400-px width */
    static int32_t row_dsc[] = {100, 100, 100, LV_GRID_TEMPLATE_LAST};
    lv_obj_set_grid_dsc_array(obj, column_dsc, row_dsc);

    lv_obj_t *label;
    lv_obj_t *btn;
    uint8_t i;
    for (i = 0; i < 9; i++)
    {
        if (i == 7)
            continue;
        uint8_t col = i % 3;
        uint8_t row = i / 3;

        btn = lv_obj_create(obj);
        /*Stretch the cell horizontally and vertically too
         *Set span to 1 to make the cell 1 column/row sized*/
        lv_obj_set_style_bg_color(btn, lv_color_hex(0x80D6FF), LV_PART_MAIN);
        lv_obj_set_grid_cell(btn, LV_GRID_ALIGN_STRETCH, col, 1,
                             LV_GRID_ALIGN_STRETCH, row, 1);
        if (i == 6)
        {
            lv_obj_set_grid_cell(btn, LV_GRID_ALIGN_STRETCH, col, 2,
                                 LV_GRID_ALIGN_STRETCH, row, 1);
        }
        if (i == 8)
        {
            lv_obj_set_grid_cell(btn, LV_GRID_ALIGN_STRETCH, col, 1,
                                 LV_GRID_ALIGN_STRETCH, row - 1, 2);
            lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_CLICKED, NULL);
        }

        label = lv_label_create(btn);
        lv_label_set_text_fmt(label, "c%d,r%d", col, row);

        lv_obj_center(label);
    }
}
