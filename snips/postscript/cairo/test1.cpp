//g++ test1.cpp  -lcairo
//import backend(s) here
#include <cairo/cairo.h>
#include <cairo/cairo-svg.h>
#include <cairo/cairo-ps.h>
//#include <cairo/cairo-image.h>
#include <stdio.h>

int main(int argc, char **argv) {
    cairo_t *cr;
    cairo_surface_t *surface;
    cairo_pattern_t *pattern;
    int x,y;

	
	//bitmaps -- can be rendered onscreen (eg GUI) or saved as PNG
    surface = (cairo_surface_t *)cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 100.0, 100.0);
    
    //surface = (cairo_surface_t *)cairo_svg_surface_create("Cairo_example.svg", 100.0, 100.0);

    //surface = (cairo_surface_t *)cairo_ps_surface_create("out.ps", 100.0, 100.0);

	cr = cairo_create(surface);
    /* Draw the squares in the background */
    for (x=0; x<10; x++)
       for (y=0; y<10; y++)
           cairo_rectangle(cr, x*10.0, y*10.0, 5, 5);

    pattern = cairo_pattern_create_radial(50, 50, 5, 50, 50, 50);
    cairo_pattern_add_color_stop_rgb(pattern, 0, 0.75, 0.15, 0.99);
    cairo_pattern_add_color_stop_rgb(pattern, 0.9, 1, 1, 1);
    cairo_set_source(cr, pattern);
    cairo_fill(cr);
    /* Writing in the foreground */
    cairo_set_font_size (cr, 15);
    cairo_select_font_face (cr, "Georgia",
        CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_source_rgb (cr, 0, 0, 0);
    cairo_move_to(cr, 10, 25);
    cairo_show_text(cr, "Hallo");
    cairo_move_to(cr, 10, 75);
    cairo_show_text(cr, "Wikipedia!");

	cairo_surface_write_to_png (surface, "out.png"); //only for the png version

    cairo_destroy (cr);
    cairo_surface_destroy (surface);
    return 0;
}
