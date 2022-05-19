﻿## 使用 `GPL` 开源协议,严禁用于商业用途

# 软件说明文档

[Sailor Project 软件说明 ](https://seasky-master.github.io/html/seasky_works/SailorProject/SailorProject.html)

# SerialScope Plus
- 程序打包命令 `windeployqt`

# 提示

- 如果软件出现异常情况，如卡顿，无法退出等，可以按住`CTRE+SHIFT+ESC`进行强制退出，如果你发现了问题所在，或者你清楚导致异常的原因，可以尝试联系作者
- 如果有那位小伙伴会用了，并且觉得好用的话，不妨帮我出一些简易的教程，并在教程中附上项目地址

## 记录
- 2021/7/7 日
    
    准备重新编写SerialScope软件

    - 拟定加入功能
    1. 常用的串口调试助手功能
        - 基础数据收发
        - HEX数据收发
        - 更多的多条发送配置，定时循环发送，方便指令调试
        - 界面优化
        - QT的 `QPlainTextEdit` 加载大量数据会造成界面卡顿，因此如果直接使用，高效率的接收数据会导致程序卡死，网上暂无该 `BUG`的改善措施，沿用上一个版本写的 `QPlainTextEdit` 控件，并需要再做一定的优化
    2. 自定义协议的支持 `Seasky协议` 的支持
        - `Seasky串口协议` 将满足极高的效率，将满足大多数的调试功能，不定长收发
        - 此版本软件发布版本固定最大支持 `24个float数据` 的传输，一个 `CMD_ID` ,一个 16位标志寄存器 `reg` ，如需发送24个 `float`数据，仅需发送 106 字节数据，同时具备了不定长收发功能
        - 增加和预留控件函数接口，方便扩展界面，此版本将加入基于`OpenGl`的3D 欧拉角显示功能
        - 和上次版本一样，所有解析的数据实时显示，以及所有数据汇总显示，汇总数据将加入时间戳，用于保存调试信息，拒绝字符串打印这种低效率的调试手段
    3. 同样是基于`Seasky`协议解算数据加入波形显示功能
    4. 加入浏览器支持，用于加载网页端说明文档，不再需要跳出软件打开网页链接


- 2021/7/11 日

    - 初步完成基本界面布局
    - 解决 `MSVC` 编译问题->中文注释编码格式导致编译不过
    - 由于本次采用`MSVC`编译，解决了 `MINGW`编译无法使用 `WEB` 功能的问题
    - 完成常用串口调试助手功能

- 2021/7/18 日
    - 初步完成所有功能框架
    - 加入 `Html` 功能
    - 代码比较乱，需要简单修改位置，名称，相关功能还需要移动到一起
    - 程序需要去耦合
    - 波形显示窗口鼠标右键，界面抖动问题需要解决

- 2021/7/25 日
    - 使用QSS初步优化界面
    - 开始完善控件部分功能，初步完善陀螺仪欧拉角的3D显示控件功能
    - 开始打包测试版本程序，后续群友测试，优化代码框架
    - 波形显示窗口鼠标右键，界面抖动问题需要解决

- 2021/7/27 日
    - 发布压缩包
    - 功能未完善、功能未完善、功能未完善、功能未完善、测试阶段
    - 改善界面，发送编辑窗口高度固定
    - 波形显示窗口鼠标右键，界面抖动问题需要解决  

- 2021/7/28 日
   - 解决波形显示窗口鼠标右键，界面抖动问题
        - 在此上一个版本是MINGW编译，自带的OPENGL库，所以没有兼容问题，而MSVC缺少OPENGL库，应该是自己添加的OPENGL库带来的兼容问题？
        - 修改了`qcustomplot`中的`void QCPPaintBufferGlFbo::draw(QCPPainter *painter) const` 函数

- 2021/7/30 日
    - 解决Linux串口调试时打印窗口数据混乱的问题，数据更新太快，由于使用了信号与槽分发数据，导致数据错位，更改后直接从串口流中取数据并处理，而不使用槽函数分发，不过不建立分发，需要在数据分类时，每种类型都需要做该处理，因此共享了串口类的指针
    - 重新梳理串口类的依赖关系，程序进一步去耦合，串口类多线程封装

- 2021/7/31 日
    - 进一步去耦合，优化依赖关系
    - 协议部分优化，修改到方便切换支持的最大FLOAT数据长度，方便定制化软件

- 2021/8/1 日
    - 添加多条指令发送窗口对导入csv表格的指令支持，以便于规范化、高效率的使用字符串命令调试

- 2021/8/2 日
    - 处理SEASKY协议显示窗口定时器关闭，导致刷新暂停的问题
    - 添加协议容错处理，解决发送非协议数据时，使能协议程序意外退出的问题

- 2021/8/7 日
    - 处理界面刷新相关的定时器，一共4个界面刷新相关的定时器，当且仅当切换到此界面才可以开启刷新定时器，以便于减小占用
    - 进一步优化程序，暂时不准备继续添加功能，此版本将作为V1版本发布


- 2021/9/4
    - 考虑工作需求，工作调试软件颇为简陋，在此需要加入需要的TCP服务器功能
    - 拟定加入功能
        - TCP Server
        - TCP Client
        - 了解QT TCP实现的相关机制，需要先打通通信接口
    
- 2021/9/5
    - 简要写了一个TCP 的类，由于没有机器，暂时不能验证

- 2021/9/16
    - 自己写的Tcp服务器无法触发连接，而其他TCP工具可以触发，对比下来是自己的问题
    - Tcp Server设置为 ``this->listen(QHostAddress::AnyIPv4,this->vServerPort)``后可以触发``vNewConnect``,然后通过``this->nextPendingConnection()``，获取``TcpSocket``指针，便于操作该连接
    - 需要记录多个连接，同时在关闭TCP是删除所有的连接，在此需要分配动态地址，保存所有`TcpSocket`信息数据，以及其对应的接收数据，故在此使用了 `QList<QTcpSocket*>` `QList<QByteArray*>`以方便管理服务器数据，使用`QVector<quint16>`记录端口号
    - 显示接收数据沿用串口调试助手界面编写的``vPlainTextEdit``自定义类，以解决QT目前文本刷新大量数据带来的卡顿问题
    
- 2021/9/11-12
    - 加入发送功能，优化`TcpServer`界面
    - 加入多条发送
    - 加入hex格式支持
    - 加入换行符支持，新增支持设定以"}"判断是否换行，该功能只有`TcpServer`拥有
    - 加入定时发送等

- 2021/9/18-21
    - 修改``vPlainTextEdit``自定义类的原始基类对象``QPlainTextEdit``为``QTextEdit``,以支持富文本操作;
    - 修改刷新界面的判断需求,所有功能都需要针对`"\n"`即换行符做一些针对性的优化
    - 富文本中换行符不支持`"\n"`,取而代之的是html语言中的<br/>
    - 加入简单的串口终端界面，你可以直接使用 `Enter`键发送你需要发送的数据，同时加入换行符，以及清除当前窗口内容
    - 终端窗口界面支持设置一些简要的命令，同时通过鼠标点击发送
    - 继续优化TCP功能，串口接收界面，以及TCP接收界面，加入时间戳，设置不同颜色
    - Linux返回数据做一些简要处理，删除`\x1B[xx:xxm`格式的`ANSI序列（终端的富文本控制符）`，同时将``ANSI序列``中的颜色设置保留，并转换为`html`的``<font>``标签，以保留颜色格式，而过滤其他格式
    - 新增功能的数据备份和恢复功能的添加，在之前的基础之上，新增功能窗口的部分设置功能，以及需要发送的数据需要在第二次打开时可以恢复第一次关闭前的状态，以减少重复性工作，然而部分功能需要恢复为默认关闭状态
    - 基本完成这个版本功能，V0.0.2版本暂时告于段落。

- 2021/10/15
    - 公布添加TCP服务器部分的源码，完全开源，同时发布v0.0.3版本的软件，一个四个软件包，包含黑色简约主题的32位和64位版本，以及默认主题的32位和64位版本
    - 在此感谢 ``@BraiseFish`` 贡献的黑色主题的 css配置文件


- 2022/5/19
  - 修复编码格式问题
  - 添加说明，串口调试助手打印需要添加换行符

## 给作者加鸡腿！
| 支付宝                         | 微信                           |
|--------------------------------|--------------------------------|
| <img src="image/seaskyr1.jpg"> | <img src="image/seaskyr2.jpg"> |