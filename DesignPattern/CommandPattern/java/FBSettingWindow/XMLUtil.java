package DesignPattern.CommandPattern.java.FBSettingWindow;

import javax.xml.parsers.*;
import org.w3c.dom.*;

import java.io.*;

public class XMLUtil
{
    public static Object getBean(int i)
    {
        try
        {
            // 创建文档对象
            DocumentBuilderFactory dFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = dFactory.newDocumentBuilder();
            Document doc;
            doc = builder.parse(new File("DesignPattern/CommandPattern/java/FBSettingWindow/config.xml"));

            // 获取包含类名的文本节点
            NodeList nl = doc.getElementsByTagName("className");
            Node classNode = null;
            if (0 == i)
            {
                classNode = nl.item(0).getFirstChild();
            }
            else
            {
                classNode = nl.item(1).getFirstChild();
            }
            String cName = classNode.getNodeValue();
            System.out.println("get classname:");
            System.out.println(cName);
            // 通过类名生成实例对象并将其返回
            Class<?> c = Class.forName(cName);
            Object obj = c.newInstance();
            return obj;
        }
        catch(Exception e)
        {
            e.printStackTrace();
            return null;
        }
    }

    private void readVoipXml(String fpath)
    {
        if (null == fpath)
            return;
        try
        {
            File file = new File(fpath);
            if (!file.exists() ||  !file.canRead())
            {
                // LogUtils.e(fpath + "is not exists or can not read");
                return;
            }

            // 创建文档对象
            DocumentBuilderFactory dFactory = DocumentBuilderFactory.newInstance();
            DocumentBuilder builder = dFactory.newDocumentBuilder();
            Document doc;
            doc = builder.parse(file);

            // 获取包含类名的文本节点
            Element sipAccount = (Element)doc.getElementsByTagName("SipAccount").item(0);

            String HOST = sipAccount.getElementsByTagName("host").item(0).getTextContent();
            String PASSWORD = sipAccount.getElementsByTagName("password").item(0).getTextContent();
            String USER = sipAccount.getElementsByTagName("user").item(0).getTextContent();

            System.out.println(HOST + " " + PASSWORD + " " + USER);
        }
        catch(Exception e)
        {
            e.printStackTrace();
            return;
        }
   
    }
}