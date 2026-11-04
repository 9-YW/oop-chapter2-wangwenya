# 面向对象程序设计第 2 章实验

本仓库包含第 2 章基础实验与校园一卡通综合项目实训的完整 C++11 源代码。

## 实验 2-1

- `task2_1_1_scores.cpp`：学生成绩统计与格式化输出
- `task2_1_2_vowels.cpp`：使用 `const char*` 统计元音
- `task2_1_3_calculator.cpp`：内联函数、默认参数与函数重载
- `task2_1_4_swap.cpp`：引用参数与函数重载

## 实验 2-2

- `CampusCardSystem.cpp`：程序入口
- `card_operations.h`：结构与函数声明
- `card_operations.cpp`：账户、消费、查询、报表及异常处理

## 编译示例

```bash
g++ -std=c++11 -Wall -Wextra -o task2_1_1 task2_1_1_scores.cpp
g++ -std=c++11 -Wall -Wextra -o task2_1_2 task2_1_2_vowels.cpp
g++ -std=c++11 -Wall -Wextra -o task2_1_3 task2_1_3_calculator.cpp
g++ -std=c++11 -Wall -Wextra -o task2_1_4 task2_1_4_swap.cpp
g++ -std=c++11 -Wall -Wextra -o campus_card CampusCardSystem.cpp card_operations.cpp
```
