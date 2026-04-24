#include "lvgl.h"
#include "ui_private.h"

void ui_init_styles(ui_element_t *ui)
{
    lv_style_init(&ui->style.container);
    lv_style_set_border_width(&ui->style.container, 0);
    lv_style_set_margin_all(&ui->style.container, 0);
    lv_style_set_radius(&ui->style.container, 0);
    lv_style_set_pad_all(&ui->style.container, 0);
    lv_style_set_pad_row(&ui->style.container, 0);
    lv_style_set_pad_column(&ui->style.container, 0);
    lv_style_set_bg_opa(&ui->style.container, LV_OPA_TRANSP);

    lv_style_init(&ui->style.tab);
    lv_style_set_border_width(&ui->style.tab, 0);
    lv_style_set_margin_all(&ui->style.tab, 0);
    lv_style_set_radius(&ui->style.tab, 0);
    lv_style_set_pad_all(&ui->style.tab, 2);
    lv_style_set_pad_row(&ui->style.tab, 2);
    lv_style_set_pad_column(&ui->style.tab, 2);

    lv_style_init(&ui->style.tab_item);
    lv_style_set_border_color(&ui->style.tab_item, lv_color_black());
    lv_style_set_border_width(&ui->style.tab_item, 1);
    lv_style_set_border_opa(&ui->style.tab_item, LV_OPA_COVER);
    lv_style_set_border_post(&ui->style.tab_item, true);
    lv_style_set_radius(&ui->style.tab_item, 8);

    lv_style_init(&ui->style.setting_section);
    lv_style_set_border_width(&ui->style.setting_section, 0);
    lv_style_set_margin_all(&ui->style.setting_section, 0);
    lv_style_set_radius(&ui->style.setting_section, 12);
    lv_style_set_pad_all(&ui->style.setting_section, 4);
    lv_style_set_pad_row(&ui->style.container, 4);
    lv_style_set_pad_column(&ui->style.container, 4);
    lv_style_set_bg_color(&ui->style.setting_section, lv_color_white());

    lv_style_init(&ui->style.setting_item);
    lv_style_set_border_width(&ui->style.setting_item, 0);
    lv_style_set_margin_all(&ui->style.setting_item, 0);
    lv_style_set_radius(&ui->style.setting_item, 0);
    lv_style_set_pad_top(&ui->style.setting_item, 0);
    lv_style_set_pad_bottom(&ui->style.setting_item, 0);
    lv_style_set_pad_left(&ui->style.setting_item, 4);
    lv_style_set_pad_right(&ui->style.setting_item, 4);
    lv_style_set_bg_opa(&ui->style.setting_item, LV_OPA_TRANSP);
}