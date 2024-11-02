arr = ['ana', '1445', '5441', '772', '277', 'ana']
res = []
hashset = set()

for i in range(len(arr)):
    sorted_element = ''.join(sorted(arr[i]))
    res.append(sorted_element)

c = 0 
unique_res = []

for n in res:
    if n in hashset:
        unique_res.append(c)
    else:
        hashset.add(n)
    c += 1

for n in unique_res:
    print(arr[n])
