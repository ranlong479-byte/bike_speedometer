#include "ui.h"
#include "lvgl.h"
#include "ui_private.h"

static ui_element_t ui;

extern void ui_init_styles(ui_element_t *ui);
extern void ui_init_gpx_tab(ui_element_t *ui);
extern void ui_init_general_tab(ui_element_t *ui);
extern void ui_init_settings_tab(ui_element_t *ui);
extern void ui_status_bar_init(ui_element_t *ui);

void my_ui_init(void)
{
    // init styles
    ui_init_styles(&ui);
    lv_obj_t *screen = lv_screen_active();

    // main_tab
    ui.main_tabview = lv_tabview_create(screen);
    lv_obj_set_pos(ui.main_tabview, 0, 20);
    lv_obj_set_size(ui.main_tabview, LV_HOR_RES, LV_VER_RES - 20);
    lv_tabview_set_tab_bar_position(ui.main_tabview, LV_DIR_BOTTOM);
    lv_tabview_set_tab_bar_size(ui.main_tabview, 20);

    // add tab
    ui.gpx_tab.obj = lv_tabview_add_tab(ui.main_tabview, "GPX");
    ui.general_tab.obj = lv_tabview_add_tab(ui.main_tabview, "General");
    ui.settings_tab = lv_tabview_add_tab(ui.main_tabview, "Settings");
    ui_init_gpx_tab(&ui);
    ui_init_general_tab(&ui);
    ui_init_settings_tab(&ui);

    // status_bar
    ui.status_bar.obj = lv_obj_create(screen);
    ui_status_bar_init(&ui);
}
