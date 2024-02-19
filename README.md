# Color库介绍
ch : C++颜色库，支持RGB，ARGB，RGB_float，ARGB_float，CMYK格式以及它们之间的转换\
en : C++ color library that supports RGB, ARGB, RGB_float, ARGB_float, CMYK formats and conversions between them

# Color库使用

## #include "color.h"

Color::RGB rgb_color_name; //创建一个RGB颜色 Create an RGB color\
Color::ARGB argb_color_name; //创建一个ARGB颜色 Create an ARGB color

Color::RGB_float argb_float_name; //创建一个ARGB_float颜色 Create an ARGB_float color\
Color::ARGB_float argb_float_name; //创建一个ARGB颜色 Create an ARGB color

Color::CMYK cmyk_color_name; //创建一个CMYK颜色 Create a CMYK color

> //普通版本白色形如{255,255,255},_float版本白色形如{1,1,1}\
> //normal version is white like {255,255,255}, and _float version is white like {1,1,1}

Color::to_float(RGB); //将RGB类型转化为RGB_float类型 Convert RGB types to RGB_float types\
Color::to_float(ARGB); //将ARGB类型转化为ARGB_float类型 Convert ARGB types to ARGB_float types

Color::to_rgb(); //可将任意类型转换为RGB类型 Any type can be converted to RGB type\
Color::to_argb(); //可将任意类型转换为ARGB类型 Any type can be converted to ARGB type\
Color::to_cmyk(); //可将任意类型转换为CMYK类型 Any type can be converted to CMYK type

还有其它函数请看源码 There are other functions that can be found in the source code
