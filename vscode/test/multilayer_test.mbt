// 多层查询测试文件
// 用于测试 moon-grep 的多层查询功能

// 结构体定义 - 用于测试 $top
struct Point {
    x: Int
    y: Int
}

struct Rectangle {
    top_left: Point
    bottom_right: Point
}

fn main {
    // 基础表达式
    let x = 1 + 2
    let y = 3 * 4
    let z = 5 - 6
    
    // 函数调用
    fn greet(name: String) {
        println("Hello, " + name)
    }
    
    // 条件表达式
    if x > 0 {
        println("Positive")
    }
    
    // 嵌套表达式
    let result = (1 + 2) * (3 + 4)
    let complex = (x + y) * (z + 1)
    
    // 函数调用表达式
    greet("World")
    greet("Moonbit")
} 