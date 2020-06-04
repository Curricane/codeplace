package DesignPattern.CommandPattern.java.ConfigSettingWindow;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class FileUtil 
{
    //将命令集合写入日志文件
    public static void writeCommands(final ArrayList commands) {
        try {
            final FileOutputStream file = new FileOutputStream(
                    "DesignPattern/CommandPattern/java/ConfigSettingWindow/config.log");

            // 创建对象输出流用于将对象写入到文件中
            final ObjectOutputStream objout = new ObjectOutputStream(new BufferedOutputStream(file));
            objout.writeObject(commands);
            objout.close();
        } catch (final Exception e) {
            System.out.println("命令保存失败");
            e.printStackTrace();
        }
    }

    // read
    public static ArrayList readCommands()
    {
        try
        {
            final FileInputStream file = new  FileInputStream("DesignPattern/CommandPattern/java/ConfigSettingWindow/config.log");
            final ObjectInputStream objin = new ObjectInputStream(file);
            ArrayList commands = (ArrayList) objin.readObject();
            objin.close();
            return commands;
        }
        catch(final Exception e)
        {
            System.out.println("命令读取失败！");
            e.printStackTrace();
            return null;
        }
    }
}