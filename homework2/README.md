# 电影票房数据可视化

- 使用`python`抓取数据
- 使用`d3.js`制作可视化效果

### Python 爬虫部分

- 参`spider.md`说明

### d3.js 笔记

- `d3.js`的四部曲...
 - 1. 声明`DOM`对象集
 - 2. 声明数据对象
 - 3. 获取缺失的`DOM`对象集
 - 4. 追加`DOM`对象并设置其属性
 - 前两步必有~

- 预置的`ease`效果
 - `linear`, `cubic`, `cubic-in-out`, `sin`, `sin-out`, `exp`, `circle`, `back`, `bounce`

#### `d3.js`之`SVG`矢量图

- `SVG`常用元素
 - `svg`: `svg`常用文档
 - `g`: 分组
 - `rect`: 矩形
 - `circle`: 圆形
 - `ellipse`: 椭圆
 - `polyline`: 折线
 - `polygon`: 多边形
 - `text`: 文字
 - `path`: 路径

- `SVG`插值策略
 - `line.interpolate([interpolate])`
 - `linear`: 线性插值
 - `linear-closed`: 线性插值，封闭起点和终点形成多边形
 - `step`: 步进插值，曲线只能沿`x`轴和`y`轴交替伸展
 - `step-before`: 步进插值，曲线只能沿`y`轴和`x`轴交替伸展
 - `step-after`: 同`step`
 - `basis`: *B*样条插值
 - `basis-open`: *B*样条插值，起点终点不相交
 - `basis-closed`: *B*样条插值，连接起点终点形成多边形
 - `bundle`: 基本等效于*basis*，除了有额外的*tension*参数用于拉直样条
 - `cardinal`: *Cardina*样条插值
 - `cardinal-open`: *Cardina*样条插值，起点终点不相交
 - `cardinal-closed`: *Cardina*样条插值，起点终点连接形成多边形
 - `monotone`: 立方插值，保留*y*方向的单调性
 - `[interpolate]`也可以是一个函数，用于定制自己的插值函数= =
