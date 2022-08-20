
#include "mylib.h"

void mylib_process(mylib_image* frame, mylib_output_frame* output_frame)
{
    for(auto i=0u; i<frame->h; ++i)
    {
        for(auto j=0u; j<frame->w; ++j)
        {
            const auto index = (i*frame->w)+j;
            auto &pix = frame->buffer[index];
            output_frame->output1.buffer[index] = (pix >> 3) & 0x3F;
            output_frame->output2.buffer[index] = pix & 0x07;
        }
    }
}
