#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <cairo.h>
#include <cairo-pdf.h>
#include <math.h>

int main()
{

    cairo_surface_t *surface;
    cairo_t *cr;

    surface = cairo_pdf_surface_create("cristal.pdf",400,600);

    cr = cairo_create(surface);
    cairo_set_source_rgb(cr,0,0,65535);

    double x = 0.1,y=0.1,xn,yn;
    for(int i=0;i<25000;i++)
    {
        int t =rand()%100;
        if(t < 25)
        {
            xn= 0.225 * x + 0 * y + 0.3726;
            yn= 0 * x + 0.225 * y + 0.6714;
        }
        if(t < 50 & t > 25)
        {
            xn= 0.255 * x + 0 * y + 0.1146;
            yn= 0 * x + 0.255 * y + 0.2232;
        }
        if(t>50 & t < 75)
        {
            xn= 0.255 * x + 0 * y + 0.6306;
            yn= 0 * x + 0.255 * y + 0.2232;
        }
        if(t > 75)
        {
            xn= 0.37 * x - 0.642 * y + 0.6356;
            yn=  0.642 * x + 0.37 * y - 0.0061;
        }
        x = xn;y=yn;
        int a =(int)(x*200+80);
        int b =(int)(300-y*200);

        cairo_arc(cr,a,b,1,0,2*M_PI);
        cairo_fill(cr);
    }

    x = 0.1,y=0.1;

    cairo_set_source_rgb(cr,0,0,0);
    cairo_select_font_face(cr,"Sans",CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr,10.0);
    cairo_move_to(cr,80,60);
     cairo_show_text(cr,"Cristal");

    cairo_surface_destroy(surface);
    cairo_destroy(cr);

    return 0;
}
