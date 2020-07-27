import binascii

a='45222e'
key1 = 'a6c8b6733c9b22de7bc0253266a3867df55acde8635e19c73313'
key1_xor_key2 = '37dcb292030faa90d07eec17e3b1c6d8daf94c35d4c9191a5e1e'
key2_xor_key3 = 'c1545756687e7573db23aa1c3452a098b71a7fbf0fddddde5fc1'
flag_xor_key1_xor_key2_xor_key3 = '04ee9855208a2cd59091d04767ae47963170d1660df7f56f5faf'
key2 = ''
key3 = ''
flag = ''

key1_bytes = binascii.unhexlify(key1)
print(key1_bytes)
lol = bytearray(key1_bytes)
print(lol)
#b = [ord(x) for x in s]
