/*******************************************************
 *     Class Name:  MySQLConn                          *
 *    Description:  MySQL数据库连接类                  *
 *      Parameter:  clazz                              *
 *          input:                                     *
 *         output:                                     *
 *         return:                                     *
 *                  1  成功                            * 
 *                  0  失败                            *
 * --------------------------------------------------- *
 *         Date:    2017/11/01                         *
 *      Address:    Beijing                            *
 *       Author:    Guokk                              *
 *******************************************************/

/*
  使用此类的相关注意事项：
    1.在项目属性里添加MySQL数据库的lib和include路径
    2.在项目程序主目录里添加libmysql.dll动态链接库
    3.修改默认构造函数中连接数据库的相关数据
*/
#ifndef MYSQLCONN_H_
#define MYSQLCONN_H_

#include <winsock2.h>
#include <mysql.h>
#include <stdio.h>
#pragma comment(lib, "libmysql.lib")

using namespace std;

class MySQLConn
{
public:
    MYSQL     * conn;   /* MYSQL对象 */
    MYSQL_RES * res;    /* 结果集 */
    MYSQL_ROW row;      /* 结果行 */
    char * server;      /* 数据库地址 */
    char * user;        /* 用户名 */
    char * password;    /* 密码 */
    char * database;    /* 数据库名 */
	char * q_mode;      /* 连接字符编码 */
public:
    MySQLConn();                               /* 默认构造函数 */
    virtual ~MySQLConn();                      /* 析构函数 */
    void OnInitMySQLConn();                    /* 初始化数据库 */
    bool ExecuteSQL(char *);                   /* 执行SQL语句 */
    bool GetRecordSet(char *);                 /* 获取结果集 */
    unsigned int GetRecordRow(char *);         /* 获取结果行 */
    unsigned int GetRecordFields(char *);      /* 获取结果列 */
    void SetRecordFree(MYSQL_RES *);           /* 释放结果集 */
    void ExitMySQLConn();                      /* 断开数据库连接 */
};

#endif
