/**
 * @file lv_test_theme_1.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_test_theme_1.h"

#if USE_LV_TESTS
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void create_tab1(lv_obj_t * parent);
static void create_tab2(lv_obj_t * parent);
static void create_tab3(lv_obj_t * parent);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Create a test screen with a lot objects and apply the given theme on them
 * @param th pointer to a theme
 */
void lv_test_theme_1(lv_theme_t * th)
{
    lv_theme_set_current(th);
    th = lv_theme_get_current();    /*If `LV_THEME_LIVE_UPDATE  1` `th` is not used directly so get the real theme after set*/
    lv_obj_t * scr = lv_cont_create(NULL, NULL);
    lv_disp_set_scr_act(scr);
    lv_cont_set_style(scr, th->style.bg);


    lv_obj_t * tv = lv_tabview_create(scr, NULL);
    lv_obj_set_size(tv, lv_disp_get_hor_res(NULL), lv_disp_get_ver_res(NULL));
    lv_obj_t * tab1 = lv_tabview_add_tab(tv, "Tab 1");
    lv_obj_t * tab2 = lv_tabview_add_tab(tv, "Tab 2");
    lv_obj_t * tab3 = lv_tabview_add_tab(tv, "Tab 3");

    create_tab1(tab1);
    create_tab2(tab2);
    create_tab3(tab3);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void create_tab1(lv_obj_t * parent)
{
    lv_page_set_scrl_layout(parent, LV_LAYOUT_PRETTY);

    lv_theme_t * th = lv_theme_get_current();

    static lv_style_t h_style;
    lv_style_copy(&h_style, &lv_style_transp);
    h_style.body.padding.inner = LV_DPI / 4;
    h_style.body.padding.hor = LV_DPI / 4;
    h_style.body.padding.ver = LV_DPI / 6;

    lv_obj_t * h = lv_cont_create(parent, NULL);
    lv_obj_set_style(h, &h_style);
    lv_obj_set_click(h, false);
    lv_cont_set_fit(h, true, true);
    lv_cont_set_layout(h, LV_LAYOUT_COL_M);

    lv_obj_t * btn = lv_btn_create(h, NULL);
    lv_btn_set_fit(btn, true, true);
    lv_btn_set_toggle(btn, true);
    lv_obj_t * btn_label = lv_label_create(btn, NULL);
    lv_label_set_text(btn_label, "Button");

    btn = lv_btn_create(h, btn);
    lv_btn_toggle(btn);
    btn_label = lv_label_create(btn, NULL);
    lv_label_set_text(btn_label, "Toggled");

    btn = lv_btn_create(h, btn);
    lv_btn_set_state(btn, LV_BTN_STATE_INA);
    btn_label = lv_label_create(btn, NULL);
    lv_label_set_text(btn_label, "Inactive");

    lv_obj_t * label = lv_label_create(h, NULL);
    lv_label_set_text(label, "Primary");
    lv_obj_set_style(label, th->style.label.prim);

    label = lv_label_create(h, NULL);
    lv_label_set_text(label, "Secondary");
    lv_obj_set_style(label, th->style.label.sec);

    label = lv_label_create(h, NULL);
    lv_label_set_text(label, "Hint");
    lv_obj_set_style(label, th->style.label.hint);

    static const char * btnm_str[] = {"1", "2", "3", SYMBOL_OK, SYMBOL_CLOSE, ""};
    lv_obj_t * btnm = lv_btnm_create(h, NULL);
    lv_obj_set_size(btnm, lv_disp_get_hor_res(NULL) / 4, 2 * LV_DPI / 3);
    lv_btnm_set_map(btnm, btnm_str);
    lv_btnm_set_toggle(btnm, true, 3);

#if LVGL_VERSION_MAJOR == 5 && LVGL_VERSION_MINOR >= 3
    lv_obj_t * table = lv_table_create(h, NULL);
    lv_table_set_col_cnt(table, 3);
    lv_table_set_row_cnt(table, 4);
    lv_table_set_col_width(table, 0, LV_DPI / 3);
    lv_table_set_col_width(table, 1, LV_DPI / 2);
    lv_table_set_col_width(table, 2, LV_DPI / 2);
    lv_table_set_cell_merge_right(table, 0, 0, true);
    lv_table_set_cell_merge_right(table, 0, 1, true);

    lv_table_set_cell_value(table, 0, 0, "Table");
    lv_table_set_cell_align(table, 0, 0, LV_LABEL_ALIGN_CENTER);

    lv_table_set_cell_value(table, 1, 0, "1");
    lv_table_set_cell_value(table, 1, 1, "13");
    lv_table_set_cell_align(table, 1, 1, LV_LABEL_ALIGN_RIGHT);
    lv_table_set_cell_value(table, 1, 2, "ms");

    lv_table_set_cell_value(table, 2, 0, "2");
    lv_table_set_cell_value(table, 2, 1, "46");
    lv_table_set_cell_align(table, 2, 1, LV_LABEL_ALIGN_RIGHT);
    lv_table_set_cell_value(table, 2, 2, "ms");

    lv_table_set_cell_value(table, 3, 0, "3");
    lv_table_set_cell_value(table, 3, 1, "61");
    lv_table_set_cell_align(table, 3, 1, LV_LABEL_ALIGN_RIGHT);
    lv_table_set_cell_value(table, 3, 2, "ms");
#endif

    h = lv_cont_create(parent, h);

    lv_obj_t * sw_h = lv_cont_create(h, NULL);
    lv_cont_set_style(sw_h, &lv_style_transp);
    lv_cont_set_fit(sw_h, false, true);
    lv_obj_set_width(sw_h, lv_disp_get_hor_res(NULL) / 4);
    lv_cont_set_layout(sw_h, LV_LAYOUT_PRETTY);

    lv_obj_t * sw = lv_sw_create(sw_h, NULL);
#if LVGL_VERSION_MAJOR == 5 && LVGL_VERSION_MINOR >= 3
    lv_sw_set_anim_time(sw, 250);
#endif

    sw = lv_sw_create(sw_h, sw);
    lv_sw_on(sw);


    lv_obj_t * bar = lv_bar_create(h, NULL);
    lv_bar_set_value(bar, 70);

    lv_obj_t * slider = lv_slider_create(h, NULL);
    lv_bar_set_value(slider, 70);

    lv_obj_t * line = lv_line_create(h, NULL);
    static lv_point_t line_p[2];
    line_p[0].x = 0;
    line_p[0].y = 0;
    line_p[1].x = lv_disp_get_hor_res(NULL) / 5;
    line_p[1].y = 0;

    lv_line_set_points(line, line_p, 2);
    lv_line_set_style(line, th->style.line.decor);

    lv_obj_t * cb = lv_cb_create(h, NULL);

    cb = lv_cb_create(h, cb);
    lv_btn_set_state(cb, LV_BTN_STATE_TGL_REL);


    lv_obj_t * ddlist = lv_ddlist_create(h, NULL);
    lv_ddlist_open(ddlist, false);
    lv_ddlist_set_selected(ddlist, 1);

    h = lv_cont_create(parent, h);

    lv_obj_t * list = lv_list_create(h, NULL);
    lv_obj_t * list_btn;
    list_btn = lv_list_add(list, SYMBOL_GPS,  "GPS",  NULL);
    lv_obj_set_size(list, lv_disp_get_hor_res(NULL) / 4, lv_disp_get_ver_res(NULL) / 2);
    lv_btn_set_toggle(list_btn, true);
    lv_list_add(list, SYMBOL_WIFI, "WiFi", NULL);
    lv_list_add(list, SYMBOL_GPS, "GPS", NULL);
    lv_list_add(list, SYMBOL_AUDIO, "Audio", NULL);
    lv_list_add(list, SYMBOL_VIDEO, "Video", NULL);
    lv_list_add(list, SYMBOL_CALL, "Call", NULL);
    lv_list_add(list, SYMBOL_BELL, "Bell", NULL);
    lv_list_add(list, SYMBOL_FILE, "File", NULL);
    lv_list_add(list, SYMBOL_EDIT, "Edit", NULL);
    lv_list_add(list, SYMBOL_CUT,  "Cut",  NULL);
    lv_list_add(list, SYMBOL_COPY, "Copy", NULL);

    lv_obj_t * roller = lv_roller_create(h, NULL);
    lv_roller_set_options(roller, "Monday\nTuesday\nWednesday\nThursday\nFriday\nSaturday\nSunday");
    lv_roller_set_selected(roller, 1, false);
    lv_roller_set_visible_row_count(roller, 3);


}

static void create_tab2(lv_obj_t * parent)
{
    lv_coord_t w = lv_page_get_scrl_width(parent);

    lv_obj_t * chart = lv_chart_create(parent, NULL);
    lv_obj_set_size(chart, w / 3, lv_disp_get_ver_res(NULL) / 3);
    lv_obj_set_pos(chart, LV_DPI / 10, LV_DPI / 10);
    lv_chart_series_t * s1 = lv_chart_add_series(chart, LV_COLOR_RED);
    lv_chart_set_next(chart, s1, 30);
    lv_chart_set_next(chart, s1, 20);
    lv_chart_set_next(chart, s1, 10);
    lv_chart_set_next(chart, s1, 12);
    lv_chart_set_next(chart, s1, 20);
    lv_chart_set_next(chart, s1, 27);
    lv_chart_set_next(chart, s1, 35);
    lv_chart_set_next(chart, s1, 55);
    lv_chart_set_next(chart, s1, 70);
    lv_chart_set_next(chart, s1, 75);


    lv_obj_t * gauge = lv_gauge_create(parent, NULL);
    lv_gauge_set_value(gauge, 0, 40);
    lv_obj_set_size(gauge, w / 4, w / 4);
    lv_obj_align(gauge, chart, LV_ALIGN_OUT_BOTTOM_LEFT, 0, LV_DPI / 4);


    lv_obj_t * arc = lv_arc_create(parent, NULL);
    lv_obj_align(arc, gauge, LV_ALIGN_OUT_BOTTOM_MID, 0, LV_DPI / 8);

    lv_obj_t * ta = lv_ta_create(parent, NULL);
    lv_obj_set_size(ta, w / 3, lv_disp_get_ver_res(NULL) / 4);
    lv_obj_align(ta, NULL, LV_ALIGN_IN_TOP_RIGHT, -LV_DPI / 10, LV_DPI / 10);
    lv_ta_set_cursor_type(ta, LV_CURSOR_BLOCK);

    lv_obj_t * kb = lv_kb_create(parent, NULL);
    lv_obj_set_size(kb, 2 * w / 3, lv_disp_get_ver_res(NULL) / 3);
    lv_obj_align(kb, ta, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, LV_DPI);
    lv_kb_set_ta(kb, ta);

#if USE_LV_ANIMATION
    lv_obj_t * loader = lv_preload_create(parent, NULL);
    lv_obj_align(loader, NULL, LV_ALIGN_CENTER, 0, - LV_DPI);
#endif
}


static void create_tab3(lv_obj_t * parent)
{
    /*Create a Window*/
    lv_obj_t * win = lv_win_create(parent, NULL);
    lv_win_add_btn(win, SYMBOL_CLOSE, lv_win_close_action);
    lv_win_add_btn(win, SYMBOL_DOWN, NULL);
    lv_obj_set_size(win, lv_disp_get_hor_res(NULL) / 2, lv_disp_get_ver_res(NULL) / 2);
    lv_obj_set_pos(win, LV_DPI / 20, LV_DPI / 20);
    lv_obj_set_top(win, true);


    /*Create a Label in the Window*/
    lv_obj_t * label = lv_label_create(win, NULL);
    lv_label_set_text(label, "Label in the window");

    /*Create a  Line meter in the Window*/
    lv_obj_t * lmeter = lv_lmeter_create(win, NULL);
    lv_obj_align(lmeter, label, LV_ALIGN_OUT_BOTTOM_LEFT, 0, LV_DPI / 2);
    lv_lmeter_set_value(lmeter, 70);

    /*Create a 2 LEDs in the Window*/
    lv_obj_t * led1 = lv_led_create(win, NULL);
    lv_obj_align(led1, lmeter, LV_ALIGN_OUT_RIGHT_MID, LV_DPI / 2, 0);
    lv_led_on(led1);

    lv_obj_t * led2 = lv_led_create(win, NULL);
    lv_obj_align(led2, led1, LV_ALIGN_OUT_RIGHT_MID, LV_DPI / 2, 0);
    lv_led_off(led2);

    /*Create a Page*/
    lv_obj_t * page = lv_page_create(parent, NULL);
    lv_obj_set_size(page, lv_disp_get_hor_res(NULL) / 3, lv_disp_get_ver_res(NULL) / 2);
    lv_obj_set_top(page, true);
    lv_obj_align(page, win, LV_ALIGN_IN_TOP_RIGHT,  LV_DPI, LV_DPI);

    label = lv_label_create(page, NULL);
    lv_label_set_text(label, "Lorem ipsum dolor sit amet, repudiare voluptatibus pri cu.\n"
                      "Ei mundi pertinax posidonium eum, cum tempor maiorum at,\n"
                      "mea fuisset assentior ad. Usu cu suas civibus iudicabit.\n"
                      "Eum eu congue tempor facilisi. Tale hinc unum te vim.\n"
                      "Te cum populo animal eruditi, labitur inciderint at nec.\n\n"
                      "Eius corpora et quo. Everti voluptaria instructior est id,\n"
                      "vel in falli primis. Mea ei porro essent admodum,\n"
                      "his ei malis quodsi, te quis aeterno his.\n"
                      "Qui tritani recusabo reprehendunt ne,\n"
                      "per duis explicari at. Simul mediocritatem mei et.");
    lv_page_set_scrl_fit(page, true, true);


    /*Create a Calendar*/
    lv_obj_t * cal = lv_calendar_create(parent, NULL);
    lv_obj_set_size(cal, 5 * LV_DPI / 2, 5 * LV_DPI / 2);
    lv_obj_align(cal, page, LV_ALIGN_OUT_RIGHT_TOP, -LV_DPI / 2, LV_DPI / 3);
    lv_obj_set_top(cal, true);

    static lv_calendar_date_t highlighted_days[2];
    highlighted_days[0].day = 5;
    highlighted_days[0].month = 5;
    highlighted_days[0].year = 2018;

    highlighted_days[1].day = 8;
    highlighted_days[1].month = 5;
    highlighted_days[1].year = 2018;

    lv_calendar_set_highlighted_dates(cal, highlighted_days, 2);
    lv_calendar_set_today_date(cal, &highlighted_days[0]);
    lv_calendar_set_showed_date(cal, &highlighted_days[0]);

    /*Create a Message box*/
    static const char * mbox_btn_map[] = {"\211", "\222Got it!", "\211", ""};
    lv_obj_t * mbox = lv_mbox_create(parent, NULL);
    lv_mbox_set_text(mbox, "Click on the window or the page to bring it to the foreground");
    lv_mbox_add_btns(mbox, mbox_btn_map, NULL);
    lv_obj_set_top(mbox, true);


}

#endif /*USE_LV_TESTS*/
