from . import _mylib
import numpy as np


def _get_arrayptr(ffi_handle, array, ctype=None):
    """Get a CFFI compatible pointer object for an array.

    Supported ``array`` types are:
    numpy ndarrays: The pointer to the underlying array buffer is cast
      to a CFFI pointer. Value returned from __call__ will be a pointer,
      but the numpy C buffer is updated in place, so continue to use the
      numpy ndarray object.
    CFFI CData pointers: If the user is already working with C arrays
      (i.e., ``ffi.new("int[10]"))`` these will be returned as given.

    Parameters
    ----------
    ffi_handle : ffi handle
    array : buffer as a numpy array or cffi CData pointer
    ctype : ctype

    Returns
    -------
    CFFI compatible pointer object
    """
    if isinstance(array, np.ndarray):
        if ctype is None:
            return ffi_handle.cast('void *', array.__array_interface__['data'][0])
        else:
            return ffi_handle.cast(ctype, array.__array_interface__['data'][0])

    elif isinstance(array, ffi_handle.CData):
        return array
    else:
        raise RuntimeError('Unknown array type. Not numpy and not a CFFI C array.')

def process(frame: np.ndarray) :
    h, w = frame.shape
    c_frame = _mylib.ffi.new("mylib_image*")
    c_frame.w = w
    c_frame.h = h
    c_frame.buffer = _get_arrayptr(_mylib.ffi, frame, "uint8_t*")

    out1 = np.zeros_like(frame);
    out2 = np.zeros_like(frame);

    c_output_frame = _mylib.ffi.new("mylib_output_frame*")
    c_output_frame.output1.w = w
    c_output_frame.output1.h = h
    c_output_frame.output1.buffer = _get_arrayptr(_mylib.ffi, out1, "uint8_t*")
    c_output_frame.output2.w = w
    c_output_frame.output2.h = h
    c_output_frame.output2.buffer = _get_arrayptr(_mylib.ffi, out2, "uint8_t*")

    _mylib.lib.mylib_process(c_frame, c_output_frame)

    return out1, out2
