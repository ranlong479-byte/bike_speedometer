#include "lvgl.h"
#include "ui_private.h"

void ui_status_bar_init(ui_element_t *ui)
{
    lv_obj_t *root = ui->status_bar.obj;

    lv_obj_set_pos(root, 0, 0);
    lv_obj_set_size(root, LV_HOR_RES, 20);
    lv_obj_add_style(root, &ui->style.container, 0);
    lv_obj_remove_flag(root, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_opa(root, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_color(root, lv_color_hex(0xC8C8C8), 0);

    // battery
    lv_obj_t *battery_label = lv_label_create(root);
    ui->status_bar.battery_label = battery_label;
    lv_obj_align(battery_label, LV_ALIGN_RIGHT_MID, -4, 0);
    lv_label_set_text(battery_label, LV_SYMBOL_BATTERY_FULL);

    // satellite
    lv_obj_t *satellite_label = lv_label_create(root);
    ui->status_bar.satellite_label = satellite_label;
    lv_obj_align(satellite_label, LV_ALIGN_LEFT_MID, 4, 0);
    lv_label_set_text(satellite_label, LV_SYMBOL_GPS);

    // time
    lv_obj_t *time_label = lv_label_create(root);
    ui->status_bar.time_label = time_label;
    lv_obj_center(time_label);
    lv_label_set_text(time_label, "12:01");
}