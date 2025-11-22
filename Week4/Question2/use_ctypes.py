from ctypes import cdll, c_char_p, create_string_buffer

lib = cdll.LoadLibrary("./libstr.so")

# set arg types
lib.make_upper.argtypes = [c_char_p]

# string buf (mutable)
text = create_string_buffer(b"reshma mahata")

# call fn
lib.make_upper(text)

# print
print(text.value.decode())