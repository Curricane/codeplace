package DesignPattern.CommandPattern.java.ConfigSettingWindow;

import java.util.ArrayList;

//配置文件设置窗口类：请求发送者
public class ConfigSettingWindow {
    //定义一个集合来存储每一次操作时的命令对象
    private ArrayList<Command> commands = new ArrayList<Command>();
    private Command command;

    //注入具体命令对象
    public void setCommand(Command command)
    {
        this.command = command;
    }

    //执行配置文件修改命令，同时将命令对象添加到命令集合中
    public void call(String args)
    {
        command.execute(args);
        if (commands.size() <= 10000)
            commands.add(this.command); 
        else
        {
            save();
            commands.clear();
        }
    }

    public void save()
    {
        FileUtil.writeCommands(commands);
    }

    public void recover()
    {
        ArrayList list;
        list = FileUtil.readCommands();

        for (Object obj : list)
        {
            ((Command)obj).execute();
        }
    }
}