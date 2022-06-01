#!/usr/bin/python3

import sys
from time import sleep

while True:
    sleep(1)
    sys.stdout.write("Hello\n")
    sys.stdout.flush()