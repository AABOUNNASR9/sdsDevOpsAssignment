
#pragma once

#ifndef ACME_MYLIB_HEADER_INCLUDED
#define ACME_MYLIB_HEADER_INCLUDED

#include <stdint.h>
#include "platform.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mylib_image
{
    int w, h;
    uint8_t* buffer;
} mylib_image;

typedef struct mylib_output_frame
{
    mylib_image output1;
    mylib_image output2;

} mylib_output_frame;



ACME_MYLIB_API void  mylib_process(mylib_image* frame, mylib_output_frame* output_frame);


#ifndef __cpluscplus
}
#endif
#endif