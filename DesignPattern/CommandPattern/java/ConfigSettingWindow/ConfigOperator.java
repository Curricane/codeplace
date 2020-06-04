package DesignPattern.CommandPattern.java.ConfigSettingWindow;

import java.io.Serializable;


class ConfigOperator implements Serializable
{

    public void insert(String args)
    {
        System.out.println("增加新节点： " + args);
    }

    public void modify(String args)
    {
        System.out.println("修改节点： " + args);
    }

    public void delete(String args)
    {
        System.out.println("删除节点： " + args);
    }
}