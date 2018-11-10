/*******************************************************
 *     Class Name:  MySQLConn                          *
 *    Description:  MySQL数据库连接类实现              *
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

#include "stdafx.h"
#include "MySQLConn.h"

MySQLConn::MySQLConn()
{
	res      = NULL;
	conn     = NULL;
	row      = 0;
    server   = "47.95.5.126";
//	server   = "localhost";
    user     = "root";
    password = "123456";
    database = "rry_schcostconsys";
	q_mode   = "set names \'utf8\'";
}

MySQLConn::~MySQLConn()
{

}

void MySQLConn::OnInitMySQLConn()
{
    /* 初始化MYSQL对象 */
    conn = mysql_init(NULL);
    /* 建立数据库连接 */
    if( !mysql_real_connect( conn, server, user, password, database, 0, NULL, 0 ) )
    {
        MessageBoxA(NULL,"连接数据库失败!","",NULL);
    }
}

bool MySQLConn::ExecuteSQL(char * sql)
{
    if(conn == NULL)
    { 
        OnInitMySQLConn();
    }

	/* 设置连接字符编码 */
	if(mysql_real_query(conn, q_mode, (unsigned long)strlen(q_mode)))
    {
        MessageBoxA(NULL,"设置连接字符编码失败!","",NULL);
        return false;
    }

	/* 执行SQL语句 */
    if(mysql_real_query(conn, sql, (unsigned long)strlen(sql)))
    {
        MessageBoxA(NULL,"执行SQL语句失败!","",NULL);
        return false;
    }

    return true;
}

bool MySQLConn::GetRecordSet(char * sql)
{
    if(!ExecuteSQL(sql))
    {
		MessageBoxA(NULL,"执行SQL语句失败!","",NULL);
        return false;
    }
    /* 将结果保存到res结构体中 */
    res = mysql_store_result(conn);

    return true;
}

unsigned int MySQLConn::GetRecordRow(char * sql)
{
	unsigned int result_row = 0;

	if( res == NULL )
	{
	    /* 获取结果集 */
	    if( !GetRecordSet(sql))
	    {
	    	MessageBoxA(NULL,"获取结果集失败!","",NULL);
	    	return 0;
	    }
	}
    /* 返回结果行 */
    while( row = mysql_fetch_row(res) )
	{
	    result_row++;
	}

	return result_row;
}

unsigned int MySQLConn::GetRecordFields(char * sql)
{
	if( res == NULL )
	{
	    /* 获取结果集 */
	    if( !GetRecordSet(sql))
	    {
	    	MessageBoxA(NULL,"获取结果集失败!","",NULL);
	    	return 0;
	    }
	}

    /* 返回结果列 */
    return mysql_num_fields(res);
}

void MySQLConn::SetRecordFree(MYSQL_RES * m_res)
{
    /* 释放结果集 */
    mysql_free_result(m_res);
}

void MySQLConn::ExitMySQLConn()
{
	/* 释放结果集 */
	if(res != NULL)
    {
        mysql_free_result(res);
    }

	/* 断开数据库连接 */
    if(conn != NULL)
    {
        mysql_close(conn);
    }
}
