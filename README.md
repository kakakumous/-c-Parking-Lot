# -c-Parking-Lot
C语言实现的一个简单但仿真的停车场管理系统，运行请使用vc++6.0或直接执行debug文件夹里的可执行文件。</br>
***
优点：可由系统管理员在可视化界面里自定义的车位数&等候区大小&停车费小时单价&免费停车时长（有控制区间防止出现奇怪情况）；<br>

缺点&可提升的地方：
* 1.停车时间没加年;
* 2.为了方便演示使用手动输入时间而不是自动获取系统时间；
* 3.数据写入文件防止断电数据丢失；
* 4.需要添加更多的错误输入拦截及其相应的错误提示；
* 5.为了写菜单用了很多goto（目移）。
***
打扫U盘找到的版本日志.txt<br>
【1.0】MON 14：48：没有有功能的算法，总之做了个好看菜单出来<br>
【1.0001】MON 15:25：闲着无聊把菜单改成了居中的。二次美化。<br>
【1.0002】TUE 9：58：发现了栈停车场的缺点和不现实，前面的打回重来了。<br>
【1.1】WED 14:35：做了车的结构体，车牌时间操作，可自定义车位数，结构体套动态结构体数组。<br>
【2.0】WED 20：19：弄完啦！！！！还可以自定义排队进场。<br>
<br>
打扫u盘找到的收费标准.txt<br>
停车场白天时段(8:00-20:00)实行计时收费，收费标准为：15分钟内免费，15分钟至1小时7元/台，超过1小时的，每30分钟加收3元；夜间时段(20:00-次日8:00)免费。<br>
***
## 参考资料
https://blog.csdn.net/weixin_41918712/article/details/80543818</br>
https://blog.csdn.net/panhongan_nettery/article/details/48085523</br>
https://blog.csdn.net/qq_38880380/article/details/81474580</br>
https://zhidao.baidu.com/question/220693038.html</br>
