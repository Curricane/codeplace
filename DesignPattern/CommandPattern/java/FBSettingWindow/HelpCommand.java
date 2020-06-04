

// 帮助命令类：具体的命令
public class HelpCommand extends Command {
    private final HelpHander hhObj;
    public HelpCommand()
    {
        hhObj = new HelpHander();
    }

    @Override
    public void execute() {
        hhObj.display();
    }
}