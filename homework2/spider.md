# 这是一个小爬虫
- 可以扒取电影票房网首页的数据，作业需要= =

### 使用方法
- 需要预先安装`python2`，未测试`python3`，请自行解决迁移问题
- 命令行参数: 无参数时默认`url`地址为`http://58921.com`，带参数调用格式为`python spider.py 58921.com`或者指定协议`python spider.py http://58921.com`
- 关于编码: 由于电影票房网的电影名称均为中文，该部分采用`Unicode`编码，如果手动导入文本后使用，请手动编码`str.encode('utf-8')`
- 扒取结果: 返回`概况`表格的所有数据，数值部分均为浮点数，电影名称为`unicode`，每条记录为一个`dict`，整个表为一个`list`。类似这样：

 ```python
 [
    {
	'title': '',
	'rate': 23.1,
	'wangpiao': 100000.23,
	'total': 370000000001.3,
	...,
    },
    {
	...,
	...
    }
 ]
 ```
  - 如需要表格第一行数据的实时票房数据，就是`data[0]['realtime']`，结果为浮点数
  - 又如需要表格第三行数据的累积票房数据，为`data[2]['total']`
  - 各列命名如下:
  	- 名称: `title`
	- 总场次: `event`
	- 占比: `rate`
	- 网票，哈票，万达，金逸: `wangpiao`, `hapiao`, `wanda`, `jinyi`
	- 实时: `realtime`
	- 预计: `forecast`
	- 累积: `total`
 - 原谅窝渣的英语水平= =

 - `P.S.` `spider2.py`输出`json`格式文本
