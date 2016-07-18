# -*- coding:utf-8 -*-
# File Name: addData.py
# Author: zhengdongjian@tju.edu.cn
# Create Time: 2015年11月27日 16:58:06

import sys
reload(sys)
sys.setdefaultencoding('utf-8')

import json
import random
import pprint

with open('data.json', 'r') as f:
    data = json.load(f)

for item in data:
    item[u'a'] = random.randint(10, 1000)
    item[u'b'] = random.randint(10, 1000)
    item[u'c'] = random.randint(10, 1000)

#print(json.dumps(data, ensure_ascii = False, indent = 2))

with open('data2.json', 'w') as f:
    json.dump(data, f, ensure_ascii = False, indent = 2)
