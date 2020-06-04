package DesignPattern.CommandPattern.java.ConfigSettingWindow;

import java.io.Serializable;

abstract public class Command implements Serializable {
    protected String name;
    protected String args;
    protected ConfigOperator configOperator;//维持对接收者对象的引用

    public Command(String name) {
		this.name = name;
	}
	
	public String getName() {
		return this.name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public void setConfigOperator(ConfigOperator configOperator) {
		this.configOperator = configOperator;
	}
	
    //声明两个抽象的执行方法execute()
	public abstract void execute(String args);
	public abstract void execute();

}

//增加命令类：具体命令
class InsertCommand extends Command {
	public InsertCommand(String name) {
		super(name);
	}
	
	public void execute(String args) {
		this.args = args;
		configOperator.insert(args);
	}
	
	public void execute() {
		configOperator.insert(this.args);
	}
}
 
//修改命令类：具体命令
class ModifyCommand extends Command {
	public ModifyCommand(String name) {
		super(name);
	}
	
	public void execute(String args) {
		this.args = args;
		configOperator.modify(args);
	}
	
	public void execute() {
		configOperator.modify(this.args);
	}
}
 
//删除命令类DeleteCommand：具体命令
class DeleteCommand extends Command {
	public DeleteCommand(String name) {
		super(name);
	}
	
	public void execute(String args) {
		this.args = args;
		configOperator.delete(args);
	}
	
	public void execute() {
		configOperator.delete(this.args);
	}
}

