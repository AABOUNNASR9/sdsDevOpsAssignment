from pathlib import Path
from turtle import shape
import pytest

import numpy as np

from acme_mylib.mylib import process

THIS_DIR = Path(__file__).parent

def test_data_dir():
    return THIS_DIR.parent.parent / "cpp_project" / "tests" / "data"


@pytest.mark.parametrize("input_filename", ["input_image.bin", "input_random_image.bin"])
def test_mylib(input_filename):
    input_filepath = test_data_dir() / input_filename

    with open(input_filepath, "rb") as f:
        input_image = np.fromstring(f.read(), dtype=np.uint8).reshape(480, 640)

    out1, out2 = process(input_image)

    assert np.all(out1 < 64)
    assert np.all(out2 < 8)