import os
import re

root = os.path.dirname(os.path.abspath(__file__))
input = os.path.join(root, "1.txt")
# 输入文件

f_input = open(input, "r", encoding="utf-8")
f_output = open(os.path.join(root, "1.srt"), "w")
# 输出文件

# 初始化第一个时间，并去除歌词常见的开头没有用的部分
num = 1
while True:
    line = f_input.readline()
    if len(line) > 1:
        # 判断第2个字符是否是数字，若不是跳过（不够严谨）
        if not (line[1] >= "0" and line[1] <= "9"):
            continue
        else:
            re_result = re.search("\[(.*?)\](.*)", line)
            hour = "00"
            minute = re_result.group(1)[0:2]
            second = re_result.group(1)[3:5]
            millisecond = re_result.group(1)[6:8]
            time1 = hour + ":" + minute + ":" + second + "," + millisecond + "0"
            content1 = re_result.group(2)
            break

try:
    while True:
        line = f_input.readline()
        if line:
            re_result = re.search("\[(.*?)\](.*)", line)
            minute = re_result.group(1)[0:2]
            second = re_result.group(1)[3:5]
            millisecond = re_result.group(1)[6:8]
            print(re_result)
            if re_result:
                if content1 != "":
                    # 处理时间，上一句歌词和下一句歌词之间的时间间隔为10毫秒
                    if int(millisecond) > 0:
                        millisecond = str(int(millisecond) - 1)
                        if len(millisecond) == 1:
                            millisecond = "0" + millisecond
                    else:
                        if int(second) > 0:
                            second = str(int(second) - 1)
                            if len(second) == 1:
                                second = "0" + second
                            millisecond = "99"

                        else:
                            if int(minute) > 0:
                                minute = str(int(minute) - 1)
                                if len(minute) == 1:
                                    minute = "0" + minute
                                second = "59"
                                millisecond = "99"
                            else:
                                print("第" + str(num) + "块时间格式错误!")
                                break
                    # 输出歌词
                    time2 = hour + ":" + minute + ":" + second + "," + millisecond + "0"
                    result = (
                        str(num)
                        + "\n"
                        + time1
                        + " --> "
                        + time2
                        + "\n"
                        + content1
                        + "\n"
                    )
                    f_output.write(result)
                    f_output.write("\n")
                    num = num + 1
                    print(result)
                # 将上一句歌词的结束时间赋值给下一句歌词的开头时间
                minute = re_result.group(1)[0:2]
                second = re_result.group(1)[3:5]
                millisecond = re_result.group(1)[6:8]
                time = hour + ":" + minute + ":" + second + "," + millisecond + "0"
                time1 = time
                content1 = re_result.group(2)
        else:
            break
finally:
    f_input.close()
    f_output.close()
