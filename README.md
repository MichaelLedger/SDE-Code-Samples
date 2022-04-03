# SDE-Code-Samples
Software Design Engineer Code Samples

### 集成开发环境（IDE，Integrated Development Environment ）
IDE 是用于提供程序开发环境的应用程序，一般包括代码编辑器、编译器、调试器和图形用户界面等工具。
集成了代码编写功能、分析功能、编译功能、调试功能等一体化的开发软件服务套。所有具备这一特性的软件或者软件套（组）都可以叫集成开发环境。

#### Xcode for C/C++

***

#### Android Studio for Java
Android Studio Version 3.6.1

- Start a new Android Studio project
- Phone and Tablet -> No Activity -> Language:Java -> custom Name/Package name/Save location
- File -> New -> Module -> Java or Kotlin Library -> Language:Java -> Name:XXX
- Run -> Edit Configurations -> Left Top '+' to add new configuration -> choose 'application'
- configurations: Name: YYY -> Main class: <package name>.<classname> -> Use classpath of module: XXX 
- Run -> Edit Configurations: XXX -> Build/Run

**建议YYY的命名和其他的类名都不同，尽量精简一点！ **
如果命名和其他类名重复了，可以选中Module文件夹，右键->Refactor->Rename...->Scope:Module 'YYY'
YYY.java -> Refactor -> Rename... -> ZZZ.java

最后在自己编写代码的界面右键，选择“run class.main()”,或者用快捷键“ctr+R”进行运行；
如果Module的run按钮无法正常显示，重启Android Studio即可。

***
#### Tips

**快捷键**
`Ctr+Shift+R` 调出全局搜索，支持替换全局的某个字符串
`Tab` 代码块后移
`Shift+Tab`代码块前移

**删除Module配置及文件**
remove configuration for this module
左侧工程视图选择 `Project` ，修改 `setting.gradle` 对应的 module 的 include 语句 `include ':lib'` 后 sync ；
执行完这步操作后，选中module文件，右键后 delete 按钮就出来了，删除后文件就彻底被删除了！

**删除app以减少工程文件大小，如果只需要module文件可删除，大概可减少10MB**
同上，module改为app；
删除app后run某个java文件，可以选中该java文件后右键，`run '<moduel-name>'` 即可。

