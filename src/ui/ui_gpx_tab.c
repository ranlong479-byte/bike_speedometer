#include "lvgl.h"
#include "ui_private.h"

extern void ui_init_map(ui_element_t *ui);
static void ui_gpx_init_speed(ui_element_t *ui)
{
    lv_obj_t *root = ui->gpx_tab.speed.obj;
    lv_obj_add_style(root, &ui->style.tab_item, 0);

    lv_obj_t *speed_label = lv_label_create(root);
    ui->gpx_tab.speed.speed_label = speed_label;
    lv_label_set_text(speed_label, "20.0km/h");
    lv_obj_center(speed_label);
}
static void ui_gpx_init_distance(ui_element_t *ui)
{
    lv_obj_t *root = ui->gpx_tab.distance.obj;
    lv_obj_add_style(root, &ui->style.tab_item, 0);

    lv_obj_t *distance_label = lv_label_create(root);
    ui->gpx_tab.distance.distance_label = distance_label;
    lv_label_set_text(distance_label, "30km");
    lv_obj_center(distance_label);
}

void ui_init_gpx_tab(ui_element_t *ui)
{
    lv_obj_t *root = ui->gpx_tab.obj;
    lv_obj_remove_flag(root, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_style(root, &ui->style.tab, 0);

    // grid: 2 rows, 2 columns
    static int32_t column_dsc[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static int32_t row_dsc[] = {LV_GRID_FR(3), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    lv_obj_set_grid_dsc_array(root, column_dsc, row_dsc);

    ui->gpx_tab.map.obj = lv_obj_create(root);
    ui->gpx_tab.speed.obj = lv_obj_create(root);
    ui->gpx_tab.distance.obj = lv_obj_create(root);
    lv_obj_set_grid_cell(ui->gpx_tab.map.obj, LV_GRID_ALIGN_STRETCH, 0, 2, LV_GRID_ALIGN_STRETCH, 0, 1);
    lv_obj_set_grid_cell(ui->gpx_tab.speed.obj, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 1, 1);
    lv_obj_set_grid_cell(ui->gpx_tab.distance.obj, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 1, 1);

    ui_init_map(ui);
    ui_gpx_init_speed(ui);
    ui_gpx_init_distance(ui);
}
