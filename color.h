#ifndef _COLOR_H_
#define _COLOR_H_

#define BLACK Color::RGB{0,0,0}
#define WHITE Color::RGB{255,255,255}

/* made by chenyo V_2024_2_19 */
/* qq : 1274574753 */

namespace Color
{
    double max3(double a, double b, double c) 
    {
        double max = a;
        if (b > max){max = b;}
        if (c > max){max = c;}
        return max;
    }

    struct RGB
    {
        double Red;
        double Green;
        double Blue;
    };
    struct RGB_float
    {
        double Red;
        double Green;
        double Blue;
    };
    struct ARGB
    {
        double Alpha;
        double Red;
        double Green;
        double Blue;
    };
    struct ARGB_float
    {
        double Alpha;
        double Red;
        double Green;
        double Blue;
    };
    struct CMYK
    {
        double Cyan;
        double Magenta;
        double Yellow;
        double Key;
    };
    /*转换成浮点表示法*/
    /* RGB -> FLOAT */
    RGB_float to_float(RGB old_color)
    {
        RGB_float col;
        col.Red = old_color.Red/255;
        col.Green = old_color.Green/255;
        col.Blue = old_color.Blue/255;
        return col;
    }
    /* ARGB -> FLOAT */
    ARGB_float to_float(ARGB old_color)
    {
        ARGB_float col;
        col.Red = old_color.Red/255;
        col.Green = old_color.Green/255;
        col.Blue = old_color.Blue/255;
        return col;
    }
    /*转换成实数表示法*/
    /* RGB_FLOAT -> RGB */
    RGB to_int(RGB_float old_color)
    {
        RGB col;
        col.Red = old_color.Red*255;
        col.Green = old_color.Green*255;
        col.Blue = old_color.Blue*255;
        return col;
    }
    /* ARGB_FLOAT -> ARGB */
    ARGB to_int(ARGB_float old_color)
    {
        ARGB col;
        col.Red = old_color.Red*255;
        col.Green = old_color.Green*255;
        col.Blue = old_color.Blue*255;
        return col;
    }

    /*各种表示法的相互转换*/
    /* RGB -> ARGB */
    ARGB to_argb(RGB old_color)
    {
        ARGB col;
        col.Alpha = 255;
        col.Red = old_color.Red;
        col.Green = old_color.Green;
        col.Blue = old_color.Blue;
        return col;
    }
    /* RGB_FLOST -> ARGB_FLOAT */
    ARGB_float to_argb_float(RGB_float old_color)
    {
        ARGB_float col;
        col.Alpha = 1;
        col.Red = old_color.Red;
        col.Green = old_color.Green;
        col.Blue = old_color.Blue;
        return col;
    }
    /* ARGB -> RGB */
    RGB to_rgb(ARGB old_color)
    {
        RGB col;
        col.Red = old_color.Red;
        col.Green = old_color.Green;
        col.Blue = old_color.Blue;
        return col;
    }
    /* ARGB_FLOST -> RGB_FLOAT */
    RGB_float to_rgb_float(ARGB_float old_color)
    {
        RGB_float col;
        col.Red = old_color.Red;
        col.Green = old_color.Green;
        col.Blue = old_color.Blue;
        return col;
    }
    /* RGB -> CMYK */
    CMYK to_cmyk(RGB old_color)
    {
        RGB_float col;
        col.Red = old_color.Red/255;
        col.Green = old_color.Green/255;
        col.Blue = old_color.Blue/255;
        CMYK cmyk;
        cmyk.Key = 1 - max3(col.Red,col.Green,col.Blue);
        cmyk.Cyan = (1-col.Red-cmyk.Key)/(1-cmyk.Key);
        cmyk.Magenta = (1-col.Green-cmyk.Key)/(1-cmyk.Key);
        cmyk.Yellow = (1-col.Blue-cmyk.Key)/(1-cmyk.Key);
        return cmyk;
    }
    /* RGB_FLOAT -> CMYK */
    CMYK to_cmyk(RGB_float old_color)
    {
        RGB_float col = old_color;
        CMYK cmyk;
        cmyk.Key = 1 - max3(col.Red,col.Green,col.Blue);
        cmyk.Cyan = (1-col.Red-cmyk.Key)/(1-cmyk.Key);
        cmyk.Magenta = (1-col.Green-cmyk.Key)/(1-cmyk.Key);
        cmyk.Yellow = (1-col.Blue-cmyk.Key)/(1-cmyk.Key);
        return cmyk;
    }
    /* CMYK -> RGB */
    RGB to_rgb(CMYK old_color)
    {
        RGB new_color;
        new_color.Red = 255*(1-old_color.Cyan)*(1-old_color.Key);
        new_color.Green = 255*(1-old_color.Magenta)*(1-old_color.Key);
        new_color.Blue = 255*(1-old_color.Yellow)*(1- old_color.Key);
        return new_color;
    }
    /* CMYK -> ARGB */
    RGB to_argb(CMYK old_color)
    {
        RGB new_color;
        new_color.Red = (1-old_color.Cyan)*(1-old_color.Key);
        new_color.Green = (1-old_color.Magenta)*(1-old_color.Key);
        new_color.Blue = (1-old_color.Yellow)*(1- old_color.Key);
        return new_color;
    }
}

#endif
