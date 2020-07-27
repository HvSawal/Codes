s = "label"
s_list = [chr(ord(c)^13) for c in s]
flag = "crypto{" + ''.join(s_list) + "}"
print(flag)
