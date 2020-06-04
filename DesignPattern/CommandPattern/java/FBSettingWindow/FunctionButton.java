package DesignPattern.CommandPattern.java.FBSettingWindow;

// 功能键类：请求发送者
public  class FunctionButton {
    private Command cmd;
    private String name;

    public FunctionButton(String name)
    {
        this.name = name;
    }

    public String getName()
    {
        return this.name;
    }

    public void setComman(Command cmd)
    {
        this.cmd = cmd;
    }

    public void onClick()
    {
        System.out.println("点击功能键： ");
        cmd.execute();
    }

}