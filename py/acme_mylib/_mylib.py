from pathlib import Path
from cffi import FFI

THIS_DIR = Path(__file__).parent

source = """

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


void mylib_process(mylib_image* frame, mylib_output_frame* output_frame);
"""

ffi = FFI()
ffi.cdef(source)

lib = ffi.dlopen(str(THIS_DIR / "mylib.dll"))