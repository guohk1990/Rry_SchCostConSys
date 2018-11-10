/*******************************************************
 *     Class Name:  MySQLConn                          *
 *    Description:  MySQL���ݿ�������ʵ��              *
 *      Parameter:  clazz                              *
 *          input:                                     *
 *         output:                                     *
 *         return:                                     *
 *                  1  �ɹ�                            * 
 *                  0  ʧ��                            *
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
    /* ��ʼ��MYSQL���� */
    conn = mysql_init(NULL);
    /* �������ݿ����� */
    if( !mysql_real_connect( conn, server, user, password, database, 0, NULL, 0 ) )
    {
        MessageBoxA(NULL,"�������ݿ�ʧ��!","",NULL);
    }
}

bool MySQLConn::ExecuteSQL(char * sql)
{
    if(conn == NULL)
    { 
        OnInitMySQLConn();
    }

	/* ���������ַ����� */
	if(mysql_real_query(conn, q_mode, (unsigned long)strlen(q_mode)))
    {
        MessageBoxA(NULL,"���������ַ�����ʧ��!","",NULL);
        return false;
    }

	/* ִ��SQL��� */
    if(mysql_real_query(conn, sql, (unsigned long)strlen(sql)))
    {
        MessageBoxA(NULL,"ִ��SQL���ʧ��!","",NULL);
        return false;
    }

    return true;
}

bool MySQLConn::GetRecordSet(char * sql)
{
    if(!ExecuteSQL(sql))
    {
		MessageBoxA(NULL,"ִ��SQL���ʧ��!","",NULL);
        return false;
    }
    /* ��������浽res�ṹ���� */
    res = mysql_store_result(conn);

    return true;
}

unsigned int MySQLConn::GetRecordRow(char * sql)
{
	unsigned int result_row = 0;

	if( res == NULL )
	{
	    /* ��ȡ����� */
	    if( !GetRecordSet(sql))
	    {
	    	MessageBoxA(NULL,"��ȡ�����ʧ��!","",NULL);
	    	return 0;
	    }
	}
    /* ���ؽ���� */
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
	    /* ��ȡ����� */
	    if( !GetRecordSet(sql))
	    {
	    	MessageBoxA(NULL,"��ȡ�����ʧ��!","",NULL);
	    	return 0;
	    }
	}

    /* ���ؽ���� */
    return mysql_num_fields(res);
}

void MySQLConn::SetRecordFree(MYSQL_RES * m_res)
{
    /* �ͷŽ���� */
    mysql_free_result(m_res);
}

void MySQLConn::ExitMySQLConn()
{
	/* �ͷŽ���� */
	if(res != NULL)
    {
        mysql_free_result(res);
    }

	/* �Ͽ����ݿ����� */
    if(conn != NULL)
    {
        mysql_close(conn);
    }
}
