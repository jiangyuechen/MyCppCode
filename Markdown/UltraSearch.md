# UltraSearch (超级搜索)
## 
## 命令与开关
### 简单搜索开关
`-k / -kwd / --keyword <keyword>` 关键词

`-ke / --kwd-expr / --keyword-expression <keyword-expression>` 关键词表达式（详见下方“关键词表达式”介绍）

`-re / --reg-expr / --regular-expression <regular-expression>` 由正则表达式决定的关键词 

`-type @<type>` 需要的网页类型
- @doc 文档
- @encyclopedia / @wiki / @baike 百科（三者含义相同）
- @video 视频
- @download 下载页面

`--match-case` 区分大小写（若不使用此开关，则表示不区分大小写）

`--match-diacritical` 匹配变音符号（若不使用此开关，则表示忽略变音符号）


### 筛选开关
`-ex / --exclude <keyword>` 排除的关键词 (目前不支持表达式和正则表达式)

`-ext / --exclude-type @<type>`  排除的网页类型（详见上文“需要的网页类型”）

### 排序开关
`--by-relevance` 根据相关度排序。

`-by-`

### 其他开关
`-s / -safe` 在安全模式中浏览（只浏览搜索结果而不允许打开页面；不加载任何加载项）

`-explorer <directory>` 指定浏览器（必须输入浏览器程序所在的位置，如：C:\Program Files (x86)\Microsoft\Edge\Application\msedge.exe

`--allow-sensitive-content` 允许显示敏感内容
- 敏感内容包括：政治敏感；文化（如宗教）敏感；血腥暴力；色情淫秽；低俗/媚俗；等等。
- 在安全模式下不可用。

`--allow-reported-page` 允许显示曾被举报的网页
- 在安全模式下不可用。

`--allow-unsafe-link` 允许打开不安全链接
- 这些链接可能包含：诈骗信息；木马病毒；非法挖矿；等等。
- 这些链接可能非常危险，请谨慎使用此开关。
- 在安全模式下不可用。

`-wl/--warning-level <number>` 警告级别
- `0` 关闭警告。
- `1` 仅警告不安全链接。
- `2` 警告敏感内容、被举报网页、不安全链接。（默认值）
- `3` 与 `-s / -safe` 效果相同。