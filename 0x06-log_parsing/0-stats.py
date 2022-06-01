#!/usr/bin/python3
""" Generate a log of internet request responses"""


def verify(line):
    """ verify line format """
    import re

    pattern = r"{} - \[.+\] {} [0-9]+ [0-9]+".format(
        r"(?:[0-9]{1,3}\.){3}[0-9]{1,3}",
        r"\"GET \/projects\/260 HTTP\/1.1\""
    )

    match = re.match(pattern, line)
    # if match:
    #     print("Line: ", line)
    #     print("Match: ", match)
    # else:
    #     print("\t No Match: ", pattern)
    return False if match else True


def get_response(line):
    """ Get response code and file size from input """
    line = line.split()
    code = line[-2]
    size = line[-1]

    return int(code), int(size)


def print_codes(codes):
    """ Print occurances of responses by status code """

    code_list = [200, 301, 400, 401, 403, 404, 405, 500]
    for code in code_list:

        if codes[code] == 0:
            continue

        print("{}: {}".format(
            code, codes[code]
        ))


def clear_buffer(total_size, buffer):
    """ Prints and Clears buffer """
    for line in buffer:
        code, size = get_response(line)
        if code in codes.keys():
            codes[code] += 1
        total_size += size

    print("File size:", total_size)
    print_codes(codes)

    buffer = []
    return total_size, buffer


if __name__ == "__main__":
    import sys

    total_size = 0
    codes = {
        200: 0, 301: 0,
        400: 0, 401: 0,
        403: 0, 404: 0,
        405: 0, 500: 0
    }

    buffer = []
    try:
        for line in sys.stdin:
            if verify(line):
                continue

            buffer.append(line)
            if len(buffer) == 10:
                total_size, buffer = clear_buffer(total_size, buffer)
    finally:
        clear_buffer(total_size, buffer)
        sys.stdout.flush()
