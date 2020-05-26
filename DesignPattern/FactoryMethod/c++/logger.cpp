#include <iostream>

using std::cout;
using std::endl;

namespace logger
{

// 日志记录接口器：抽象产品
class Logger
{
public:
    virtual void writeLog() = 0;
    virtual ~Logger(){};   
};

// 数据库日志记录器
class DatabaseLogger: public Logger
{
public:
    DatabaseLogger()
    {
        cout << "DatabaseLogger Created" << endl;
    };
    ~DatabaseLogger()
    {
        cout << "bye DatabaseLogger" << endl;
    };
    void writeLog()
    {
        cout << "logger in DatabaseLogger" << endl;
    };
};

// 文件日志记录器
class FileLogger:public Logger
{
public:
    FileLogger()
    {
        cout << "FileLogger Created" << endl;
    };
    ~FileLogger()
    {
        cout << "bye FileLogger" << endl;
    };
    void writeLog()
    {
        cout << "logger in FileLogger" << endl;
    };
};

}; // end logger


namespace FactoryMethod
{

// 日志工厂接口
class LoggerFactory
{
public:
    virtual logger::Logger* createLogger() = 0;
    virtual ~LoggerFactory()
    {
        cout << "bye LoggerFactory" << endl;
    }
};

// 文件日志工长
class FileLoggerFactory: public LoggerFactory
{
public:
    FileLoggerFactory()
    {
        cout << "FileLoggerFactory Created" << endl;
    }
    ~FileLoggerFactory()
    {
        cout << "bye FileLoggerFactory" << endl;
    }
    logger::Logger* createLogger()
    {
        return new logger::FileLogger();
    }
};

// 数据库日志工长
class DatabaseLoggerFactory: public LoggerFactory
{
    DatabaseLoggerFactory()
    {
        cout << "DatabaseLoggerFactory Created" << endl;
    }
    ~DatabaseLoggerFactory()
    {
        cout << "bye DatabaseLoggerFactory" << endl;
    }
    logger::Logger* createLogger()
    {
        return new logger::DatabaseLogger();
    }
};

}; // end FactoryMethod

int main()
{
    FactoryMethod::LoggerFactory *loggerFactory = nullptr;
    logger::Logger *logger = nullptr;
    loggerFactory = new FactoryMethod::FileLoggerFactory();
    logger = loggerFactory->createLogger();
    logger->writeLog();
    delete logger;
    delete loggerFactory;
}