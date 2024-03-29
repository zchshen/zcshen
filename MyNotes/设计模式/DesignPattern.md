# 设计模式

>## 设计模式六大原则
1. 单一职责原则: 类的职责单一
2. 开闭原则: 对扩展开放，对修改封闭
3. 里氏替换原则: 任何抽象类使用的地方都可以使用其实现类替代
4. 接口隔离原则: 尽可能的不依赖不关心的接口
5. 依赖倒置原则: 依赖于抽象(接口), 不依赖具体实现(类)
6. 迪米特法则: 对象间的依赖尽可能降低, 保证低耦合

>## 创建型
1. 简单工厂方法模式  
    + 工厂角色、抽象产品角色、具体产品角色
    + 违背开闭原则，新增产品时需要修改工厂代码
2. 工厂方法模式  
    + 简单工厂方法模式+开闭原则 = 工厂方法模式
    + 抽象工厂角色(单个产品)、具体工厂角色、抽象产品角色、具体产品角色
    + 系统中类个数可能会过度膨胀。
3. 抽象工厂方法模式
    + 工厂方法模式+产品族 = 抽象工厂方法模式
    + 抽象工厂角色(一族产品)、具体工厂角色、抽象产品角色、具体产品角色
    + 适用于多余一个的产品族，且产品等级结构稳定场景
    + 当需要增加产品等级时，需要修改抽象层，违背开闭原则
4. 单例模式  
    + 饿汉模式单例
    + 懒汉模式单例

>## 结构型模式
1. 代理模式
    + 抽象主题角色、代理主题角色、真实主题角色
2. 装饰器模式
    + 抽象构件、具体构件、抽象装饰类、具体装饰类
3. 外观模式
    + 一种具有类似功能的类群。
    + 迪米特法则，尽可能的减少类之间不必要的依赖。
4. 适配器模式
    + 将目标类和适配者类进行解耦
    + 增加了类的透明性和复用性 
    + 灵活性和扩展性比较好
    + 目标类、适配者类、适配器类

>## 行为型模式
1. 模板方法模式
    + 抽象类、具体子类，将实现细节延迟到子类中实现
    + 在父类中固定算法框架, 通过子类实现处理细节
    + 可通过子类重写父类的钩子函数，实现反向控制，决定某一特定步骤是否执行
2. 命令模式  
    + 降低系统耦合度
    + 新命令可以容易加入系统
    + 可以比较容易的设计一个命令队列
    + 可能会导致命令过多的具体命令类
3. 策略模式  
    + 定义了一系列算法，并将算法进行封装，使算法独立与客户，可以相互切换
    + 环境类、抽象策略类、具体策略类
4. 观察者模式  
    + 抽象观察者、具体观察者、抽象通知者、具体通知者
    + 表示层和数据层分离
    + 观察目标和观察者之间建立抽象耦合
    + 观察者模式支持广播通信
    + 观察者与观察目标之间不能有循环依赖