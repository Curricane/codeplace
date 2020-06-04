package DesignPattern.CommandPattern.java.FBSettingWindow;

import java.util.*;

// 功能键设置窗口类
class FBSettingWindow
{
    private String title;

    private final ArrayList<FunctionButton> functionButtons = new ArrayList<>();

    public FBSettingWindow(String title) {
        this.title = title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getTitle() {
        return this.title;
    }

    public void addFunctionButton(final FunctionButton fb) {
        functionButtons.add(fb);
    }

    public void removeFunctionButton(final FunctionButton fb) {
        functionButtons.remove(fb);
    }

    // 显示窗口及功能
    public void display() {
        System.out.println("显示窗口：" + this.title);
        System.out.println("显示功能键：");
        for (final Object obj : functionButtons) {
            System.out.println(((FunctionButton) obj).getName());
        }
        System.out.println("---------------------------");
    }
}


// 最小化命令类：具体的命令
class MinimizeCommand extends Command
{
    private WindowHanlder whobj;

    public MinimizeCommand()
    {
        whobj = new WindowHanlder();
    }
    @Override
    public void execute() {
        whobj.minimize();
    }
    
}

// 请求接受者
class HelpHander
{
    public void display()
    {
        System.out.println("显示帮助文档");
    }
}

class WindowHanlder
{
    public void minimize() 
    {
        System.out.println("将窗口最小化");
    }
}

