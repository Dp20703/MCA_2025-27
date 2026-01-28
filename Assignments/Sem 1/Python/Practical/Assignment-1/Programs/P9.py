# 9) Convert string Hello$World into Base64

import base64

text='Hello$world'

# convert text into bytes
text_bytes=text.encode('utf-8')
# convert bytes into base64 bytes
base64_bytes=base64.b64encode(text_bytes)

# convert base64 bytes back to string
base64_string=base64_bytes.decode('utf-8')

print('Original string: ',text)
print('Base64 encoded string: ',base64_string)

# output
# Original string:  Hello$world
# Base64 encoded string:  SGVsbG8kd29ybGQ=