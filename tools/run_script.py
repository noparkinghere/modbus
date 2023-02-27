import time
import os
targetDir = r'./config/'
files =  os.listdir(targetDir)

for f in files:
    if f[-3:] == '.py':
        print(f)
        result1 = os.system(".\\config\\"+f)

with open(".\\config\\auto_modbus.json", "r", encoding='utf-8') as f1:
    content = f1.read()
    with open(".\\modbus_addr_py\\code_create\\auto_modbus.json", "w", encoding='utf-8') as f2:
        f2.write(content)
# result1 = os.system('.\\config\\convert2json.py')

# result1 = os.system(str)
# result1 = os.system(str)