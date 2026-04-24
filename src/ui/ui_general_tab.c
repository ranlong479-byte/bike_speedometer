#include "lvgl.h"
#include "ui_private.h"

static void ui_general_init_speed(ui_element_t *ui) {
    lv_obj_t* root = ui->general_tab.speed.obj;
    lv_obj_add_style(root, &ui->style.tab_item, 0);
}
static void ui_general_init_distance(ui_element_t *ui) {
    lv_obj_t* root = ui->general_tab.distance.obj;
    lv_obj_add_style(root, &ui->style.tab_item, 0);
}
static void ui_general_init_time(ui_element_t *ui) {
    lv_obj_t* root = ui->general_tab.time.obj;
    lv_obj_add_style(root, &ui->style.tab_item, 0);
}
static void ui_general_init_freq(ui_element_t *ui) {
    lv_obj_t* root = ui->general_tab.freq.obj;
    lv_obj_add_style(root, &ui->style.tab_item, 0);
}
static void ui_general_init_heartbeat(ui_element_t *ui) {
    lv_obj_t* root = ui->general_tab.heartbeat.obj;
    lv_obj_add_style(root, &ui->style.tab_item, 0);
}
static void ui_general_init_power(ui_element_t *ui) {
    lv_obj_t* root = ui->general_tab.power.obj;
    lv_obj_add_style(root, &ui->style.tab_item, 0);
}
static void ui_general_init_slope(ui_element_t *ui) {
    lv_obj_t* root = ui->general_tab.slope.obj;
    lv_obj_add_style(root, &ui->style.tab_item, 0);
}

void ui_init_general_tab(ui_element_t *ui)
{
    lv_obj_t *root = ui->general_tab.obj;
    lv_obj_remove_flag(root, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_style(root, &ui->style.tab, 0);

    // grid layout 4 rows, 2 columns
    static int32_t column_dsc[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static int32_t row_dsc[] = {LV_GRID_FR(2), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    lv_obj_set_grid_dsc_array(root, column_dsc, row_dsc);

    // add item
    ui->general_tab.distance.obj = lv_obj_create(root);
    ui->general_tab.freq.obj = lv_obj_create(root);
    ui->general_tab.heartbeat.obj = lv_obj_create(root);
    ui->general_tab.power.obj = lv_obj_create(root);
    ui->general_tab.slope.obj = lv_obj_create(root);
    ui->general_tab.speed.obj = lv_obj_create(root);
    ui->general_tab.time.obj = lv_obj_create(root);
    lv_obj_set_grid_cell(ui->general_tab.speed.obj, LV_GRID_ALIGN_STRETCH, 0, 2, LV_GRID_ALIGN_STRETCH, 0, 1);
    lv_obj_set_grid_cell(ui->general_tab.freq.obj, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 1, 1);
    lv_obj_set_grid_cell(ui->general_tab.heartbeat.obj, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 1, 1);
    lv_obj_set_grid_cell(ui->general_tab.power.obj, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 2, 1);
    lv_obj_set_grid_cell(ui->general_tab.slope.obj, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 2, 1);
    lv_obj_set_grid_cell(ui->general_tab.distance.obj, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_STRETCH, 3, 1);
    lv_obj_set_grid_cell(ui->general_tab.time.obj, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_STRETCH, 3, 1);

    ui_general_init_speed(ui);
    ui_general_init_distance(ui);
    ui_general_init_time(ui);
    ui_general_init_slope(ui);
    ui_general_init_freq(ui);
    ui_general_init_heartbeat(ui);
    ui_general_init_power(ui);
}