# -*- coding:utf-8 -*-
# Author: zhengdongjian@tju.edu.cn
# Create Time: 2015年11月17日 11:34:29

import sys
reload(sys)
sys.setdefaultencoding('utf-8')
sys.stdout = open('sample.csv', 'w')

import urllib
import urllib2
import re
import chardet
import string

url = 'http://'
#url pre-check
#print sys.argv[:]
if len(sys.argv) < 2:
    sys.stderr.write('Missing url address! Fetch http://58921.com by default...\n')
    url += '58921.com'
    #exit()
elif len(sys.argv) > 2:
    sys.stderr.write('Too many arguments!\n')
    sys.stderr.write('Usage: python spider.py url_to_fetch\n')
    exit()
else:
    if string.find(sys.argv[1], 'http://') != -1:
        url = sys.argv[1]
    else:
        url += sys.argv[1]
#print url
user_agent = 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'
headers = { 'User-Agent': user_agent}

try:
    myrequest = urllib2.Request(url, headers = headers)
    myresponse = urllib2.urlopen(myrequest)
    #print myresponse.read().decode('utf-8')
except urllib2.URLError, e:
    if hasattr(e, "code"):
        sys.stderr.write(e.code)
    if hasattr(e, "reason"):
        sys.stderr.write(e.reason)
    exit()
if myresponse is None:
    sys.stderr.write('Warning: Connect error!\n')
    exit()
#only fetch from the summary table
try:
    content = myresponse.read().decode('utf-8')
except UnicodeDecodeError, e:
    sys.stderr.write('error occured at:', 'myresponse.read().decode(\'utf-8\'):\n')
    if hasattr(e, 'code'):
        sys.stderr.write(e.code)
    if hasattr(e, 'reason'):
        sys.stderr.write(e.reason)
    exit()
left = unicode.find(content, 'id="box_office_live_summary');
right = unicode.find(content, 'form_description', left);
content = content[left:right]

#regular match
pattern = re.compile('<tr class="odd">.*?</tr>|<tr class="even">.*?</tr>', re.S)
items = re.findall(pattern, content)

#print(len(items))
## convert unicode to double
def str2db(s):
    slash = unicode.find(s, '万')
    if slash == -1:
        if unicode.find(s, '-') != -1:
            return 0
        slash = unicode.find(s, '亿')
        if slash == -1:
            return float(s)
        else:
            return float(s[0:slash]) * 1e8
    else:
        return float(s[0:slash]) * 1e4

## create data table
names = ['title', 'id', 'event/rate', 'wangpiao', 'hapiao', 'wanda', 'jinyi', 'realtime', 'forecast', 'total']
data = [] #final json list
for item in items:
    #for each item, split by td
    #follow as title(电影名称), 编号,  总场次/占比, 网票票房, 哈票, 万达, 金逸, 实时, 预计, 累积
    #mark-- as 0--------------, (1)-,  1----------, 2-------, 3---, 4---, 5---, 6---, 7---, 8---
    #named- as title----------  id--   event/rate-, wangpiao  hapiao wanda jinyi realtime forecast total
    tds = re.findall('<td>.*?</td>', item)
    answer = {}
    
    #title & id
    left = unicode.find(tds[0], 'title="') + 7
    right = unicode.find(tds[0], '"', left)
    answer['title'] = tds[0][left : right]
    answer['id'] = re.findall('film/(.*?)/', tds[0])[0]

    #event & rate
    tds[1] = tds[1][4 : (len(tds[1]) - 6)]
    event_and_rate = unicode.split(tds[1], '/')
    answer['event'] = str2db(event_and_rate[0])
    answer['rate'] = float(event_and_rate[1])
    
    #wangpiao, hapiao, wangda, jinyi, realtime, forecast, total
    idx = 2 #[2, ..., 8]
    while idx <= 8:
        answer[names[idx + 1]] = str2db(tds[idx][4 : (len(tds[idx]) - 5)])
        idx = idx + 1
    data.append(answer)
sys.stderr.write('Totally ' + str(len(data)) + ' recordings fetched\n')

print 'id,title,event,rate,wangpiao,hapiao,wanda,jinyi,realtime,forecast,total'
idx = 0
while idx < len(data):
    #named- as title----------  event/rate-, wangpiao  hapiao wanda jinyi realtime forecast total
    print unicode(data[idx]['id']) + ',' + unicode(data[idx]['title']) + ',' + unicode(data[idx]['event']) + ',' + unicode(data[idx]['rate']) + ',' + unicode(data[idx]['wangpiao']) + ',' + unicode(data[idx]['hapiao']) + ',' + unicode(data[idx]['wanda']) + ',' + unicode(data[idx]['jinyi']) + ',' + unicode(data[idx]['realtime']) + ',' + unicode(data[idx]['forecast']) + ',' + unicode(data[idx]['total'])
    #for res in data[idx]:
        #print res + ', ' + str(data[idx][res])
    idx = idx + 1
exit()
for dat in data:
    #print chardet.detect(str(dat))
    print unicode(dat)
    print dat['title']
    print '-------------------'
